# Ranked XP and rank level

Findings from the decompiled game (EBOOT v1.03, functions below are entry addresses) and from the first Ranked races on this server. Evidence tags: **[EBOOT]** decompiled code or strings, **[LIVE]** seen on this server, **[DISC]** read from the game's data files, **[INFERENCE]** conclusion drawn from the two.

## Summary

- **[EBOOT]** The game computes XP and the rank level itself, after every Ranked race, from the finishing order and the levels of the other players. The server supplies neither.
- **[LIVE]** The Ranked `score` in `finishGame` is the player's **total XP after the race**, not the points of that race. Real values of one driver: 51, 101, 147 after three wins against the same opponent; the loser stayed at 1.
- **[INFERENCE]** The in-game rank level is not sent in a result. It goes to the server only in the matchmaking request's data blob (`Rank Level`, see below).
- The earlier Ranked board of this server summed `score` over all races (299 for those three wins). That was wrong and is fixed: the board now shows the latest total XP.

## What the game does

| Function | Role |
|---|---|
| `0x2788c8` (called by `0x278b38`) | `PreRaceStatsUpdate`: prints XP, level, winning streak, quit status and quit count, then copies the XP into the player's network object (`xp of Player is set in NetObj = %d, level %d`). |
| `0x279040` (calls `0x278d88`) | `QuitRaceStatsUpdate`: a quit resets the winning streak to 0 and the XP is posted as `score` with a `localQuit` flag. |
| `0x2790f8` | `PostRaceRankingUpdate`: the XP formula below. Only runs for a Ranked game. |
| `0x2b6f80` | Level of an XP value: the highest level whose threshold is not above the XP; below the first threshold the table's default level. |
| `0x2b6e98` | Maps a level to a rank tier (icon): steps at levels 10, 20, 30 and 40 with three sub-ranks in each group of ten. |
| `0x34fb0`, `0x33730` | The rank progress bar (`GetOnlinePlayerRankProgressPercentage`) and the reader of the profile value `Online.ranked.xp`. |
| `0x77778` | Loads `data/onlinerankings/rankings.xml` from the game's data (the thresholds and point tables). |

### XP formula **[EBOOT]**

For each other ranked player in the race, with the player's own level `L` and the other player's level `M`:

1. `rel = L - M`, clamped to the range stored in the table.
2. If the player finished ahead of that player, add the table's **win points** for `rel`; otherwise add the table's **loss points** for `rel` to a second sum. Log lines: `I beat %s = Win point %d`, `%s beat me = lossPoints %d`.
3. `XP after = XP before + win sum + trunc(loss sum * loss factor of level L)` (`XP BEFORE`, `**** XP AFTER = %d ***`, `LOST = %f`, `WIN = %d`). The loss points are presumably negative; the sign is in the data file, not in the code.
4. Limits: after a rank-up the player is immune for 3 races (XP cannot go down: `XP not decreased due to recent rank promotion`, `Immunity count decremented`); XP never falls below the starting XP of the player's current level, and never rises above the table's maximum.
5. If the rank tier went up, the immunity counter is set to 3 (`Ranked up baby! Immune for 3 races`).
6. The new XP is posted as the stat `score`.

This fits the live data: a start of 1 XP, +50 for a win against an equal level, +46 against a different level; the loser stays at 1 because XP cannot fall below the floor of the first level.

The structure the code reads: a list of levels (XP threshold as integer plus the loss factor as double, 16 bytes each), the count of levels, the maximum XP, the clamp range for `rel`, and a matrix of win and loss points (8 bytes per `rel`).

## The table: `data/onlinerankings/rankings.xml` **[DISC]**

The file is inside the game's archive `USRDIR/ms2.psarc` (PSARC, zlib; the extractor is `tools/game-data/psarc.py` in this repository). It is not part of the EBOOT and not in any capture. Reading it confirmed the formula above: the live races (1 -> 51 -> 101 -> 147 XP) are exactly +50 for a win against an equal level and +46 for a win against a level below.

- **Bounds:** 50 levels in 5 ranks, minimum XP 1, maximum XP 80000, relative level clamped to -50..50, at most 10 quits counted.
- **Levels (XP needed):** 1: 1, 2: 100, 3: 200, 4: 300, 5: 400, 6: 500, 7: 1000, 8: 1500, 9: 2000, 10: 2500, 11: 3000, then +500 per level to 16: 5500, 17: 6000, 18: 7000, 19: 8000, 20: 9000, 21: 10000, then +1500 to 24: 14500 and so on in steps of 1500 to 30: 23500, 31: 25500, +2000 to 40: 43500, 41: 46500, +3000 to 49: 70500, 50: 75000.
- **Loss factor** of the player's own level (share of the loss points that counts): 0 at level 1, 0.025 to 0.1 for levels 2-5, 0.15-0.4 for 6-9, 0.5 at 10; it then drops back to 0.25 at the first level of every rank (11, 21, 31, 41) and rises again to 0.5, 0.7, 0.8, 0.9 and 1.0 at level 50.
- **Points per opponent (win / loss) by own level minus the opponent's level:** 0: +50 / -50; 1: 46 / -54; 2: 43 / -57; 3: 40 / -60; 4: 37 / -63; 5: 35 / -65; 10: 28 / -72; 14 and above: 25 / -75. Negative values mirror this: -1: 54 / -46; -2: 57 / -43; -3: 60 / -40; -5: 65 / -35; -10: 72 / -28; -12: 73 / -27; -14 and below: 75 / -25. So a win always gives 25-75 points and a loss takes 25-75 points, and beating a stronger player pays more.
- **Rank tiers:** levels 1-10, 11-20, 21-30, 31-40, 41-50.
- **Quit penalty (table 4)** by the number of quits: 1: -250, 2: -750, 3: -1000, 4: -1250, 5: -1500, 6: -2000, 7: -2100, 8: -2200, 9: -2500, 10: -3000.

The server has these numbers in `server/src/online/rank.ts` (level from XP, points for a level difference, expected XP of a race), and the status site shows the level next to the XP.

### Where the XP is stored and sent

**The player stats blob** **[EBOOT]**. The game keeps a `PlayerStats` structure of **180 bytes** (big-endian) and uploads it to the Medius account (`MediusAccountUpdateStats`, `Account Stats uploaded to server`) in a **256-byte buffer**: the 180 bytes first, zeros after (the update message is 21 bytes message id + 17 bytes session key + 3 bytes + 256 bytes of stats). The structure is versioned: bytes 0-1 are the version, currently **8**; an older blob from the server is upgraded step by step (`server version is %03d / current version is %03d`, `Upgraded PlayerStats to version %d`), and a blob with a version outside 1..8 is treated as a new account and reset (`PlayerStats version is invalid. Assuming new account and resetting.`). Functions: `0x2abe58` (load, upgrade, reset), `0x27ca10` (upload), `0x27ff88` (download), `0x2abaa8` (quit penalty), the upgrade steps `0x2ab510`, `0x2ab6e8`, `0x2ab6a8`, `0x2ab668`, `0x2ab7b8`, `0x2ab728`.

| Offset | Type | Content | Evidence |
|---|---|---|---|
| 0 | u16 | version (8) | load and reset code |
| 2 | u8 | "changed" flag, set after an upgrade or reset | load code |
| 4 | i32 | starts at 1 (meaning not decoded) | reset code |
| **8** | i32 | **XP**, starts at 1 | reset code, quit penalty (`XP was = %d`, `XP changed to = %d`), `xp of Player is set in NetObj` |
| **12** | i32 | **ranked quit count**; +1 for each quit (the penalty is taken from the quit table), -1 for each finished Ranked race | `0x2abaa8`, `Ranked quit count decremented` |
| 16-28 | i32 x4 | counters (inferred earlier from real blobs; probably the Ranked golds, silvers, bronzes and players beaten) | earlier captures, not decoded in code |
| **32** | i32 | **dropout count**, +1 when the player reconnects after dropping out | `Incrementing PlayerStats dropout count on reconnection` |
| 72 | i32 | counter that only grows (inferred from real blobs); version 8 inserted an `i32` here followed by a 16-character text field | upgrade step 7 to 8 (`0x2ab728`) |
| 76 | 16 bytes | text, starts as 16 spaces (added in version 8) | upgrade step 7 to 8 |
| 132 and 136 | i32 x2 | both start at 3204 (0xC84); possibly a content (DLC) version | reset code |

So the XP is at offset 8 and **can go down** (loss points, quit penalties). Real blob values are needed to confirm the golds, silvers and bronzes. The earlier assumption that offset 8 is a "best Ranked score" that only grows was wrong, and the anti-cheat rule `stats blob went backwards` (review only, never rejects) must not treat offset 8 as monotonic. Fixed together with this note; the quit count at offset 12 falls by design.

The profile on the console also keeps the keys `Online.ranked.xp`, `online.ranked.golds`, `silvers`, `bronzes`, `playersbeaten`, `longwinningstreak`, `gamesplayed`, `online.casualgamesplayed`, `online.customgamesplayed`, `online.dropout` and `festival.rank`; that is the player's own save data, the blob above is what reaches the server.

**The matchmaking request blob** **[EBOOT]** (`0x27d9e8`, `Data Blob being sent to the server`): the application data of `MediusMatchPartyRequest` is **12 bytes** (big-endian):

| Offset | Type | Content |
|---|---|---|
| 0 | u8 | Ranked game flag (1 = Ranked) |
| 4 | i32 | **Rank Level**: the average of the party members' levels (sum of the levels divided by the party size), 1 for an unranked party |
| 8 | i32 | Location ID (-1 when the game is a custom game) |

Other values of the request: party size, **minimum players 6 for Ranked and 4 otherwise**, superset id. The server (Horizon) uses only the flag in byte 0. A level-aware matchmaker can read the level at offset 4; the game makes no use of it on its own, so how wide a level difference may be is entirely a server decision.

## What the server can do with this

- Show the XP and the level on the Ranked board and in the driver profile (done: the board shows the latest XP and its level, the profile chart shows the XP after each race with the change per race).
- Check results against the formula: `expectedXp` gives the XP that follows from the previous XP, the opponents' levels and the finishing order, so a claimed XP that cannot follow is a strong cheat signal. It is used as a review-only check (`xp-mismatch`, never rejects a race): a driver is judged when the driver and all other drivers of the race have an earlier Ranked race on the server (their XP before is the earlier score). An unchanged XP after a loss is accepted (immunity); quits are not judged. A difference can also come from drivers who did not report, or from XP earned on another server in between, so a finding is for a human to look at.
- Match by level, using the `Rank Level` at offset 4 of the 12-byte matchmaking blob (layout above). Needs a Horizon change; with the present player numbers a strict level rule would only make queues longer.
- It cannot set or change a player's level: the game computes it locally, and a changed value would be overwritten by the next race.

## Open

1. Real stats blobs to confirm the layout (the XP at offset 8, the counters at 16-28, offset 72) and the meaning of offsets 4 and 132-136.
2. Whether a rank-up or the XP is checked by the game against the server's stored copy when a profile is downloaded (`DownloadSelectedPlayerStats`).
