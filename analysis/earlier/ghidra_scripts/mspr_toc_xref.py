# PyGhidra post-script: TOC xref analysis v3 for MSPR (PPC64 PS3).
# Light strategy: for each candidate TOC base and known log string, scan
# the text segment bytes directly for the exact addis/lwz instruction pair.
# Pure C-speed finds, low memory. Static analysis of a local file only.
# @category: MSPR

import struct
import os
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
WORK = os.environ.get("MSPR_RE_WORK", os.path.join(os.path.expanduser("~"), "mspr-work"))   # same folder as tools/legacy/_paths.py

OUT_DIR = os.path.join(WORK, "ghidra_findings")

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
]

mem = currentProgram.getMemory()
af = currentProgram.getAddressFactory().getDefaultAddressSpace()
fm = currentProgram.getFunctionManager()
monitor = ConsoleTaskMonitor()


def get_bytes(vaddr: int, n: int) -> bytes:
    return bytes(getBytes(af.getAddress(vaddr & 0xFFFFFFFFFFFFFFFF), n))


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


# map text segment once
text = None
text_base = None
for b in mem.getBlocks():
    if b.isInitialized() and b.isExecute():
        text_base = b.getStart().getOffset()
        text = get_bytes(text_base, b.getSize())
        break
print("text mapped: base=%#x size=%d" % (text_base, len(text)))
n_words = len(text) // 4

# unique string anchors
anchors = {}
for s in TARGET_STRINGS:
    a = find_string_addr(s)
    if a:
        anchors[s] = a[0]
print("anchors found: %d/%d" % (len(anchors), len(TARGET_STRINGS)))

# brute-force TOC: for each candidate, all anchor deltas must resolve
toc_base = None
candidates = list(range(0x1000000, 0x1100000, 0x8000))
for cand in candidates:
    ok = True
    checked = 0
    for s, sa in anchors.items():
        delta = sa - cand
        if not (-0x80000000 <= delta <= 0x7FFFFFFF):
            ok = False
            break
        hi = ((delta + 0x8000) >> 16) & 0xFFFF
        lo = (delta - (hi << 16)) & 0xFFFF
        addis_hi = struct.pack(">I", (15 << 26) | (13 << 16) | hi)  # addis rX, r13, hi (any rD)
        addis_hi2 = struct.pack(">I", (15 << 26) | (2 << 16) | hi)  # addis rX, r2, hi
        found_ref = False
        for wbytes in (addis_hi, addis_hi2):
            pos = 0
            while True:
                i = text.find(wbytes, pos)
                if i == -1:
                    break
                pos = i + 4
                if i + 8 > len(text):
                    continue
                nxt = struct.unpack_from(">I", text, i + 4)[0]
                rd = (nxt >> 21) & 0x1F
                ra = (nxt >> 16) & 0x1F
                simm = nxt & 0xFFFF
                src = 13 if wbytes == addis_hi else 2
                if ra == src and simm == lo:
                    found_ref = True
                    break
                # also allow addi rX, src, lo directly after a different-hi addis? keep simple
            if found_ref:
                break
        if not found_ref:
            ok = False
            break
        checked += 1
    if ok and checked == len(anchors):
        toc_base = cand
        print("TOC BASE FOUND: %#x" % toc_base)
        break
    if cand % 0x40000 == 0:
        print("...scanning toc %#x" % cand)

print("toc_base:", hex(toc_base) if toc_base else None)

os.makedirs(OUT_DIR, exist_ok=True)
log = open(OUT_DIR + "/toc_xrefs.txt", "w", encoding="utf-8")
dec = open(OUT_DIR + "/decompiled_toc.c", "w", encoding="utf-8")
log.write("toc_base=%s\n" % (hex(toc_base) if toc_base else None))

ifc = DecompInterface()
ifc.openProgram(currentProgram)

decompiled = set()


def func_from_ref(ia: int):
    a = af.getAddress(ia)
    func = getFunctionContaining(a)
    if func is not None:
        return func
    # backtrack to previous blr
    search_from = max(text_base, ia - 0x8000)
    data = text[search_from - text_base: ia - text_base + 4]
    pos = len(data) - 4
    while pos >= 0:
        if struct.unpack_from(">I", data, pos)[0] == 0x4E800020:
            start = search_from + pos + 4
            fs = af.getAddress(start)
            try:
                disassemble(fs)
                return fm.createFunction(fs, None)
            except Exception as e:
                log.write("    create failed %#x: %s\n" % (start, e))
                return None
        pos -= 4
    return None


if toc_base:
    for s in TARGET_STRINGS:
        for sa in find_string_addr(s)[:2]:
            delta = sa - toc_base
            hi = ((delta + 0x8000) >> 16) & 0xFFFF
            lo = (delta - (hi << 16)) & 0xFFFF
            refs = []
            for src in (13, 2):
                wbytes = struct.pack(">I", (15 << 26) | (src << 16) | hi)
                pos = 0
                while True:
                    i = text.find(wbytes, pos)
                    if i == -1:
                        break
                    pos = i + 4
                    nxt = struct.unpack_from(">I", text, i + 4)[0]
                    ra = (nxt >> 16) & 0x1F
                    simm = nxt & 0xFFFF
                    if ra == src and simm == lo:
                        refs.append(text_base + i)
            log.write("'%s' @%#x refs=%s\n" % (s[:50], sa, [hex(r) for r in refs[:8]]))
            for ia in refs[:6]:
                func = func_from_ref(ia)
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

log.close()
dec.close()
print("done -> " + OUT_DIR)
