"""TCP reassembly + HTTP body extraction tests with synthetic data."""

from mspr_capture.analyze import Analyzer
from tests.synth import tcp_pkt

import json


def _http_stream_pkts(a: Analyzer, path=b"/motorstormpr/leaderboard/ranked", body=b'{"players":[{"name":"TestGuy","score":1234}]}'):
    # request (2 segments) and response (content-length)
    req = b"GET " + path + b"?row=0 HTTP/1.1\r\nHost: svo.psrewired.com\r\nX-SVOMac: deadbeefcafe1234\r\n\r\n"
    resp = (
        b"HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nContent-Length: "
        + str(len(body)).encode()
        + b"\r\n\r\n"
        + body
    )
    a.add_packet(tcp_pkt("192.0.2.10", "67.222.156.252", 5001, 80, req[:20], ts=1000.0))
    a.add_packet(tcp_pkt("192.0.2.10", "67.222.156.252", 5001, 80, req[20:], ts=1000.1))
    a.add_packet(tcp_pkt("67.222.156.252", "192.0.2.10", 80, 5001, resp, ts=1000.2))


def test_http_body_reassembled_from_segments():
    a = Analyzer()
    _http_stream_pkts(a)
    s = a.summary(interface="t", bpf_filter="t", backend="t")
    bodies = [b for b in s["http_bodies"] if b["flow"].startswith("192.0.2.10:5001")]
    assert len(bodies) == 1, "one JSON response body expected"
    parsed = json.loads(bodies[0]["body_redacted"])
    assert parsed["players"][0]["name"] == "TestGuy"
    assert bodies[0]["status"] == "200"


def test_sensitive_headers_redacted_in_bodies_and_transactions():
    a = Analyzer()
    _http_stream_pkts(a)
    s = a.summary(interface="t", bpf_filter="t", backend="t")
    tx = [t for t in s["http_plaintext"] if "X-SVOMac" in json.dumps(t)]
    if tx:
        assert "deadbeefcafe1234" not in json.dumps(tx), "X-SVOMac must be redacted"


def test_flow_classification():
    a = Analyzer()
    _http_stream_pkts(a)
    s = a.summary(interface="t", bpf_filter="t", backend="t")
    cls = {f["classified"] for f in s["flows"]}
    assert "http-plaintext" in cls


def test_connection_events_recorded():
    from tests.synth import tcp_pkt as tp

    a = Analyzer()
    a.add_packet(tp("192.0.2.10", "67.222.156.250", 5555, 10071, b"", ts=1000.0, flags="S"))
    a.add_packet(tp("67.222.156.250", "192.0.2.10", 10071, 5555, b"", ts=1000.1, flags="SA"))
    a.add_packet(tp("192.0.2.10", "67.222.156.250", 5555, 10071, b"", ts=1001.0, flags="FA"))
    s = a.summary(interface="t", bpf_filter="t", backend="t")
    types = [c["type"] for c in s["connections"]]
    assert any("SYN" in t for t in types)
    assert any("FIN" in t for t in types)
