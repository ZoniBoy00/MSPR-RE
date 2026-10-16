"""Static strings scanner for PS3 binaries (works on ELF and SELF).

Extracts printable ASCII runs and filters for network/protocol-relevant
content. Purely static analysis of a local file.
"""

import re
import sys
from collections import Counter
from pathlib import Path
import _paths as P

MIN_LEN = 6


def extract_strings(data: bytes, min_len: int = MIN_LEN):
    return re.findall(rb"[\x20-\x7e]{%d,}" % min_len, data)


def main():
    path = Path(sys.argv[1]) if len(sys.argv) > 1 else Path(P.work("EBOOT.BIN"))
    data = path.read_bytes()
    print(f"file: {path}  size: {len(data):,} bytes")

    strings = extract_strings(data)
    print(f"ascii strings >= {MIN_LEN}: {len(strings):,}")

    interesting = re.compile(
        rb"(motorstormpr|psrewired|scee|svo|scert|leaderboard|finishgame|"
        rb"https?:|/motorstorm|\.online\.|accountid|onlineid|np\.|rpcn|"
        rb"ticket|eula|region|announce|game/finish|10060|10071|10077|11001)",
        re.IGNORECASE,
    )

    hits = [s for s in strings if interesting.search(s)]
    print(f"protocol-relevant hits: {len(hits):,}\n")
    for s in hits[:200]:
        print(s.decode(errors="replace")[:160])

    print("\n--- most common strings (sanity) ---")
    for s, c in Counter(strings).most_common(15):
        print(f"{c:>5}  {s[:80].decode(errors='replace')}")


if __name__ == "__main__":
    main()
