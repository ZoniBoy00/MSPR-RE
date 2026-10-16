# MSPR Emulation Server Blueprint

Research note. Historical: written before the server was built; the current state is in the server repository.

## TL;DR

**MotorStorm: Pacific Rift is already supported**: Jump-Suit/PSMultiServer (the Horizon server, C#)
supports MSPR as RPCS3 cross-play (🟢 US/EU). Our own server = running PSMultiServer + implementing the
SVO/HTTP layer (fully documented in this project's captures) + ranked/casual once PS Rewired opens them.

## 1. MSPR's online stack (proven with captures + EBOOT analysis)

| Layer | Protocol | Ports | Readiness |
|---|---|---|---|
| Medius lobby/matchmaking | Medius (MUM/MUIS/MAS/MLS) | TCP 10071/10075/10077 | ✅ Horizon: RT.Models/* ready |
| DME game session | SCE-RT DME | TCP+UDP 11001 | ✅ Horizon: RT.Models/DME/* |
| SVO web services | plaintext HTTP | TCP 10060 | 🔧 to implement ourselves — fully documented below |
| Modern API | QUIC/HTTP3 (ECH) | UDP 443 | ❓ api.psrewired.com — contents encrypted |
| NAT/UPnP | UPnP SOAP | router | handled by the client |

Medius components (PSMultiServer README): MUM (universes), MUIS (universe list → MAS), MAS
(authentication), MLS (lobby, channels, clans, stats), DME (game session data), NAT (hole punching),
BWPS (bandwidth).

## 2. SVO/HTTP layer — complete spec (from captures)

Port 10060, plaintext HTTP, host `svo.psrewired.com`. At login the server gives the client a URL_List
route map:

```
GET  /motorstormpr/index?languageID=1        -> URL_List (XML)
POST /motorstormpr/https:ticket/login        -> SP_Login (accountID)
GET  /motorstormpr/getRegion?country=fi
GET  /motorstormpr/getEula?country=fi&languageCode=1
GET  /motorstormpr/acceptEula?country=fi&languageCode=1
GET  /motorstormpr/getAnnouncement?country=fi&languageCode=1
GET  /motorstormpr/leaderboard/timeattack?location.region=0&row=0&pageSize=10&location.track=1&location.vehicle=0
GET  /motorstormpr/leaderboard/ranked?...&stat.score=1&stat.playersBeaten=1
GET  /motorstormpr/leaderboard/speed?...&friends=true&...
GET  /motorstormpr/speed-weekend/beaten?
POST /motorstormpr/finishGame                -> race results (form-urlencoded)
```

Headers: `SVO-Platform: PS3`, `X-SVOMac` (per-request MAC), `Cookie` (session). Responses are XML.

### finishGame schema (complete)
```
location.gameMode, location.track, location.vehicle, gameId, gameName,
endState, endNormal, position, placed2, totalRaceTime, bestTime,
bestTimeSplit1/2/3, laps, boostDistance, furthestBoostDistance,
distanceTravelled, jumpDistance, jumps, totalRaceTimeInFirst, wrecks, version
```

### Leaderboard response XML
```xml
<user accountName="X" accountId="N" bestTime="13574" rank="1"
      vehicle="1" currentPlayer="0" ghostAvailable="0" estimated="0"/>
```

## 3. Medius layer — use existing code

- **Jump-Suit/PSMultiServer** (C#, contains Horizon) — MSPR supported 🟢
- **Horizon-Private-Server/horizon-server** — the same C# code standalone
- **hashsploit/clank** (Java) — Medius v1.5–1.8, MAS/MLS/MUIS/DME/NAT
- **PSOnlineReturnalGaming/uya-medius-encryption** — Medius message encryption: **RC4-SHA1**, keys in the
  first 2 handshake messages; Medius.Crypto: RC/RSA/Hash classes

MSPR ports ↔ Medius components:
- 10071/10075/10077 → MAS/MLS/channel servers (TCP, RC4-SHA1 encrypted)
- 11001 → DME (game session, SCE-RT)

EBOOT confirmations: `MediusLogin`, `MediusAccountUpdateStats`, `mediusAccountId`, `dmeServer`,
`Medius session key %s`, `MediusJoinLeastPopulatedChannel`, matchmaking states
(ROOM_IN_CASUAL_STANDARD, ROOM_IN_MATCHMAKE, ...).

## 4. Public helper API (for stats on our own server)

`https://api.psrewired.com/us/api/` (no key):
- `rooms?applicationId=21624`, `rooms/{id}` (players + 256-byte stats blobs)
- `universes?applicationId=21624`, `universes/players?...`
- `stats?applicationId=21624` → global player count
- with a key: leaderboards, servers (API-KEY header)

## 5. Tools in this project (reusable)

- `tools/unself.exe` — PS3 SELF decryption (Windows)
- `tools/strings_scan.py`, `tools/eboot_analyze.py` — binary analysis
- `tools/final_extract2.py` — TOC string xrefs (TOC=0x208958)
- `tools/mspr_status.py` — public API monitoring to JSONL
- `mspr_capture/` — passive network capture
- `re/ghidra_proj/MSPRFINAL2` — 10,740 functions analysed

## 6. Not opened

- ms2.psarc (4.8 GB, 536k entries) — probably contains live SVO/Medius PRX modules (next dig if needed)
- SCERT live encryption on port 11001 (DME) — ready implementation in Horizon
- api.psrewired.com's ECH contents (not ours to open)

## 7. READY IMPLEMENTATION FOUND: PSMultiServer

Jump-Suit/PSMultiServer contains a production implementation of MSPR's SVO layer:
- Servers\SVO\Games\PS3\MotorstormPR2.cs (371 lines)
  - /MOTORSTORM2PS3_SVML/index.jsp -> URL_List
  - getEula, leaderboards (leaderboardsListURL), finishGameURI (/game/Game_Finish)
  - port 10060, domain parameter
- MUIS supports MotorStorm (Servers\Horizon\MUIS\MuisClass.cs)

Deployment (on the server machine):
1. git clone Jump-Suit/PSMultiServer
2. build.bat (C# .NET) or docker-compose.yml
3. Configure MSPR (applicationId 21624, domain pointing)
4. DNS/hosts: MSPR domains -> server IP
5. Our own SVO server (server\mspr_server.py) = a simpler alternative / fallback; PSMultiServer's
   implementation is wider (leaderboardsListURL etc.)

Note: the ranked/casual modes are not ready in PSMultiServer either — the same limit as PS Rewired
(allowedRanks: 0). Adding them needs decompiling the matchmaking messages (Ghidra work, see sections 5-6).

## 8. PSMultiServer BUILD SUCCEEDED

- dotnet build: Horizon.csproj + SVO.csproj -> 0 errors (net6.0)
- the NuGet source nuget.org had to be added (dotnet nuget add source)
- The SVO server is configured in Program.cs SVOServerConfiguration
  - HTTPSDNSList: add 'motorstorm2ps3.online.scee.com'
  - DatabaseConfig: static/db.config.json
  - HTTPSCertificateFile: static/SSL/SVO.pfx
- SVOProcessor.cs: MotorstormPR2.cs = MSPR SVO implementation
  (routes /MOTORSTORM2PS3_SVML/index.jsp + /MOTORSTORM2PS3_XML/*)
- Horizon: MUIS/MAS/MLS/DME/NAT — configure the universes for app 21624

Next deploy session:
1. SVO: add the MSPR domain to HTTPSDNSList + check the MotorstormPR2 routes
2. Horizon: configure the Medius universes (app 21624, MSPR lobbies)
3. Certificates (SVO.pfx, SCERT-style internal certificate)
4. DNS: MSPR domains -> server (mspr_dns.py or hosts)
5. Test with RPCS3: login -> lobby -> custom -> ranked/casual

## 9. RESULT: Horizon supports MSPR (confirmed

- PSMultiServer build: Horizon + SVO, 0 errors
- Horizon\MUIS\MuisClass.cs: CompatibleApplicationIds contains 21624 (MSPR)!
- SVO: MotorstormPR2.cs (SVO implementation)
- ebootdefs.json = for PS Home HDK clients (not MSPR)

DEPLOYMENT GUIDE (next session):
1. PSMultiServer README: .env/environment + databases (MySQL/SQLite)
2. Start Horizon (Medius :10071/10075/10077 + DME :11001) + SVO (:10060)
3. DNS/hosts: motorstorm2ps3.online.scee.com + svo.psrewired.com -> server
4. RPCS3: DNS pointing or hosts
5. Test: login -> lobby -> custom games
6. Ranked/casual: needs decompiling the StartMatchMaking chain
   (re\RANKED-CASUAL-DESIGN.md + matchmaking_flow_strings.txt ready)

*Afterwards : the final server uses our own TypeScript SVO (`server/`) instead of
PSMultiServer's SVO, and Ranked/Casual were reverse engineered and implemented — see
../ranked-casual.md.*
