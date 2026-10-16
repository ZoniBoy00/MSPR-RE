"""Analysis of captured packets into a sanitized JSON summary.

Produces OBSERVED facts only:
- DNS queries and answers
- Network flows (src/dst ip, ports, protocol, packets, bytes, timing)
- Plaintext HTTP request lines and non-sensitive headers (redacted)
- Packets seen on historically-used SCERT TCP ports (10070-10099)

No port numbers, hostnames or endpoints are hardcoded as facts; the
10070-10099 range is only used to *annotate* observations, never to
invent destinations.
"""

from __future__ import annotations

from collections import defaultdict
from datetime import datetime, timezone
from typing import Dict, List, Optional, Tuple

from scapy.all import DNS, DNSQR, DNSRR, IP, IPv6, Raw, TCP, UDP  # type: ignore

from .redact import redact_headers, redact_value

SCERT_HINT_PORTS = set(range(10070, 10000 + 100))  # hint only, from old captures


def _iso(ts: float) -> str:
    return datetime.fromtimestamp(ts, tz=timezone.utc).isoformat()


class Analyzer:
    """Incrementally analyze packets captured from one interface."""

    MAX_BODY_BYTES = 64 * 1024
    MAX_BODIES = 200

    def __init__(self) -> None:
        self.dns_queries: List[Dict] = []
        self.flows: Dict[Tuple, Dict] = {}
        self.http_transactions: List[Dict] = []
        self.http_bodies: List[Dict] = []
        self.connections: List[Dict] = []
        self.scert_observed: Dict[str, Dict] = {}
        self.packet_count = 0
        self.bytes_total = 0
        self.first_ts: Optional[float] = None
        self.last_ts: Optional[float] = None
        self.ip_to_names: Dict[str, set] = defaultdict(set)
        # TCP reassembly buffers for plaintext HTTP (key: (flowkey, direction))
        self._tcp_buf: Dict[Tuple, Dict[int, bytes]] = {}
        self._tcp_isn: Dict[Tuple, int] = {}
        self._http_flows: set = set()

    # ------------------------------------------------------------------ #
    @staticmethod
    def _classify(proto: str, sport: int, dport: int) -> str:
        ports = {sport, dport}
        if 53 in ports:
            return "dns"
        if 80 in ports:
            return "http-plaintext"
        if proto == "udp" and 443 in ports:
            return "quic-http3"
        if proto == "tcp" and 443 in ports:
            return "tls"
        if any(p in SCERT_HINT_PORTS for p in ports):
            return "scert-hint-range"
        return "other"

    def add_packet(self, pkt, ts: Optional[float] = None) -> None:
        if ts is None:
            ts = float(pkt.time)
        self.packet_count += 1
        self.bytes_total += len(pkt)
        self.first_ts = ts if self.first_ts is None else min(self.first_ts, ts)
        self.last_ts = ts if self.last_ts is None else max(self.last_ts, ts)

        ip_layer = pkt.getlayer(IP) or pkt.getlayer(IPv6)
        if ip_layer is None:
            return
        src, dst = ip_layer.src, ip_layer.dst

        dns = pkt.getlayer(DNS)
        if dns is not None:
            self._handle_dns(dns, ts)

        tcp = pkt.getlayer(TCP)
        udp = pkt.getlayer(UDP)
        sport = dport = None
        if tcp is not None:
            sport, dport = int(tcp.sport), int(tcp.dport)
        elif udp is not None:
            sport, dport = int(udp.sport), int(udp.dport)

        if sport is None:
            return

        self._record_flow(src, dst, sport, dport, "tcp" if tcp is not None else "udp", ts, len(pkt))

        # TCP connection lifecycle events (SYN/FIN/RST) - observed facts
        if tcp is not None:
            flags = int(tcp.flags)
            if flags & 0x02 and not flags & 0x10:  # SYN without ACK
                self.connections.append(
                    {
                        "timestamp": _iso(ts),
                        "src": f"{src}:{sport}",
                        "dst": f"{dst}:{dport}",
                        "transport": "tcp",
                        "type": "connect (SYN)",
                        "classified": self._classify("tcp", sport, dport),
                    }
                )
            if flags & 0x01:
                self.connections.append(
                    {"timestamp": _iso(ts), "src": f"{src}:{sport}", "dst": f"{dst}:{dport}", "type": "close (FIN)"}
                )
            if flags & 0x04:
                self.connections.append(
                    {"timestamp": _iso(ts), "src": f"{src}:{sport}", "dst": f"{dst}:{dport}", "type": "reset (RST)"}
                )
            # Reassembly for plaintext HTTP streams (detected by signature, not port)
            if tcp is not None and tcp.haslayer(Raw):
                try:
                    raw = bytes(tcp.getlayer(Raw).load)
                    is_http = (
                        raw.startswith((b"GET ", b"POST ", b"PUT ", b"HEAD ", b"DELETE ", b"OPTIONS ", b"PATCH "))
                        or raw.startswith(b"HTTP/1.")
                    )
                    key = self._flow_key(src, dst, sport, dport, "tcp")
                    if is_http:
                        self._http_flows.add(key)
                        self.flows.setdefault(key, {})["classified"] = "http-plaintext"
                    if key in self._http_flows:
                        direction = (
                            "c->s" if raw.startswith((b"GET ", b"POST ", b"PUT ", b"HEAD ", b"DELETE ", b"OPTIONS ", b"PATCH "))
                            else "s->c"
                        )
                        k = (key, direction)
                        buf = self._tcp_buf.setdefault(k, {})
                        buf[int(tcp.seq)] = raw
                except Exception:
                    pass

        # Annotation: packet on the historical SCERT hint range (observed fact only)
        for p in (sport, dport):
            if p in SCERT_HINT_PORTS:
                key = f"tcp/{p}" if tcp is not None else f"udp/{p}"
                rec = self.scert_observed.setdefault(
                    key, {"peer_ips": set(), "packets": 0, "bytes": 0, "first_seen": _iso(ts)}
                )
                rec["packets"] += 1
                rec["bytes"] += len(pkt)
                rec["peer_ips"].add(dst if dport == p else src)
                rec["last_seen"] = _iso(ts)

        if tcp is not None and tcp.haslayer(Raw):
            try:
                self._try_http(bytes(tcp.getlayer(Raw).load), src, dst, sport, dport, ts)
            except Exception:
                pass

    # ------------------------------------------------------------------ #
    def _handle_dns(self, dns, ts: float) -> None:
        try:
            qd = dns.qd
            qname = qd.qname.decode(errors="replace").rstrip(".") if qd else None
            qtype = int(qd.qtype) if qd else None
        except Exception:
            return
        if not qname:
            return

        answers: List[str] = []
        try:
            an = dns.an
            records = an if isinstance(an, (list, tuple)) else ([an] if an is not None else [])
            for rr in records:
                if not isinstance(rr, DNSRR):
                    continue
                if rr.type == 1:  # A
                    answers.append(str(rr.rdata))
                    self.ip_to_names[str(rr.rdata)].add(qname)
                elif rr.type == 28:  # AAAA
                    answers.append(str(rr.rdata))
                    self.ip_to_names[str(rr.rdata)].add(qname)
                elif rr.type in (2, 5, 12):  # NS/CNAME/PTR
                    answers.append(
                        f"{'CNAME' if rr.type == 5 else 'NS' if rr.type == 2 else 'PTR'} "
                        f"{rr.rdata.decode(errors='replace').rstrip('.')}"
                    )
        except Exception:
            pass

        self.dns_queries.append(
            {"timestamp": _iso(ts), "query": qname, "type": qtype, "answers": answers}
        )

    def _flow_key(self, src, dst, sport, dport, proto) -> Tuple:
        if (src, sport) > (dst, dport):
            return (dst, dport, src, sport, proto)
        return (src, sport, dst, dport, proto)

    def _record_flow(self, src, dst, sport, dport, proto, ts, nbytes) -> None:
        # Canonical direction so both directions of one connection share a flow
        key = self._flow_key(src, dst, sport, dport, proto)
        flow = self.flows.get(key)
        if flow is None:
            flow = self.flows[key] = {
                "protocol": proto,
                "src_ip": key[0],
                "src_port": key[1],
                "dst_ip": key[2],
                "dst_port": key[3],
                "packets": 0,
                "bytes": 0,
                "first_seen": _iso(ts),
                "last_seen": _iso(ts),
                "dns_names": [],
                "classified": self._classify(proto, key[1], key[3]),
            }
        flow["packets"] += 1
        flow["bytes"] += nbytes
        flow["last_seen"] = _iso(ts)
        flow["dns_names"] = sorted(self.ip_to_names.get(key[2], set()))

    # ------------------------------------------------------------------ #
    def finalize(self) -> None:
        """Reassemble buffered plaintext-HTTP streams and extract bodies."""
        for key, buf in self._tcp_buf.items():
            flowkey, direction = key
            stream = b""
            base = min(buf)
            for seq in sorted(buf):
                chunk = buf[seq]
                pos = seq - base
                end = pos + len(chunk)
                if len(stream) < end:
                    stream += b"\x00" * (end - len(stream))
                stream = stream[:pos] + chunk + stream[end:]

            i = 0
            body_count = 0
            while i < len(stream) and body_count < self.MAX_BODIES:
                idx = stream.find(b"HTTP/1.", i)
                if idx == -1:
                    break
                hdr_end = stream.find(b"\r\n\r\n", idx)
                if hdr_end == -1:
                    break
                head = stream[idx:hdr_end].decode("utf-8", errors="replace")
                lines = head.split("\r\n")
                if lines[0].startswith("HTTP/"):
                    parts = lines[0].split(" ", 2)
                    meta = {"direction": direction, "status": parts[1] if len(parts) > 1 else "?"}
                else:
                    meta = {"direction": direction, "request": lines[0]}
                headers = {}
                for line in lines[1:]:
                    if ":" in line:
                        n, _, v = line.partition(":")
                        headers[n.strip().lower()] = v.strip()

                body_start = hdr_end + 4
                if "content-length" in headers:
                    try:
                        clen = int(headers["content-length"])
                    except ValueError:
                        clen = 0
                else:
                    clen = 0
                if clen:
                    body = stream[body_start:body_start + clen]
                    i = body_start + clen
                elif "chunked" in headers.get("transfer-encoding", ""):
                    body = b""
                    p = body_start
                    i = len(stream)
                    while p < len(stream):
                        nl = stream.find(b"\r\n", p)
                        if nl == -1:
                            break
                        try:
                            size = int(stream[p:nl].split(b";")[0], 16)
                        except ValueError:
                            break
                        if size == 0:
                            i = nl + 4
                            break
                        body += stream[nl + 2:nl + 2 + size]
                        p = nl + 2 + size + 2
                else:
                    nxt = stream.find(b"HTTP/1.", body_start)
                    body = stream[body_start: nxt if nxt != -1 else len(stream)]
                    i = body_start + len(body)

                if not body:
                    continue
                body_count += 1
                body = body[:self.MAX_BODY_BYTES]
                text_body = body.decode("utf-8", errors="replace")
                stripped = text_body.lstrip()
                ctype = headers.get("content-type", "")
                is_json_xml = bool(stripped) and stripped[0] in "{[<"
                is_form = "application/x-www-form-urlencoded" in ctype.lower()
                if not is_json_xml and not is_form:
                    continue  # store JSON/XML bodies and form submissions
                self.http_bodies.append(
                    {
                        "flow": f"{flowkey[0]}:{flowkey[1]} -> {flowkey[2]}:{flowkey[3]}",
                        **meta,
                        "content_type": headers.get("content-type", "?"),
                        "size_bytes": len(body),
                        "body_redacted": redact_value(text_body),
                    }
                )


    # ------------------------------------------------------------------ #
    def _try_http(self, raw: bytes, src, dst, sport, dport, ts) -> None:
        try:
            text = raw[:8192].decode("utf-8", errors="replace")
        except Exception:
            return

        # Request?
        if text.startswith(("GET ", "POST ", "PUT ", "HEAD ", "DELETE ", "OPTIONS ", "PATCH ")):
            try:
                lines = text.split("\r\n")
                method, path, _version = lines[0].split(" ", 2)
                headers = []
                for line in lines[1:]:
                    if not line:
                        break
                    if ":" in line:
                        n, _, v = line.partition(":")
                        headers.append((n.strip(), v.strip()))
                self.http_transactions.append(
                    {
                        "timestamp": _iso(ts),
                        "direction": "request",
                        "src": f"{src}:{sport}",
                        "dst": f"{dst}:{dport}",
                        "method": method,
                        "path": redact_value(path),
                        "headers": redact_headers(headers),
                    }
                )
            except Exception:
                pass
            return

        # Response? (observed only when a status line is plainly visible)
        if text.startswith("HTTP/1."):
            try:
                lines = text.split("\r\n")
                _version, status, reason = lines[0].split(" ", 2)
                headers = []
                for line in lines[1:]:
                    if not line:
                        break
                    if ":" in line:
                        n, _, v = line.partition(":")
                        headers.append((n.strip(), v.strip()))
                self.http_transactions.append(
                    {
                        "timestamp": _iso(ts),
                        "direction": "response",
                        "src": f"{src}:{sport}",
                        "dst": f"{dst}:{dport}",
                        "status": int(status),
                        "reason": reason.strip(),
                        "headers": redact_headers(headers),
                    }
                )
            except Exception:
                pass

    # ------------------------------------------------------------------ #
    def summary(self, interface: str, bpf_filter: str, backend: str, events: Optional[List[Dict]] = None) -> Dict:
        self.finalize()
        flows_out = []
        for f in self.flows.values():
            g = dict(f)
            try:
                from datetime import datetime as _dt

                t0 = _dt.fromisoformat(f["first_seen"]).timestamp()
                t1 = _dt.fromisoformat(f["last_seen"]).timestamp()
                g["duration_s"] = round(t1 - t0, 3)
            except Exception:
                g["duration_s"] = None
            flows_out.append(g)
        # Interesting protocols first, then by volume
        flows_out.sort(key=lambda f: (f["bytes"], f["packets"]), reverse=True)
        flows_out.sort(key=lambda f: f["classified"] in ("other", "tls"))

        scert_out = []
        for key, rec in self.scert_observed.items():
            scert_out.append(
                {
                    "port_key": key,
                    "peer_ips": sorted(rec["peer_ips"]),
                    "packets": rec["packets"],
                    "bytes": rec["bytes"],
                    "first_seen": rec["first_seen"],
                    "last_seen": rec.get("last_seen"),
                    "note": "OBSERVED on historical SCERT hint range; purpose not confirmed",
                }
            )
        scert_out.sort(key=lambda r: r["port_key"])

        return {
            "tool": "mspr_capture",
            "observed": {
                "interface": interface,
                "bpf_filter": bpf_filter,
                "backend": backend,
                "packet_count": self.packet_count,
                "bytes_total": self.bytes_total,
                "first_timestamp": _iso(self.first_ts) if self.first_ts else None,
                "last_timestamp": _iso(self.last_ts) if self.last_ts else None,
            },
            "events": events or [],
            "dns_queries": self.dns_queries,
            "connections": self.connections,
            "flows": flows_out,
            "http_plaintext": self.http_transactions,
            "http_bodies": self.http_bodies,
            "scert_hint_range_observations": scert_out,
            "notes": [
                "All entries above are OBSERVED facts from packet metadata and plaintext payloads.",
                "HTTP request/response bodies are stored only for JSON payloads, with credentials redacted.",
                "TCP/UDP payload contents other than plaintext HTTP are NOT interpreted.",
                "Ports 10070-10099 are annotated only as a historical hint, not a conclusion.",
                "If traffic was encrypted (TLS/SCERT), payload contents are intentionally opaque.",
                "Run tools/reanalyze.py <pcapng> to regenerate a summary offline.",
            ],
        }
