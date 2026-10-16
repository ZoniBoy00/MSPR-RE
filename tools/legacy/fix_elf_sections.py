"""Fix decrypted PS3 EBOOT ELF for Ghidra import (v2).

Appends new section names to .shstrtab and repoints section headers.
Static metadata fix only - section contents untouched.
"""

import struct
import _paths as P

src = P.work("EBOOT.ELF")
dst = P.work("EBOOT.ghidra.elf")

d = bytearray(open(src, "rb").read())
e_shoff, = struct.unpack_from(">Q", d, 0x28)
e_shentsize, e_shnum, e_shstrndx = struct.unpack_from(">HHH", d, 0x3A)


def sh_off(i):
    return e_shoff + i * e_shentsize


def sh(i):
    return struct.unpack_from(">IIQQQQIIQQ", d, sh_off(i))


# existing shstrtab
shstr = sh(e_shstrndx)
strtab_off, strtab_size = shstr[4], shstr[5]

names = {
    1: b".eh_frame",
    2: b".text",
    3: b".scehdr1",
    4: b".rodata",
    5: b".scehdr2",
    6: b".rodata2",
    7: b".scehdr3",
    8: b".data1",
    9: b".scehdr4",
    10: b".d1",
    11: b".d2",
    12: b".d3",
    13: b".d4",
    14: b".d5",
    15: b".bss",
    16: b".data2",
    17: b".data3",
    18: b".data4",
    19: b".data5",
    20: b".data6",
    21: b".data7",
    22: b".data8",
    23: b".data9",
    24: b".data10",
    25: b".data11",
    26: b".bss2",
    27: b".bss3",
    28: b".comment",
}

# build new strtab: original + appended names
new_strtab = bytes(d[strtab_off:strtab_off + strtab_size])
offsets = {}
for i, n in names.items():
    offsets[i] = len(new_strtab)
    new_strtab += n + b"\x00"

# append new strtab at end of file (aligned)
new_strtab_off = len(d)
pad = (-new_strtab_off) % 16
d += b"\x00" * pad
new_strtab_off += pad
d += new_strtab

# update shstrtab section header to point at appended table
struct.pack_into(">IIQQQQIIQQ", d, sh_off(e_shstrndx),
                 0, 3, 0, 0, new_strtab_off, len(new_strtab), 0, 0, 1, 0)

# update each section's sh_name
for i, n in names.items():
    o = sh_off(i)
    name, typ, flags, addr, off, size, link, info, align, entsize = struct.unpack_from(">IIQQQQIIQQ", d, o)
    struct.pack_into(">I", d, o, offsets[i])

# fix section 0 (null section) name stays 0
open(dst, "wb").write(d)
print("written", dst, len(d))
