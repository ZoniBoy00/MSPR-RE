"""TOC pair scan v2: include ld (op 58, DS-form) and count pairs.
Pure Python, fast with unpack. Static analysis only."""

import struct
import _paths as P

ELF = P.work("EBOOT.ghidra.elf")
OUT = P.work("toc_solution3.txt")

data = open(ELF, "rb").read()
e_phoff, = struct.unpack_from(">Q", data, 0x20)
e_phentsize, e_phnum = struct.unpack_from(">HH", data, 0x36)
segs = []
for i in range(e_phnum):
    o = e_phoff + i * e_phentsize
    t, f, off, va, pa, fsz, msz, al = struct.unpack_from(">IIQQQQQQ", data, o)
    if t == 1 and fsz > 0:
        segs.append((va, f, data[off:off + fsz]))

text = next(c for va, f, c in segs if f & 1)
text_va = next(va for va, f, c in segs if f & 1)
n = len(text) // 4
words = struct.unpack_from(">%dI" % n, text, 0)


def find_str_addrs(s: str):
    pat = s.encode()
    out = []
    for va, _f, c in segs:
        p = 0
        while True:
            i = c.find(pat, p)
            if i == -1:
                break
            out.append(va + i)
            p = i + 1
    return out


# collect addis rX, r2/r13, hi -> list of (addr, rD, hi)
addis = []
for i in range(n - 1):
    w = words[i]
    if (w >> 26) != 15:
        continue
    ra = (w >> 16) & 0x1F
    if ra not in (2, 13):
        continue
    addis.append((text_va + i * 4, (w >> 21) & 0x1F, w & 0xFFFF))
print("addis r2/r13 total: %d" % len(addis))

# for each string, brute force toc: count strings resolvable
STRINGS = [
    "Logging into Medius Server with NP Ticket",
    "MediusGetPlayerInfo() failed",
    "GotMatchMakingTicket",
    "ROOM_IN_MATCHMAKE",
    "CustomGameCreated",
    "FillRankedLeaderboardTable",
]

# index addis by hi for speed
from collections import defaultdict
by_hi = defaultdict(list)
for addr, rd, hi in addis:
    by_hi[hi].append((addr, rd))

best = (0, None, None)
for toc in range(0x1000000, 0x1100000, 0x1000):
    resolved = 0
    for s in STRINGS:
        for sa in find_str_addrs(s)[:1]:
            delta = sa - toc
            if not (-0x80000000 <= delta <= 0x7FFFFFFF):
                continue
            hi = ((delta + 0x8000) >> 16) & 0xFFFF
            lo = (delta - (hi << 16)) & 0xFFFF
            hit = False
            for addr, rd in by_hi.get(hi, [])[:500]:
                nxt = struct.unpack(">I", text[(addr - text_va) + 4:(addr - text_va) + 8])[0]
                op = nxt >> 26
                nra = (nxt >> 16) & 0x1F
                if op == 58:  # ld, DS-form: bits 15:2
                    if nra == rd and ((nxt & 0xFFFC) == (lo & 0xFFFC)):
                        hit = True
                        break
                if nra == rd and (nxt & 0xFFFF) == lo and op in (32, 14, 36, 12):
                    hit = True
                    break
            if hit:
                resolved += 1
                break
    if resolved > best[0]:
        best = (resolved, toc, None)
        print("toc=%#x resolves %d/%d strings" % (toc, resolved, len(STRINGS)))
    if resolved == len(STRINGS):
        break

print("BEST:", best[0], hex(best[1]) if best[1] else None)
open(OUT, "w").write("resolved=%d toc=%s\n" % (best[0], hex(best[1]) if best[1] else None))
