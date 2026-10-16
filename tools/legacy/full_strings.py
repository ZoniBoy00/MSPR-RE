"""Organize ALL protocol-relevant strings from the decrypted MSPR EBOOT
into a categorized documentation file. Static analysis only."""

import re
from collections import defaultdict
import _paths as P

ELF = P.work("EBOOT.ELF")
OUT = P.work("FULL_STRINGS.md")

data = open(ELF, "rb").read()
strings = re.findall(rb"[\x20-\x7e]{6,}", data)
strings = [s.decode(errors="replace") for s in strings]

CATEGORIES = {
    "SVO / HTTP actions": r"(svo|SVBrowser|TicketLogin|ticketLogin|getRegion|getEula|acceptEula|getAnnouncement|finishGame|index\?|languageID|country=|languageCode)",
    "Medius / lobby": r"(medius|Medius|lobby|Lobby|room|Room|MatchMak|matchmak|GAME_WORLD|LOBBY_WORLD)",
    "Leaderboard": r"(leaderboard|Leaderboard|LeaderBoard|ghost|Ghost|bestTime|bestMedal|rank|Rank)",
    "Game modes / tickets": r"(Ticket|GAMETYPE|Ranked|Casual|Custom|Eliminator|Speed|Aggression|Skill|Festival)",
    "Race stats fields": r"(totalRaceTime|bestTime|boostDistance|distanceTravelled|jumpDistance|furthest|wrecks|jumps|laps|placed|position|endState|endNormal|gameId|gameName|gameMode|vehicle|track|playerBeaten|stat\.)",
    "Login / auth": r"(npsso|NP Ticket|ticket|login|Login|account|Account|onlineId|onlineID|npId|auth)",
    "Network / ports / hosts": r"(10060|10071|10075|10077|11001|31313|scee|psrewired|online\.scee|\.online\.|udp|UDP|TCP|socket)",
    "Voice / chat / P2P": r"(voice|Voice|chat|Chat|P2P|p2p|NAT|nat|UPnP|upnp)",
    "Errors / statuses": r"(SCERT_|MEDIUS_|_FAILED|_FAILED|status.*id|errorCode|Error)",
    "File paths / sources": r"(source/|\.cpp|\.h:|ms2|/online/|/svo/)",
}

seen = {k: set() for k in CATEGORIES}
uncat = set()
for s in strings:
    placed = False
    for cat, pat in CATEGORIES.items():
        if re.search(pat, s):
            if s not in seen[cat]:
                seen[cat].add(s)
            placed = True
            break
    if not placed and ("online" in s.lower() or "evo" in s.lower()):
        uncat.add(s)

with open(OUT, "w", encoding="utf-8") as f:
    f.write("# MSPR EBOOT — categorized protocol strings (static analysis)\n\n")
    for cat in CATEGORIES:
        f.write("## %s (%d)\n\n" % (cat, len(seen[cat])))
        for s in sorted(seen[cat]):
            f.write("- `%s`\n" % s.replace("`", "'"))
        f.write("\n")
    f.write("## Other online/evo-related (%d)\n\n" % len(uncat))
    for s in sorted(uncat)[:800]:
        f.write("- `%s`\n" % s.replace("`", "'"))

total = sum(len(v) for v in seen.values()) + len(uncat)
print("categorized strings written:", total, "->", OUT)
for cat in CATEGORIES:
    print("  %-28s %d" % (cat, len(seen[cat])))
