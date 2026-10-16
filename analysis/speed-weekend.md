# Speed Weekend and Volcano Weekend: what the game needs from a server

> **Verified (RPCS3, Speed Weekend):** the result, the Weekend board and the `beaten` answer below work in the game; `viewed` clears the marker. Details: [findings](findings.md#2-speed-and-volcano-weekend-verified-live). Items 1 and 3 of "still unknown" are answered there; the shape of `beaten` is as guessed, the marker turns red and, after the board is opened, green.

Findings from the game's strings and function-to-string map (EBOOT v1.03; addresses are function entries in the original local project) and from the first real Speed Weekend race on this server. Evidence tags as in the [reverse engineering report](reverse-engineering.md): **[EBOOT]**, **[LIVE]**, **[INFERENCE]**.

## Where the Weekend content comes from

**[EBOOT]** Almost all of it is in the game. The ticket select screen (`speedweekend-ticketselect.gui`), the ticket types and their progress flags (`speedweekend.complete`, `barrelcomplete`, `barrelraced`, `numwins`, `longesttimeleft`), and the loading hints (`unqualified`, `bikeatv`, `bikeatvtwo`, `bikeatvthree`, `barrel`, `barreltwo`, `originalfestival`, `leaderboard`, `redhelmet`) are game data and local save data. Offline target times exist too (`SpeedWeekendSetOfflineTargetTime`, `ticket.%d.%d.best_time`).

So a server does not have to deliver an event schedule or ticket definitions. What the game asks its SVO server for is the result side:

| Function | Request or tag | Used for |
|---|---|---|
| `0x2c8328` | `finishGame` with `location.gameMode`, `location.track`, `location.vehicle`, `endState`, `gameName`, `gameId` and the race stats | Posting the result. Weekend modes are 10 (Volcano Weekend) and 11 (Speed Weekend). |
| `0x2cbcc8` | `leaderboard/speed` with `location.region`, `location.track`, `location.vehicle`, `row`, `pageSize`, `friends`, `stat.timeRemaining`, `stat.vehicle` | The Weekend leaderboard and the "target player" and "global top" shown during a race (`SpeedWeekendGetTargetPlayer`, `GetGlobalTopTime`, `GetGlobalRank`). The same function adds the request parameter `myPosition=true` (see below). |
| `0x2cb7a8` | row attributes `accountName`, `accountId`, `timeRemaining`, `rank`, `vehicle`, `currentPlayer`, `estimated` | The parser of one Weekend row. Note: no `ghostAvailable`, unlike a Time Attack row (`0x2cb258`: `accountName`, `accountId`, `bestTime`, `rank`, `vehicle`, `currentPlayer`, `ghostAvailable`, `estimated`). |
| `0x2c9198` | `speed-weekend/viewed` with `location.track`, `location.vehicle` | Tells the server that the player has looked at that board. |
| `0x2c97b0`, `0x2c99b8` | `speed-weekend/beaten`; answer tags `beaten_times` with `time`, `accountName`, `account`, `oldTime`, `track`, `vehicle` | "Somebody beat your time": who, with what time, over which old time, on which track and vehicle. |
| `0x2c9628`, `0x2c99b8` | `AnnouncementTxt` and the log line "Display announcements is %d" | The announcement text of the Weekend (`SpeedWeekendGetAnnouncementText`) is the general `getAnnouncement` text. |

## What this server does

- **[LIVE]** The game asks `speed-weekend/beaten` at login and gets the same empty answer as PS Rewired's capture. It asks `leaderboard/speed` for the tracks it wants (with and without `friends=true`) when the menu opens and again after a race with `stat.timeRemaining=<time left>&stat.vehicle=<vehicle>`.
- **[LIVE]** A Speed Weekend race (mode 11, Rain God Spires, bike) sent `bestTime=22431`, `timeRemaining=22431`, `totalRaceTime=70232`, `totalRaceTimeInFirst=70232`, `won=1`, `position=1`, `laps=1`. `bestTime` is the time left on the countdown (22.4 s), more is better. Times are milliseconds.
- The server stores the race, keeps it off the Time Attack boards, and answers `leaderboard/speed` with rows made of exactly the attributes above, most time left first.

## What is still unknown

1. **The shape of the `beaten` answer.** Decompiling the parser (`0x2c99b8`) shows: the root element is `beaten_times`; its children are `<time>` elements (at most 200); for each, the game reads the string `accountName` and the integers `account`, `time`, `oldTime`, `track` and `vehicle` (the vehicle is stored minus 1) with the same helpers that read the attributes of the leaderboard rows, so the likely form is `<XML><beaten_times><time accountName=".." account=".." time=".." oldTime=".." track=".." vehicle=".."/></beaten_times></XML>`. **Tested:** the game accepts this form and marks the ticket red (see the update at the top); an empty list stays PS Rewired's idle answer. The game shows a notice when the list is not empty.
2. **`myPosition`.** Decompiling `0x2cbcc8` shows that it is a **request parameter**, not an answer field: the game adds `myPosition=true` next to `friends=true` (source lines 0x14d and 0x151 of `ms2actions.cpp`), so it asks the server to include the player's own position. No captured request has it, so the answer the game expects (probably the player's own row, `currentPlayer="1"`, with the true rank) is not confirmed. The server ignores the parameter.
3. **Ghosts.** After a Time Attack race the game posts the ghost (the replay of the best lap) as the body of the `finishGame` request (`ghostLength=47460` in the query, `application/octet-stream`). The server now stores the fastest ghost per driver, track and vehicle (`server/data/ghosts`). The download request is decoded in [ghosts](ghosts.md): `GET ghost?location.gameMode=9&location.vehicle=V&location.track=T&account=ID`, answered with `<ghost><data>BASE64</data></ghost>`. The server serves stored ghosts that way and says `ghostAvailable="1"` for them. Verified in the game (the request is `leaderboard/ghost`, see [ghosts](ghosts.md)).
4. **Whether a Weekend race posts a ghost.** None of the Speed Weekend races seen (five, two accounts) had a `ghostLength`.
5. **The text of the beaten notice** and the numbering of `vehicle` in it (the parser subtracts one); only the red/green marker was seen.

## Seen in the game

- A won run: `won=1`, `position=1`, `timeRemaining`=`bestTime` in ms, `laps=1`. A lost or abandoned run: `position=100`, `bestTime=0`, `laps=0`. After a won run the game posts a second report with only the best time, `position=100` and no `totalRaceTime` (bookkeeping, not a race).
- `speed-weekend/viewed?location.track=14&location.vehicle=1` is sent about every four seconds while a board is open; `speed-weekend/beaten?` at every login.
- Two accounts on the same track: the second account's 34.87 s left beat the first one's 32.87 s; the first account got the red marker, and the green one after looking at the board.

## Ways to find out

- **Ghost download:** a controlled Time Attack run in RPCS3 (upload, choose the ghost, replay); see [ghosts](ghosts.md).
- **`beaten` shape:** the strings come from the game's SVO client; decompiling `0x2c99b8` in Ghidra shows which child names it looks for. The PowerPC ELF could not be opened with the tooling used so far.
- **Real data:** a capture of the original service during a Weekend (PS Rewired's captures were taken when none was running).
