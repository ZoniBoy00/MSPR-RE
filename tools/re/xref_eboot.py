"""String cross-references for a decrypted PS3 EBOOT (PPC64, 32-bit pointers).

Resolves data references made through the TOC (r2):
  * lwz/ld rX, d(r2)            -> pointer stored in the TOC entry
  * addi rX, r2, d              -> address inside the TOC area
  * addis rX, r2, hi ; lwz/addi rY, lo(rX)
  * lwz rX, d(r2) ; addi rY, rX, off   (pooled .rodata: base pointer + offset)
Register values are tracked linearly inside each function (reset at blr).

Output: re/<tag>/xrefs.json  {string: [[insn_addr, func_start], ...]}
        re/<tag>/func_strings.txt  per-function string lists (for triage)

Usage: python -X utf8 tools\\xref_eboot.py re\\v103\\EBOOT.elf
"""

from __future__ import annotations

import json
import struct
import sys
from collections import defaultdict
from pathlib import Path


def s16(v: int) -> int:
    return v - 0x10000 if v & 0x8000 else v


class Image:
    def __init__(self, path: Path):
        d = path.read_bytes()
        self.raw = d
        self.entry = struct.unpack_from(">Q", d, 0x18)[0]
        phoff = struct.unpack_from(">Q", d, 0x20)[0]
        phs, phn = struct.unpack_from(">HH", d, 0x36)
        self.segs = []
        for i in range(phn):
            t, f, off, va, _pa, fs, ms, _al = struct.unpack_from(">IIQQQQQQ", d, phoff + i * phs)
            if t == 1 and fs:
                self.segs.append((va, va + ms, f, d[off:off + fs]))
        # code = executable PT_LOAD
        self.code = next(s for s in self.segs if s[2] & 1)

    def read(self, va: int, n: int) -> bytes | None:
        for lo, hi, _f, blob in self.segs:
            if lo <= va < hi:
                o = va - lo
                return blob[o:o + n] if o < len(blob) else b"\0" * n
        return None

    def u32(self, va: int) -> int | None:
        b = self.read(va, 4)
        return struct.unpack(">I", b)[0] if b and len(b) == 4 else None

    def cstr(self, va: int, maxlen=200) -> str | None:
        b = self.read(va, maxlen)
        if not b:
            return None
        s = b.split(b"\0", 1)[0]
        if len(s) < 4:
            return None
        try:
            t = s.decode("ascii")
        except UnicodeDecodeError:
            return None
        if sum(c.isalpha() for c in t) < 3 or not all(32 <= ord(c) < 127 or c in "\t\n\r" for c in t):
            return None
        return t


def toc_ranges(img: "Image") -> list[tuple[int, int, int]]:
    """[(start, end, toc)] from OPD descriptors. Large PS3 binaries use several TOCs."""
    lo, hi = img.code[0], img.code[1]
    main_toc = img.u32(img.entry + 4)
    pairs = {}
    for slo, shi, flags, blob in img.segs:
        if flags & 1:
            continue
        for o in range(0, len(blob) - 7, 4):
            a, t = struct.unpack_from(">II", blob, o)
            if lo <= a < hi and a % 4 == 0 and slo <= t < shi + 0x100000:
                pairs.setdefault(t, []).append(a)
    tocs = [t for t, v in pairs.items() if len(v) > 1000] or [main_toc]
    owner = sorted((a, t) for t in tocs for a in pairs.get(t, []))
    runs = []
    for a, t in owner:
        if runs and runs[-1][2] == t:
            runs[-1][1] = a
        else:
            runs.append([a, a, t])
    out = []
    for i, (a, _b, t) in enumerate(runs):
        start = lo if i == 0 else a
        end = runs[i + 1][0] if i + 1 < len(runs) else hi
        out.append((start, end, t))
    return out


def toc_for(ranges, addr: int) -> int:
    for a, b, t in ranges:
        if a <= addr < b:
            return t
    return ranges[-1][2]


def function_starts(img: "Image", words, lo: int, toc: int) -> list[int]:
    """OPD descriptors (code_addr, toc) in data + direct bl targets."""
    hi = lo + len(words) * 4
    starts = set()
    for slo, shi, flags, blob in img.segs:
        if flags & 1:
            continue
        for o in range(0, len(blob) - 7, 4):
            a, t = struct.unpack_from(">II", blob, o)
            if t in toc and lo <= a < hi and a % 4 == 0:
                starts.add(a)
    for i, w in enumerate(words):
        if (w >> 26) == 18 and (w & 3) == 1:  # bl
            off = w & 0x03FFFFFC
            if off & 0x02000000:
                off -= 0x04000000
            t = lo + i * 4 + off
            if lo <= t < hi:
                starts.add(t)
    return sorted(starts)


def main():
    elf = Path(sys.argv[1])
    img = Image(elf)
    func_addr = img.u32(img.entry)
    toc = img.u32(img.entry + 4)
    print("entry OPD %#x -> func %#x, TOC %#x" % (img.entry, func_addr, toc))

    lo, hi, _f, blob = img.code
    n = len(blob) // 4
    words = struct.unpack_from(">%dI" % n, blob, 0)

    ranges = toc_ranges(img)
    for a, b, t in ranges:
        print("  TOC %#x for %#x..%#x" % (t, a, b))
    starts = function_starts(img, words, lo, {t for _a, _b, t in ranges})
    print("function starts: %d (OPD + bl targets)" % len(starts))
    (elf.parent / "functions.txt").write_text("\n".join("%#x" % a for a in starts))

    xrefs: dict[str, list] = defaultdict(list)
    func_strings: dict[int, list] = defaultdict(list)
    regs: dict[int, int] = {}
    fstart = lo
    start_set = set(starts)

    def hit(ia: int, va: int):
        s = img.cstr(va)
        if s:
            xrefs[s].append([ia, fstart])
            func_strings[fstart].append(s)

    for i, w in enumerate(words):
        ia = lo + i * 4
        op = w >> 26
        rd = (w >> 21) & 31
        ra = (w >> 16) & 31
        if ia in start_set:
            regs.clear()
            fstart = ia
            toc = toc_for(ranges, ia)
        if w == 0x4E800020:  # blr
            regs.clear()
            continue
        if op in (32, 58) and ra == 2:  # lwz / ld rD, d(r2)
            d = s16(w & 0xFFFF) if op == 32 else s16(w & 0xFFFC)
            ent = toc + d
            ptr = img.u32(ent) if op == 32 else img.u32(ent + 4)
            if ptr is not None:
                regs[rd] = ptr
                hit(ia, ptr)
            continue
        if op == 14 and ra == 2:  # addi rD, r2, d
            regs[rd] = toc + s16(w & 0xFFFF)
            hit(ia, regs[rd])
            continue
        if op == 15 and ra == 2:  # addis rD, r2, hi
            regs[rd] = (toc + (s16(w & 0xFFFF) << 16)) & 0xFFFFFFFF
            continue
        if op == 14 and ra in regs:  # addi rD, rA, off   (pool base + off)
            v = (regs[ra] + s16(w & 0xFFFF)) & 0xFFFFFFFF
            regs[rd] = v
            hit(ia, v)
            continue
        if op in (32, 58) and ra in regs:  # lwz rD, off(rA) via addis pair
            ent = (regs[ra] + (s16(w & 0xFFFF) if op == 32 else s16(w & 0xFFFC))) & 0xFFFFFFFF
            ptr = img.u32(ent) if op == 32 else img.u32(ent + 4)
            if ptr is not None:
                regs[rd] = ptr
                hit(ia, ptr)
            continue
        # any other write to rd invalidates it (rough but safe)
        if op in (31, 21, 24, 25, 28, 29, 34, 40, 42, 7, 12, 13):
            regs.pop(rd if op != 31 else ra if (w >> 1 & 0x3FF) in (444, 28, 60, 476, 316) else rd, None)

    out = elf.parent
    (out / "xrefs.json").write_text(json.dumps({k: v for k, v in sorted(xrefs.items())}, indent=0))
    with open(out / "func_strings.txt", "w", encoding="utf-8") as f:
        for fs in sorted(func_strings):
            uniq = list(dict.fromkeys(func_strings[fs]))
            f.write("FUNC %#x (%d strings)\n" % (fs, len(uniq)))
            for s in uniq:
                f.write("    %r\n" % s[:160])
    print("strings referenced: %d, functions: %d" % (len(xrefs), len(func_strings)))


if __name__ == "__main__":
    main()
