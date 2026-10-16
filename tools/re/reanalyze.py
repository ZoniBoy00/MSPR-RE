"""Regenerate the sanitized summary from an existing PCAPNG (offline)."""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from scapy.all import PcapReader
from mspr_capture.analyze import Analyzer
from mspr_capture.report import write_reports

pcapng = Path(sys.argv[1])
out = pcapng.with_name(pcapng.stem + "-summary-redacted.json")

a = Analyzer()
with PcapReader(str(pcapng)) as pr:
    for pkt in pr:
        a.add_packet(pkt)

s = a.summary(interface="Ethernet", bpf_filter="ip and (tcp or udp)", backend="offline-reanalyze", events=[])

# tshark enrichment (same as live capture)
from mspr_capture.tshark_enrich import find_tshark, extract_handshakes, export_http_objects

ts = find_tshark()
if ts:
    s["tls_quic_handshakes"] = extract_handshakes(ts, str(pcapng))
    s["http_objects"] = export_http_objects(ts, str(pcapng), pcapng.parent)
    print(f"tshark: {len(s['tls_quic_handshakes'])} handshakes, {len(s['http_objects'])} http objects")
else:
    s["tls_quic_handshakes"] = []
    s["http_objects"] = []
    print("tshark not found - enrichment skipped")
write_reports(s, out)
print("written:", out)
print("http:", len(s["http_plaintext"]), "flows:", len(s["flows"]), "dns:", len(s["dns_queries"]))
