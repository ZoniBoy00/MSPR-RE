"""Offline decoder for Medius (SCE-RT) TCP streams in a PCAP/PCAPNG capture.

What can and cannot be read:
  * The key exchange is RSA, then every message is encrypted with a session key. A passive capture holds the
    session key only under the client's RSA key, so the session keys must come from somewhere else: a key log
    written by `mspr_proxy --keylog`, or by your own server. Without keys the frames are listed but stay opaque.
  * With keys, every sealed frame is tried against each candidate key; a frame counts as decrypted only when its
    4-byte hash matches the plaintext, so a wrong key never produces output that looks right.
  * The game's RSA public key (CLIENT_CRYPTKEY_PUBLIC) is readable without any key, because it is sent under the
    SCERT default key.

Key log format: one JSON object per line with `k_down` and/or `k_up` (64-byte session keys as hex); a plain text
file with one hex key per line also works.

Usage:
    python -m mspr_capture.medius_decode capture.pcapng [--keys keys.jsonl] [--ports 10071,10073,10075,10078,10079]
        [--json out.jsonl]
"""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "scert"))
from rt import RCQ, RT_NAMES, SERVER_RSA, medius_label, split_frames  # noqa: E402

DEFAULT_PORTS = (10071, 10073, 10075, 10077, 10078, 10079)


def load_keys(path):
    keys = []
    for line in Path(path).read_text(encoding="utf-8").splitlines():
        line = line.strip()
        if not line:
            continue
        if line.startswith("{"):
            rec = json.loads(line)
            keys += [bytes.fromhex(rec[k]) for k in ("k_down", "k_up", "key") if rec.get(k)]
        else:
            keys.append(bytes.fromhex(line))
    return keys


def reassemble(pcap, ports):
    """Returns {(client_ip, client_port, server_ip, server_port): {"C": bytes, "S": bytes}} in stream order."""
    from scapy.all import IP, TCP, PcapNgReader, PcapReader  # imported late: only needed here

    Reader = PcapNgReader if str(pcap).lower().endswith(".pcapng") else PcapReader
    segs = {}
    with Reader(str(pcap)) as rd:
        for pkt in rd:
            if IP not in pkt or TCP not in pkt:
                continue
            t = pkt[TCP]
            payload = bytes(t.payload)
            if not payload:
                continue
            if t.dport in ports:
                key, side = (pkt[IP].src, t.sport, pkt[IP].dst, t.dport), "C"
            elif t.sport in ports:
                key, side = (pkt[IP].dst, t.dport, pkt[IP].src, t.sport), "S"
            else:
                continue
            segs.setdefault((key, side), {}).setdefault(t.seq, payload)
    streams = {}
    for (key, side), by_seq in segs.items():
        buf, nxt = b"", None
        for seq in sorted(by_seq):
            data = by_seq[seq]
            if nxt is None:
                nxt = seq
            if seq + len(data) <= nxt:
                continue                                    # retransmission
            buf += data[nxt - seq:] if seq < nxt else data
            nxt = seq + len(data)
        streams.setdefault(key, {})[side] = buf
    return streams


def decode_stream(buf, keys, side):
    """Yields dicts for each frame of one direction."""
    frames, rest = split_frames(buf)
    for i, f in enumerate(frames):
        rec = {"i": i, "dir": "C->S" if side == "C" else "S->C", "id": f.mid, "name": RT_NAMES.get(f.mid, "?"),
               "len": len(f.body), "sealed": f.sealed, "ctx": f.ctx}
        if not f.sealed:
            rec["payload"] = f.body.hex()
        elif f.ctx == 7:
            if side == "C":
                body, ok = SERVER_RSA.decrypt(f.body, f.hash)
                rec.update(ok=ok, payload=body.hex() if ok else None, note="game RSA public key" if ok else None)
            else:
                rec["note"] = "session key under the client's RSA key (needs the client's private key)"
        else:
            for k in keys:
                plain, ok = RCQ(k, f.ctx).decrypt(f.body, f.hash)
                if ok:
                    rec.update(ok=True, payload=plain.hex(), key=k[:4].hex())
                    break
            else:
                rec["ok"] = False
        if rec.get("payload") and f.mid in (0x0a, 0x0b):
            rec["medius"] = medius_label(bytes.fromhex(rec["payload"]))
        yield rec
    if rest:
        yield {"i": len(frames), "dir": "C->S" if side == "C" else "S->C", "note": "%d trailing bytes (incomplete frame)" % len(rest)}


def main():
    ap = argparse.ArgumentParser(description="Decode Medius TCP streams in a capture")
    ap.add_argument("pcap")
    ap.add_argument("--keys", help="key log (JSONL from mspr_proxy --keylog, or hex per line)")
    ap.add_argument("--ports", default=",".join(map(str, DEFAULT_PORTS)))
    ap.add_argument("--json", help="write every frame as JSONL here")
    a = ap.parse_args()
    keys = load_keys(a.keys) if a.keys else []
    ports = {int(p) for p in a.ports.split(",")}
    streams = reassemble(a.pcap, ports)
    out = open(a.json, "w", encoding="utf-8") if a.json else None
    total = opened = sealed = 0
    for key, sides in sorted(streams.items()):
        print("== %s:%d -> %s:%d" % key)
        for side in ("C", "S"):
            for rec in decode_stream(sides.get(side, b""), keys, side):
                rec["conn"] = "%s:%d-%s:%d" % key
                total += 1
                sealed += bool(rec.get("sealed"))
                opened += bool(rec.get("ok") and rec.get("payload"))
                if out:
                    out.write(json.dumps(rec) + "\n")
                tag = "" if not rec.get("sealed") else (" [decrypted]" if rec.get("ok") else " [opaque]")
                print("  %s 0x%02x %-28s %5d B%s %s%s" % (rec["dir"], rec.get("id", 0), rec.get("name", ""), rec.get("len", 0),
                                                         tag, rec.get("medius") or "", (" " + rec["note"]) if rec.get("note") else ""))
    print("\n%d frames, %d sealed, %d readable" % (total, sealed, opened))


if __name__ == "__main__":
    main()
