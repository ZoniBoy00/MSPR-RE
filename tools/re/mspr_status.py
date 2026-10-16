"""mspr_status - poll PS Rewired's public status API for MSPR (app 21624).

Complements the passive network capture with the server's own public data:
lobbies, players, and the per-player stats blobs the server itself exposes.

Public endpoints (no API key required, verified 2026-10):
  GET {base}/rooms?applicationId=21624
  GET {base}/rooms/{roomId}          -> sub-lobbies incl. players + stats blobs
  GET {base}/universes?applicationId=21624
  GET {base}/universes/players?applicationId=21624

Be polite: default interval is 20 s (same as the community status bots).
Everything is stored locally as JSONL. Nothing is uploaded.
"""

from __future__ import annotations

import argparse
import base64
import json
import re
import struct
import time
import urllib.request
from datetime import datetime, timezone
from pathlib import Path

APP_ID = 21624
BASE_URL = "https://api.psrewired.com/us/api"
USER_AGENT = "mspr_status/0.1 (local monitoring)"
ASCII_KEY_RE = re.compile(rb"[a-zA-Z0-9_.\-]{4,}")


def fetch_json(url: str, timeout: int = 20):
    req = urllib.request.Request(url, headers={"User-Agent": USER_AGENT})
    with urllib.request.urlopen(req, timeout=timeout) as resp:
        return json.loads(resp.read().decode("utf-8", errors="replace"))


def decode_stats_blob(b64: str) -> dict:
    """Best-effort structural decode of the server's 256-byte stats blob.

    This is data the server publishes on a public endpoint - no crypto is
    broken here. Layout is not officially documented, so only the clearly
    observable parts are reported: embedded ASCII keys and big-endian u32
    counters. Anything else stays as raw hex.
    """
    out: dict = {"raw_hex": "", "ascii_keys": [], "u32_be_leading": []}
    if not b64:
        return out
    try:
        blob = base64.b64decode(b64)
    except Exception:
        return out
    out["raw_hex"] = blob.hex()
    out["size_bytes"] = len(blob)
    out["ascii_keys"] = sorted({m.decode() for m in ASCII_KEY_RE.findall(blob)})
    n = len(blob) // 4
    if n:
        words = struct.unpack(">%dI" % n, blob[: n * 4])
        # keep the small, counter-plausible values; large values are likely
        # packed fields/addresses and are covered by raw_hex anyway
        out["u32_be_leading"] = [w for w in words[:16] if 0 < w < 100_000]
    return out


def poll_once() -> dict:
    ts = datetime.now(tz=timezone.utc).isoformat()
    rooms = fetch_json(f"{BASE_URL}/rooms?applicationId={APP_ID}") or []
    players = fetch_json(f"{BASE_URL}/universes/players?applicationId={APP_ID}") or []
    universes = fetch_json(f"{BASE_URL}/universes?applicationId={APP_ID}") or []

    room_details = []
    for room in rooms:
        rid = room.get("id")
        try:
            detail = fetch_json(f"{BASE_URL}/rooms/{rid}")
        except Exception:
            detail = []
        sublobbies = []
        for sub in detail if isinstance(detail, list) else []:
            pls = []
            for p in sub.get("players", []) or []:
                pls.append(
                    {
                        "name": p.get("name"),
                        "lastPing": p.get("lastPing"),
                        "stats": decode_stats_blob(p.get("stats", "")),
                    }
                )
            sublobbies.append(
                {
                    "name": sub.get("name"),
                    "playerCount": sub.get("playerCount"),
                    "maxPlayers": sub.get("maxPlayers"),
                    "players": pls,
                }
            )
        room_details.append(
            {
                "roomId": rid,
                "name": room.get("name"),
                "playerCount": room.get("playerCount"),
                "allowedRanks": room.get("allowedRanks"),
                "sublobbies": sublobbies,
            }
        )

    return {
        "timestamp": ts,
        "universes": universes,
        "online_players": [
            {
                "name": p.get("name"),
                "onlineSince": p.get("onlineSince"),
                "lastPing": p.get("lastPing"),
                "accountType": p.get("pS3AccountType"),
            }
            for p in players
        ],
        "rooms": room_details,
        "summary": {
            "rooms": len(rooms),
            "players_online": len(players),
        },
    }


def main() -> int:
    ap = argparse.ArgumentParser(prog="mspr_status", description="Poll PS Rewired public status API for MSPR (local logging only).")
    ap.add_argument("--out-dir", default=str(__import__("pathlib").Path(__file__).resolve().parent.parent / "captures" / "status_log"), help="JSONL output directory")
    ap.add_argument("--interval", type=float, default=20.0, help="poll interval seconds (default 20, be gentle)")
    ap.add_argument("--once", action="store_true", help="poll once and print, no log file")
    ap.add_argument("--count", type=int, default=0, help="stop after N polls (0 = until Ctrl-C)")
    args = ap.parse_args()

    out_dir = Path(args.out_dir)
    n = 0
    while True:
        try:
            data = poll_once()
        except Exception as e:
            print(f"[mspr_status] poll failed: {e}")
            data = {"timestamp": datetime.now(tz=timezone.utc).isoformat(), "error": str(e)}

        s = data.get("summary", {})
        print(
            f"[{data['timestamp'][:19]}] rooms={s.get('rooms', '?')} "
            f"players_online={s.get('players_online', '?')}"
        )

        if args.once:
            print(json.dumps(data, indent=2, ensure_ascii=False)[:4000])
            return 0

        out_dir.mkdir(parents=True, exist_ok=True)
        log = out_dir / f"mspr-status-{datetime.now():%Y%m%d}.jsonl"
        with open(log, "a", encoding="utf-8") as f:
            f.write(json.dumps(data, ensure_ascii=False) + "\n")

        n += 1
        if args.count and n >= args.count:
            print(f"[mspr_status] {n} polls done, log: {log}")
            return 0
        time.sleep(args.interval)


if __name__ == "__main__":
    raise SystemExit(main())
