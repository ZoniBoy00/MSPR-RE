"""Decompile selected functions of a decrypted PS3 EBOOT with PyGhidra.

Loads the PT_LOAD segments at their virtual addresses (no Ghidra ELF loader:
it mis-handles PS3 OPDs), sets r2 = TOC (read from the entry OPD) for the
whole code range, then decompiles each requested function. Hex constants
that point at C strings are annotated inline, so the output reads like source.

Usage:
  python -X utf8 tools\\ghidra_decompile.py re\\v103\\EBOOT.elf OUT.c 0x280260 0xb6076c ...
  python -X utf8 tools\\ghidra_decompile.py re\\v103\\EBOOT.elf OUT.c @addrs.txt
"""

from __future__ import annotations

import os
import re
import struct
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from xref_eboot import Image, toc_ranges  # noqa: E402

GHIDRA_DIR = os.environ.get("GHIDRA_INSTALL_DIR", "")
PROJECT_DIR = Path(__file__).resolve().parent.parent / "re" / "ghidra_proj"


def parse_addrs(args):
    out = []
    for a in args:
        if a.startswith("@"):
            out += [int(x.split()[0], 16) for x in Path(a[1:]).read_text().split("\n") if x.strip()]
        else:
            out.append(int(a, 16))
    return out


def main():
    elf, out_path, addrs = Path(sys.argv[1]), Path(sys.argv[2]), parse_addrs(sys.argv[3:])
    img = Image(elf)
    toc = img.u32(img.entry + 4)

    os.environ.setdefault("GHIDRA_INSTALL_DIR", GHIDRA_DIR)
    import pyghidra
    pyghidra.start(verbose=False)
    from java.math import BigInteger
    from ghidra.app.decompiler import DecompInterface, DecompileOptions
    from ghidra.util.task import ConsoleTaskMonitor

    stub = Path(tempfile.gettempdir()) / ("%s_stub.bin" % elf.parent.name)
    stub.write_bytes(b"\0" * 16)
    name = "%s_%s" % (elf.parent.name, elf.stem)

    with pyghidra.open_program(str(stub), project_location=str(PROJECT_DIR), project_name=name,
                               analyze=False, language="PowerPC:BE:64:A2ALT",
                               loader="ghidra.app.util.opinion.BinaryLoader") as flat:
        prog = flat.getCurrentProgram()
        space = prog.getAddressFactory().getDefaultAddressSpace()
        mem = prog.getMemory()
        fm = prog.getFunctionManager()
        mon = ConsoleTaskMonitor()
        tx = prog.startTransaction("load")
        try:
            if mem.getBlock(space.getAddress(img.code[0])) is None:
                for b in list(mem.getBlocks()):
                    mem.removeBlock(b, mon)
                for i, (lo, hi, flags, blob) in enumerate(img.segs):
                    blk = mem.createInitializedBlock("seg%d" % i, space.getAddress(lo), hi - lo, 0, mon, False)
                    mem.setBytes(space.getAddress(lo), blob)
                    blk.setExecute(bool(flags & 1))
                    blk.setWrite(bool(flags & 2))
                ctx = prog.getProgramContext()
                r2 = ctx.getRegister("r2")
                for a, b, t in toc_ranges(img):
                    ctx.setValue(r2, space.getAddress(a), space.getAddress(b - 1), BigInteger.valueOf(t))
        finally:
            prog.endTransaction(tx, True)

        ifc = DecompInterface()
        opts = DecompileOptions()
        ifc.setOptions(opts)
        ifc.openProgram(prog)

        hexre = re.compile(r"0x([0-9a-f]{5,8})\b")
        tocre = re.compile(r"\b[a-z]*Ram0*([0-9a-f]{6,8})\b")
        with open(out_path, "w", encoding="utf-8") as out:
            for a in addrs:
                tx = prog.startTransaction("fn")
                try:
                    addr = space.getAddress(a)
                    fn = fm.getFunctionAt(addr)
                    if fn is None:
                        flat.disassemble(addr)
                        fn = flat.createFunction(addr, "FUN_%08x" % a)
                finally:
                    prog.endTransaction(tx, True)
                out.write("// ===== function %#x =====\n" % a)
                if fn is None:
                    out.write("// could not create function\n\n")
                    continue
                res = ifc.decompileFunction(fn, 120, mon)
                if not res.decompileCompleted():
                    out.write("// decompile failed: %s\n\n" % res.getErrorMessage())
                    continue
                code = res.getDecompiledFunction().getC()

                def note(m):
                    s = img.cstr(int(m.group(1), 16))
                    return m.group(0) + (" /* %r */" % s[:90] if s else "")

                def toc_note(m):
                    # uRam0000000000e99a14 = TOC entry -> 32-bit pointer -> string?
                    ptr = img.u32(int(m.group(1), 16))
                    s = img.cstr(ptr) if ptr else None
                    return m.group(0) + (" /* %r */" % s[:90] if s else "")
                code = tocre.sub(toc_note, code)
                out.write(hexre.sub(note, code))
                out.write("\n\n")
                print("decompiled %#x" % a, flush=True)


if __name__ == "__main__":
    main()

