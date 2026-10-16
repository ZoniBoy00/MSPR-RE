# Ghidra headless post-script for RAW-imported MSPR EBOOT (Cell PPU).
# Builds memory from the decrypted ELF's PT_LOAD segments, then locates
# SVO/Medius classes via Itanium C++ ABI RTTI/vtables and decompiles
# their virtual methods. Static analysis of a local file only.
# @category: MSPR
# @runtime: Jython

import struct
from ghidra.program.model.address import AddressSet
from ghidra.program.model.mem import MemoryBlock
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

af = currentProgram.getAddressFactory().getDefaultAddressSpace()
mem = currentProgram.getMemory()
fm = currentProgram.getFunctionManager()
monitor = ConsoleTaskMonitor()

print("creating memory blocks from PT_LOAD segments...")
for i in range(e_phnum):
    o = e_phoff + i * e_phentsize
    p_type, p_flags, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_align = struct.unpack_from(">IIQQQQQQ", data, o)
    if p_type != 1 or p_filesz == 0:
        continue
    start = af.getAddress(p_vaddr)
    try:
        block = mem.createInitializedBlock("seg%d" % i, start, p_filesz, 0, monitor, False)
        block.setExecute(bool(p_flags & 1))
        chunk = data[p_offset:p_offset + p_filesz]
        mem.setBytes(start, chunk)
        print("seg%d: vaddr=%#x size=%#x flags=%d" % (i, p_vaddr, p_filesz, p_flags))
    except Exception as e:
        print("seg%d failed: %s" % (i, e))

print("memory mapped, total size: %d" % mem.getSize())

text_lo = min(af.getAddress(p[3]) for p in [struct.unpack_from(">IIQQQQQQ", data, e_phoff + i * e_phentsize) for i in range(e_phnum)] if p[0] == 1 and p[5] > 0)
text_hi = max(af.getAddress(p[3] + p[5]) for p in [struct.unpack_from(">IIQQQQQQ", data, e_phoff + i * e_phentsize) for i in range(e_phnum)] if p[0] == 1 and p[5] > 0)


def find_bytes(pattern):
    """Find all addresses of pattern in memory (simple scan over blocks)."""
    results = []
    blocks = mem.getBlocks()
    for b in blocks:
        if not b.isInitialized():
            continue
        size = b.getSize()
        if size > 0x2000000:
            continue  # skip huge blocks for now
        buf = bytearray(size)
        ok = True
        step = 0x100000
        for off in range(0, size, step):
            n = min(step, size - off)
            chunk = bytes(b.getBytes(b.getStart().add(off), n))
            buf[off:off + n] = chunk
        pos = 0
        while True:
            idx = buf.find(pattern, pos)
            if idx == -1:
                break
            results.append(b.getStart().add(idx))
            pos = idx + 1
    return results


def read_u64(addr):
    v = mem.getLong(addr)
    return v


def addr_in_code(a):
    return text_lo.compareTo(a) <= 0 and text_hi.compareTo(a) > 0


ifc = DecompInterface()
ifc.openProgram(currentProgram)

os_makedirs_ok = True
import os
try:
    os.makedirs(OUT_DIR)
except Exception:
    pass

log = open(OUT_DIR + "/rtti_vtables.txt", "w")
dec = open(OUT_DIR + "/decompiled_vfuncs.c", "w")

for cls in TARGET_CLASSES:
    mangled = "N" + "3evo6online" + str(len(cls)) + cls + "E"
    # SVO classes live in evo::online; Medius classes may have other namespace -
    # fall back to bare name search too.
    name_addrs = find_bytes(mangled.encode())
    if not name_addrs:
        name_addrs = find_bytes(cls.encode())
    if not name_addrs:
        log.write("%s: typeinfo name not found\n" % cls)
        print("%s: name not found" % cls)
        continue

    for name_addr in name_addrs[:4]:
        # find pointers to this name address (typeinfo objects)
        pat = struct.pack(">Q", name_addr.getOffset())
        ti_addrs = find_bytes(pat)
        log.write("%s: name@%s typeinfo-candidates=%d\n" % (cls, name_addr, len(ti_addrs)))
        for ti in ti_addrs[:6]:
            # find vtables: pointers to typeinfo object (vtable+8 slot)
            vpat = struct.pack(">Q", ti.getOffset())
            vslots = find_bytes(vpat)
            for slot in vslots[:8]:
                vtable = slot.subtract(8)
                log.write("  typeinfo@%s vtable@%s\n" % (ti, vtable))
                # read function pointers from vtable+16 onward
                a = vtable.add(16)
                count = 0
                while count < 30:
                    try:
                        fp = read_u64(a)
                    except Exception:
                        break
                    fa = af.getAddress(fp)
                    if not addr_in_code(fa):
                        break
                    fname = "%s_vtbl%d_%d" % (cls, vtable.getOffset(), count)
                    try:
                        func = fm.getFunctionAt(fa)
                        if func is None:
                            disassemble(fa)
                            func = fm.createFunction(fa, fname)
                    except Exception as e:
                        log.write("    fn create failed at %s: %s\n" % (fa, e))
                        break
                    if func is not None:
                        res = ifc.decompileFunction(func, 60, monitor)
                        dec.write("// ==== %s.%s (entry %s) ====\n" % (cls, fname, fa))
                        if res.decompileCompleted():
                            dec.write(res.getDecompiledFunction().getC())
                        else:
                            dec.write("// decompile failed\n")
                        dec.write("\n\n")
                    a = a.add(8)
                    count += 1

log.close()
dec.close()
print("done -> " + OUT_DIR)
