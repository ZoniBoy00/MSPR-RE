# MSPR-RE

Reverse engineering of the online code of **MotorStorm: Pacific Rift** (PS3, EBOOT v1.03): how the game finds its servers, what it sends and what it expects back. The results are what made the private server [**MSPR-Server**](https://github.com/ZoniBoy00/MSPR-Server) possible; the two repositories belong together (the server implements what is documented here).

You can use this repository in three ways:

| I want to… | Go to |
|---|---|
| **Understand the protocol** (DNS, SVO, Medius, DME, tickets, ghosts, ranks) | [analysis/](analysis/README.md), start with [reverse-engineering.md](analysis/reverse-engineering.md) |
| **Look at real traffic** (redacted) | [captures/](captures/README.md) |
| **Analyse the game or my traffic myself** | [tools/](tools/README.md), [tools/legacy/](tools/legacy/README.md) for the first-round scripts |

## Layout

| Folder | Contents |
|---|---|
| [`analysis/`](analysis/README.md) | The written reports (current ones at the top level, `archive/` for the dated first-round notes) and the raw material: `v103/` (strings, function list, xrefs, Medius registry, first decompiled functions) and `earlier/` (Ghidra output, stream dumps). |
| [`captures/`](captures/README.md) | Redacted summaries of a Ranked and a Custom Game session, the HTTP objects extracted from them and request-log excerpts of a running server. Other players' names and ids are replaced by placeholders. |
| [`tools/`](tools/README.md) | `mspr_capture` (passive capture and Medius decoder), `mspr_proxy` (man-in-the-middle for your own client), `scert` (SCE-RT crypto), `re` (current Ghidra/EBOOT tools), `game-data` (read and patch `ms2.psarc`), `legacy` (first-round scripts), `tests`. |

## Quick start

```
pip install -r requirements.txt
cd tools && python -m pytest        # 21 tests of the capture tool and the proxy
```

Reading needs nothing but a text viewer. Running the EBOOT analysis needs your own decrypted EBOOT in a work folder (default `work/`, see [tools/legacy/README.md](tools/legacy/README.md)); no script has a machine specific path, the locations come from `MSPR_RE_WORK`, `GHIDRA_INSTALL_DIR` and `MSPR_PCAP`.

## Not included

- The game binaries (EBOOT.BIN, ELF files) and the Ghidra project: copyrighted or very large. Decrypt the EBOOT from your own copy of the game to reproduce the analysis.
- The raw packet captures (`.pcapng`): they contain other players' account names. Redacted summaries are in `captures/`.
- Extracted game data (`ms2.psarc` contents).

## What is solved

- The whole login-to-race path: DNS, SVO routes, Medius/SCERT handshake, matchmaking messages for Ranked and Casual.
- Ghost download: the game asks `GET leaderboard/ghost?...` and accepts `<ghost><data>BASE64</data></ghost>` ([ghosts.md](analysis/ghosts.md)).
- `speed-weekend/beaten` and `viewed`; game mode 11 is the Speed Weekend ([speed-weekend.md](analysis/speed-weekend.md)).
- Weekend race reports: `won`, `position` (100 = not finished), the extra bookkeeping report.
- NP ticket layout and signatures (RPCN secp224k1/SHA-224, PSN secp192r1/SHA-1), checked against real RPCS3 tickets ([findings.md](analysis/findings.md)).
- Rank and XP: formula, the 12-byte matchmaking blob and the stats blob ([ranked-xp.md](analysis/ranked-xp.md)).

## Open items

1. A real PS3: its PSN ticket against the signature check, why its Ranked results arrive only at the next SVO login.
2. The answer the game expects to `myPosition=true`. (The text of the "beaten" notice and the numbering of `vehicle` are settled by the game's text and vehicle tables, see [game-data.md](analysis/game-data.md).)
3. Real stats blobs, to confirm the counters behind rank and XP.
4. The Speed Weekend (game mode 11): the event specifics (tickets, targets, schedule) and whether a race posts a ghost (the races seen had none). The Volcano Weekend (game mode 10) is only inferred from the game's strings and has never been raced.
5. Ticket version 4.0 (an unsolved hash); a real 6-player Ranked race.

## Built with AI assistance

Large parts of the analysis, the tools and the documentation were written with [Claude](https://claude.com/claude-code) (Anthropic), working under the direction of the maintainer, who supplied the captures and ran the game tests. See [CREDITS.md](CREDITS.md). Findings are tagged with their evidence (`[EBOOT]`, `[CAPTURE]`, `[LIVE]`, `[INFERENCE]`) so that observation and conclusion can be told apart. If you find a mistake, please open an issue.

## Licence

GPL-3.0, see [LICENSE](LICENSE). Not affiliated with or endorsed by Sony Interactive Entertainment or the developers of the game; MotorStorm is a trademark of its owners. Interoperability research on software you own.
