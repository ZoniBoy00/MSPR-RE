"""Open the saved MSPRFINAL Ghidra project and run the TOC xref extraction.

pyghidra.open_project + Project.openProgram avoids re-importing.
Run: python tools/legacy/mspr_project_driver.py
"""

import os
import pyghidra
import _paths as P

GHIDRA_DIR = P.GHIDRA_DIR
PROJECT_PATH = P.work("ghidra_proj")
PROJECT_NAME = "MSPRFINAL2"
PROGRAM_PATH = "/"  # root folder
PROGRAM_NAME = "EBOOT.final.elf"
OUT_DIR = P.work("ghidra_findings")

TARGET_STRINGS = [
    "Logging into Medius Server with NP Ticket",
    "MediusAccountUpdateStats() failed",
    "MediusGetPlayerInfo() failed",
    "GotMatchMakingTicket",
    "ROOM_IN_MATCHMAKE",
    "ROOM_IN_CASUAL_STANDARD",
    "CustomGameCreated",
    "DownloadGhostFromLeaderBoard",
    "FillRankedLeaderboardTable",
    "Game Type Set To GAMETYPE_RANKED_ONLINE",
    "SVBrowser::TicketLogin",
    "PostStats",
    "MediusLogin",
]


def main():
    os.environ.setdefault("GHIDRA_INSTALL_DIR", GHIDRA_DIR)
    pyghidra.start(verbose=False)
    from ghidra.app.decompiler import DecompInterface
    from ghidra.app.plugin.assembler import Assembler
    from ghidra.util.task import ConsoleTaskMonitor
    from ghidra.base.project import GhidraProject

    monitor = ConsoleTaskMonitor()
    project = GhidraProject.openProject(PROJECT_PATH, PROJECT_NAME, True)
    program = project.openProgram(PROGRAM_PATH, PROGRAM_NAME, False)

    af = program.getAddressFactory().getDefaultAddressSpace()
    mem = program.getMemory()
    fm = program.getFunctionManager()

    # FlatProgramAPI lives in ghidra.program.flatapi
    from ghidra.program.flatapi import FlatProgramAPI as FPA
    api = FPA(program)

    def get_bytes(vaddr: int, n: int) -> bytes:
        return bytes(api.getBytes(af.getAddress(vaddr & 0xFFFFFFFFFFFFFFFF), n))

    print("memory size:", mem.getSize())
    print("function count:", fm.getFunctionCount())

    # --- find strings ---
    def find_string_addr(s: str):
        pat = s.encode("utf-8", errors="replace")
        found = []
        for b in mem.getBlocks():
            if not b.isInitialized():
                continue
            size = b.getSize()
            base = b.getStart().getOffset()
            step = 0x400000
            for off in range(0, size, step):
                n = min(step + len(pat), size - off)
                try:
                    chunk = get_bytes(base + off, n)
                except Exception:
                    break
                pos = 0
                while True:
                    i = chunk.find(pat, pos)
                    if i == -1:
                        break
                    found.append(base + off + i)
                    pos = i + 1
        return found

    # --- check whether Ghidra already has references to our strings ---
    st = program.getSymbolTable()
    refmgr = program.getReferenceManager()
    ifc = DecompInterface()
    ifc.openProgram(program)

    os.makedirs(OUT_DIR, exist_ok=True)
    dec = open(os.path.join(OUT_DIR, "decompiled_final.c"), "w", encoding="utf-8")
    log = open(os.path.join(OUT_DIR, "final_log.txt"), "w", encoding="utf-8")

    decompiled = set()
    for s in TARGET_STRINGS:
        for sa in find_string_addr(s)[:3]:
            addr = af.getAddress(sa)
            refs = refmgr.getReferencesTo(addr)
            ref_list = [r.getFromAddress() for r in refs]
            log.write("'%s' @%#x refs=%s\n" % (s[:50], sa, [str(r) for r in ref_list[:8]]))
            for ra in ref_list[:6]:
                func = fm.getFunctionContaining(ra)
                if func is None:
                    continue
                ep = func.getEntryPoint().getOffset()
                if ep in decompiled:
                    continue
                decompiled.add(ep)
                res = ifc.decompileFunction(func, 120, monitor)
                dec.write("// ==== '%s' -> %s @ %#x ====\n" % (s[:50], func.getName(), ep))
                if res.decompileCompleted():
                    dec.write(res.getDecompiledFunction().getC())
                else:
                    dec.write("// decompile failed\n")
                dec.write("\n\n")

    dec.close()
    log.close()
    project.save(program)
    project.close()
    print("done -> " + OUT_DIR)


if __name__ == "__main__":
    main()
