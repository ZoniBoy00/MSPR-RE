"""Inspect QUIC/UDP-443 traffic to api.psrewired.com in the ranked capture."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from scapy.all import PcapReader, IP, UDP
import _paths as P

API = {"172.67.168.92", "104.21.62.140"}
path = P.PCAP

sizes = []
initial = 0
first_bytes = None
ports = set()

with PcapReader(path) as pr:
    for pkt in pr:
        ip = pkt.getlayer(IP)
        if ip is None:
            continue
        udp = pkt.getlayer(UDP)
        if udp is None:
            continue
        if ip.src in API or ip.dst in API:
            if int(udp.dport) == 443 or int(udp.sport) == 443:
                payload = bytes(udp.payload)
                sizes.append(len(payload))
                ports.add(int(udp.sport))
                # QUIC long header: 0b11xxxxxx, first byte top bits = 11
                if payload and (payload[0] & 0x80) and (payload[0] & 0x40) and (payload[0] & 0x20):
                    initial += 1
                    if first_bytes is None:
                        first_bytes = payload[:64]

print("udp-443 packets to/from api.psrewired.com:", len(sizes))
print("client source ports:", sorted(ports)[:10])
print("payload size min/avg/max:", min(sizes), sum(sizes)//len(sizes), max(sizes))
print("QUIC Initial (long-header) packets:", initial)
if first_bytes:
    print("first packet hex head:", first_bytes.hex())
