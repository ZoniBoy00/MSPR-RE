"""Dump the Medius client library message registry from a decrypted EBOOT.

The library registers every message as
    register(r3=type, r4=class, r5=unpack_fn_opd|0, r6=1, r7=pack_fn_opd)
in one long function. This walks that code, resolves the TOC-loaded OPD
pointers to code addresses and writes re/<tag>/medius_registry.json:
    {"<class>:<type>": {"unpack": addr|null, "pack": addr|null, "site": addr}}

Usage: python -X utf8 tools\\medius_registry.py re\\v103\\EBOOT.elf 0x66af00
"""

from __future__ import annotations

import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from xref_eboot import Image, s16, toc_ranges, toc_for  # noqa: E402


def main():
    elf = Path(sys.argv[1])
    start = int(sys.argv[2], 16)
    img = Image(elf)
    toc = toc_for(toc_ranges(img), start)
    lo, hi, _f, blob = img.code
    n = len(blob) // 4
    words = struct.unpack_from(">%dI" % n, blob, 0)

    def opd_to_code(opd):
        if not opd:
            return None
        code = img.u32(opd)
        if code is not None and lo <= code < hi:
            return code
        return img.cstr(opd) or opd

    out = {}
    regs = {}
    i = (start - lo) // 4
    end = min(n, i + 60000)
    misses = 0
    while i < end:
        w = words[i]
        op, rd, ra = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        if op == 14 and ra == 0:
            regs[rd] = s16(w & 0xFFFF)
        elif op == 32 and ra == 2:
            regs[rd] = img.u32(toc + s16(w & 0xFFFF))
        elif op == 18 and (w & 1):
            if 3 in regs and 4 in regs and 7 in regs and 0 <= regs[3] < 256 and 0 <= regs[4] < 8:
                key = "%d:%#04x" % (regs[4], regs[3])
                out[key] = {
                    "unpack": opd_to_code(regs.get(5)) if regs.get(5) else None,
                    "pack": opd_to_code(regs.get(7)) if regs.get(7) else None,
                    "site": lo + i * 4,
                }
                misses = 0
            else:
                misses += 1
                if misses > 40 and out:
                    break
            regs = {}
        elif w == 0x4E800020 and out:
            break
        i += 1

    path = elf.parent / "medius_registry.json"
    path.write_text(json.dumps(out, indent=1, default=lambda v: v))
    print("registered messages: %d -> %s" % (len(out), path))


if __name__ == "__main__":
    main()
