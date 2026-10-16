"""Shared synthetic packet builders for tests (no real traffic needed)."""

from __future__ import annotations

from scapy.all import (
    DNS,
    DNSQR,
    DNSRR,
    Ether,
    IP,
    Raw,
    TCP,
    UDP,
    conf,
)


def dns_query_pkt(name: str, ts: float = 1000.0):
    pkt = (
        Ether()
        / IP(src="192.0.2.10", dst="192.0.2.1")
        / UDP(sport=53000, dport=53)
        / DNS(rd=1, qd=DNSQR(qname=name, qtype="A"))
    )
    pkt.time = ts
    return pkt


def dns_answer_pkt(name: str, ip: str, ts: float = 1000.1):
    pkt = (
        Ether()
        / IP(src="192.0.2.1", dst="192.0.2.10")
        / UDP(sport=53, dport=53000)
        / DNS(
            qr=1,
            qd=DNSQR(qname=name, qtype="A"),
            an=DNSRR(rrname=name, ttl=60, rdata=ip),
        )
    )
    pkt.time = ts
    return pkt


def tcp_pkt(src, dst, sport, dport, payload: bytes = b"", ts: float = 1000.0, flags="PA"):
    pkt = (
        Ether()
        / IP(src=src, dst=dst)
        / TCP(sport=sport, dport=dport, flags=flags)
        / Raw(payload)
    )
    pkt.time = ts
    return pkt


def udp_pkt(src, dst, sport, dport, payload: bytes = b"", ts: float = 1000.0):
    pkt = Ether() / IP(src=src, dst=dst) / UDP(sport=sport, dport=dport) / Raw(payload)
    pkt.time = ts
    return pkt
