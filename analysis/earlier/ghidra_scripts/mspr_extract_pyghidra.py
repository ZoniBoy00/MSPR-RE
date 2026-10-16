# PyGhidra (Python 3) headless post-script for RAW-imported MSPR EBOOT.
# Builds memory from the decrypted ELF's PT_LOAD segments, locates
# SVO/Medius classes via Itanium C++ ABI RTTI/vtables and decompiles
# their virtual methods. Static analysis of a local file only.
# @category: MSPR

import struct
import os
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
WORK = os.environ.get("MSPR_RE_WORK", os.path.join(os.path.expanduser("~"), "mspr-work"))   # same folder as tools/legacy/_paths.py

ELF_PATH = os.path.join(WORK, "EBOOT.ghidra.elf")
OUT_DIR = os.path.join(WORK, "ghidra_findings")

TARGET_CLASSES = [
    "SVOActionLogin", "SVOActionPostStats", "SVOActionGetGhost",
    "SVOActionGetEula", "SVOActionMonitor", "SVOActionInitialise",
    "SVOManager", "SVBrowser",
    "MediusLogin", "MediusAccountUpdateStats", "MediusGetPlayerInfo",
]

print("reading ELF...")
data = open(ELF_PATH, "rb").read()
e_phoff, = struct.unpack_from(">Q", data, 0x20)
e_phentsize, e_phnum = struct.unpack_from(">HH", data, 0x36)

segs = []  # (vaddr, bytes)
for i in range(e_phnum):
    o = e_phoff + i * e_phentsize
    p_type, p_flags, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_align = struct.unpack_from(">IIQQQQQQ", data, o)
    if p_type == 1 and p_filesz > 0:
        segs.append((p_vaddr, p_flags, data[p_offset:p_offset + p_filesz]))

lo = min(s[0] for s in segs)
hi = max(s[0] + len(s[2]) for s in segs)

af = currentProgram.getAddressFactory().getDefaultAddressSpace()
mem = currentProgram.getMemory()
fm = currentProgram.getFunctionManager()
monitor = ConsoleTaskMonitor()

print("creating memory blocks from PT_LOAD segments...")
# remove the raw-import block so segment blocks can be placed at virtual addresses
for b in list(mem.getBlocks()):
    if b.getSize() >= 1000000:  # the raw file block
        try:
            mem.removeBlock(b, monitor)
            print("removed raw block:", b.getName())
        except Exception as e:
            print("remove failed:", e)

for i, (vaddr, flags, content) in enumerate(segs):
    try:
        block = mem.createInitializedBlock("seg%d" % i, af.getAddress(vaddr), len(content), 0, monitor, False)
        block.setExecute(bool(flags & 1))
        mem.setBytes(af.getAddress(vaddr), content)
        print("seg%d: vaddr=%#x size=%#x flags=%d" % (i, vaddr, len(content), flags))
    except Exception as e:
        print("seg%d failed: %s" % (i, e))


def addr_in_code(a):
    return lo <= a.getOffset() < hi


def find_addrs(pattern: bytes):
    """Find all virtual addresses of pattern across mapped segments."""
    out = []
    for vaddr, _flags, content in segs:
        pos = 0
        while True:
            idx = content.find(pattern, pos)
            if idx == -1:
                break
            out.append(vaddr + idx)
            pos = idx + 1
    return out


def read_u64_img(vaddr: int) -> int:
    for base, _flags, content in segs:
        if base <= vaddr < base + len(content):
            return struct.unpack_from(">Q", content, vaddr - base)[0]
    return 0


def to_addr(v: int):
    return af.getAddress(v & 0xFFFFFFFFFFFFFFFF)


ifc = DecompInterface()
ifc.openProgram(currentProgram)

os.makedirs(OUT_DIR, exist_ok=True)
log = open(OUT_DIR + "/rtti_vtables.txt", "w", encoding="utf-8")
dec = open(OUT_DIR + "/decompiled_vfuncs.c", "w", encoding="utf-8")

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
                    fa = to_addr(fp)
                    fname = "%s_vtbl%x_%d" % (cls, vtable, count)
                    try:
                        func = fm.getFunctionAt(fa)
                        if func is None:
                            disassemble(fa)
                            func = fm.createFunction(fa, fname)
                    except Exception as e:
                        log.write("    fn create failed at %#x: %s\n" % (fp, e))
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
