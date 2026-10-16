# MSPR / PS Rewired — Custom Game observation report

Historical capture analysis

**Source:** `captures\mspr-custom.pcapng` (+ `-summary-redacted.json`, `http_objects/`, status snapshots)
**Duration:** 17:51:16–17:57:47 UTC (~6.5 min) · 29,393 packets · 11.6 MB
**Session:** Custom game lobby + one race (the player finished 8th of 12)

## 1. Full protocol map (OBSERVED)

| Function | Protocol | Target | Observation |
|---|---|---|---|
| HTTP API (login, EULA, leaderboards, **result report**) | **plaintext HTTP** | `svo.psrewired.com`:**10060** | 58 requests, all 200/304 |
| **Race session (race running)** | **TCP + UDP** | `motorstorm2ps3.online.scee.com`:**11001** | UDP 6705 packets / 594 kB + TCP 816 packets / 66 kB, 308 s = the whole race |
| Lobby/SCERT channels | TCP | same host: 10071, 10075, 10077 | 3 short sessions during the lobby phases |
| RPCN (RPCS3's PSN) | TCP | `np.rpcs3.net`:31313 | continuous 90 packets over the whole session |
| Modern API | QUIC/HTTP3 (UDP 443) | `api.psrewired.com` (ECH-encrypted) | in the background over the whole session |
| UPnP router port openings | SOAP/HTTP | own router :49152 | `AddPortMapping` + `GetExternalIPAddress` — RPCS3 opens ports for hosting |
| 192.0.2.2:65432 | TCP | own machine | 3 packets every ~65 s — VPN/RPCN tunnel keepalive |

**Most important correction to the earlier picture:** the actual game traffic runs on port **11001**, not
on the 10070-range ports. 10071/10075/10077 are lobby/session channels.

## 2. The game's HTTP API — full route map observed

The server gives the client a URL list at login (the `index` response):

```
ticketLogin          = /game/ticket/login (https:ticket/login)
finishGameURI        = /game/finish
leaderboard/timeattack, leaderboard/speed, leaderboard/ranked
getRegion, getEula, acceptEula, getAnnouncement
```

## 3. `POST /motorstormpr/finishGame` — complete race statistics (OBSERVED)

The result report is form-urlencoded, 364 B, protected with Cookie + X-SVOMac:

```
location.gameMode=4          # game mode (4 = custom?)
location.track=2             # track
location.vehicle=4           # vehicle
gameId=150                   # sub-lobby (room 150 = 0000007a-BillyShears)
endState=1, endNormal=1      # normal finish
position=8, placed2=1        # placing
totalRaceTime=185276         # ms
bestTime=186311              # ms
laps=2
boostDistance=1902011, furthestBoostDistance=134034
distanceTravelled=5520824
jumpDistance=3515000, jumps=19
totalRaceTimeInFirst=5966    # ms in the lead
wrecks=3
version=2
```

This is the whole schema MSPR uses to report race results. The server's per-player stats blobs (public
API, 256 B) are probably these same fields packed — the match fits (jumps, wrecks, distance...).

*Later : the game's own time formatter (EBOOT 0x2a1be0, `%02d:%02d.%02d`) and the split
times of Time Attack reports show that lap times (bestTime) are hundredths of a second, not ms.*

## 4. Leaderboard — real data observed (speed track 14)

```xml
<user accountName="RemotePlayerB" accountId="89085" bestTime="13574" rank="1" vehicle="1" currentPlayer="0" ghostAvailable="0" estimated="0"/>
<user accountName="RemotePlayerC" accountId="84908" bestTime="14005" rank="2" .../>
<user accountName="RemotePlayerA" accountId="89379" bestTime="20445" rank="3" .../>
```

The `ghostAvailable` field = ghost availability. The login response carries the player's own
`accountID` (61025).

## 5. Correlation with the status API (13 snapshots)

- `17:52:18` **Player1 joined** → 17:52:12 the SCERT 10077 connection opened, `17:52:23` port 11001 traffic started ✓
- `17:57:29` `finishGame` POST → the race ended ~17:57:32, 11001 traffic stopped ✓
- Room player counts swung between 5 and 10 as the selection screens changed

## 6. What stayed encrypted (limits)

- Port 11001 payloads (SCERT-encrypted): the exact game event stream
- `api.psrewired.com` QUIC/ECH: contents
- Cookie/X-SVOMac/sig: redacted — not reported

## 7. Tool updates from this capture

- HTTP bodies are now saved for **form-urlencoded** requests too (finishGame was revealed thanks to this)
- A classic mistake fixed: HTTP was on port 10060, not 80

