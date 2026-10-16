"""PS Rewired public status API client (no key needed for these endpoints).

Endpoints verified public 2026-10 (see also community bots:
github.com/ZoniBoy00/MotorStorm-Status-Bots):
  GET {base}/rooms?applicationId={id}
  GET {base}/rooms/{roomId}
  GET {base}/universes?applicationId={id}
  GET {base}/universes/players?applicationId={id}
  GET {base}/stats?applicationId={id}

Use politely - community bots poll every 20 s.
"""

from __future__ import annotations

import json
import urllib.request
from datetime import datetime, timezone

APP_ID = 21624
BASE_URL = "https://api.psrewired.com/us/api"
USER_AGENT = "mspr_capture-status/0.1 (local monitoring)"


def fetch_json(url: str, timeout: int = 15):
    req = urllib.request.Request(url, headers={"User-Agent": USER_AGENT})
    with urllib.request.urlopen(req, timeout=timeout) as resp:
        return json.loads(resp.read().decode("utf-8", errors="replace"))


def poll_light() -> dict:
    """Lightweight snapshot: rooms, online players, server summary.

    Per-room player detail (with stats blobs) is intentionally skipped here
    to keep capture-time polling cheap; use tools/mspr_status.py for deep
    polling with stats-blob decoding.
    """
    ts = datetime.now(tz=timezone.utc).isoformat()
    rooms = fetch_json(f"{BASE_URL}/rooms?applicationId={APP_ID}") or []
    players = fetch_json(f"{BASE_URL}/universes/players?applicationId={APP_ID}") or []
    universes = fetch_json(f"{BASE_URL}/universes?applicationId={APP_ID}") or []
    try:
        stats = fetch_json(f"{BASE_URL}/stats?applicationId={APP_ID}")
    except Exception:
        stats = None

    return {
        "timestamp": ts,
        "universes": [
            {"name": u.get("name"), "status": u.get("status"), "playerCount": u.get("playerCount")}
            for u in universes
        ],
        "rooms": [
            {"roomId": r.get("id"), "name": r.get("name"), "playerCount": r.get("playerCount"), "allowedRanks": r.get("allowedRanks")}
            for r in rooms
        ],
        "online_players": [
            {"name": p.get("name"), "onlineSince": p.get("onlineSince"), "accountType": p.get("pS3AccountType")}
            for p in players
        ],
        "global_stats": stats,
        "summary": {"rooms": len(rooms), "players_online": len(players)},
    }
