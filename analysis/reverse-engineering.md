# MSPR v1.03 reverse engineering: status and findings

This report combines the static analysis of the v1.03 EBOOT, the current Horizon and TypeScript server code, the earlier PS Rewired captures and the existing tests.

Evidence tags: **[EBOOT]** static game binary or its decompilation; **[CAPTURE]** network capture; **[SOURCE]** behaviour of the current server code; **[LIVE]** a reported test with the real game in RPCS3; **[INFERENCE]** a conclusion that no capture proves separately.

The game binary, the Ghidra project, the decompiled sources and the raw captures are not in this repository; paths such as `analysis/...` name files of the original local project.

## Summary

The server path is implemented and the game reaches the Ranked/Casual race lobby from login in RPCS3, plays a two-player race and returns to the lobby. The SVO request and response formats, the main matchmaking messages and the internal matchmaking code are documented in some detail. The reverse engineering is not complete, though: the game's in-race DME datagrams are not decoded, not all of the 10,740 Ghidra functions are named, and races with more than two players are not tested.

One finding from code review, reproduced by reading the code and not yet by a live test: `MsprMatchmaker.OnCancel` removes the waiting ticket but always reduces the reservation by one instead of by the size of the cancelled party, and it does not remove the party from the `Parties` list. Once the world has been created, cancelling an assigned ticket no longer finds a waiting ticket at all. That can leave capacity and roster numbers wrong.

## 1. Network layers and message meaning

| Layer | Direction and job | What is known |
|---|---|---|
| DNS | Game to the local MSPR server | Points the game's original server names at the private server. **[SOURCE]** DNS answers and the IP form of the SVO address are implemented. |
| SVO HTTP, default port 10060 | Game to `server/` | Plain HTTP requests and XML answers: ticket login, EULA and announcement, leaderboards and `finishGame`. `X-SVOMac` is checked on the response side. **[CAPTURE/SOURCE]** |
| Medius (MUIS, MAS, MLS, MMS) | Game to Horizon, TCP, SCERT-protected | Account login, joining the lobby, matchmaking supersets, the referral to MMS, the assigned game world, and the return to the MLS lobby. **[CAPTURE/EBOOT/SOURCE]** |
| DME | Game to Horizon DME, client-server plus UDP | Creates the game world and relays race data. The matchmaking answer carries the world id, DME address, host type, application data and party rosters. The application-specific fields of the in-race datagrams are not decoded. **[CAPTURE/SOURCE]** |

### Matchmaking messages

All requests and responses below are in the Medius LobbyExt class (class 4); SCE-RT framing and encryption are the outer layer. Sources: `analysis/v103/medius_registry.json`, `analysis/v103/decomp/match_wire.c`, Horizon's `RT.Models/Lobby/` classes and `SERVER/Medius/Mspr/`.

| Type | Direction | Contents and purpose |
|---|---|---|
| `0x5D MatchGetSupersetListRequest` | game to MLS/MMS | MessageID and SessionKey. The game asks which matchmaking supersets exist. |
| `0x5E MatchGetSupersetListResponse` | MLS/MMS to game | MessageID, status, EndOfList, SupersetID, an unknown field, and length-prefixed name, description and extra info. The server offers supersets 1 and 2 (`MSPR_1`, `MSPR_2`). |
| `0x78 MatchPartyRequest2` | game to MLS first, then MMS | MessageID, SessionKey, SupersetID, PartySize, MinGameSize, MaxGameSize, MatchOptions, ApplicationDataSize, account ids and application data. A one-player request is documented as 80 bytes. MSPR's 12-byte application data starts with the ranked flag and carries an average rank value that the server does not use for matching. |
| `0x60 MatchPartyResponse` | MLS/MMS to game | MessageID, status and plugin status. Status 8 = Referral, 6 = JoinAssignedGame, 1 = NoResult; 7 HostGame is ignored. Referral carries MMS's `NetConnectionInfo`. JoinAssignedGame carries the world id, password, host type, address lists, application data and the party roster. |
| `0x71 JoinLeastPopulatedChannelRequest` | game to MMS | MessageID, SessionKey, a flag. The game asks which lobby to return to after the match. |
| `0x72 JoinLeastPopulatedChannelResponse` | MMS to game | Status, lobby/world id and MLS connection info. The client leaves MMS and rejoins MLS. |
| `MatchCancelRequest` | game to MLS/MMS | MessageID, SessionKey, SupersetID. Horizon calls `OnCancel`; see the reservation/roster inconsistency above. |

The field order and serialisers of `0x5E` and `0x60` are in `MsprMessages.cs`. The messages are packed: integers are little-endian and byte fields are not padded. The contents of a Medius message class are not the same as the outer SCERT packet.

Since this report was written, the game list filters have been completed as well: Custom Game lobbies are listed through `MediusGameList_ExtraInfoRequest` with the filters `MATCH_MAKING_GAMES = 0` and `GENERIC_FIELD_5 = 1`, which Horizon now evaluates.

## 2. Matchmaking life cycle

```text
The game chooses Ranked or Casual and sets the flag
  -> MLS MatchGetSupersetList (0x5D) / response 0x5E
  -> MLS MatchPartyRequest2 (0x78)
  -> MLS Referral (0x60, status 8) gives the address of MMS
  -> the game switches to MMS and sends 0x78 again
  -> MMS creates a DME world for the first party
  -> DME/MPS confirms the creation
  -> MMS returns JoinAssignedGame (0x60, status 6)
  -> the game asks for the return lobby with 0x71 / receives 0x72
  -> the game goes back to MLS and joins the assigned world
  -> the race lobby starts by the game's own rules; the game moves to the DME race
  -> the result is reported to SVO with finishGame
```

**The matching key in the server code [SOURCE]:** requests are bucketed by `SupersetID` and the `ranked` flag, as long as the reserved player slots do not exceed the request's maximum (at most 12). The party's account id list is reserved as a whole. The first request creates the world; later requests are added to its waiting list or assigned to the already created world. A bucket whose world has ended (for example after the lobby timer ran out) is dropped at the next request.

**Conditions the code does not use:** average rank, player skill, map, lap count, or application data other than the first ranked byte. Region is not part of the bucket key; the DME is chosen with the application and location values of the first party's host. Rank-based or region-based matching is therefore neither shown nor implemented. Superset 1 or 2, the ranked flag and the maximum slot limit are the only explicit separators.

**Player counts [EBOOT]:** in the client's request MinGameSize is 4 for Casual and 6 for Ranked, MaxGameSize 12. The server uses the first request's minimum when it creates the world. The test setting `MSPR_MM_MIN_PLAYERS` changes the advertised minimum. The game's own race auto-start conditions are in the client's `CheckMatchMakingAutoStart` logic. **[LIVE]** With fewer players than the minimum the race lobby's 30-second timer ends the game and the players return to the menu; each player's timer runs from the moment that player joined.

**Cancel, timeout and leaving:** the client's strings show `CancelMatchMaking`, `CancelMatchMakingAndLeaveGroup` and timeout and race lobby states. Horizon's cancel handler removes the waiting ticket only from the `Waiting` list. An open bucket expires after 10 minutes, but old buckets are cleaned up while handling a request, not by a timer. A player's connection dropping or leaving after assignment has been verified for the two-player case only.

## 3. Ranked/Casual selection and race data

- The client sets the Ranked or Casual flag and builds `MatchPartyRequest2`. The client's ticket and GUI strings cover the track, vehicle, laps, the standard/eliminator type and requirements such as rank, skill, speed and aggression. **The strings show that the features exist; they do not by themselves show the network fields or the selection algorithm.**
- The matchmaking server classifies a request as casual or ranked by the first byte of the application data, groups by superset and creates the DME world. It does not compute rank distance, apply a skill limit or filter by map.
- Ranked XP, wins, streaks and disconnects appear among the client's stat field strings. The 256-byte internal field map of the stats blob is still unfinished.
- **Ranked leaderboard [LIVE].** An earlier version of this report said the game's Ranked board comes from RPCN/PSN NP Score and that SVO answers with an empty frame. That was wrong. The game requests `/motorstormpr/leaderboard/ranked?...&stat.score=1&stat.playersBeaten=1`, and its `finishGame` report carries `score`, `playersBeaten`, `won` and `placedN`. The server now answers that request with each player's summed stats, and the game shows the table. The game only calls `sceNpScoreTerm` (which fails with `NOT_INITIALIZED`); it does not use NP Score for this board. PS Rewired's captured answer was empty, probably because no Ranked race had been recorded on that account yet **[INFERENCE]**.
- The `finishGame` result is a report sent by the client. SVO checks its internal consistency, times, splits, track, vehicle and lap ranges, the number of reports and whether the player was in an online game. It does not make client-side physics authoritative and cannot detect speed hacks on its own.
- **Units [LIVE].** Time Attack reports times in hundredths of a second, the online modes in milliseconds (for example a two-lap race `bestTime=187326` is 3:07.33). `position` is the size-of-field position, not the place; `placedN=1` marks place N.
- The exact field layout of the race DME payload, the timing of vehicle, position, damage and checkpoint updates, and whether any part is validated by the server remain open. The earlier Custom Game capture proves TCP and UDP traffic for the whole race, not the payload semantics.

## 4. SVO HTTP route map

Sources: `server/src/svo/protocol.ts`, `svo/server.ts`, the SQLite store and the fixtures in `server/test/fixtures/svo/*.json`.

| Route | Request and fields | Server answer and effect |
|---|---|---|
| `GET /motorstormpr/index` | Fetch the URL list | XML URL_List: ticketLogin, finishGameURI, leaderboards, EULA, region, announcement and speed weekend routes. |
| `POST .../https:ticket/login` | NP ticket; `userContext`, language and region parameters | Reads the online id and user id from the ticket, returns the accountID in XML and sets the `AuthKeyTime` cookie. PSN and RPCN accounts are kept apart. |
| `GET .../getRegion` | no relevant fields | The configured region id and Medius location. |
| `GET .../getEula` | language and country, session cookie | EULA XML; the accepted state follows the configuration and the stored EULA hash. |
| `GET .../acceptEula` | session cookie | Stores the acceptance; answers a generic success XML. |
| `GET .../getAnnouncement` | language and country | The announcement text from the configuration file. |
| `GET .../leaderboard/timeattack` | `location.track`, `location.vehicle`, `row`, `pageSize`, `friends` | Results from SQLite as XML `user` rows; times in hundredths. Online races are not included. |
| `GET .../leaderboard/speed` | `location.track`, `location.vehicle`, `row`, `pageSize`, `friends`, `stat.timeRemaining`, `stat.vehicle`, `myPosition` | Weekend rows (`timeRemaining`, most time left first). Verified. |
| `GET .../leaderboard/ghost` | `location.gameMode=9`, `location.vehicle`, `location.track`, `account` | `<XML><ghost><data>BASE64</data></ghost></XML>` of the stored ghost (empty `data` if none). Verified: the game asks it under `leaderboard/`, not `/ghost`. |
| `GET .../leaderboard/ranked` | `stat.score`, `stat.playersBeaten`, `row`, `pageSize` | Per-player sums of the requested stats, highest score first (the attribute names equal the stat names). |
| `GET .../speed-weekend/beaten` | none (at every login) | The Weekend times of others that beat the player's own: `<beaten_times><time accountName account time oldTime track vehicle/>`; an empty list is the idle STATUS_OK. The game shows a red marker. Verified. |
| `GET .../speed-weekend/viewed` | `location.track`, `location.vehicle` (about every 4 s while the board is open) | STATUS_OK; the server marks the board as looked at (the marker turns green). |
| `POST .../finishGame` | form fields: game mode, track, vehicle, game id and name, end flags, position, total time, best time and splits, lap data, extra stats | The race is stored; the anti-cheat flags a suspicious result, but the answer is the generic STATUS_OK for compatibility. |
| `GET .../home` and unknown routes | no handler | `/home` is in the URL list; unknown routes are logged and get a generic success. This must not be read as a working home service. |

A Weekend race (`location.gameMode` 10 or 11) reports `won`, `position` (1 when won, 100 when not finished) and `timeRemaining`, and is followed by a bookkeeping report with only `bestTime` and `position=100`. Details and the NP ticket layout: [findings](findings.md).

The response MAC is `MD5(clientMac + "sp9ck0348sld" + 20 x "0")`. It matched all 68 earlier request/response pairs. The HTTP response is deliberately `Connection: close` without Content-Length, as the captured client expects.

## 5. Important functions and names

These are the best identified addresses. **10,740 functions of the Ghidra project were analysed**, not all named or manually checked. `functions.txt` is an address list, not a complete semantic registry.

| Address / symbol | Interpretation | Evidence and confidence |
|---|---|---|
| `0x87ed48` | `SetRankedOption`, writes the ranked flag of the matchmaking object | decompilation plus vtable binding; strong static evidence |
| `0x87ed58` | `SetCasualOption`, clears the flag | same |
| `0x87ed68` | `RankedOptionSelected`, returns the flag | same |
| `0x884f58` | Superset selection and storage; the client chooses 1 or 2 | static decompilation; in the live test the request used superset 1 |
| `0x27d9e8` | Builds `MatchPartyRequest2` including players, min/max and application data | decompiled; linked to the serialiser `0x6714a8` |
| `0x2801d8` | MatchPartyResponse callback: handles referral 8, join assignment 6, no-result 1 and the error branches | decompiled; the live server behaviour confirms the MLS-to-MMS requirement |
| `0x281688` | `MatchMadeGameTypeString` by vtable binding | static vtable and text reference; the whole function is not decompiled |
| `0x6714a8` | MatchPartyRequest2 serialiser | registry plus `match_wire.c` |
| `0x6720e0` | MatchPartyResponse deserialiser | registry plus `match_wire.c` |
| `0x6728e0` | SupersetListResponse deserialiser | registry plus `match_wire.c` |
| `0x648f18` | Reads the SVO URL (varint length and NUL terminator) | earlier v1.03 analysis; see ranked-casual.md |
| `CancelMatchMaking`, `CheckMatchMakingAutoStart`, `GotMatchMakingTicket`, `TicketTrackName` | found in the client strings and partly in the function string list | their exact function entries, call paths and timeout branches are not verified in the current reports |

`tools/re/ghidra_scripts/ApplyMSPRNames.py` applies the verified names and comments. Its syntax was checked but it has not been run in Ghidra, because the PS3 PowerPC ELF could not be opened by the available tooling. Run it from the Script Manager with the MSPR v1.03 EBOOT program active and check the log for SKIP lines.

Still to do in Ghidra: verify the addresses above in the real v1.03 program, follow the call paths of `CancelMatchMaking`, `CheckMatchMakingAutoStart` and `GotMatchMakingTicket`, record the timeout conditions and compare them with the runtime log, and mark uninterpreted parts as unknown rather than naming tens of thousands of functions from a neighbouring string.

## 6. Tests

### In the repository

- **Server tests:** `cd server && npm ci && npm test` runs the unit tests (EULA, DNS, anti-cheat, accounts, race statistics, Ranked standings) and replays every captured PS Rewired SVO request from `server/test/fixtures/svo` against the SVO server, comparing the XML skeleton and the response MAC.
- **Horizon end-to-end:** start the server in test mode and run `python -X utf8 tools/medius/e2e_check.py`. It covers DNS/MUIS/SVO login, a stats round trip and one Ranked MatchParty path (MLS Referral, MMS JoinAssignedGame, the `0x72` return). It does not test two players and does not finish a real DME race.
- **Horizon unit tests:** `dotnet run --project horizon/Servers/Horizon.Tests` checks the capacity and game list visibility rules.
- **Build:** `dotnet build horizon/Servers/Horizon/Horizon.csproj -c Release --no-incremental`.

### Live test matrix

| Test | Needs | Status |
|---|---|---|
| Custom Game with two players | two RPCN accounts / RPCS3 instances | partly done: lobby created and listed for the second player; joining and racing not re-verified after the list fix |
| Ranked with two players | the same | done: lobby, race, results, Ranked board, back to the lobby |
| Casual with two players | `MSPR_MM_MIN_PLAYERS=2` | not done separately |
| Cancel before and after the assignment | two players, one cancels at different stages | open; would confirm the `OnCancel` issue above |
| Timeout and DME creation failure | server logs and a failed DME or dropped connection | open |
| Internet addresses and return from the DME | a second RPCS3 on an outside network | open (a public server is in use, but only from the host's own network so far) |
| More than two players | four to six accounts | open |

## Conclusion

The static protocol map, the server's matchmaking branches and the SVO route code can now be read together. The tested part reaches, in a real RPCS3 game, matchmaking, the race, the results and the leaderboards for two players. The next decisive evidence will come from runtime tests with more players and from correlating the DME payload, not from more string searches. A complete schema of the DME race packets or the semantics of every Ghidra function cannot honestly be marked finished with the current material.
