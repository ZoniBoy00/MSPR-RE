"""MSPR class map v2 — typeinfo-name driven RTTI extraction.

Strategy: PS3 stores data pointers tagged (0x40000000000 + addr).
1. Find the mangled-typeinfo-name string region.
2. Scan data sections for tagged pointers whose target reads as a
   mangled C++ name (N...E) — those locations are typeinfo objects'
   name fields.
3. typeinfo object = ptr_location - 8. Find tagged pointers to the
   typeinfo object -> vtable = location - 8. Functions follow.
4. Emit class map: typeinfo name -> vtable -> function addresses.
Static analysis of a local file only.
"""

import struct
import re
import _paths as P

ELF = P.work("EBOOT.ghidra.elf")
OUT = P.work("class_map.txt")

TAG = 0x40000000000
TEXT_LO, TEXT_HI = 0x10000, 0x1028ac8
MANGLED = re.compile(rb"^N\d+[a-zA-Z_][\x20-\x7e]{3,200}E$")

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


def read_va(va: int, n: int = 8) -> bytes | None:
    va &= ~TAG
    for _i, addr, off, size in secs:
        if addr <= va < addr + size:
            return data[off + (va - addr): off + (va - addr) + n]
    return None


def is_code(v: int) -> bool:
    v = untag(v)
    return TEXT_LO <= v < TEXT_HI


def untag(v: int) -> int:
    return v & ~TAG


# --- step 1: scan data sections for tagged pointers to mangled names ---
typeinfo_objs = {}  # typeinfo_addr -> class_name
for i, addr, off, size in secs:
    n = size // 8
    if n < 2:
        continue
    vals = struct.unpack_from(">%dQ" % n, data, off)
    for k, v in enumerate(vals):
        if v < TAG:  # only tagged pointers
            continue
        target = v & ~TAG
        raw = read_va(target, 240)
        if not raw:
            continue
        name = raw.split(b"\x00")[0]
        if MANGLED.match(name) and b"evo" in name or (name.startswith(b"N") and b"online" in name):
            # typeinfo object = location - 8 (name_ptr is second field)
            ti_addr = addr + k * 8 - 8
            typeinfo_objs[ti_addr] = name.decode(errors="replace")

print("typeinfo objects found: %d" % len(typeinfo_objs))

# --- step 2: find vtables pointing to typeinfo objects ---
class_entries = []  # (vtable_addr, name, funcs)
for i, addr, off, size in secs:
    n = size // 8
    if n < 8:
        continue
    vals = struct.unpack_from(">%dQ" % n, data, off)
    for k, v in enumerate(vals):
        if v < TAG:
            continue
        ti = v & ~TAG
        if ti not in typeinfo_objs:
            continue
        vtable_addr = addr + k * 8 - 8
        funcs = []
        a = vtable_addr + 16
        while len(funcs) < 40:
            raw = read_va(a, 8)
            if not raw:
                break
            fp = struct.unpack(">Q", raw)[0]
            if not is_code(fp):
                break
            funcs.append(untag(fp))
            a += 8
        if funcs:
            class_entries.append((vtable_addr, typeinfo_objs[ti], funcs))

with open(OUT, "w", encoding="utf-8") as f:
    f.write("vtable_addr | class (mangled) | #vfns | first funcs\n")
    for vtable_addr, name, funcs in sorted(class_entries, key=lambda x: x[1]):
        short = ",".join("%#x" % a for a in funcs[:5])
        f.write("%#x | %s | %d | %s\n" % (vtable_addr, name, len(funcs), short))

INTEREST = re.compile(r"svo|medius|scert|online|matchmak|leaderboard|room|ticket|browser", re.I)
print("\n=== interesting classes ===")
cnt = 0
for vtable_addr, name, funcs in sorted(class_entries, key=lambda x: x[1]):
    if INTEREST.search(name):
        print("%#x  %s  (%d vfns)" % (vtable_addr, name[:90], len(funcs)))
        cnt += 1
print("interesting: %d / total classes: %d" % (cnt, len(class_entries)))
