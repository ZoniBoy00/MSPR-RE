"""Derive the PS3 TOC base and find log-string referencing instructions.

Pure math approach: scan the text segment for all 'addis rX, r13/r2, hi'
followed by 'lwz/addi rY, rX, lo' pairs; each pair implies a virtual
address delta = (hi<<16)+simm. For each known string S, the true TOC base
is S - delta for the pair referencing it. Intersecting candidate sets
across multiple strings pins down the TOC base uniquely.
"""

import struct
import _paths as P

ELF = P.work("EBOOT.ghidra.elf")
OUT = P.work("toc_solution.txt")

STRINGS = [
    "Logging into Medius Server with NP Ticket",
    "MediusAccountUpdateStats() failed",
    "MediusGetPlayerInfo() failed",
    "GotMatchMakingTicket",
    "ROOM_IN_MATCHMAKE",
    "ROOM_IN_CASUAL_STANDARD",
    "CustomGameCreated",
    "DownloadGhostFromLeaderBoard",
    "FillRankedLeaderboardTable",
    "SVBrowser::TicketLogin",
]

data = open(ELF, "rb").read()
e_phoff, = struct.unpack_from(">Q", data, 0x20)
e_phentsize, e_phnum = struct.unpack_from(">HH", data, 0x36)
segs = []
for i in range(e_phnum):
    o = e_phoff + i * e_phentsize
    t, f, off, va, pa, fsz, msz, al = struct.unpack_from(">IIQQQQQQ", data, o)
    if t == 1 and fsz > 0:
        segs.append((va, f, data[off:off + fsz]))

text = next(c for va, f, c in segs if f & 1)  # executable segment
text_va = next(va for va, f, c in segs if f & 1)
print("text: va=%#x size=%#x" % (text_va, len(text)))

n = len(text) // 4
words = struct.unpack_from(">%dI" % n, text, 0)

# collect pairs: addr -> delta
pairs = {}  # addr_of_addis -> delta
i = 0
while i < n - 1:
    w = words[i]
    if (w >> 26) == 15:  # addis
        ra = (w >> 16) & 0x1F
        if ra in (2, 13):
            hi = w & 0xFFFF
            nxt = words[i + 1]
            op = nxt >> 26
            rd = (nxt >> 21) & 0x1F
            nra = (nxt >> 16) & 0x1F
            simm = nxt & 0xFFFF
            if nra == ((w >> 21) & 0x1F) and op in (32, 14, 36, 12):
                delta = (hi << 16) + (simm - 0x10000 if simm >= 0x8000 else simm)
                pairs[text_va + i * 4] = delta
    i += 1
print("pairs found: %d" % len(pairs))

deltas = set(pairs.values())

# for each string: candidate tocs = S - delta for all deltas
def find_str_addrs(s: str):
    pat = s.encode("utf-8", errors="replace")
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


common = None
for s in STRINGS:
    addrs = find_str_addrs(s)
    if not addrs:
        print("string not found:", s[:50])
        continue
    cands = {a - d for a in addrs for d in deltas}
    common = cands if common is None else (common & cands)
    print("%-50s addrs=%d cands=%d common=%d" % (s[:50], len(addrs), len(cands), len(common) if common else 0))
    if common is not None and len(common) <= 4:
        break

if common:
    print("TOC candidate bases:", [hex(x) for x in sorted(common)][:8])
    toc = min(common)
    # now resolve referencing instructions for each string
    inv = {}
    for a, d in pairs.items():
        inv[(a, d)] = True
    lines = ["toc_base=%#x" % toc, ""]
    for s in STRINGS:
        for sa in find_str_addrs(s)[:2]:
            target_delta = sa - toc
            refs = [a for a, d in pairs.items() if d == target_delta]
            lines.append("%s @%#x refs=%s" % (s[:50], sa, [hex(r) for r in refs[:6]]))
    open(OUT, "w").write("\n".join(lines))
    print("written", OUT)
else:
    print("no common TOC base found")
