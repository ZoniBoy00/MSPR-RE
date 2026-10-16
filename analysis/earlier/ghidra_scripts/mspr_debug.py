# @category: MSPR
# Debug: enumerate memory blocks and test string presence.
mem = currentProgram.getMemory()
print("total memory size: %d" % mem.getSize())
for b in mem.getBlocks():
    print("block: name=%r start=%s size=%d init=%s exec=%s" % (
        b.getName(), b.getStart(), b.getSize(), b.isInitialized(), b.isExecute()))

# test: search for a known ASCII string in first blocks via getBytes chunked
pat = b"MediusLoginFailed"
for b in mem.getBlocks():
    if not b.isInitialized():
        continue
    size = b.getSize()
    base = b.getStart().getOffset()
    step = 0x400000
    count = 0
    errs = 0
    for off in range(0, size, step):
        n = min(step, size - off)
        try:
            chunk = bytes(b.getBytes(b.getStart().add(off), n))
        except Exception as e:
            errs += 1
            print("getBytes ERROR block=%s off=%#x: %s" % (b.getName(), off, e))
            continue
        i = chunk.find(pat)
        if i != -1:
            print("FOUND in %s at %#x" % (b.getName(), base + off + i))
            count += 1
    print("block %s scanned, hits=%d errors=%d" % (b.getName(), count, errs))
print("debug done")
