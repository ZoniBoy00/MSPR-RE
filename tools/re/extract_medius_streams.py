"""Extract Medius (SCE-RT) TCP streams from a capture as ordered, framed
messages: [(direction, msg_id, encrypted, hash, payload), ...].

Writes re/medius_streams/<pcap>-<stream>-<port>.json
Usage: python -X utf8 tools\\extract_medius_streams.py captures\\X.pcapng [ports...]
"""

import json
import subprocess
import sys
from pathlib import Path

TSHARK = r"C:\Program Files\Wireshark\tshark.exe"
OUT = Path(__file__).resolve().parent.parent / "re" / "medius_streams"


def tcp_streams(pcap, ports):
    flt = " or ".join("tcp.dstport==%d" % p for p in ports)
    out = subprocess.run(
        [TSHARK, "-r", pcap, "-Y", "(%s) && tcp.flags.syn==1 && tcp.flags.ack==0" % flt,
         "-T", "fields", "-e", "tcp.stream", "-e", "tcp.dstport", "-e", "frame.time_relative"],
        capture_output=True, text=True).stdout
    res = []
    for line in out.splitlines():
        sid, port, t = line.split("\t")
        res.append((int(sid), int(port), float(t)))
    return res


def follow_chunks(pcap, sid):
    """Return [(dir, bytes)] in order; dir 'C' = client->server."""
    out = subprocess.run([TSHARK, "-r", pcap, "-q", "-z", "follow,tcp,raw,%d" % sid],
                         capture_output=True, text=True).stdout
    chunks, started = [], False
    for line in out.splitlines():
        if line.startswith("Node 1:"):
            started = True
            continue
        if not started or line.startswith("====="):
            continue
        if line.startswith("\t"):
            d, h = "S", line.strip()
        elif line.strip():
            d, h = "C", line.strip()
        else:
            continue
        b = bytes.fromhex(h)
        if chunks and chunks[-1][0] == d:
            chunks[-1] = (d, chunks[-1][1] + b)
        else:
            chunks.append((d, b))
    return chunks


def frame(buf):
    """Split an SCE-RT byte stream into messages."""
    msgs, i = [], 0
    while i + 3 <= len(buf):
        mid = buf[i]
        ln = buf[i + 1] | (buf[i + 2] << 8)
        enc = bool(mid & 0x80) and ln > 0
        hdr = 7 if enc else 3
        if i + hdr + ln > len(buf):
            msgs.append({"id": mid & 0x7F, "enc": enc, "truncated": True,
                         "raw": buf[i:].hex()})
            break
        h = buf[i + 3:i + 7].hex() if enc else ""
        payload = buf[i + hdr:i + hdr + ln]
        msgs.append({"id": mid & 0x7F, "enc": enc, "hash": h, "payload": payload.hex()})
        i += hdr + ln
    return msgs


def main():
    pcap = sys.argv[1]
    ports = [int(p) for p in sys.argv[2:]] or [10071, 10075, 10077, 10078, 11001]
    OUT.mkdir(parents=True, exist_ok=True)
    for sid, port, t in tcp_streams(pcap, ports):
        seq = []
        cbuf, sbuf = b"", b""
        for d, b in follow_chunks(pcap, sid):
            for m in frame(b):
                m["dir"] = d
                seq.append(m)
        name = "%s-%04d-%d.json" % (Path(pcap).stem, sid, port)
        (OUT / name).write_text(json.dumps({"pcap": pcap, "stream": sid, "port": port,
                                            "t": t, "messages": seq}, indent=1))
        summary = " ".join("%s%02x%s/%d" % (m["dir"], m["id"], "*" if m.get("enc") else "",
                                            len(m.get("payload", "")) // 2) for m in seq)
        print("%-6d %-5d t=%7.2f  %s" % (sid, port, t, summary[:200]))


if __name__ == "__main__":
    main()
