# Ghidra headless post-script: extract MSPR online-stack functions.
# Lists all functions matching protocol-relevant names and decompiles
# the key SVO/Medius entry points to C pseudocode.
# @category: MSPR

import re
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

OUT = os.path.join(WORK, "ghidra_findings")

PATTERNS = re.compile(
    r"(SVOAction|SVOManager|Medius|PostStats|GetGhost|SCERT|"
    r"leaderboard|Leaderboard|MatchMaking|matchmak|finishGame|FinishGame|"
    r"svo|Svo|SVBrowser|PostStats|GetEula|getEula)",
    re.IGNORECASE,
)

DECOMPILE_TARGETS = [
    "SVOActionLogin", "SVOActionPostStats", "SVOActionGetGhost",
    "SVOActionGetEula", "SVOActionMonitor", "SVOActionInitialise",
    "MediusLogin", "MediusAccountUpdateStats", "MediusGetPlayerInfo",
    "MediusNPlogin",
]

import os
WORK = os.environ.get("MSPR_RE_WORK", os.path.join(os.path.expanduser("~"), "mspr-work"))   # same folder as tools/legacy/_paths.py
try:
    os.makedirs(OUT)
except Exception:
    pass

fm = currentProgram.getFunctionManager()
monitor = ConsoleTaskMonitor()

# 1) list matching functions
matches = []
for f in fm.getFunctions(True):
    name = f.getName()
    if PATTERNS.search(name):
        matches.append((name, f.getEntryPoint().toString(), f.getBody().getNumAddresses()))

with open(OUT + "/functions.txt", "w") as fh:
    fh.write("name | entry | size\n")
    for name, ep, size in sorted(matches):
        fh.write("%s | %s | %d\n" % (name, ep, size))

print("matched %d functions" % len(matches))

# 2) decompile priority targets (best match per target name)
ifc = DecompInterface()
ifc.openProgram(currentProgram)

with open(OUT + "/decompiled.c", "w") as fh:
    for target in DECOMPILE_TARGETS:
        best = None
        for name, ep, size in matches:
            if target.lower() in name.lower():
                if best is None or size < best[2]:  # prefer smallest (most specific)
                    best = (name, ep, size)
        if best is None:
            fh.write("// %s: no matching function\n\n" % target)
            continue
        try:
            addr = currentProgram.getAddressFactory().getAddress(best[1])
            func = fm.getFunctionAt(addr)
            if func is None:
                fh.write("// %s: no function at %s\n\n" % (target, best[1]))
                continue
            res = ifc.decompileFunction(func, 120, monitor)
            fh.write("// ==== %s -> %s (entry %s) ====\n" % (target, best[0], best[1]))
            if res.decompileCompleted():
                fh.write(res.getDecompiledFunction().getC())
            else:
                fh.write("// decompile failed: %s\n" % res.getErrorMessage())
            fh.write("\n\n")
        except Exception as e:
            fh.write("// %s error: %s\n\n" % (target, e))

print("done: " + OUT)
