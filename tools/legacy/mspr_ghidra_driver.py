"""MSPR EBOOT static analysis driver (PyGhidra, forced Binary Loader).

Avoids Ghidra's ELF loader entirely (its PPC64 OPD handling crashes on
PS3 ELFs) by importing the decrypted binary as raw bytes with the
Cell PPU language, then building memory from PT_LOAD segments and
decompiling SVO/Medius virtual functions found via RTTI vtables.

Run: python tools/legacy/mspr_ghidra_driver.py
Static analysis of a local file only.
"""

import struct
import os
import sys

import pyghidra
import _paths as P

GHIDRA_DIR = P.GHIDRA_DIR
RAW_BIN = P.work("EBOOT.raw.bin")
ELF_REF = P.work("EBOOT.ghidra.elf")
PROJECT_PATH = P.work("ghidra_proj")
OUT_DIR = P.work("ghidra_findings")

TARGET_CLASSES = [
    "SVOActionLogin", "SVOActionPostStats", "SVOActionGetGhost",
    "SVOActionGetEula", "SVOActionMonitor", "SVOActionInitialise",
    "SVOManager", "SVBrowser",
    "MediusLogin", "MediusAccountUpdateStats", "MediusGetPlayerInfo",
]


def main():
    os.environ.setdefault("GHIDRA_INSTALL_DIR", GHIDRA_DIR)
    pyghidra.start(verbose=False)
    from ghidra.app.decompiler import DecompInterface
    from ghidra.util.task import ConsoleTaskMonitor
    with pyghidra.open_program(
        RAW_BIN,
        project_location=PROJECT_PATH,
        project_name="MSPRRAW3",
        analyze=False,
        language="PowerPC:BE:64:A2ALT",
        loader="ghidra.app.util.opinion.BinaryLoader",
    ) as flat:
        program = flat.getCurrentProgram()
        af = program.getAddressFactory().getDefaultAddressSpace()
        mem = program.getMemory()
        fm = program.getFunctionManager()
        monitor = ConsoleTaskMonitor()

        # --- parse ELF segments ---
        data = open(ELF_REF, "rb").read()
        e_phoff, = struct.unpack_from(">Q", data, 0x20)
        e_phentsize, e_phnum = struct.unpack_from(">HH", data, 0x36)
        segs = []
        for i in range(e_phnum):
            o = e_phoff + i * e_phentsize
            p_type, p_flags, p_offset, p_vaddr, _pa, p_filesz, _memsz, _al = struct.unpack_from(">IIQQQQQQ", data, o)
            if p_type == 1 and p_filesz > 0:
                segs.append((p_vaddr, p_flags, data[p_offset:p_offset + p_filesz]))

        print("removing raw import block...")
        for b in list(mem.getBlocks()):
            if b.getSize() >= 1000000:
                try:
                    mem.removeBlock(b, monitor)
                except Exception as e:
                    print("remove failed:", e)

        print("creating PT_LOAD blocks...")
        for i, (vaddr, flags, content) in enumerate(segs):
            try:
                block = mem.createInitializedBlock("seg%d" % i, af.getAddress(vaddr), len(content), 0, monitor, False)
                block.setExecute(bool(flags & 1))
                mem.setBytes(af.getAddress(vaddr), content)
                print("seg%d: vaddr=%#x size=%#x" % (i, vaddr, len(content)))
            except Exception as e:
                print("seg%d failed: %s" % (i, e))

        lo = min(s[0] for s in segs)
        hi = max(s[0] + len(s[2]) for s in segs)

        def find_addrs(pattern: bytes):
            out = []
            for vaddr, _f, content in segs:
                pos = 0
                while True:
                    idx = content.find(pattern, pos)
                    if idx == -1:
                        break
                    out.append(vaddr + idx)
                    pos = idx + 1
            return out

        def read_u64_img(v: int) -> int:
            for base, _f, content in segs:
                if base <= v < base + len(content):
                    return struct.unpack_from(">Q", content, v - base)[0]
            return 0

        ifc = DecompInterface()
        ifc.openProgram(program)

        os.makedirs(OUT_DIR, exist_ok=True)
        log = open(os.path.join(OUT_DIR, "rtti_vtables.txt"), "w", encoding="utf-8")
        dec = open(os.path.join(OUT_DIR, "decompiled_vfuncs.c"), "w", encoding="utf-8")

        for cls in TARGET_CLASSES:
            mangled = ("N3evo6online" + str(len(cls)) + cls + "E").encode()
            name_addrs = find_addrs(mangled) or find_addrs(cls.encode())
            if not name_addrs:
                log.write("%s: typeinfo name not found\n" % cls)
                print("%s: name not found" % cls)
                continue

            for name_addr in name_addrs[:4]:
                ti_addrs = find_addrs(struct.pack(">Q", name_addr))
                log.write("%s: name@%#x typeinfo-candidates=%d\n" % (cls, name_addr, len(ti_addrs)))
                for ti in ti_addrs[:6]:
                    vslots = find_addrs(struct.pack(">Q", ti))
                    for slot in vslots[:8]:
                        vtable = slot - 8
                        log.write("  typeinfo@%#x vtable@%#x\n" % (ti, vtable))
                        a = vtable + 16
                        for count in range(30):
                            fp = read_u64_img(a)
                            if fp == 0 or not (lo <= fp < hi):
                                break
                            fa = af.getAddress(fp & 0xFFFFFFFFFFFFFFFF)
                            fname = "%s_vtbl%x_%d" % (cls, vtable, count)
                            try:
                                func = fm.getFunctionAt(fa)
                                if func is None:
                                    flat.disassemble(fa)
                                    func = fm.createFunction(fa, fname)
                            except Exception as e:
                                log.write("    create failed at %#x: %s\n" % (fp, e))
                                break
                            if func is not None:
                                res = ifc.decompileFunction(func, 60, monitor)
                                dec.write("// ==== %s.%s (entry %#x) ====\n" % (cls, fname, fp))
                                if res.decompileCompleted():
                                    dec.write(res.getDecompiledFunction().getC())
                                else:
                                    dec.write("// decompile failed\n")
                                dec.write("\n\n")
                            a += 8
        log.close()
        dec.close()
        print("done -> " + OUT_DIR)


if __name__ == "__main__":
    main()
