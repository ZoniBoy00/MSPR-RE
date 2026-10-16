"""Derive the PS3 TOC (r2) register base by intersecting single-instruction
'lwz rT, simm(r2)' references to known log strings. Pure static analysis."""

import struct
import _paths as P

ELF = P.work("EBOOT.ghidra.elf")
OUT = P.work("toc_solution2.txt")

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


def find_lwz_r2(s_addr: int):
    """All text offsets of 'lwz rT, simm(r2)' where simm = s_addr - r2_base,
    for every plausible r2_base. Returns dict r2_base -> [text offsets]."""
    hits = {}
    for base in range(s_addr - 0x7FFF, s_addr + 0x8000, 4):
        simm = (s_addr - base) & 0xFFFF
        # lwz rT, simm(r2): op=32, any rT, RA=2
        wmask = (32 << 26) | (2 << 16)
        wlo = simm
        # scan only high bits fixed: pattern bytes: op/rt varies... build via find on
        # 2-byte aligned: match (word & 0xFC1F0000) == (32<<26)|(2<<16) and low16 == simm
        # do a fast scan over text for words with low16 == simm is too common; instead
        # iterate: we can't find cheaply. Skip: use different technique below.
        pass
    return hits


# Better technique: single pass over text words; for each lwz rX, simm(r2)
# compute implied base = s_addr - simm; collect candidate bases per string.
n = len(text) // 4
words = struct.unpack_from(">%dI" % n, text, 0)


def candidate_bases(s_addr: int):
    cands = set()
    for i in range(n):
        w = words[i]
        if (w >> 26) != 32:
            continue
        if ((w >> 16) & 0x1F) != 2:
            continue
        simm = w & 0xFFFF
        if simm >= 0x8000:
            simm -= 0x10000
        base = s_addr - simm
        cands.add(base)
    return cands


strings = [
    "MediusLoginFailed",
    "MediusGetPlayerInfo() failed",
    "MediusAccountUpdateStats() failed",
    "Logging into Medius Server with NP Ticket",
    "ROOM_IN_MATCHMAKE",
    "CustomGameCreated",
]

common = None
lines = []
for s in strings:
    addrs = find_str_addrs(s)
    if not addrs:
        lines.append("%-50s NOT FOUND" % s)
        continue
    c = candidate_bases(addrs[0])
    if common is None:
        common = set(c)
    else:
        common &= c
    lines.append("%-50s addr=%#x lwz-r2-cands=%d common=%d" % (s[:50], addrs[0], len(c), len(common)))
    if len(common) <= 2:
        break

lines.append("common bases: %s" % [hex(x) for x in sorted(common)][:10] if common else "NONE")
open(OUT, "w").write("\n".join(lines))
print("\n".join(lines))
