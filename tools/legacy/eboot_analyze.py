"""Deeper static analysis of the decrypted MSPR EBOOT (PS3 ELF).

Extracts ASCII + UTF-16LE strings and groups protocol-relevant findings:
SVO/SCERT client identifiers, matchmaking/game-mode names, stats keys.
Purely static, local analysis for interoperability documentation.
"""

import re
import sys
from pathlib import Path
import _paths as P

OUT = Path(P.work("analysis_report.md"))


def ascii_strings(data: bytes, min_len=6):
    return re.findall(rb"[\x20-\x7e]{%d,}" % min_len, data)


def utf16_strings(data: bytes, min_len=6):
    out = []
    for m in re.finditer(rb"(?:[\x20-\x7e]\x00){%d,}" % min_len, data):
        out.append(m.group().decode("utf-16-le", errors="replace"))
    return out


KEYWORDS = [
    "scert", "svo", "motorstorm", "matchmak", "lobby", "ranked", "casual",
    "custom", "gameMode", "game_mode", "finishGame", "leaderboard", "ticket",
    "login", "ticket", "room", "player", "stats", "ghost", "region", "eula",
    "accountid", "onlineid", "klicensee", "10060", "10071", "10077", "11001",
    "https", "http", "scee", "psrewired", "21624",
]


def main():
    data = Path(P.work("EBOOT.ELF")).read_bytes()
    a = [s.decode(errors="replace") for s in ascii_strings(data)]
    u = utf16_strings(data)

    def relevant(s: str) -> bool:
        low = s.lower()
        return any(k in low for k in KEYWORDS)

    hits_a = sorted({s for s in a if relevant(s)})
    hits_u = sorted({s for s in u if relevant(s)})

    lines = ["# MSPR EBOOT.BIN static analysis", "", f"ASCII strings: {len(a):,}, UTF-16 strings: {len(u):,}", ""]
    lines += ["## Protocol-relevant ASCII strings", ""]
    lines += [f"- `{s[:200]}`" for s in hits_a]
    lines += ["", "## Protocol-relevant UTF-16 strings", ""]
    lines += [f"- `{s[:200]}`" for s in hits_u]

    OUT.write_text("\n".join(lines), encoding="utf-8")
    print(f"ascii hits: {len(hits_a)}  utf16 hits: {len(hits_u)}  ->  {OUT}")


if __name__ == "__main__":
    main()
