"""Decompile the interesting functions listed by full_extract.py.
Run: python tools/legacy/decompile_interesting.py
"""

import os
import pyghidra
import _paths as P

GHIDRA_DIR = P.GHIDRA_DIR
PROJECT_PATH = P.work("ghidra_proj")
PROJECT_NAME = "MSPRFINAL2"
PROGRAM_NAME = "EBOOT.final.elf"
OUT_DIR = P.work("ghidra_findings")
LIST_FILE = os.path.join(OUT_DIR, "decompile_list.txt")


def main():
    os.environ.setdefault("GHIDRA_INSTALL_DIR", GHIDRA_DIR)
    pyghidra.start(verbose=False)
    from ghidra.app.decompiler import DecompInterface
    from ghidra.util.task import ConsoleTaskMonitor
    from ghidra.base.project import GhidraProject
    from ghidra.program.flatapi import FlatProgramAPI

    addrs = []
    with open(LIST_FILE) as f:
        for line in f:
            line = line.strip()
            if line.startswith("0x") or line.startswith("0X"):
                addrs.append(int(line, 16))
    print("functions to decompile: %d" % len(addrs))
    if not addrs:
        return

    monitor = ConsoleTaskMonitor()
    project = GhidraProject.openProject(PROJECT_PATH, PROJECT_NAME, True)
    program = project.openProgram("/", PROGRAM_NAME, False)
    api = FlatProgramAPI(program)
    af = program.getAddressFactory().getDefaultAddressSpace()
    fm = program.getFunctionManager()

    ifc = DecompInterface()
    ifc.openProgram(program)

    out = open(os.path.join(OUT_DIR, "decompiled_all.c"), "w", encoding="utf-8")
    ok = 0
    for k, va in enumerate(addrs):
        a = af.getAddress(va)
        try:
            func = fm.getFunctionAt(a)
            if func is None:
                api.disassemble(a)
                func = api.createFunction(a, None)
            if func is None:
                out.write("// ==== %#x: no function ====\n\n" % va)
                continue
            res = ifc.decompileFunction(func, 120, monitor)
            out.write("// ==== [%d/%d] %#x ====\n" % (k + 1, len(addrs), va))
            if res.decompileCompleted():
                out.write(res.getDecompiledFunction().getC())
                ok += 1
            else:
                out.write("// decompile failed: %s\n" % res.getErrorMessage())
            out.write("\n\n")
        except Exception as e:
            out.write("// ==== %#x error: %s ====\n\n" % (va, e))
        if (k + 1) % 10 == 0:
            print("... %d/%d" % (k + 1, len(addrs)))

    out.close()
    project.close()
    print("decompiled %d/%d -> %s" % (ok, len(addrs), os.path.join(OUT_DIR, "decompiled_all.c")))


if __name__ == "__main__":
    main()
