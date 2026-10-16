"""MSPR FINAL v2 — fixed-TOC (r2 = 0x208958) reference map.

1. Map every 32-bit word in the image that points into rodata
   (candidate TOC entries / literal pointers).
2. Single pass over code: lwz/addi/ld rX, simm(r2) -> entry addr
   = 0x208958 + simm; if that entry maps to a keyword string, record
   (function, string).
3. Save full map + interesting functions.
Static analysis of a local file only.
"""

import struct
import re
import os
import _paths as P

ELF = P.work("EBOOT.ghidra.elf")
OUT_DIR = P.work("ghidra_findings")
TOC = 0x208958
RODATA_LO, RODATA_HI = 0xD00000, 0x12366C4

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


def read_str(va: int, max_len=140) -> str | None:
    if not (RODATA_LO <= va < RODATA_HI):
        return None
    for _i, addr, off, size in secs:
        if addr <= va < addr + size:
            raw = data[off + (va - addr): off + (va - addr) + max_len]
            s = raw.split(b"\x00")[0]
            if len(s) < 5:
                return None
            try:
                t = s.decode("ascii")
            except Exception:
                return None
            return t if all(32 <= ord(c) < 127 for c in t) else None
    return None


t_addr, t_off, t_size = next((addr, off, size) for i, addr, off, size in secs if addr == 0x10230)
text = data[t_off:t_off + t_size]
n = len(text) // 4
words = struct.unpack_from(">%dI" % n, text, 0)
print("words: %d" % n)

# 1) entry map: entry_addr -> string
print("building TOC entry map...")
entry_str = {}
for i in range(n):
    v = words[i]
    if RODATA_LO <= v < RODATA_HI:
        s = read_str(v)
        if s:
            entry_str[0x10230 + i * 4] = s
print("entries pointing to strings: %d" % len(entry_str))

# 2) code pass: lwz/addi rX, simm(r2)
KEYWORDS = re.compile(
    r"(medius|svo|scert|matchmak|leaderboard|finishgame|poststats|ghost|"
    r"ticketlogin|lobby|ranked|casual|universe|session key|eula|"
    r"CreateOnlineGame|ROOM_IN|dmeServer|End Game Report|bestTime|"
    r"getRegion|getAnnouncement|Downloading|stat\.)",
    re.I,
)

by_func = {}  # func_start -> list[(ia, string)]


def func_start(ia: int) -> int | None:
    pos = (ia - 0x10230) // 4 - 1
    lo = max(0, pos - 0x2000)
    while pos >= lo:
        if words[pos] == 0x4E800020:
            return 0x10230 + (pos + 1) * 4
        pos -= 1
    return None


def s16(v):
    return v - 0x10000 if v >= 0x8000 else v


all_refs = 0
for i in range(n):
    w = words[i]
    op = w >> 26
    ra = (w >> 16) & 0x1F
    if ra != 2 or op not in (32, 14, 58):
        continue
    simm = s16(w & 0xFFFF) if op != 58 else (s16((w & 0xFFFC)) )
    if op == 58:
        simm = s16((w & 0xFFFC))
    e = TOC + simm
    s = entry_str.get(e)
    if not s:
        continue
    all_refs += 1
    ia = 0x10230 + i * 4
    if KEYWORDS.search(s):
        fs = func_start(ia)
        if fs is not None:
            by_func.setdefault(fs, []).append((ia, s))

print("total r2 refs resolving to strings: %d" % all_refs)
print("functions with keyword strings: %d" % len(by_func))

# 2b) pair scan: addis rX, r2, hi + lwz/addi/ld rY, lo(rX) with FIXED toc
print("scanning addis pairs with fixed TOC...")
addis_by_hi = {}
for i in range(n - 1):
    w = words[i]
    if (w >> 26) != 15:
        continue
    ra = (w >> 16) & 0x1F
    if ra != 2:
        continue
    rd = (w >> 21) & 0x1F
    hi = s16(w & 0xFFFF) << 16
    addis_by_hi.setdefault(hi, []).append((0x10230 + i * 4, rd, i))

pair_refs = 0
for i in range(n):
    v = words[i]
    if RODATA_LO <= v < RODATA_HI:
        s = read_str(v)
        if not s:
            continue
        E = 0x10230 + i * 4  # the pointer word itself is the TOC entry
        delta = E - TOC
        hi = s16(((delta + 0x8000) >> 16) & 0xFFFF) << 16
        lo = s16(delta - hi)
        for addr, rd, wi in addis_by_hi.get(hi, []):
            nxt = words[wi + 1] if wi + 1 < n else 0
            op = nxt >> 26
            nra = (nxt >> 16) & 0x1F
            simm = s16((nxt & 0xFFFC)) if op == 58 else s16(nxt & 0xFFFF)
            if nra == rd and simm == lo:
                ia = addr
                fs = func_start(ia)
                if fs is None:
                    continue
                pair_refs += 1
                if KEYWORDS.search(s):
                    by_func.setdefault(fs, []).append((ia, s))
print("pair refs with keyword strings: %d" % pair_refs)

with open(os.path.join(OUT_DIR, "full_string_xrefs.txt"), "w", encoding="utf-8") as f:
    for fs in sorted(by_func):
        f.write("function %#x:\n" % fs)
        for ia, s in sorted(by_func[fs])[:80]:
            f.write("  %#x : %s\n" % (ia, s[:120]))
        f.write("\n")

INTEREST = re.compile(r"(medius|svo|matchmak|leaderboard|finishgame|poststats|ghost|ticketlogin|universe|session key|dmeserver)", re.I)
lst = []
for fs, rlist in by_func.items():
    score = sum(1 for _a, s in rlist if INTEREST.search(s))
    if score:
        lst.append((score, fs, rlist))
lst.sort(key=lambda x: -x[0])
with open(os.path.join(OUT_DIR, "decompile_list.txt"), "w") as f:
    for score, fs, rlist in lst[:120]:
        f.write("%#x\n" % fs)
print("interesting functions: %d (top 120 listed)" % len(lst))
for score, fs, rlist in lst[:15]:
    strs = " | ".join(s[:45] for _a, s in rlist[:3])
    print("%#x score=%d: %s" % (fs, score, strs))
