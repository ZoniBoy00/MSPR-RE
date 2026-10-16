"""Replace one small file inside a PSARC archive in place, with an undo file.

The archive is not rebuilt: the new content is compressed (zlib) and written over the old file's compressed block, and the
two table fields that describe it (the size of the block and the size of the file) are updated. That only works when
the new content is a single block (under 64 kB) and its compressed form is not larger than the old one. Everything else in
the archive stays byte for byte the same. The bytes that were overwritten are saved in an undo file.

    python tools/psarc_patch.py ARCHIVE patch  PATH_IN_ARCHIVE NEW_FILE [--undo UNDO.json]
    python tools/psarc_patch.py ARCHIVE restore UNDO.json

Work on a copy of the archive first. Never run it on a file you have no backup of.
"""

from __future__ import annotations

import json
import struct
import sys
import zlib
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from psarc import Psarc  # noqa: E402


def patch(archive: str, path: str, new: bytes, undo_path: str) -> None:
    a = Psarc(archive)
    if a.comp != b"zlib":
        raise SystemExit("only zlib archives are supported")
    idx = a.index_of(path)
    if idx is None:
        raise SystemExit("not in the archive: " + path)
    md5, blk, size, off = a.entries[idx]
    if size > a.block_size or len(new) > a.block_size:
        raise SystemExit("only single-block files can be replaced")
    old_c = a.bsz[blk]
    comp = zlib.compress(new, 9)
    if len(comp) >= len(new):                       # a block that does not shrink is stored raw
        comp = new
    if old_c == 0 or len(comp) > old_c:
        raise SystemExit("new content needs %d bytes, the old slot has %d" % (len(comp), old_c))
    w = 2 if a.block_size <= 0x10000 else 3 if a.block_size <= 0x1000000 else 4
    entry_pos = 32 + idx * a.entry_size
    table_pos = 32 + a.n * a.entry_size + blk * w
    with open(archive, "r+b") as f:
        undo = {"archive_size": Path(archive).stat().st_size, "patches": []}

        def put(pos: int, data: bytes) -> None:
            f.seek(pos)
            undo["patches"].append({"pos": pos, "old": f.read(len(data)).hex()})
            f.seek(pos)
            f.write(data)

        put(off, comp.ljust(old_c, b"\0"))
        put(table_pos, len(comp).to_bytes(w, "big"))
        put(entry_pos + 20, len(new).to_bytes(5, "big"))
    Path(undo_path).write_text(json.dumps(undo), encoding="utf-8")
    print("patched %s: %d -> %d bytes (compressed %d of %d); undo file %s" % (path, size, len(new), len(comp), old_c, undo_path))


def restore(archive: str, undo_path: str) -> None:
    undo = json.loads(Path(undo_path).read_text(encoding="utf-8"))
    if Path(archive).stat().st_size != undo["archive_size"]:
        raise SystemExit("the archive has another size than when it was patched")
    with open(archive, "r+b") as f:
        for p in reversed(undo["patches"]):
            f.seek(p["pos"])
            f.write(bytes.fromhex(p["old"]))
    print("restored", len(undo["patches"]), "areas")


if __name__ == "__main__":
    if len(sys.argv) >= 5 and sys.argv[2] == "patch":
        undo = sys.argv[sys.argv.index("--undo") + 1] if "--undo" in sys.argv else "psarc_patch_undo.json"
        patch(sys.argv[1], sys.argv[3], Path(sys.argv[4]).read_bytes(), undo)
    elif len(sys.argv) == 4 and sys.argv[2] == "restore":
        restore(sys.argv[1], sys.argv[3])
    else:
        print(__doc__)
