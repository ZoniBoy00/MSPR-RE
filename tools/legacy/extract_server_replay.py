"""Extract per-port server->client payload sequences from the PS Rewired
capture into a JSON replay file for the Medius stub."""

import struct
import json
from collections import defaultdict
from scapy.all import PcapReader, TCP, IP
import _paths as P

PCAP = P.PCAP
OUT = P.work("medius_server_replay.json")
PORTS = {10071, 10075, 10077, 11001}

streams = defaultdict(list)
with PcapReader(PCAP) as pr:
    for pkt in pr:
        ip = pkt.getlayer(IP)
        tcp = pkt.getlayer(TCP)
        if ip is None or tcp is None:
            continue
        if int(tcp.sport) not in PORTS:
            continue
        payload = bytes(tcp.payload)
        if not payload:
            continue
        key = int(tcp.sport)
        streams[key].append((int(tcp.seq), payload))

# pick the stream with the most data per port, order by seq
replay = {}
for port, pkts in streams.items():
    # choose stream with max total bytes
    # group by seq continuity: just take all, sort by seq, dedupe
    pkts.sort(key=lambda x: x[0])
    seen_seq = set()
    payloads = []
    for seq, pl in pkts:
        if seq in seen_seq:
            continue
        seen_seq.add(seq)
        payloads.append(pl.hex())
    replay[str(port)] = payloads
    print("port %d: %d payloads, %d bytes total" % (port, len(payloads), sum(len(p) // 2 for p in payloads)))

with open(OUT, "w") as f:
    json.dump(replay, f)
print("written", OUT)
