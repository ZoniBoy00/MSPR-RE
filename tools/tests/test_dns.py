"""DNS observation tests with synthetic packets."""

from mspr_capture.analyze import Analyzer
from tests.synth import dns_answer_pkt, dns_query_pkt


def test_dns_query_and_answer_recorded():
    a = Analyzer()
    a.add_packet(dns_query_pkt("msr.psrewired.com"))
    a.add_packet(dns_answer_pkt("msr.psrewired.com", "203.0.113.10"))

    assert len(a.dns_queries) == 2
    q, ans = a.dns_queries
    assert q["query"] == "msr.psrewired.com"
    assert q["answers"] == []  # query has no answers
    assert ans["query"] == "msr.psrewired.com"
    assert "203.0.113.10" in ans["answers"]
    # IP -> name mapping built from answer
    assert a.ip_to_names["203.0.113.10"] == {"msr.psrewired.com"}


def test_dns_names_attached_to_flows():
    a = Analyzer()
    a.add_packet(dns_query_pkt("msr.psrewired.com"))
    a.add_packet(dns_answer_pkt("msr.psrewired.com", "203.0.113.10"))
    # Client connects to the resolved IP on a game port
    a.add_packet(
        _tcp_to("192.0.2.10", "203.0.113.10", 55123, 10071)
    )

    flows = [f for f in a.flows.values() if f["dst_ip"] == "203.0.113.10"]
    assert len(flows) == 1, "game connection must be one flow (DNS flows are separate)"
    f = flows[0]
    assert f["dst_ip"] == "203.0.113.10"
    assert f["dst_port"] == 10071
    assert f["dns_names"] == ["msr.psrewired.com"]


def _tcp_to(src, dst, sport, dport, ts=1000.5):
    from scapy.all import Ether, IP, TCP
    pkt = Ether() / IP(src=src, dst=dst) / TCP(sport=sport, dport=dport, flags="S")
    pkt.time = ts
    return pkt
