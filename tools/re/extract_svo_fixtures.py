"""Extract every SVO (TCP 10060) HTTP request/response pair from PS Rewired
captures into server/test/fixtures/svo/*.json, so the local SVO server can mirror
the real responses exactly.

Usage: python -X utf8 tools\\re\\extract_svo_fixtures.py research\\captures\\*.pcapng
"""

import json
import re
import subprocess
import sys
from pathlib import Path

TSHARK = r"C:\Program Files\Wireshark\tshark.exe"
OUT = Path(__file__).resolve().parents[2] / "server" / "test" / "fixtures" / "svo"


def streams(pcap):
    out = subprocess.run(
        [TSHARK, "-r", pcap, "-Y", "tcp.port==10060 && tcp.flags.syn==1 && tcp.flags.ack==0",
         "-T", "fields", "-e", "tcp.stream"],
        capture_output=True, text=True).stdout
    return sorted({int(x) for x in out.split()})


def follow(pcap, sid):
    out = subprocess.run(
        [TSHARK, "-r", pcap, "-q", "-z", "follow,tcp,raw,%d" % sid],
        capture_output=True, text=True).stdout
    client, server = b"", b""
    started = False
    for line in out.splitlines():
        if line.startswith("Node 1:"):
            started = True
            continue
        if not started or line.startswith("====="):
            continue
        if line.startswith("\t"):
            server += bytes.fromhex(line.strip())
        elif line.strip():
            client += bytes.fromhex(line.strip())
    return client, server


def split_http(blob):
    head, _, body = blob.partition(b"\r\n\r\n")
    lines = head.decode("latin-1").split("\r\n")
    headers = {}
    for l in lines[1:]:
        if ":" in l:
            k, v = l.split(":", 1)
            headers[k.strip()] = v.strip()
    return lines[0], headers, body


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    seen = {}
    for pcap in sys.argv[1:]:
        for sid in streams(pcap):
            c, s = follow(pcap, sid)
            if not c or not s:
                continue
            reqline, reqh, reqbody = split_http(c)
            respline, resph, respbody = split_http(s)
            parts = reqline.split(" ")
            if len(parts) < 2:
                continue
            method, uri = parts[0], parts[1]
            route = uri.split("?")[0]
            key = method + " " + route
            rec = {
                "method": method, "uri": uri, "request_headers": reqh,
                "request_body": reqbody.decode("latin-1"),
                "status_line": respline, "response_headers": resph,
                "response_body": respbody.decode("latin-1"),
            }
            seen.setdefault(key, []).append(rec)
    for key, recs in seen.items():
        name = re.sub(r"[^A-Za-z0-9]+", "_", key).strip("_")
        (OUT / (name + ".json")).write_text(json.dumps(recs, indent=1), encoding="utf-8")
        print("%-60s %d samples" % (key, len(recs)))


if __name__ == "__main__":
    main()
