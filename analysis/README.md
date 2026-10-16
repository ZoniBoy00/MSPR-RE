# analysis

What is known about MotorStorm: Pacific Rift's online code, written down. Start with the first row if you want the whole picture, or jump to the topic you need.

| Document | Read it for |
|---|---|
| [reverse-engineering.md](reverse-engineering.md) | **Start here.** The protocol layers (DNS, SVO over HTTP, Medius/SCERT, DME), every SVO route with its request and answer, the identified functions of the EBOOT, and what is still unknown. Evidence is tagged `[EBOOT]`, `[CAPTURE]`, `[LIVE]`, `[SOURCE]`, `[INFERENCE]`. |
| [findings.md](findings.md) | The newest results, in order: the ghost download, the Speed Weekend, the signature of the NP ticket, the first real PS3, Horizon on .NET 10. |
| [ghosts.md](ghosts.md) | Ghost upload and download: the formats and what the game accepts. |
| [speed-weekend.md](speed-weekend.md) | The weekend event: `beaten`, `viewed`, race reports, game mode numbers. |
| [ranked-xp.md](ranked-xp.md) | Rank and XP: the decoded formula, the 12-byte matchmaking blob and the stats blob. |
| [game-data.md](game-data.md) | The game's own files (`ms2.psarc`) and the option that sets the SVO address. |
| [announcements.md](announcements.md) | The in-game announcement feed. |
| [archive/](archive/README.md) | The notes and reports of the first rounds, with a map from their old paths to the current ones. Superseded by the documents above, kept for the reasoning. |
| [v103/](v103) | Raw material of EBOOT v1.03: strings, function list, function-to-string map, cross references, the Medius message registry, and the first decompiled functions (`decomp/`). Searchable with any text tool. |
| [earlier/](earlier) | Raw output of the first rounds: Ghidra findings and post-scripts, Medius stream dumps, handshake notes, string lists. |

## Conventions

- The game binary, the Ghidra project and the raw captures are not here. Paths in the text that look like `analysis/...` or `captures/...` name files in this repository when they exist; the others name files of the original local work folder.
- Addresses are virtual addresses of the decrypted v1.03 EBOOT (TOC base `r2 = 0x208958`).
- Names of functions and classes that were derived from RTTI or strings are facts; names given by hand (`ApplyMSPRNames.py` in `tools/re/ghidra/`) are marked as verified or as guesses in the reports.

## Reproducing

1. Decrypt your own copy of the EBOOT (v1.03) and put it in a work folder; see [tools/legacy/README.md](../tools/legacy/README.md) for the layout.
2. The maintained tools are in [tools/re](../tools/re): `reanalyze.py` and `ghidra_decompile.py` (headless Ghidra), `xref_eboot.py`, `medius_registry.py`.
3. To read your own traffic use [tools/mspr_capture](../tools/mspr_capture) (passive) or [tools/mspr_proxy](../tools/mspr_proxy) (man-in-the-middle for your own client).
