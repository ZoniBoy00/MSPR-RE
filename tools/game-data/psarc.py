"""Minimal PSARC reader: list entries and extract files by path substring. Read-only on the archive."""
import hashlib
import struct
import sys
import zlib
import lzma
from pathlib import Path


class Psarc:
    def __init__(self, path):
        self.f = open(path, "rb")
        h = self.f.read(32)
        assert h[:4] == b"PSAR", h[:4]
        self.ver = struct.unpack(">HH", h[4:8])
        self.comp = h[8:12]
        self.toc_len, self.entry_size, self.n, self.block_size, self.flags = struct.unpack(">IIIII", h[12:32])
        toc = self.f.read(self.toc_len - 32)
        self.entries = []
        for i in range(self.n):
            e = toc[i * self.entry_size:(i + 1) * self.entry_size]
            md5 = e[:16]
            blk = struct.unpack(">I", e[16:20])[0]
            size = int.from_bytes(e[20:25], "big")
            off = int.from_bytes(e[25:30], "big")
            self.entries.append((md5, blk, size, off))
        rest = toc[self.n * self.entry_size:]
        w = 2 if self.block_size <= 0x10000 else 3 if self.block_size <= 0x1000000 else 4
        self.bsz = [int.from_bytes(rest[i:i + w], "big") for i in range(0, len(rest) - w + 1, w)]
        self.names = None

    def read_entry(self, i):
        md5, blk, size, off = self.entries[i]
        self.f.seek(off)
        out = b""
        while len(out) < size:
            csize = self.bsz[blk]
            blk += 1
            want = min(self.block_size, size - len(out))
            if csize == 0:
                data = self.f.read(self.block_size)
            else:
                raw = self.f.read(csize)
                if csize == want and csize == self.block_size or csize == want and len(out) + csize == size and raw[:1] not in (b"\x78",):
                    data = raw
                else:
                    try:
                        data = lzma.decompress(raw) if self.comp == b"lzma" else zlib.decompress(raw)
                    except Exception:
                        data = raw
            out += data
        return out[:size]

    def manifest(self):
        if self.names is None:
            txt = self.read_entry(0).decode("utf-8", "replace")
            self.names = [n for n in txt.replace("\r", "").split("\n") if n]
        return self.names

    def index_of(self, name):
        names = self.manifest()
        n0 = "/" + name.lstrip("/")
        if n0 in names:
            return names.index(n0) + 1
        return None

    def index_of_md5(self, name):
        for cand in (name, name.lstrip("/"), "/" + name.lstrip("/")):
            md5 = hashlib.md5(cand.encode()).digest()
            for i, e in enumerate(self.entries):
                if e[0] == md5:
                    return i
        return None


if __name__ == "__main__":
    a = Psarc(sys.argv[1])
    print("PSARC", a.ver, a.comp, "entries", a.n, "block", a.block_size, file=sys.stderr)
    names = a.manifest()
    cmd = sys.argv[2]
    if cmd == "list":
        pat = sys.argv[3].lower() if len(sys.argv) > 3 else ""
        for n in names:
            if pat in n.lower():
                print(n)
    elif cmd == "extract":
        prefix, outdir = sys.argv[3], Path(sys.argv[4])
        n = tot = 0
        for idx, nm in enumerate(names):
            if nm.startswith(prefix):
                data = a.read_entry(idx + 1)
                dest = outdir / nm.lstrip("/")
                dest.parent.mkdir(parents=True, exist_ok=True)
                dest.write_bytes(data)
                n += 1
                tot += len(data)
        print("extracted", n, "files,", tot, "bytes")
    elif cmd == "sizes":
        import collections
        c = collections.Counter()
        for idx, nm in enumerate(names):
            c["/" + nm.lstrip("/").split("/")[0]] += a.entries[idx + 1][2]
        for k, v in c.most_common():
            print("%12d %s" % (v, k))
    elif cmd == "get":
        out = Path(sys.argv[4])
        i = a.index_of(sys.argv[3])
        data = a.read_entry(i)
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_bytes(data)
        print("wrote", out, len(data))
