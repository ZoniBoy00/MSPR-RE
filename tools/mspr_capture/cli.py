"""CLI for mspr_capture - passive network observation for MSPR on RPCS3."""

from __future__ import annotations

import argparse
import json
import os
import sys
from datetime import datetime
from pathlib import Path

from .analyze import Analyzer
from .capture import CaptureSession, find_interface, list_interfaces
from .report import write_reports
from .tshark_enrich import find_tshark, extract_handshakes, export_http_objects
import threading
import time


def build_parser() -> argparse.ArgumentParser:
    p = argparse.ArgumentParser(
        prog="mspr_capture",
        description=(
            "Passive, local-only network observation for RPCS3/PS3 (PS Rewired) traffic. "
            "Captures only packets on the interface you select. Does not modify DNS, "
            "routing, firewall, proxies or game files, and uploads nothing."
        ),
    )
    p.add_argument("--list-interfaces", action="store_true", help="list capture-capable interfaces and exit")
    p.add_argument("--interface", "-i", help="interface name or description fragment (explicit selection required)")
    p.add_argument("--duration", "-d", type=float, default=600.0, help="capture duration in seconds (default 600)")
    p.add_argument("--output-dir", "-o", default="captures", help="directory for PCAPNG + JSON output (default ./captures)")
    p.add_argument("--max-mb", type=float, default=200.0, help="stop capture after this many MB (default 200)")
    p.add_argument(
        "--bpf-filter",
        default="ip and (tcp or udp)",
        help="BPF capture filter (default: 'ip and (tcp or udp)')",
    )
    p.add_argument("--label", default=None, help="optional label included in output filenames")
    p.add_argument(
        "--no-events",
        action="store_true",
        help="disable interactive event markers (type a line during capture to timestamp an action)",
    )
    p.add_argument(
        "--with-status",
        action="store_true",
        help="poll PS Rewired's public status API during capture and embed snapshots for correlation",
    )
    p.add_argument(
        "--status-interval",
        type=float,
        default=30.0,
        help="status API poll interval in seconds when --with-status (default 30)",
    )
    return p


def _status_listener(snapshots: list, interval: float, active: dict) -> None:
    """Background poller for the public status API (lightweight snapshots)."""
    from .status_api import poll_light

    while active.get("on"):
        try:
            snap = poll_light()
            snapshots.append(snap)
            print(
                f"[mspr_capture] status: rooms={snap['summary']['rooms']} "
                f"players_online={snap['summary']['players_online']}"
            )
        except Exception as e:
            print(f"[mspr_capture] status poll failed: {e}")
        # sleep in short steps so Ctrl-C / stop is responsive
        for _ in range(int(max(5.0, interval) * 10)):
            if not active.get("on"):
                break
            time.sleep(0.1)


def _event_listener(events: list, start_wall: float, active: dict) -> None:
    """Read stdin lines as user-timestamped event markers."""
    while active.get("on"):
        try:
            line = input()
        except EOFError:
            break
        text = line.strip()
        if text:
            events.append({"offset_s": round(time.time() - start_wall, 2), "marker": text[:120]})
            print(f"[mspr_capture] marker recorded at +{events[-1]['offset_s']}s: {text.strip()[:80]}")


def main(argv=None) -> int:
    args = build_parser().parse_args(argv)

    if args.list_interfaces:
        for it in list_interfaces():
            print(f"{it['index']:>3}  {it['name']}  |  {it['description']}")
        return 0

    if not args.interface:
        print("ERROR: an explicit interface is required. Use --list-interfaces, then --interface <name>.", file=sys.stderr)
        return 2

    iface = find_interface(args.interface)
    if iface is None:
        print(f"ERROR: no interface matching '{args.interface}'. Use --list-interfaces.", file=sys.stderr)
        return 2

    out_dir = Path(args.output_dir).resolve()
    out_dir.mkdir(parents=True, exist_ok=True)

    stamp = datetime.now().strftime("%Y%m%d-%H%M%S")
    label = f"-{args.label}" if args.label else ""
    pcapng_path = out_dir / f"mspr-{stamp}{label}.pcapng"
    json_path = out_dir / f"mspr-{stamp}{label}-summary.json"

    print(f"[mspr_capture] interface : {iface}")
    print(f"[mspr_capture] filter    : {args.bpf_filter}")
    print(f"[mspr_capture] duration  : {args.duration:.0f}s (Ctrl-C for clean stop)")
    print(f"[mspr_capture] output    : {pcapng_path}")
    print("[mspr_capture] passive capture running... launch the game and reproduce the flow now.")
    if not args.no_events:
        print("[mspr_capture] TIP: type a short label + Enter during capture to mark the moment (e.g. 'opened ranked').")

    events: list = []
    active = {"on": True}
    start_wall = time.time()
    if not args.no_events:
        threading.Thread(target=_event_listener, args=(events, start_wall, active), daemon=True).start()

    status_snapshots: list = []
    if args.with_status:
        threading.Thread(
            target=_status_listener, args=(status_snapshots, args.status_interval, active), daemon=True
        ).start()
        print(f"[mspr_capture] status API polling every {args.status_interval:.0f}s")

    # Live analysis: analyzer is fed inline during capture (no second pass).
    analyzer = Analyzer()
    session = CaptureSession(
        interface=iface,
        output_pcapng=str(pcapng_path),
        duration_s=args.duration,
        max_mb=args.max_mb,
        bpf_filter=args.bpf_filter,
        live_analyzer=analyzer,
    )
    reason = session.run()
    active["on"] = False
    print(f"[mspr_capture] capture stopped: {reason} ({session.packets_captured} packets, {session.bytes_captured} bytes)")

    if session.packets_captured == 0:
        print("[mspr_capture] No packets captured. Check the interface name and filter (e.g. game on another adapter/VPN?).")
        return 1

    summary = analyzer.summary(interface=iface, bpf_filter=args.bpf_filter, backend="npcap-scapy", events=events)
    summary["status_snapshots"] = status_snapshots
    if status_snapshots:
        summary["notes"].append(
            "status_snapshots come from PS Rewired's public status API (rooms/players), polled locally during the capture."
        )

    # Optional tshark enrichment (TLS/QUIC SNI+ALPN, HTTP object export)
    tshark = find_tshark()
    if tshark:
        try:
            print(f"[mspr_capture] enriching with tshark: {tshark}")
            summary["tls_quic_handshakes"] = extract_handshakes(tshark, str(pcapng_path))
            summary["http_objects"] = export_http_objects(tshark, str(pcapng_path), out_dir)
            print(f"[mspr_capture] handshakes: {len(summary['tls_quic_handshakes'])}, http objects: {len(summary['http_objects'])}")
        except Exception as e:
            print(f"[mspr_capture] tshark enrichment skipped: {e}")
            summary["tls_quic_handshakes"] = []
            summary["http_objects"] = []
    else:
        summary["tls_quic_handshakes"] = []
        summary["http_objects"] = []
        print("[mspr_capture] tshark not found - TLS/QUIC handshake and HTTP object enrichment skipped")

    write_reports(summary, json_path)

    print(f"[mspr_capture] sanitized JSON summary: {json_path}")
    print(f"[mspr_capture] DNS queries observed : {len(summary['dns_queries'])}")
    print(f"[mspr_capture] flows observed       : {len(summary['flows'])}")
    print(f"[mspr_capture] plaintext HTTP       : {len(summary['http_plaintext'])}")
    print(f"[mspr_capture] HTTP JSON bodies     : {len(summary['http_bodies'])}")
    print(f"[mspr_capture] connections (SYN)    : {sum(1 for c in summary['connections'] if 'SYN' in c.get('type',''))}")
    print(f"[mspr_capture] event markers        : {len(events)}")
    print(f"[mspr_capture] status snapshots     : {len(status_snapshots)}")
    print("[mspr_capture] Done. Files stay local; nothing was uploaded.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
