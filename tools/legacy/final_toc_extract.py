"""MSPR final extraction with CONFIRMED TOC base (0x208958).

Scans all r2-relative data references in code (lwz/addi single + addis/lwz
pairs), resolves target strings, and decompiles every function that
references Medius/SVO/leaderboard/matchmaking strings.
Static analysis of a local file only.
"""

import struct
import re
import os
import _paths as P

ELF = P.work("EBOOT.ghidra.elf")
OUT_DIR = P.work("ghidra_findings")
TOC = 0x208958
TEXT_LO, TEXT_HI = 0x10230, 0x10230 + 0xCADB38

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


def read_va(va: int, n: int) -> bytes | None:
    va &= ~0x40000000000
    for _i, addr, off, size in secs:
        if addr <= va < addr + size:
            return data[off + (va - addr): off + (va - addr) + n]
    return None


# text segment bytes (mixed code+data on PS3)
tsec = next((addr, off, size) for i, addr, off, size in secs if addr == 0x10230)
t_addr, t_off, t_size = tsec
text = data[t_off:t_off + t_size]
n = len(text) // 4
words = struct.unpack_from(">%dI" % n, text, 0)
print("text words: %d" % n)

KEYWORDS = re.compile(
    r"(medius|svo|scert|leaderboard|matchmak|ticket|ROOM_IN|PostStats|ghost|"
    r"finishGame|lobby|ranked|casual|custom game|CreateOnlineGame|Universe|"
    r"stat\.|bestTime|totalRace|EULA|getRegion|getAnnouncement|session key)",
    re.I,
)


def read_str(va: int, max_len=120) -> str | None:
    if not (0xd00000 <= va < 0x12366c4):
        return None
    raw = read_va(va, max_len)
    if not raw:
        return None
    s = raw.split(b"\x00")[0]
    if len(s) < 6:
        return None
    try:
        t = s.decode("ascii")
    except Exception:
        return None
    return t if all(32 <= ord(c) < 127 for c in t) else None


def read_str_via_toc(target: int) -> str | None:
    """TOC entry at target contains a 32-bit pointer to the string."""
    v = read_va(target, 4)
    if not v:
        return None
    val = struct.unpack(">I", v)[0]
    return read_str(val)


# --- collect all r2-relative string references ---
refs = []  # (instr_addr, toc_entry_addr, string)
for i in range(n - 1):
    w = words[i]
    op = w >> 26
    ra = (w >> 16) & 0x1F
    simm = w & 0xFFFF
    if simm >= 0x8000:
        simm -= 0x10000
    ia = 0x10230 + i * 4

    if ra == 2 and op in (32, 14):  # lwz/addi rX, simm(r2)
        entry = TOC + simm
        s = read_str_via_toc(entry)
        if s and KEYWORDS.search(s):
            refs.append((ia, entry, s))

    # addis r12, r2, hi  followed by  lwz/addi rX, lo(r12)
    if op == 15 and ra == 2:
        hi = simm & 0xFFFF
        nxt = words[i + 1]
        nop = nxt >> 26
        nra = (nxt >> 16) & 0x1F
        rd = (w >> 21) & 0x1F
        if nra == rd and nop in (32, 14, 36):
            nlo = nxt & 0xFFFF
            if nlo >= 0x8000:
                nlo -= 0x10000
            entry = TOC + (hi << 16) + nlo
            s = read_str_via_toc(entry)
            if s and KEYWORDS.search(s):
                refs.append((ia, entry, s))

print("r2-relative keyword string refs: %d" % len(refs))

# --- map refs to functions via blr backtracking ---
def find_func_start(ia: int) -> int | None:
    pos = (ia - 0x10230) // 4 - 1
    lo_lim = max(0, pos - 0x2000)
    while pos >= lo_lim:
        if words[pos] == 0x4E800020:  # blr
            return 0x10230 + (pos + 1) * 4
        pos -= 1
    return None


by_func = {}
for ia, target, s in refs:
    fs = find_func_start(ia)
    if fs is None:
        continue
    by_func.setdefault(fs, []).append((ia, target, s))

print("functions with keyword refs: %d" % len(by_func))

with open(os.path.join(OUT_DIR, "string_xref_map.txt"), "w", encoding="utf-8") as f:
    for fs in sorted(by_func):
        f.write("function %#x:\n" % fs)
        for ia, target, s in sorted(by_func[fs]):
            f.write("  %#x -> %#x : %s\n" % (ia, target, s[:100]))
        f.write("\n")
print("string xref map written")

# summary of most interesting functions
INTEREST = re.compile(r"(medius|svo|matchmak|leaderboard|finishgame|poststats|ghost|login)", re.I)
print("\n=== top functions ===")
for fs in sorted(by_func, key=lambda f: -len(by_func[f])):
    strs = [s for _a, _t, s in by_func[fs]]
    joined = " | ".join(strs[:4])
    if INTEREST.search(joined):
        print("%#x (%d refs): %s" % (fs, len(by_func[fs]), joined[:130]))
