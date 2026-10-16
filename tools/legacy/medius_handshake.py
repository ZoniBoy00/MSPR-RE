"""Extract the first server->client payloads on Medius ports (10071/10075/10077)
and DME (11001) from the PS Rewired capture — to learn what the server sends
first, so our stub can replay it and capture the client's responses."""

import struct
from collections import defaultdict
from scapy.all import PcapReader, TCP, IP
import _paths as P

PCAP = P.PCAP
PORTS = {10071, 10075, 10077, 11001, 10060}

streams = defaultdict(list)  # (src,sport,dst,dport) -> [(seq, payload, ts)]

with PcapReader(PCAP) as pr:
    for pkt in pr:
        ip = pkt.getlayer(IP)
        tcp = pkt.getlayer(TCP)
        if ip is None or tcp is None:
            continue
        if int(tcp.dport) not in PORTS and int(tcp.sport) not in PORTS:
            continue
        payload = bytes(tcp.payload)
        if not payload:
            continue
        key = (ip.src, int(tcp.sport), ip.dst, int(tcp.dport))
        streams[key].append((int(tcp.seq), payload, float(pkt.time)))

print("streams found:")
for key, pkts in sorted(streams.items(), key=lambda x: -len(x[1])):
    src, sport, dst, dport = key
    total = sum(len(p) for _s, p, _t in pkts)
    print("  %s:%d -> %s:%d  pkts=%d bytes=%d" % (src, sport, dst, dport, len(pkts), total))

out_lines = []

# dump first server->client payload per port (server = the 67.222.156.x side)
print("\n=== first server->client payloads per port ===")
seen_ports = set()
for key, pkts in sorted(streams.items(), key=lambda x: x[0][3]):
    src, sport, dst, dport = key
    if dport in PORTS:  # server->client means destination port is the client's ephemeral? no:
        pass
    # server->client: src port is the server port
    if sport not in PORTS:
        continue
    if sport in seen_ports:
        continue
    seen_ports.add(sport)
    pkts.sort(key=lambda x: x[0])
    first = pkts[0][1]
    out_lines.append("--- port %d: first server payload (%d bytes) ---" % (sport, len(first)))
    for i in range(0, min(len(first), 96), 16):
        chunk = first[i:i + 16]
        out_lines.append("  %04x  %-47s  %s" % (i, " ".join("%02x" % b for b in chunk),
              "".join(chr(b) if 32 <= b < 127 else "." for b in chunk)))

# also dump first client->server payload per port
out_lines.append("=== first client->server payloads per port ===")
seen_ports = set()
for key, pkts in sorted(streams.items(), key=lambda x: x[0][3]):
    src, sport, dst, dport = key
    if dport not in PORTS or dport in seen_ports:
        continue
    seen_ports.add(dport)
    pkts.sort(key=lambda x: x[0])
    first = pkts[0][1]
    out_lines.append("--- port %d: first client payload (%d bytes) ---" % (dport, len(first)))
    for i in range(0, min(len(first), 96), 16):
        chunk = first[i:i + 16]
        out_lines.append("  %04x  %-47s  %s" % (i, " ".join("%02x" % b for b in chunk),
              "".join(chr(b) if 32 <= b < 127 else "." for b in chunk)))

open(P.work("medius_handshake.txt"), "w", encoding="utf-8").write("\n".join(out_lines))
print("written to re/medius_handshake.txt")
