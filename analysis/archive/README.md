# analysis/archive

The notes and reports of the first rounds of the work. They are **historical**: they show how the protocol was found out and in what order, including conclusions that were later corrected (the notes say where). For the current state read [reverse-engineering.md](../reverse-engineering.md) and [findings.md](../findings.md).

| File | What it is | Replaced by |
|---|---|---|
| [RE-FINDINGS.md](RE-FINDINGS.md) | The first notes on the EBOOT: strings, the TOC base, the Medius handshake. | [reverse-engineering.md](../reverse-engineering.md) |
| [REPORT-ranked-capture.md](REPORT-ranked-capture.md), [REPORT-custom-capture.md](REPORT-custom-capture.md) | What the first two captures (a Ranked and a Custom Game session) showed. | [reverse-engineering.md](../reverse-engineering.md), [captures](../../captures/README.md) |
| [EMULATION-SERVER-BLUEPRINT.md](EMULATION-SERVER-BLUEPRINT.md) | The plan for a replacement server, written before one existed. | The server repository, [MSPR-Server](https://github.com/ZoniBoy00/MSPR-Server) |
| [RANKED-CASUAL-DESIGN.md](RANKED-CASUAL-DESIGN.md) | The design of Ranked and Casual matchmaking. | [reverse-engineering.md](../reverse-engineering.md) |
| [status-history.md](status-history.md) | A progress snapshot and the log of the first days. Its percentages, "what does not work yet" lists and file paths describe that moment only. | The open items in the [README](../../README.md) |

## Old paths in these notes

The notes were written in a local work folder with a different layout. Read the old paths like this:

| In the notes | Now |
|---|---|
| `re\`, `re\v103\` | [`analysis/earlier/`](../earlier) and [`analysis/v103/`](../v103) |
| `tools\<script>.py` of the first rounds | [`tools/legacy/`](../../tools/legacy) |
| `tools\xref_eboot.py`, `ghidra_decompile.py`, `medius_registry.py`, `extract_*.py` | [`tools/re/`](../../tools/re) |
| `captures\` | [`captures/`](../../captures) |
| `server\`, `docs\`, `research\`, `source\` | the [MSPR-Server](https://github.com/ZoniBoy00/MSPR-Server) repository (not part of this one) |
