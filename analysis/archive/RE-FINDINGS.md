# MSPR reverse engineering findings (static analysis, own copy)

Research notes (historical; some
conclusions were later revised, see the notes in sections 8–9)

Source: decrypted `EBOOT.ELF` (PS3 ELF, PowerPC). Analysis: static strings and RTTI/C++ symbols only —
no code execution, no crypto extraction. Tools: `tools/unself` (fail0verflow ps3tools
build), `tools/strings_scan.py`, `tools/eboot_analyze.py`.

## 1. Architecture of the online stack (confirmed)

MSPR online = three independent systems:

| Layer | Protocol / class | Transport | Notes |
|---|---|---|---|
| Web services | **SVO** (`evo::online::SVOManager`, `SVOAction*`) | HTTP, port 10060 | login/EULA/leaderboards/finishGame — all XML, no payload encryption |
| Lobby & matchmaking | **Medius** (`MediusLogin`, `MediusGetPlayerInfo`, `MediusAccountUpdateStats`...) | TCP 10071/10075/10077 | the classic SCEA/Sony Online middleware; this is what PS Rewired emulates for other games too |
| Race session | custom evo session | TCP+UDP 11001 | encrypted payload (SCERT-style) |

Key string: `$svohttphttpsbuildidentifier: svoclient-nightly-3.03.200806061111 $`
→ SVO client library v3.03 (June 2008 nightly).

## 2. Crucial finding: endpoint routes are server-provided

The client does **not** hardcode `/motorstormpr/*` paths. It requests a `URL_List` from the server at
login (`index?languageID=1` response, already captured in `http_objects/`). A server emulator must
therefore serve the URL_List exactly as PS Rewired's does — every route name the client knows:

```
ticketLogin, finishGameURI (/game/finish),
leaderboard/timeattack, leaderboard/speed, leaderboard/ranked, leaderboard,
getRegion, getEula, acceptEula, getAnnouncement
```

## 3. Medius layer (lobby/matchmaking) — observed symbols

Login with NP ticket (`MediusLogin`, `MediusNPlogin`), account stats (`MediusAccountUpdateStats` → matches
the 256-byte public-API stats blobs), player info, game worlds per lobby world, ban/privilege checks.

Matchmaking states observed: `ROOM_IN_MATCHMAKE`, `ROOM_IN_MATCHMAKE_NOMATCH`, `ROOM_IN_CASUAL_STANDARD`,
`ROOM_IN_CASUAL_ELIMINATOR`, `CustomGameCreated`, `CheckMatchMakingAutoStart`, `GotMatchMakingTicket` —
i.e. casual/ranked matchmaking logic is fully present in the client; only the server side is missing on
PS Rewired today (consistent with `allowedRanks: 0`).

## 4. Leaderboard internals

`FillRankedLeaderboardTable`, `GetTopLeaderboard`, `GetPlayerPositionLeaderboard`,
`GetFriendlistLeaderboard`, `DownloadGhostFromLeaderBoard`, `ProcessTimeAttackScoresForNpLeaderboard`,
`LeaderboardIsRanked` — the client supports ghosts (`GetGhost`, `ghostAvailable`) which the server hands
out on request.

## 5. Stats reporting

`SVOActionPostStats` + `finishGame` (HTTP) → the form schema documented in `REPORT-custom-capture`.
`MediusAccountUpdateStats` → the 256-byte blobs published on the public API. Field-name mapping between
them is the next analysis target (Ghidra on the PostStats/Medius functions).

## 6. What was NOT done

- No keys extracted, no crypto implementation, no payload decryption
- No Ghidra/REA decompilation yet (next phase if SCERT/Medius framing is needed)
- `ms2.psarc` (4.8 GB game archive) untouched

## Reproduce

```
python tools\strings_scan.py re\EBOOT.ELF
python -X utf8 tools\eboot_analyze.py    # -> re\analysis_report.md
```

## 7. Ghidra analysis status

Achieved:
- EBOOT.BIN decrypted (unself + ps3keys) -> re\EBOOT.ELF
- Ghidra 12.1.4 headless pipeline built; the ELF loader's OPD crash worked around in two ways: section
  names (EBOOT.ghidra.elf) and e_shnum=0 (EBOOT.nosec.elf)
- Raw import + Binary Loader + PowerPC:BE:64:A2ALT works (tools\mspr_ghidra_driver.py)

Not solved (task for the next session):
- String references are not direct addis/lwz pairs with TOC candidates, nor 32/64-bit absolute pointers
  -> references probably go through the PS3's own TOC/OPD structure, which needs a Ghidra PS3 loader
  extension (community versions handle OPD+TOC automatically) or REA's native analysis on top of Ghidra.

Files: re\EBOOT.ELF, re\EBOOT.ghidra.elf, re\EBOOT.nosec.elf, re\strings_decrypted.txt,
re\analysis_report.md, re\ghidra_scripts\*, tools\unself.exe (Windows build of fail0verflow ps3tools).

## 8. BREAKTHROUGH: TOC base solved

**TOC base = 0x208958** (verified: TOC entry 0x208dd4 = toc+0x47c holds a 32-bit pointer to the string
0xe013bd, exactly as the decompiled code `lwz rX, 0x47c(r2)` requires).

Mechanism: PS3 EBOOT data references = 32-bit pointers in TOC entries, the code reads `lwz rX, off(r2)`.
Strings are not found by a direct pointer search because the reference goes through the TOC entry
(double indirection).

Tool: tools\final_toc_extract.py
- scans every lwz/addi rX, simm(r2) + addis/lwz pair
- resolves TOC entry -> 32-bit pointer -> string
- produces string_xref_map.txt (function -> referenced strings)

Status: 3 functions decompiled (ghost download handling 0x2042c4/4428/a04). FULL coverage still needs
handling of `addis r2, r2, hi` TOC window moves (r2 moves from function to function; a 32 KB window does
not cover the whole data area). That is a direct extension of this script.

Summary of the emulator path: the SVO/HTTP layer is documented (captures), the Medius layer = public
Clank/Horizon code + this binary with its references, the race session (11001) = SCERT, left to be
decompiled with the same TOC tool.

*Later : the v1.03 EBOOT has several TOC ranges; `tools/re/xref_eboot.py` resolves
them per function.*

## 9. Final report: what was found, what is left to dig

### Confirmed mechanisms (tools work)
- TOC base 0x208958, TOC entries are 32-bit pointers, code `lwz rX, off(r2)`
- final_extract2.py: 5660 string-pointing entries, 74 code references
  (ghost download functions 0x2042c4/4428/a04 decompiled)

### Key finding: the Medius strings in the EBOOT are DEAD COPIES
- Not a single 32/64-bit pointer (tagged or not) to any Medius string; no addis pairs; no r2 references
- Conclusion: the live Medius client is a separate PRX module
  -> probably inside ms2.psarc (PSARC v1, 536,696 entries, 4.8 GB)

*Later : this conclusion was wrong. With the per-function TOC ranges of the v1.03 EBOOT the
Medius client library is found in the EBOOT itself (registry at 0x66af00, 275 messages) and was
decompiled; see ../ranked-casual.md.*

### Next dig (follow-up session)
1. Unpack ms2.psarc (psarc tools: python-psarc / PSARC extractor)
2. Find the .sprx/.prx modules (Medius/SVO clients) -> unself -> Ghidra
3. The same TOC analysis for them -> MediusLogin/PostStats pseudocode
4. Adapting the Clank/Horizon servers to MSPR's Medius version

### Raw material for the emulator server, NOW saved
- SVO/HTTP: complete (captures + URL_List + finishGame schema)
- Medius: error codes, states, session key format (FULL_STRINGS.md) + public Clank/Horizon code
- Race session 11001: ports/profile known, SCERT framing left to dig

## 10. MEDIUS HANDSHAKE FULLY DOCUMENTED

Source: re\medius_10071_dialogue.txt (PS Rewired capture, port 10071, complete conversation of
18 packets) + re\medius_handshake.txt (all ports).

Handshake structure (SCE-RT/Medius, SCERT encryption):
1. S->C  2 B    00 00 (greeting)
2. S->C  6 B    zeros (RT header)
3. S->C  536 B  SCERT certificate (X.509, RSA SHA1, SCEE SCERT Group1 / SCERT Root Authority,
                valid 2005-2035). RT header: 25 f1 02 71 | 00 00 | 06 e7 (length)
4. S->C  220 B  encrypted key exchange
5. S->C  6 B    header
6. S->C  71 B + 31 B encrypted messages
The client answers with its 785-801 B certificate (the same structure on every port; the port only
affects the state: 24 0e / 24 1e = port-specific id).

The code needed for building it already exists:
- SCE-RT/Medius message formats: hashsploit/clank (Java)
- RC4-SHA1 encryption: PSOnlineReturnalGaming/uya-medius-encryption (C#)
- Server components (MAS/MLS/MUIS/DME/NAT): Horizon/PSMultiServer (C#)
- MSPR ports: 10071=MAS?, 10075=MLS?, 10077=channel?, 11001=DME, 10060=SVO HTTP

*Later : actual ports: 10071 = MUIS, 10075 = MAS, 10077 = MPS, 10078 = MLS, 10079 = MMS,
10073 + UDP 50000 = DME. MSPR uses Medius 113 with CONNECT_ACCEPT_TCP.*
