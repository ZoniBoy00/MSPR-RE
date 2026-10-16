"""Extract ALL ranked/casual/game-mode related strings with addresses
from the decrypted MSPR EBOOT — the game's own naming for its online
modes. Static analysis only."""

import struct
import re
import _paths as P

ELF = P.work("EBOOT.ghidra.elf")
OUT = P.work("ranked_casual_strings.txt")

data = open(ELF, "rb").read()
e_shoff, = struct.unpack_from(">Q", data, 0x28)
e_shentsize, e_shnum, e_shstrndx = struct.unpack_from(">HHH", data, 0x3A)
secs = []
for i in range(e_shnum):
    o = e_shoff + i * e_shentsize
    name, typ, flags, addr, off, size, link, info, align, entsize = struct.unpack_from(">IIQQQQIIQQ", data, o)
    if typ in (0, 8) or size == 0:
        continue
    secs.append((i, addr, off, size))

PAT = re.compile(
    r"(ranked|casual|Ranked|Casual|RANKED|CASUAL|GAMETYPE|GameType|gameMode|"
    r"ROOM_IN|CustomGame|custom game|Custom game|MatchMaking|matchmaking|"
    r"MatchMaking|lobby world|LobbyWorld|GameWorld|game world)",
)

out = []
for i, addr, off, size in secs:
    if typ != 1:  # PROGBITS only
        continue
    region = data[off:off + size]
    for m in re.finditer(rb"[\x20-\x7e]{6,240}", region):
        s = m.group().decode(errors="replace")
        if PAT.search(s):
            out.append((addr + m.start(), s))

with open(OUT, "w", encoding="utf-8") as f:
    for a, s in out:
        f.write("%#x  %s\n" % (a, s))
print("matches: %d -> %s" % (len(out), OUT))
