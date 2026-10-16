"""Locate the matchmaking/ranked/casual functions in the EBOOT using the
confirmed TOC mechanism (r2=0x208958), and dump their string references.
Static analysis only."""

import struct
import re
import _paths as P

ELF = P.work("EBOOT.ghidra.elf")
OUT = P.work("matchmaking_functions.txt")
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

# TOC entries pointing to matchmaking-related strings
MM = re.compile(r"(matchmak|MatchMak|ROOM_IN|Ticket|TICKET|ranked|Ranked|RANKED|casual|Casual|CASUAL|GameType|lobby world|LobbyWorld|GameWorld|Universe|universe|Ranked Option|Casual Option)", re.I)
entries = {}  # entry_addr -> string
for i in range(n):
    v = words[i]
    if RODATA_LO <= v < RODATA_HI:
        s = read_str(v)
        if s and MM.search(s):
            entries[0x10230 + i * 4] = s
print("matchmaking TOC entries: %d" % len(entries))


def s16(v):
    return v - 0x10000 if v >= 0x8000 else v


def func_start(ia: int) -> int | None:
    pos = (ia - 0x10230) // 4 - 1
    lo = max(0, pos - 0x2000)
    while pos >= lo:
        if words[pos] == 0x4E800020:
            return 0x10230 + (pos + 1) * 4
        pos -= 1
    return None


# scan code: lwz/addi/ld rX, simm(r2) + addis pairs referencing entries
by_func = {}
for i in range(n):
    w = words[i]
    op = w >> 26
    ra = (w >> 16) & 0x1F
    if ra != 2 or op not in (32, 14, 58):
        continue
    simm = s16(w & 0xFFFF) if op != 58 else s16(w & 0xFFFC)
    e = TOC + simm
    if e in entries:
        ia = 0x10230 + i * 4
        fs = func_start(ia)
        if fs is not None:
            by_func.setdefault(fs, []).append((ia, entries[e]))

# addis pairs
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

for e, s in entries.items():
    delta = e - TOC
    hi = s16(((delta + 0x8000) >> 16) & 0xFFFF) << 16
    lo = s16(delta - hi)
    for addr, rd, wi in addis_by_hi.get(hi, []):
        nxt = words[wi + 1] if wi + 1 < n else 0
        op = nxt >> 26
        nra = (nxt >> 16) & 0x1F
        simm = s16((nxt & 0xFFFC)) if op == 58 else s16(nxt & 0xFFFF)
        if nra == rd and simm == lo:
            fs = func_start(addr)
            if fs is not None:
                by_func.setdefault(fs, []).append((addr, s))

with open(OUT, "w", encoding="utf-8") as f:
    f.write("matchmaking TOC entries: %d\n\n" % len(entries))
    for fs in sorted(by_func):
        f.write("function %#x:\n" % fs)
        for ia, s in sorted(by_func[fs]):
            f.write("  %#x : %s\n" % (ia, s[:120]))
        f.write("\n")
print("functions referencing matchmaking strings: %d" % len(by_func))
for fs in sorted(by_func, key=lambda f: -len(by_func[f]))[:12]:
    strs = " | ".join(s[:40] for _a, s in by_func[fs][:3])
    print("%#x (%d): %s" % (fs, len(by_func[fs]), strs[:130]))
