# Live traffic (server log excerpts)

Request-log lines of the running server (RPCS3 with two test accounts, the first one and RacerTwo), addresses removed. They are the evidence for [analysis/findings.md](../analysis/findings.md). Times are UTC. Other players are not named.

## Ghost download (Time Attack, Colossus Canyon, Rally Car)

```text
07:02:24 POST /motorstormpr/finishGame?location.gameMode=9&location.track=6&location.vehicle=4&endState=1&bestSplit1=3601&bestSplit2=3896&bestSplit3=3903&bestTime=11400&...&ghostLength=68800   (body: the ghost, 68 800 bytes)
07:05:01 GET  /motorstormpr/leaderboard/ghost?location.gameMode=9&location.vehicle=4&location.track=6&account=61025      (by the second account; answered with the stored ghost)
```

Server note: `ghost stored for FirstAccount: track 6, vehicle 4, 68800 bytes`. The first answer to the download was an empty leaderboard (the request had been routed to the leaderboard handler); the game then showed "An error occurred while communicating with the server".

## Speed Weekend (mode 11), Rain God Spires, bike

```text
07:15:19 GET  /motorstormpr/speed-weekend/beaten?                                       (at login; answered with the idle STATUS_OK)
07:15:25 GET  /motorstormpr/leaderboard/speed?location.region=0&row=0&pageSize=10&location.track=14&location.vehicle=1&stat.timeRemaining=22431&stat.vehicle=1
07:17:30 POST /motorstormpr/finishGame      (form body, 271 bytes)
         location.gameMode=11 location.track=14 location.vehicle=1 endState=1 bestTime=32868 boostDistance=409501
         distanceTravelled=2358741 endNormal=1 furthestBoostDistance=98241 laps=1 position=1 timeRemaining=32868
         totalRaceTime=72132 totalRaceTimeInFirst=72132 version=2 won=1
07:17:30 GET  /motorstormpr/leaderboard/speed?...&location.track=14&location.vehicle=1&stat.timeRemaining=32868&stat.vehicle=1   (and the same with friends=true)
```

A lost run of the second account (one attempt, 10 s):

```text
location.gameMode=11 location.track=14 location.vehicle=1 endState=1 bestTime=0 boostDistance=0 distanceTravelled=1379
endNormal=1 laps=0 overheats=1 position=100 totalRaceTime=10066 totalRaceTimeInFirst=10066 version=2 wrecks=1
```

The bookkeeping report that follows a won run (125 bytes, posted about a second after the login that came next):

```text
location.gameMode=11 location.track=14 location.vehicle=1 endState=1 bestTime=34874 endNormal=1 laps=0 position=100 version=2
```

After the second account (34 874 ms left) beat the first (32 868 ms), the first account's next login:

```text
07:34:04 GET /motorstormpr/speed-weekend/beaten?          -> <beaten_times><time accountName="RacerTwo" account="61026" time="34874" oldTime="32868" track="14" vehicle="1"/></beaten_times>
07:34:09 GET /motorstormpr/speed-weekend/viewed?location.track=14&location.vehicle=1     (and again every ~4 s while the board is open)
```

The game showed a red marker and bar for that ticket; after the board was opened it turned green.

## NP ticket check of six RPCS3 logins

```json
{"kind":"login","msg":"FirstAccount logged in to SVO (RPCS3 (RPCN))","data":{"svoPlatform":"PS3","userAgent":"-","ticket":{"signer":"rpcn","valid":true,"reason":"ok"}}}
```

`SVO-Platform: PS3` is sent by RPCS3 too and there is no User-Agent.

## A real PS3

```text
GET  /motorstormpr/index?languageID=1
POST /motorstormpr/https:ticket/login?sig=...&userContext=0&sigclass=0&siglength=16&timeZone=1&languageID=1     (248-byte ticket, PSN signer; account key "<name>@PSN")
GET  /motorstormpr/getRegion?country=us        GET .../getEula?...      GET .../acceptEula?...
GET  /motorstormpr/leaderboard/timeattack?location.region=0&row=0&pageSize=10&location.track=1&location.vehicle=0&stat.bestTime=6320&stat.vehicle=7   (one per track)
```

Ranked games with a PS3 player ended with `NO RESULT` for that player in the game summary; the results came after the next SVO login (`result.queued`).

## Horizon hang on .NET 10 (the empty channel group)

`top -H`: one `.NET TP` thread at 99.9 % CPU for 100 s. `dotnet-stack report`:

```text
Thread (0xB5C65):
  System.Linq!Enumerable+IEnumerableSelectIterator.MoveNext
  System.Private.CoreLib!Task.WhenAll(IEnumerable<Task>)
  Horizon!Horizon.SERVER.Medius.MMS+<Tick>d__17.MoveNext
  Horizon!Horizon.SERVER.MediusClass+<TickAsync>d__26.MoveNext
  Horizon!Horizon.SERVER.MediusClass+<LoopServer>d__27.MoveNext
```

The log of the stuck client: `CLIENT_HELLO` and `CRYPTKEY_PUBLIC` received on the lobby port and no `SERVER_CRYPTKEY_PEER` ever sent; 15 s later the DME world was destroyed by its timeout.
