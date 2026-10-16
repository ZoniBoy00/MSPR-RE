# tools

Python and Ghidra helpers used for the reverse engineering. None of them is needed to run the server (the server repository has its own small set in its `tools/` folder). Install the packages with `pip install -r requirements.txt` from the repository root.

| Folder | Purpose |
|---|---|
| `re/` | The working set for the EBOOT analysis: `ghidra_decompile.py` and `reanalyze.py` (headless Ghidra), `xref_eboot.py` (cross-references), `medius_registry.py` (the Medius message registry), `extract_medius_streams.py` and `extract_svo_fixtures.py` (turn a capture into Medius streams and SVO test fixtures), `mspr_status.py` (polls the former service's public status API), `ghidra/ApplyMSPRNames.py` (applies the verified names and comments). |
| `game-data/` | `psarc.py` reads the game's `ms2.psarc` (`python tools/game-data/psarc.py ms2.psarc list <text>` / `get <path> <out>`); `psarc_patch.py` and `svo_url_override.py` change one small file inside the archive in place, with an undo file (the second one sets the game's `svoUrl` option, see `analysis/game-data.md`). Work on a copy of the archive; extracted game data is not kept in this repository. |
| `mspr_capture/` | Passive network capture for RPCS3 or a PS3 on your LAN, with a decoder for Medius (`medius_decode.py`), DNS, flows and HTTP, and redaction of private data. See its README. |
| `mspr_proxy/` | A Medius man-in-the-middle for your own game client, to read the traffic of a server that encrypts it. See its README. |
| `scert/` | The shared SCE-RT code (`rt.py`, `scert_crypto.py`) used by the proxy and the capture tool. |
| `tests/` | Tests of the capture tool and the proxy (`python -m pytest tools/tests`, run from `tools/`). |
| `legacy/` | The scripts of the first rounds (string scans, TOC solving, ELF fixing, QUIC inspection, early Ghidra drivers). Kept for reference; the results are in `analysis/earlier/`. Locations come from `_paths.py` (`MSPR_RE_WORK`, `GHIDRA_INSTALL_DIR`, `MSPR_PCAP`), see [legacy/README.md](legacy/README.md). |
