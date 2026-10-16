# MSPR / PS Rewired — observation report

Historical capture analysis

**Source:** `captures\mspr-ranked.pcapng` + `-summary-redacted.json`
**Duration:** 17:12:49–17:18:32 UTC (about 5 min 43 s) · 16,702 packets · 6.8 MB
**Session:** Casual lobby (did not work), Ranked lobby (did not work), leaderboards (worked)

Everything below is **OBSERVED** in the packet data. Inferences are marked separately.

## 1. DNS observations (relevant to the game)

| Host | IP | Seen |
|---|---|---|
| `motorstorm2ps3.online.scee.com` | 67.222.156.250 | 16× — the game's "classic" SCEE online address |
| `svo.psrewired.com` | 67.222.156.252 | 2× |
| `api.psrewired.com` | 172.67.168.92 / 104.21.62.140 (Cloudflare) | 2× |
| `np.rpcs3.net` | 167.235.60.94 | 2× (RPCS3's own PSN services) |

Other DNS queries came from background applications (Steam, Discord, Windows Update, Office,
Cloudflare DoH etc.) — no game traffic.

## 2. Plaintext HTTP — `svo.psrewired.com`

**All of the game's HTTP API is unencrypted plaintext HTTP.** Observed routes:

### Session/authentication (repeated ~7×, i.e. every time the player returned to the lobby)
- `GET  /motorstormpr/index?languageID=1`
- `POST /motorstormpr/https:ticket/login?sig=[REDACTED]&userContext=0&sigclass=0&siglength=16&timeZone=1&languageID=1`
- `GET  /motorstormpr/getRegion?country=fi`
- `GET  /motorstormpr/getEula?country=fi&languageCode=1`
- `GET  /motorstormpr/getAnnouncement?country=fi&languageCode=1`
- `GET  /motorstormpr/acceptEula?country=fi&languageCode=1`

### Leaderboards (seen directly in the capture)
- `GET /motorstormpr/leaderboard/timeattack?location.region=0&row=0&pageSize=10&location.track=1&location.vehicle=0`
- `GET /motorstormpr/leaderboard/ranked?location.region=0&row=0&pageSize=10&stat.score=1&stat.playersBeaten=1`
- `GET /motorstormpr/leaderboard/speed?location.region=0&row=0&pageSize=10&location.track=14&location.vehicle=1`
- `GET /motorstormpr/leaderboard/speed?...&friends=true&...` (friends view)
- `GET /motorstormpr/speed-weekend/beaten?`

Responses: **44× 200 OK, 2× 304** — no errors.

`stat.score` and `stat.playersBeaten=` are observed query parameters of the Ranked leaderboard
(inference: they are the board's sort metrics, but parameter names alone are no proof of a full schema).

## 3. SCERT game traffic (most of the bytes)

| Target | Ports | Observation |
|---|---|---|
| 67.222.156.250 (`motorstorm2ps3.online.scee.com`) | **TCP 10071, 10075, 10077** | 3 logins = 3 short sessions; ~60–100 packets per port per session |
| 67.222.156.252 (`svo.psrewired.com`) | **TCP 10060** | many short sessions, 11–14 packets each |
| 67.222.156.252 | UDP 53 | DNS queries straight to the PS Rewired server |
| 104.21.62.140 (`api.psrewired.com`) | **UDP 443** (QUIC/HTTP3) | 888 packets / 333 kB — the UDP flow with the most packets |
| 192.0.2.11 | TCP 10079 | another device on the home network on the same port (coincidence) |

**Limit:** the SCERT payloads are encrypted — the tool does not decrypt them and is not meant to. The
contents (matchmaking messages, rank points, race stats) are **unreadable** without PS Rewired's official
documentation or permission. The observed ports (10060, 10071, 10075, 10077) are observations, not old hints.

**Inference (not certain):** the timestamps of the TCP 10071/10075/10077 sessions match lobby connections;
TCP 10060 traffic to `svo.psrewired.com` happens during the leaderboard queries. This is a correlation of
timestamps, not of payloads.

*Later : 192.0.2.11:10079 was NOT a coincidence. It is PS Rewired's MMS (matchmaking
server): its MLS refers the game to this LAN address, which is unreachable from the internet. That is
why Ranked/Casual did not work on PS Rewired; see ../ranked-casual.md.*

## 4. Why the Casual/Ranked lobby seemed not to work

Observation: the leaderboards work over HTTP, but the lobby/matchmaking is SCERT-protected TCP
10071/10075/10077 traffic to `motorstorm2ps3.online.scee.com`. The capture shows **short** SCERT sessions
(30–60 packets, ~10–15 s) but **no** long matchmaking flow. This fits the lobby connection failing before
the actual matchmaking phase — but the cause (compatibility, version, server state) cannot be determined
from the packet data.

## 5. Protocol summary

| Function | Protocol | Host:port |
|---|---|---|
| HTTP API (leaderboard, EULA, login ticket) | **plaintext HTTP** | `svo.psrewired.com` |
| Game/lobby (SCERT, encrypted) | TCP | `motorstorm2ps3.online.scee.com`: 10071/10075/10077 |
| SVO secondary | TCP | `svo.psrewired.com`: 10060 |
| Modern API | **QUIC/HTTP3 (UDP 443)** | `api.psrewired.com` |
| PSN authentication | TLS | `np.rpcs3.net` (RPCS3's emulated PSN) |

## 6. Redaction

`Authorization`, `Cookie`, PSN ids and the `sig=` signature are redacted. The original PCAPNG keeps
everything — keep it local and do not share it publicly (it also contains unredacted HTTP traffic from
other applications).
