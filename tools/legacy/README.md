# tools/legacy

The scripts of the first reverse engineering rounds. They are kept because the results in `analysis/earlier/` and the method (how the TOC base of the PS3 EBOOT was found, how strings are mapped to code) are worth reproducing. The current, maintained tools are in [`../re`](../re).

## Setup

None of the scripts has a machine specific path any more. All of them take their locations from [`_paths.py`](_paths.py):

| What | Default | Override |
|---|---|---|
| Work folder (inputs and outputs) | `<repository>/work/` (ignored by git) | `MSPR_RE_WORK` |
| Ghidra installation (`*_driver.py`, `decompile_interesting.py`) | none, must be set | `GHIDRA_INSTALL_DIR` |
| Capture read by the pcap scripts | `<work>/capture.pcapng` | `MSPR_PCAP` |

Put the files from your own copy of the game into the work folder (they are not in this repository):

| File | How you get it |
|---|---|
| `EBOOT.ELF` / `EBOOT.BIN` | The EBOOT of the game (v1.03), decrypted with a PS3 decrypter such as RPCS3's or `make_fself`/`scetool`. |
| `EBOOT.ghidra.elf` | `python fix_elf_sections.py` (adds section headers Ghidra needs). |
| `EBOOT.raw.bin` | Raw bytes of the decrypted EBOOT, for `mspr_ghidra_driver.py`. |
| `capture.pcapng` | Your own capture, for example with [`../mspr_capture`](../mspr_capture). |

Python 3.10+ and the packages in [`../../requirements.txt`](../../requirements.txt) (`scapy` for the capture scripts, `cryptography` for the QUIC one, `pyghidra` for the Ghidra drivers). Run the scripts from this folder or give the full path; they all work with `python tools/legacy/<script>.py` from the repository root.

## Scripts

### Finding strings and the TOC base (static, only the EBOOT)

| Script | Purpose |
|---|---|
| `strings_scan.py [file]` | ASCII strings of a PS3 binary, filtered for network and protocol words. |
| `eboot_analyze.py` | Strings (ASCII and UTF-16LE) grouped by topic, writes `analysis_report.md`. |
| `full_strings.py` | The protocol-relevant strings as a categorised document (`FULL_STRINGS.md`). |
| `ranked_casual_strings.py` | Strings of the ranked, casual and game-mode code (`ranked_casual_strings.txt`). |
| `toc_solve.py`, `toc_solve2.py`, `toc_solve3.py` | Three attempts to derive the TOC (`r2`) base from `addis`/`lwz`/`ld` pairs; the third one gave the confirmed value `0x208958`. |
| `final_toc_extract.py`, `final_extract2.py`, `full_extract.py` | With the TOC base known: map every data reference in the code to its string and decompile the functions that use them. |
| `mm_functions.py` | The matchmaking functions and their string references (`matchmaking_functions.txt`). |
| `rtti_extract.py` | Class map from the RTTI typeinfo names (`class_map.txt`). |
| `fix_elf_sections.py` | Repairs the section headers of the decrypted ELF so Ghidra can load it. |

### Ghidra (needs `GHIDRA_INSTALL_DIR` and `pyghidra`)

| Script | Purpose |
|---|---|
| `mspr_ghidra_driver.py` | Imports the raw EBOOT with the Cell PPU language (avoids the ELF loader that crashes on PS3 files) and decompiles the SVO and Medius classes found through RTTI. |
| `mspr_project_driver.py`, `mspr_final_driver.py` | Open the saved project and run the xref extraction. |
| `decompile_interesting.py` | Decompiles the functions listed by `full_extract.py`. |

The Ghidra post-scripts these drivers started (and the first ones that were run by hand) are in `analysis/earlier/ghidra_scripts/`. They run inside Ghidra, read the work folder from `MSPR_RE_WORK` (default `~/mspr-work`) and write to its `ghidra_findings/`.

### Captures (need `scapy`, a capture of your own)

| Script | Purpose |
|---|---|
| `medius_handshake.py` | The first server-to-client payloads on the Medius ports (10071, 10075, 10077, 11001), to see what a server sends first. |
| `extract_server_replay.py` | Per-port server payload sequences as JSON, for a replaying stub. |
| `quic_inspect.py`, `quic_initial_decrypt.py` | Looks at the QUIC traffic of the former service's API and decrypts the Initial packet's ClientHello (RFC 9001). The game itself does not use QUIC. |

### Windows helpers (PowerShell, edit the address first)

`add_hosts.ps1` and `remove_hosts.ps1` point the game's host names at a test server through the `hosts` file (the first rounds, before the DNS part of the server existed) and `port_poller.ps1` shows which ports the game connects to. They contain the example address `192.0.2.10`; change it to your own. Run them as administrator. For real use the server's own DNS (see the server repository) is the better way.
