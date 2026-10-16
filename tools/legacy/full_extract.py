"""MSPR FULL extraction — complete TOC-tracked string xref map + decompilation.

Tracks the r2 (TOC) register offset through 'addis r2, r2, hi' window
shifts, resolves every r2-relative data reference (TOC entry -> 32-bit
pointer -> string), groups references by function, decompiles all
functions referencing Medius/SVO/matchmaking/leaderboard strings.
Static analysis of a local file only.
"""

import struct
import re
import os
import _paths as P

ELF = P.work("EBOOT.ghidra.elf")
OUT_DIR = P.work("ghidra_findings")
TOC = 0x208958
TEXT_VA = 0x10230

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


t_addr, t_off, t_size = next((addr, off, size) for i, addr, off, size in secs if addr == TEXT_VA)
text = data[t_off:t_off + t_size]
n = len(text) // 4
words = struct.unpack_from(">%dI" % n, text, 0)
print("text words: %d" % n)


def read_str(va: int, max_len=140) -> str | None:
    if not (0xd00000 <= va < 0x12366c4):
        return None
    raw = read_va(va, max_len)
    if not raw:
        return None
    s = raw.split(b"\x00")[0]
    if len(s) < 5:
        return None
    try:
        t = s.decode("ascii")
    except Exception:
        return None
    return t if all(32 <= ord(c) < 127 for c in t) else None


def s16(v):
    return v - 0x10000 if v >= 0x8000 else v


# --- full scan with r2 window tracking ---
refs = []  # (instr_va, string)
r2off = 0
i = 0
pending = None  # (addr, rd, hi) for addis awaiting lwz/addi/ld
while i < n:
    w = words[i]
    op = w >> 26
    ra = (w >> 16) & 0x1F
    rd = (w >> 21) & 0x1F
    simm = s16(w & 0xFFFF)
    ia = TEXT_VA + i * 4

    if op == 15 and ra == 2:  # addis
        if rd == 2:
            r2off += simm << 16  # window shift
            i += 1
            continue
        pending = (ia, rd, simm << 16)  # addis rD, r2, hi -> wait for lwz/addi/ld
        i += 1
        continue

    if pending and ra == pending[1] and op in (32, 14, 36, 58):
        lo = simm
        if op == 58:  # ld DS-form: offset = (w & 0xFFFC) as signed
            lo = s16((w & 0xFFFC))
        target = TOC + r2off + pending[2] + lo
        entry = read_va(target, 4)
        if entry:
            ptr = struct.unpack(">I", entry)[0]
            s = read_str(ptr)
            if s:
                refs.append((pending[0], ptr, s))
                refs.append((ia, ptr, s))
        pending = None
        i += 1
        continue

    if ra == 2 and op in (32, 14):  # single lwz/addi rX, simm(r2)
        target = TOC + r2off + simm
        entry = read_va(target, 4)
        if entry:
            ptr = struct.unpack(">I", entry)[0]
            s = read_str(ptr)
            if s:
                refs.append((ia, ptr, s))
    pending = None
    i += 1

print("total r2-relative string refs: %d" % len(refs))

# --- group by function (blr backtracking) ---
def find_func_start(ia: int) -> int | None:
    pos = (ia - TEXT_VA) // 4 - 1
    lo_lim = max(0, pos - 0x2000)
    while pos >= lo_lim:
        if words[pos] == 0x4E800020:
            return TEXT_VA + (pos + 1) * 4
        pos -= 1
    return None


by_func = {}
for ia, ptr, s in refs:
    fs = find_func_start(ia)
    if fs is None:
        continue
    by_func.setdefault(fs, []).append((ia, ptr, s))
print("functions with string refs: %d" % len(by_func))

# --- save full map ---
os.makedirs(OUT_DIR, exist_ok=True)
with open(os.path.join(OUT_DIR, "full_string_xrefs.txt"), "w", encoding="utf-8") as f:
    for fs in sorted(by_func):
        f.write("function %#x (%d refs):\n" % (fs, len(by_func[fs])))
        for ia, ptr, s in sorted(by_func[fs])[:60]:
            f.write("  %#x -> %#x : %s\n" % (ia, ptr, s[:110]))
        f.write("\n")
print("full map written")

# --- select interesting functions for decompilation ---
INTEREST = re.compile(
    r"(medius|svo|scert|matchmak|leaderboard|finishgame|poststats|ghost|"
    r"ticketlogin|lobby|ranked|casual|universe|session key|EULA|"
    r"CreateOnlineGame|ROOM_IN|dmeServer|End Game Report)",
    re.I,
)

interesting = []
for fs, rlist in by_func.items():
    joined = " | ".join(s for _a, _p, s in rlist)
    score = len(INTEREST.findall(joined))
    if score > 0:
        interesting.append((score, fs, rlist))
interesting.sort(key=lambda x: -x[0])
print("interesting functions: %d" % len(interesting))

with open(os.path.join(OUT_DIR, "interesting_functions.txt"), "w", encoding="utf-8") as f:
    for score, fs, rlist in interesting:
        f.write("function %#x score=%d refs=%d\n" % (fs, score, len(rlist)))
        for ia, ptr, s in sorted(rlist)[:25]:
            f.write("  %#x : %s\n" % (ia, s[:110]))
        f.write("\n")

# save the decompile list for the Ghidra phase
with open(os.path.join(OUT_DIR, "decompile_list.txt"), "w") as f:
    for score, fs, rlist in interesting[:80]:
        f.write("%#x\n" % fs)
print("top %d functions listed for decompilation" % min(80, len(interesting)))
