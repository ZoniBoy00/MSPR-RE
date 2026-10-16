"""Open MSPRFINAL2 project and run the final string-xref extraction.
Run: python tools/legacy/mspr_final_driver.py
"""

import os
import struct
import re

import pyghidra
import _paths as P

GHIDRA_DIR = P.GHIDRA_DIR
PROJECT_PATH = P.work("ghidra_proj")
PROJECT_NAME = "MSPRFINAL2"
PROGRAM_NAME = "EBOOT.final.elf"
OUT_DIR = P.work("ghidra_findings")

KEYWORDS = re.compile(
    r"(medius|svo|scert|leaderboard|matchmak|ticket|ROOM_IN|PostStats|ghost|"
    r"finishGame|lobby|ranked|casual|custom game|CreateOnlineGame|"
    r"stat\.|bestTime|totalRace|EULA|getRegion|getAnnouncement|Universe)",
    re.I,
)


def main():
    os.environ.setdefault("GHIDRA_INSTALL_DIR", GHIDRA_DIR)
    pyghidra.start(verbose=False)
    from ghidra.app.decompiler import DecompInterface
    from ghidra.util.task import ConsoleTaskMonitor
    from ghidra.base.project import GhidraProject
    from ghidra.program.flatapi import FlatProgramAPI

    monitor = ConsoleTaskMonitor()
    project = GhidraProject.openProject(PROJECT_PATH, PROJECT_NAME, True)
    program = project.openProgram("/", PROGRAM_NAME, False)
    api = FlatProgramAPI(program)

    af = program.getAddressFactory().getDefaultAddressSpace()
    mem = program.getMemory()
    fm = program.getFunctionManager()
    listing = program.getListing()

    exec_blk = None
    data_lo = data_hi = None
    for b in mem.getBlocks():
        if not b.isInitialized():
            continue
        if b.isExecute():
            if exec_blk is None or b.getSize() > exec_blk.getSize():
                exec_blk = b
        if not b.isExecute() and b.getSize() > 0x100000 and b.getStart().getOffset() > 0xD00000:
            if data_lo is None:
                data_lo = b.getStart().getOffset()
            data_hi = b.getStart().getOffset() + b.getSize()

    print("exec:", exec_blk.getStart(), int(exec_blk.getSize()))
    print("rodata: %#x-%#x" % (data_lo, data_hi))

    text_base = exec_blk.getStart().getOffset()
    text_size = int(exec_blk.getSize())
    text_data = bytes(api.getBytes(exec_blk.getStart(), text_size))
    n = len(text_data) // 4
    words = struct.unpack_from(">%dI" % n, text_data, 0)

    ifc = DecompInterface()
    ifc.openProgram(program)

    os.makedirs(OUT_DIR, exist_ok=True)
    out = open(os.path.join(OUT_DIR, "decompiled_final.c"), "w", encoding="utf-8")
    log = open(os.path.join(OUT_DIR, "final_log.txt"), "w", encoding="utf-8")

    refs_by_func = {}
    checked = 0
    no_func_refs = []
    for i, w in enumerate(words):
        if not (data_lo <= w < data_hi):
            continue
        try:
            raw = bytes(api.getBytes(af.getAddress(w), 96))
        except Exception:
            continue
        s = raw.split(b"\x00")[0].decode("utf-8", errors="replace")
        if len(s) < 6 or not KEYWORDS.search(s):
            continue
        checked += 1
        ia = text_base + i * 4
        func = fm.getFunctionContaining(af.getAddress(ia))
        if func is None:
            no_func_refs.append((ia, s[:80]))
            continue
        ep = func.getEntryPoint().getOffset()
        refs_by_func.setdefault(ep, (func, []))[1].append((ia, s[:80]))

    # refs outside defined functions: backtrack to previous blr terminator,
    # disassemble forward, create function, decompile
    for ia, s in no_func_refs:
        off = ia - text_base
        pos = off - 4
        start = None
        while pos > 0:
            if struct.unpack_from(">I", text_data, pos)[0] == 0x4E800020:  # blr
                start = text_base + pos + 4
                break
            pos -= 4
        if start is None:
            log.write("'%s' @%#x: no function start found\n" % (s[:60], ia))
            continue
        fs = af.getAddress(start)
        try:
            api.disassemble(fs)
            func = api.createFunction(fs, None)
        except Exception as e:
            log.write("'%s' @%#x: create failed %#x: %s\n" % (s[:60], ia, start, e))
            continue
        if func is None:
            continue
        ep = func.getEntryPoint().getOffset()
        if ep in refs_by_func:
            continue
        refs_by_func[ep] = (func, [(ia, s[:80])])

    print("keyword refs: %d, functions: %d" % (checked, len(refs_by_func)))
    log.write("keyword refs: %d, functions: %d\n" % (checked, len(refs_by_func)))

    for ep, (func, refs) in sorted(refs_by_func.items()):
        res = ifc.decompileFunction(func, 120, monitor)
        out.write("// ==== function @ %#x (%s) ====\n" % (ep, func.getName()))
        for ia, s in refs[:20]:
            out.write("//   %#x: %s\n" % (ia, s))
        if res.decompileCompleted():
            out.write(res.getDecompiledFunction().getC())
        else:
            out.write("// decompile failed\n")
        out.write("\n\n")
        log.write("%#x %s %d\n" % (ep, func.getName(), len(refs)))

    out.close()
    log.close()
    project.close()
    print("done -> " + OUT_DIR)


if __name__ == "__main__":
    main()
