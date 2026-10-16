"""Set the game's SVO address in its own configuration (ms2.psarc, Configs/Includes/ms2_BuildOptions.cfg).

The file has a commented-out `svoUrl` debug option. This script turns it into a real option with your URL, in place and
with an undo file (see psarc_patch.py). Work on a copy of the game's archive first.

    python tools/svo_url_override.py ARCHIVE http://YOUR_IP:10060/motorstormpr/index [--undo undo.json]
    python tools/psarc_patch.py ARCHIVE restore undo.json
"""

import re
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from psarc import Psarc  # noqa: E402
from psarc_patch import patch  # noqa: E402

CFG = "Configs/Includes/ms2_BuildOptions.cfg"

if len(sys.argv) < 3:
    raise SystemExit(__doc__)
archive, url = sys.argv[1], sys.argv[2]
undo = sys.argv[sys.argv.index("--undo") + 1] if "--undo" in sys.argv else "svo_override_undo.json"
a = Psarc(archive)
text = a.read_entry(a.index_of(CFG)).decode("utf-8")
new, n = re.subn(r'<!--svoUrl\s+value\s*=\s*"[^"]*"\s*/-->', '<svoUrl value="%s" />' % url, text)
if n != 1:
    raise SystemExit("the commented svoUrl line was not found (already patched?)")
patch(archive, CFG, new.encode("utf-8"), undo)
