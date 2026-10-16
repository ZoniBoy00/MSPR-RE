"""Optional tshark (Wireshark) enrichment - best effort, never required.

When tshark is available it provides high-fidelity passive decoding of
TLS/QUIC handshakes (SNI, ALPN) and HTTP object export. Everything here
is still strictly passive analysis of the local PCAPNG file.
"""

from __future__ import annotations

import json
import shutil
import subprocess
from pathlib import Path
from typing import Dict, List, Optional

from .redact import redact_value

TSHARK_CANDIDATES = [
    r"C:\Program Files\Wireshark\tshark.exe",
    r"C:\Program Files (x86)\Wireshark\tshark.exe",
]


def find_tshark() -> Optional[str]:
    p = shutil.which("tshark")
    if p:
        return p
    for c in TSHARK_CANDIDATES:
        if Path(c).exists():
            return c
    return None


def _run(tshark: str, args: List[str], timeout: int = 300) -> str:
    proc = subprocess.run(
        [tshark, *args],
        capture_output=True,
        text=True,
        encoding="utf-8",
        errors="replace",
        timeout=timeout,
    )
    return proc.stdout or ""


def extract_handshakes(tshark: str, pcapng: str) -> List[Dict]:
    """TLS + QUIC ClientHello facts: SNI, ALPN, TLS version, transport."""
    out = _run(
        tshark,
        [
            "-r", pcapng,
            "-Y", "tls.handshake.type==1 || quic.long.packet_type==0",
            "-T", "fields",
            "-E", "separator=|",
            "-E", "occurrence=a",
            "-e", "ip.dst",
            "-e", "tcp.dstport",
            "-e", "udp.dstport",
            "-e", "tls.handshake.extensions_server_name",
            "-e", "tls.handshake.extensions_alpn_str",
            "-e", "tls.handshake.version",
        ],
    )
    rows: List[Dict] = []
    seen = set()
    for line in out.splitlines():
        parts = (line.split("|") + [""] * 6)[:6]
        dst, tcpport, udpport, sni, alpn, version = parts
        host = sni or ""
        proto_alpn = alpn or ""
        transport = "tcp" if tcpport else ("udp" if udpport else "?")
        key = (host, proto_alpn, transport, dst)
        if not host and not proto_alpn:
            continue
        if key in seen:
            continue
        seen.add(key)
        rows.append(
            {
                "dst_ip": dst,
                "transport": transport,
                "dst_port": tcpport or udpport,
                "sni": redact_value(host) if host else "",
                "alpn": proto_alpn,
                "tls_version": version,
                "note": "OBSERVED from ClientHello. ECH may hide the real SNI behind a public name.",
            }
        )
    rows.sort(key=lambda r: (r["sni"], r["transport"]))
    return rows


def export_http_objects(tshark: str, pcapng: str, out_dir: Path) -> List[Dict]:
    """Export plaintext HTTP response bodies (e.g. leaderboard JSON) locally."""
    obj_dir = out_dir / "http_objects"
    obj_dir.mkdir(parents=True, exist_ok=True)
    try:
        _run(tshark, ["-r", pcapng, "-Y", "http.response", "--export-objects", f"http,{obj_dir}"], timeout=600)
    except Exception:
        return []

    manifest: List[Dict] = []
    for f in sorted(obj_dir.iterdir()):
        if not f.is_file() or f.stat().st_size == 0:
            continue
        raw = f.read_bytes()
        # Only keep textual (JSON/HTML/XML) bodies; drop binaries like images.
        head = raw[:512]
        is_text = head.lstrip()[:1] in (b"{", b"[", b"<") or b"html" in head.lower()
        sanitized = b""
        if is_text:
            try:
                text = raw.decode("utf-8", errors="replace")
                text = redact_value(text)
                sanitized = text.encode("utf-8", errors="replace")
                f.write_bytes(sanitized)
                preview = text[:200].replace("\n", " ")
            except Exception:
                continue
            manifest.append(
                {
                    "file": f.name,
                    "size_bytes": len(sanitized),
                    "preview": redact_value(preview),
                }
            )
        else:
            # Binary body: keep only size, do not store content.
            f.unlink()
            manifest.append({"file": f.name, "size_bytes": len(raw), "preview": "[binary body removed]"})
    return manifest
