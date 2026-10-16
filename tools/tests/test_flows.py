"""Flow summary tests with synthetic packets."""

from mspr_capture.analyze import Analyzer
from tests.synth import tcp_pkt, udp_pkt


def test_bidirectional_tcp_merges_into_one_flow():
    a = Analyzer()
    a.add_packet(tcp_pkt("192.0.2.10", "203.0.113.10", 55123, 10071, b"\x00", ts=1000.0, flags="S"))
    a.add_packet(tcp_pkt("203.0.113.10", "192.0.2.10", 10071, 55123, b"\x00", ts=1000.1, flags="SA"))

    flows = list(a.flows.values())
    assert len(flows) == 1, "both directions must merge into one flow"
    f = flows[0]
    assert f["packets"] == 2
    assert f["protocol"] == "tcp"
    assert {f["src_ip"], f["dst_ip"]} == {"192.0.2.10", "203.0.113.10"}
    assert f["first_seen"] <= f["last_seen"]


def test_udp_flow_counts_bytes_and_packets():
    a = Analyzer()
    for i in range(5):
        a.add_packet(udp_pkt("192.0.2.10", "203.0.113.20", 60000, 3074, b"x" * 100, ts=1000.0 + i))
    flows = list(a.flows.values())
    assert len(flows) == 1
    assert flows[0]["packets"] == 5
    assert flows[0]["bytes"] >= 500  # payload bytes at minimum
    assert flows[0]["protocol"] == "udp"


def test_packet_counters_and_time_window():
    a = Analyzer()
    a.add_packet(tcp_pkt("192.0.2.10", "203.0.113.10", 55123, 443, b"\x16\x03", ts=1000.0))
    a.add_packet(tcp_pkt("192.0.2.10", "203.0.113.10", 55123, 443, b"\x17\x03", ts=1010.0))

    s = a.summary(interface="Ethernet", bpf_filter="test", backend="test")
    assert s["observed"]["packet_count"] == 2
    assert s["observed"]["first_timestamp"].startswith("1970-01-01T00:16:40")
    assert s["observed"]["last_timestamp"].startswith("1970-01-01T00:16:50")
