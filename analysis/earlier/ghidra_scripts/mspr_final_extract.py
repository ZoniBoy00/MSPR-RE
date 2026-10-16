# Final extraction: find all 32-bit rodata references in code, resolve
# target strings, filter by protocol keywords, decompile containing
# functions. Uses the fully-analyzed MSPRFINAL2 project.
# @category: MSPR

import struct
import re
import os
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
WORK = os.environ.get("MSPR_RE_WORK", os.path.join(os.path.expanduser("~"), "mspr-work"))   # same folder as tools/legacy/_paths.py

OUT_DIR = os.path.join(WORK, "ghidra_findings")

KEYWORDS = re.compile(
    r"(medius|svo|scert|leaderboard|matchmak|ticket|ROOM_IN|PostStats|ghost|"
    r"finishGame|lobby|ranked|casual|custom game|CreateOnlineGame|"
    r"stat\.|bestTime|totalRace|EULA|getRegion|getAnnouncement|Universe)",
    re.I,
)

program = currentProgram
af = program.getAddressFactory().getDefaultAddressSpace()
mem = program.getMemory()
fm = program.getFunctionManager()
listing = program.getListing()
monitor = ConsoleTaskMonitor()

# locate executable block and data range
exec_blk = None
data_lo, data_hi = None, None
for b in mem.getBlocks():
    if not b.isInitialized():
        continue
    if b.isExecute() and exec_blk is None:
        exec_blk = b
    # rodata heuristic: initialized, non-exec, size > 1MB, address > 0xd00000
    if not b.isExecute() and b.getSize() > 0x100000 and b.getStart().getOffset() > 0xd00000:
        if data_lo is None:
            data_lo = b.getStart().getOffset()
        data_hi = b.getStart().getOffset() + b.getSize()

print("exec block:", exec_blk.getStart(), exec_blk.getSize())
print("rodata range: %#x - %#x" % (data_lo, data_hi))

text_base = exec_blk.getStart().getOffset()
text_data = bytes(exec_blk.getBytes(exec_blk.getStart(), exec_blk.getSize()))
n = len(text_data) // 4
words = struct.unpack_from(">%dI" % n, text_data, 0)

ifc = DecompInterface()
ifc.openProgram(program)

os.makedirs(OUT_DIR, exist_ok=True)
out = open(OUT_DIR + "/decompiled_final.c", "w", encoding="utf-8")
log = open(OUT_DIR + "/final_log.txt", "w", encoding="utf-8")

refs_by_func = {}
checked = 0
for i, w in enumerate(words):
    if not (data_lo <= w < data_hi):
        continue
    a = af.getAddress(w)
    try:
        data_ref = listing.getDataAt(a)
    except Exception:
        data_ref = None
    if data_ref is None:
        continue
    val = data_ref.getValue()
    if val is None:
        continue
    s = str(val)
    if len(s) < 6 or not KEYWORDS.search(s):
        continue
    checked += 1
    ia = text_base + i * 4
    func = fm.getFunctionContaining(af.getAddress(ia))
    if func is None:
        continue
    ep = func.getEntryPoint().getOffset()
    refs_by_func.setdefault(ep, (func, []))[1].append((ia, s[:80]))

print("keyword string refs: %d, functions: %d" % (checked, len(refs_by_func)))

for ep, (func, refs) in sorted(refs_by_func.items()):
    res = ifc.decompileFunction(func, 120, monitor)
    dec = res.decompileCompleted()
    out.write("// ==== function @ %#x (%s) ====\n" % (ep, func.getName()))
    out.write("// string refs:\n")
    for ia, s in refs[:20]:
        out.write("//   %#x: %s\n" % (ia, s))
    if dec:
        out.write(res.getDecompiledFunction().getC())
    else:
        out.write("// decompile failed\n")
    out.write("\n\n")
    log.write("%#x %s %d\n" % (ep, func.getName(), len(refs)))

out.close()
log.close()
print("done -> " + OUT_DIR)
