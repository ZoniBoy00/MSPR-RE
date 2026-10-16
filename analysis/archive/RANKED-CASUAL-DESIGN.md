# MSPR Ranked & Casual Server — Design

Plan (client logic from the EBOOT + server side with Horizon's messages; historical, the implementation:
../ranked-casual.md)

## 1. Client matchmaking flow (EBOOT, proven with strings)

```
Player picks Ranked/Casual
  → GameTypeSetRankedOnline / GameTypeSetCasualOnline
  → SetRankedOption / SetCasualOption
  → StartMatchMaking
  → [Medius: matchmaking ticket is created]
  → GotMatchMakingTicket
  → CheckMatchMakingAutoStart / GetMatchMakingCountDownTime
  → ROOM_IN_MATCHMAKE / ROOM_IN_MATCHMAKE_NOMATCH
  → [matches are found]
  → ROOM_IN_CASUAL_STANDARD / ROOM_IN_CASUAL_ELIMINATOR
    / ROOM_IN_RANKED_STANDARD / ROOM_IN_RANKED_ELIMINATOR
  → MatchMadeGameTypeString
  → CustomGameCreated / UpdateCustomGameFromRaceLobby (custom path)
  → races → finishGame (SVO HTTP) → MediusAccountUpdateStats
```

Custom game: CreateCustomGame → CustomGameCreated → JoinCustomGame / FindCustomGames →
UpdateCustomGamesListTable → RaceLobby*.

## 2. Server side — Horizon's ready Medius messages

| Client state | Horizon message (RT.Models/Lobby/) | Status |
|---|---|---|
| StartMatchMaking | MediusMatchFindGameRequest / StatusResponse | ✅ ready |
| CancelMatchMaking | MediusMatchCancelRequest | ✅ ready |
| CreateCustomGame | MediusMatchCreateGameRequest/Response | ✅ ready |
| Party | MediusMatchPartyRequest/Response | ✅ ready |
| Lobby lists | MediusLobbyWorldPlayerList*, MediusGameWorldPlayerList* | ✅ ready |
| Stats | MediusAccountUpdateStats (+ MatchmakingDTO database) | ✅ ready |
| DME session | RT.Models/DME/* (TypeClientConnect, TypeUpdateClientStatus...) | ✅ ready |

## 3. What is missing (the real work)

1. **MSPR's Medius version mapping** — MSPR uses a Medius version whose message formats may differ from
   Horizon's defaults. Found by comparing the captured handshake with Horizon's Medius implementation.
2. **Ticket parameters** — the EBOOT has TicketNumberofLaps, TicketTrackName,
   TicketBestMedal/Skill/Speed/Aggression: matchmaking request parameters the client sends. To be
   decompiled from the StartMatchMaking function.
3. **Ranked calculation** — Online.ranked.ranking, mediusAccountId stats: the ranking logic as the
   server's own implementation.
4. **Live testing against the client** — iterative work: stub → correct answer → next message → ...
   (the same path as with the SVO server).

## 4. Realistic estimate

- Custom game mode + lobbies: working with PSMultiServer's Medius support + the SVO layer
- Ranked/casual: the messages are ready in Horizon, but the MSPR mapping + testing = weeks of iterative
  work with the real client
- Ranked/casual does not work on PS Rewired itself (allowedRanks: 0) — nobody has solved this for MSPR
  yet. The first to decompile the StartMatchMaking chain is the first in the world.

*Afterwards : Ranked and Casual reach the race lobby with the real game on this server.
The actual flow (MLS referral → MMS → JoinAssignedGame → JoinLeastPopulatedChannel → MLS) differed from
this plan; see ../ranked-casual.md.*
