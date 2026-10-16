# MSPR PROJECT — COMPLETE STATUS REVIEW

**Historical snapshot.** Everything below describes the project at the time of the snapshot: the percentages, the "what does not work yet" lists and the file paths (see [README](README.md) for the old-to-new path map) are not the current state.

Where things stand now: the SVO routes, the Medius matchmaking for Ranked and Casual and the race are implemented and played with the real game (RPCS3, and first tests with a real PS3); ghost download, Speed Weekend and the NP ticket signature are decoded. The Ghidra work covers the v1.03 EBOOT (10,740 functions, the verified names are in `tools/re/ghidra/`). Read [reverse-engineering.md](../reverse-engineering.md), [findings.md](../findings.md) and the open items in the [README](../../README.md).

## The first days, stage by stage

The stages follow each other in time, oldest first. The numbers only give the order.

## Stage 1 — the own server works end to end with the test client

(Paths in this section are from before the folder redo: now server\scripts\ and server\medius\.)
RPCS3: the MSPR config's DNS = this PC's IP (or `Start-MSPRServer.ps1 -UseLocalRPCS3`).

Verified (server\e2e_check.py + server\medius_testclient.py, MSPR's own CLIENT_HELLO from a capture,
real PS3 SCERT crypto):
- DNS motorstorm2ps3.online.scee.com -> server
- MUIS :10071 handshake identical to PS Rewired (C24 S25 C12 S13 C00 S07 C21 S1a), SvoURL message 151 B
  like PS Rewired
- MAS :10075 ExtendedSessionBegin->50 B, SetLocalizationParams1->30 B, TicketLogin (RPCN NP ticket)->227 B —
  the same sizes as PS Rewired
- MLS :10078 handshake with session key + access token (CONNECT_TCP 106 B)
- SVO :10060 all 68 captured requests replayed -> X-SVOMac correct, same XML structure

Findings:
- The earlier "DNS error" = RPCS3's DnsHook got no answer (our DNS was not running). The game never
  reached Horizon; the ~40 MAS/MPS connections in the logs were Horizon's own DME.
- SVO responses need X-SVOMac = md5(clientMac + "sp9ck0348sld" + 20×"0") (68/68 match).
- PS Rewired uses the public default SCERT key (the same as Horizon's DefaultKey). The client's RSA key is
  per session -> the RC keys of the PS Rewired capture cannot be decrypted; against our own server
  everything decrypts (Horizon log, HORIZON_VERBOSE=1).
- MSPR = Medius 1.13 (PS3), app 21624; PS Rewired answers CONNECT_TCP directly with CONNECT_ACCEPT_TCP
  (no CONNECT_REQUIRE).
- Horizon.dll embeds its dependencies (Costura) -> after CastleLibrary/HorizonService changes always run
  `dotnet build Horizon.csproj -c Release --no-incremental`.

Changes to PSMultiServer:
- MUIS.cs: 21624 -> CONNECT_ACCEPT_TCP; MAS/MLS/MPS/MMS: 21624 added to the ConnectAcceptTCPGames list
- MuisClass.cs + static\muis.json: SvoURL http://<ip>:10060/motorstormpr/index, NATIp = own IP
- MediusUniverseSvoURLResponse.cs: 21624 -> fixed 128 B URL (later: varint length, see ranked-casual.md)
- RT.Models\VerboseLog.cs: HORIZON_VERBOSE=1 logs every decoded message (release build)
- XI5Ticket.cs: HORIZON_XI5_IGNORE_EXPIRY=1 (tests only; the signature is still checked)

New files: server\scert_crypto.py, medius_testclient.py, medius_ids.py, e2e_check.py, run_horizon.cmd,
Stop-MSPRServer.ps1, fixtures\svo\*; tools\extract_svo_fixtures.py, tools\extract_medius_streams.py
(-> re\medius_streams\); tests\test_svo_replay.py. server\mspr_server.py rewritten (PS Rewired compatible SVO).

Next step: the real game against our own server -> Horizon.log shows every decoded message (MLS lobby,
custom game, DME). After that ranked/casual (MMS).

## Stage 2 — Ranked and Casual worked out and implemented

Folder layout: see README.md. Paths: `server\scripts\Start-MSPRServer.ps1`,
`server\scripts\Stop-MSPRServer.ps1`, test `server\medius\e2e_check.py`.

- EBOOT 1.03 decrypted: `rpcs3 --decrypt` -> `re\v103\EBOOT.elf` (NPDRM, unself does not work)
- Two TOCs (0xe977a8 / 0xea7770) -> the xref, Ghidra and registry tools support both
  (`tools\xref_eboot.py`, `tools\ghidra_decompile.py`, `tools\medius_registry.py`)
- Ranked/casual fully worked out: docs\ranked-casual.md. On PS Rewired ranked does not work because the
  MLS refers to the MMS at the LAN address 192.0.2.11:10079.
- Implemented in Horizon: MsprMatchmaker (supersets 1+2, MatchPartyRequest2 -> the server creates a DME
  world -> JoinAssignedGame), correct 0x5E/0x60 messages, persistence of accounts + the stats blob
  (static\mspr_accounts.json). e2e_check: the whole chain OK.
- The in-game ranked leaderboard = RPCN NP Score (works with RPCN as is).
- Open: real game -> JoinGame/DME race, the field layout of the stats blob (XP) for SVO ranked.

## Stage 3 — the TypeScript server

- Architecture: Horizon (C#) = Medius/DME, `server-ts/` (TypeScript/Node) = SVO + DNS + status web.
- server-ts: node:sqlite database (accounts, races), EULA/announcement as text files
  (`server-ts/config/eula.txt`, `announcement.txt`), an EULA change forces re-acceptance, the status page
  :8080 reads Horizon's `/GetRooms/` (port 61920). 71 tests OK.
- The Start/Stop scripts use server-ts; the Python SVO/DNS moved to `server/legacy/python/`.
- Useful from PSMultiServer: Horizon CRUD `/GetRooms/` (in use). Next big step: Horizon's DB middleware API
  (db.config.json DatabaseUrl) implemented in server-ts -> one SQLite for accounts + Medius stats.

## Stage 4 — the ready package

- One database: Horizon's MSPR accounts + Medius stats -> server-ts SQLite (loopback API /horizon/accounts),
  the same account id for SVO and Medius; JSON backup if the API is down.
- Public hosting: Start -PublicIp auto|x.x.x.x (Horizon UsePublicIp/PublicIpOverride + DNS).
- Packaging: INSTALL/START/STOP-MSPR.cmd, Install-MSPR.ps1, Build-Package.ps1 -> dist\*.zip; the package
  was tested in a clean folder: install + start + e2e OK.
- Fixed bug: the INSERT of a new account failed after the column migration (test added, 72/72).
- User guide: docs\getting-started.md.

## Stage 5 — the folder layout redone

Root: `MSPR-Server/` (ready runnable server + `MSPR-Server-<date>.zip`), `source/` (source code: server-ts,
PSMultiServer, server), `research/` (re, captures, tools, mspr_capture), `docs/`, `_archive/`.
See README.md. Paths in the sections below are old: re\ -> research\re\, server\ -> source\server\.
- Fixed: Horizon's absolute paths in horizon.json/medius.json -> the start script fixes them on every start
  (without this a moved package did not read its own configs, e.g. -PublicIp did not work). Tested.
- e2e_check restores the test account's original stats (the captured ticket = a real player account).
- Build-Package updates MSPR-Server and keeps the database, config and EULA.

## 1. WHAT IS DONE

### Network research (100% at the snapshot)
- The PS Rewired protocol fully documented (captures\REPORT-*.md)
- MSPR's online architecture mapped as 3 layers
  * SVO/HTTP :10060 (login/EULA/leaderboards/finishGame) — FULLY DOCUMENTED
  * Medius :10071/10075/10077 (lobby/matchmaking, SCERT-encrypted)
  * DME :11001 + TCP/UDP 50000 (game session, SCERT-encrypted)
- The finishGame stats schema complete (bestTime, laps, wrecks, jumps etc.)
- The leaderboard XML format known
- The URL_List mechanism: the server tells the routes, the client does not hardcode them

### Game binary RE (80% at the snapshot)
- EBOOT.BIN decrypted (unself + ps3keys) -> re\EBOOT.ELF
- 2059 protocol strings categorised (re\FULL_STRINGS.md)
- 353 matchmaking strings (re\matchmaking_flow_strings.txt)
- 145 ranked/casual strings with addresses (re\ranked_casual_strings.txt)
- The matchmaking flow mapped (StartMatchMaking -> GotMatchMakingTicket -> ROOM_IN_* -> MatchMadeGameTypeString)
- C++ symbols present (evo::online::SVO*, Medius* classes)
- Ghidra project with 10740 functions (re\ghidra_proj\MSPRFINAL2)
- TOC base solved: 0x208958 (tools\final_extract2.py)

### Tools (100% at the snapshot)
- mspr_capture v0.2: passive network capture (17/17 tests)
- mspr_status.py: public API monitoring
- unself.exe: PS3 SELF decryption (Windows)
- strings_scan.py, eboot_analyze.py, mm_functions.py, final_extract2.py
- ranked_casual_strings.py, medius_handshake.py, full_strings.py
- Ghidra + PyGhidra installed and working

### PSMultiServer (build done, configuration in progress)
- Horizon (Medius MAS/MLS/MPS/MUIS/MMS/DME/NAT/BWPS) — 0 errors
- SVO — 0 errors
- MSPR (21624) in Horizon's CompatibleApplicationIds list ✓
- MotorstormPR2.cs = ready MSPR SVO implementation
- CRYPTKEY_GAME handlers added (MAS.cs, MPS.cs, MASClient.cs, MPSClient.cs)
- natservice.pdonline.scea.com + title.pdonline.scea.com -> hosts

### Own SVO server (works)
- server\mspr_server.py :10060 — every endpoint, catch-all, JSON db
- server\mspr_dns.py :53 — MSPR domains + wildcard source
- server\medius_replay_stub.py — handshake replay (obsolete, Horizon replaced it)

## 2. What did not work at the time of the snapshot (all solved since)

The snapshot listed four open problems and a plan of four steps with working-hour estimates. All of them are done; the table says how they ended.

| Open at the snapshot | How it ended |
|---|---|
| Ranked and Casual: no implementation anywhere, and they did not work on the original service either (its MLS pointed the game to a LAN address of the MMS, see Stage 2) | Worked out from the EBOOT and implemented in Horizon (`MsprMatchmaker`); played with the real game, see Stage 2 and [reverse-engineering.md](../reverse-engineering.md). |
| The game closed the Medius connection right after the SCERT handshake (cause unknown) | Not reproduced since. Stage 1 found that the game had never reached Horizon in those tests (the connections in the log were Horizon's own DME), so this was probably a misreading of the same missing-DNS problem. Against the replacement server the game completes the handshake and reaches the lobby. The cause was not confirmed separately. |
| The SVO flow stopped after `getRegion` with a DNS error | Solved: Stage 1 found the cause (the emulator's DNS hook got no answer because the replacement DNS was not running), and the whole flow from `index` to the leaderboards and the results runs against the replacement server, see [reverse-engineering.md](../reverse-engineering.md). |
| A DME session for a Custom Game | Works, as do the Ranked and Casual races. |

## 3. The plan of the snapshot (done)

Step 1 finish the SVO flow, step 2 the Medius handshake, step 3 the DME game session, step 4 Ranked and Casual. All four steps are complete. What is still open today is listed in the [README](../../README.md).

## 4. The files of the snapshot, and where they are now

The snapshot listed the files of the original local work folder. None of those paths exist in this repository; this is where the material went.

| In the snapshot | Now |
|---|---|
| `captures\REPORT-ranked-*.md`, `REPORT-custom-*.md` | [REPORT-ranked-capture.md](REPORT-ranked-capture.md), [REPORT-custom-capture.md](REPORT-custom-capture.md) in this folder |
| `captures\mspr-*.pcapng` | Not published (other players' names). The redacted summaries and HTTP objects are in [`captures/`](../../captures). |
| `mspr_capture\` | [`tools/mspr_capture/`](../../tools/mspr_capture) |
| `server\mspr_server.py`, `mspr_dns.py`, `medius_replay_stub.py`, the start script, `data\mspr_server.json` | Gone: the first Python server was replaced by the TypeScript server in [MSPR-Server](https://github.com/ZoniBoy00/MSPR-Server) (not part of this repository). |
| `PSMultiServer\` (Horizon and SVO, .NET 6) | The Horizon part lives in MSPR-Server (`horizon/`, now on .NET 10); the SVO of PSMultiServer is not used. |
| `re\EBOOT.ELF`, `EBOOT.BIN`, `ghidra_proj\` | Not published: the game's own code and a very large project. Decrypt your own copy, see [tools/legacy](../../tools/legacy/README.md). |
| `re\FULL_STRINGS.md`, `ranked_casual_strings.txt`, `matchmaking_flow_strings.txt`, `medius_10071_dialogue.txt`, `medius_handshake.txt` | [`analysis/earlier/`](../earlier) |
| `re\ghidra_findings\` | [`analysis/earlier/ghidra_findings/`](../earlier/ghidra_findings) and, for the later work, [`analysis/v103/`](../v103) |
| `re\RE-FINDINGS.md`, `RANKED-CASUAL-DESIGN.md`, `EMULATION-SERVER-BLUEPRINT.md` | [RE-FINDINGS.md](RE-FINDINGS.md), [RANKED-CASUAL-DESIGN.md](RANKED-CASUAL-DESIGN.md), [EMULATION-SERVER-BLUEPRINT.md](EMULATION-SERVER-BLUEPRINT.md) in this folder |

## 5. Starting the stack

The commands of the snapshot (two Python scripts and `Horizon.exe` from a .NET 6 build) no longer apply. The current server is started as described in the [getting-started guide of MSPR-Server](https://github.com/ZoniBoy00/MSPR-Server/blob/main/docs/guides/getting-started.md).
