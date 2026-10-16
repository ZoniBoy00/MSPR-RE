# Time Attack ghosts

> **Verified:** the download works in the game. The request is `GET /motorstormpr/leaderboard/ghost?location.gameMode=9&location.vehicle=V&location.track=T&account=ID` (not `/ghost`; the earlier inference below was wrong), answered with `<XML><ghost><data>BASE64</data></ghost></XML>`; the ghost is saved and shows in Time Attack. See [findings](findings.md#1-ghost-download-the-request-is-leaderboardghost-live).

Findings from the decompiled game (EBOOT v1.03, `source/online/svo/ms2actions.cpp`). Evidence tags: **[EBOOT]** decompiled code, **[LIVE]** seen on this server, **[INFERENCE]**.

## Upload **[EBOOT, LIVE]**

After a Time Attack race the game posts the result with `POST /motorstormpr/finishGame?...&ghostLength=N`. The body is the ghost as `application/octet-stream` (`0x2c8760`: `Posting ghost data : %s %s %s`, `Size %d`). A real run sent `ghostLength=47460`. `0x2c9408` can skip the post (`Skipping ghost data post`), `0x2c9538` posts stats at once when no ghost check is needed.

The server keeps the fastest ghost of each driver for each track and vehicle in `data/ghosts` (`<account>-<track>-<vehicle>.ghost` and a `.json` with the lap time), only when the announced length matches the body and the body is at most 256 kB.

## Download **[EBOOT]**

1. A Time Attack leaderboard row (`0x2cb258`) has the attributes `accountName`, `accountId`, `bestTime`, `rank`, `vehicle`, `currentPlayer`, `ghostAvailable` and `estimated`. The game offers the ghost of a row only when `ghostAvailable` is 1.
2. Choosing a ghost starts the SVO action `ghost` (`0x2c9900` creates it, `0x2c7c00` builds the request) with the query parameters `location.gameMode`, `location.vehicle`, `location.track` and `account` (the account id of the driver whose ghost is wanted). Because the name `ghost` is not among the addresses of the `index` answer, the request was expected at the SVO base address, `GET /motorstormpr/ghost?...` **[INFERENCE, wrong]**. **[LIVE]** The game builds it from the leaderboard address: `GET /motorstormpr/leaderboard/ghost?...`.
3. The answer is parsed by `0x2caf88`: the element `ghost` with a child `data` whose text is **Base64** (`Base64 size = %d`, `Unencoded size = %d` in `0x2cabb8`). The decoded bytes are loaded as the ghost (`Ghost: Buffer size %d, Current time %d, Split 1 time %d, Split 2 time %d, Split 3 time %d, Track=%s, Vehicle=%s`) and accepted only when the track and vehicle texts are set, the buffer is not empty and the current time and the three split times are not zero. Otherwise the game shows `GHOST DATA CORRUPT`; when nothing decodes it shows `NO GHOST DATA`.

So the downloaded ghost is the same data the owner uploaded; the server needs to store and return it, not to understand it.

## How the game uses a downloaded ghost **[EBOOT, RPCS3 log]**

Findings of a second round of reading:

- **Ghosts use SVO only.** The game's NP score code (`CallPostNpScoreCB`, `CallPostNpGhostCB`, `RegisterGhostDownload`, `RetrieveGhostData`, `PostGhostData`) is dead weight: the EBOOT imports only `sceNpScoreTerm` from the NP score library, and RPCS3's log shows it failing with `NOT_INITIALIZED`. There is no PSN/RPCN route to a ghost, so nothing outside this server can supply one.
- **Download starts in the leaderboard.** The GUI call `DownloadGhostFromLeaderBoard` (`0x14bc8`) runs a virtual method of the leaderboard object, which queues the state machine `RetrieveGhost` (`0x857788`) and with it the SVO action `ghost`. The button depends on `GetSelectedGhostAvailability`: it is dimmed when the selected row has no ghost (`ghostAvailable` 0). Whether it also stays dimmed on the player's own row is not known (the live test saw nothing to do on it).
- **A downloaded ghost is saved on the console** (`Saving the online ghost data`, `Checking for downloaded ghost for account %s`, `No downloaded ghost available`; `0x8df98`), and the Time Attack ghost table then lists it as an online ghost (`ghost_icon_downloaded.dds`, "Online Player Ghost Time"). The same table holds the player's own profile ghost and the developers' ghosts (`0x74240`, `Adding profile ghost`, `Adding dev ghost`, `Adding online ghost`). So the ghost choice shown before a race is built from local data: the player's own ghost, the developers' and whatever was downloaded earlier.
- **A ghost is tied to a vehicle.** The data holds the vehicle model (`racetruck02_LV02`) and track (`track_colossus_canyon`), and the leaderboard is asked per track and vehicle class, so a ghost is offered only when that class is selected.

## Live tests

- Time Attack, Colossus Canyon, Racing Truck, three laps, online: the game posted the result with the ghost (`ghostLength` and a 72 820-byte body: a 0x40-byte header followed by a buffer of 72 756 bytes); the server stored it and the board row said `ghostAvailable="1"`.
- A first run, started without an SVO session, posted no ghost at all (the game logs in to SVO only when the result is sent). The ghost is recorded and posted only when the online session exists before the race.
- The ghost that showed up in the player's own Time Attack was the local profile ghost; the log has no `ghost` request from the game.
- A second account could not use it: its Racing Truck is locked (the game offered Rally Car), and the ghost exists only for Racing Truck.

## A second account downloads the ghost **[LIVE]**

One account raced Time Attack on Colossus Canyon with the Rally Car; its result carried a 68 800-byte ghost, which the server stored as `<account>-6-4.ghost`. A second account opened the Rally Car board and pressed download, and the game sent `GET /motorstormpr/leaderboard/ghost?location.gameMode=9&location.vehicle=4&location.track=6&account=<first account>`. The first attempt was answered by the server's leaderboard handler (an empty leaderboard) and the game said "An error occurred while communicating with the server"; after `leaderboard/ghost` was routed to the ghost handler the ghost loaded and appears in Time Attack. The Base64 text with `\r\n` line ends inside the XML was accepted as it is.

## What the server does

- A Time Attack row says `ghostAvailable="1"` when the driver's ghost for that track and vehicle is stored, otherwise 0. (Weekend rows have no such attribute.)
- `GET leaderboard/ghost?...` (and `ghost?...`) answers `<XML><ghost><data>BASE64</data></ghost></XML>`, with an empty `data` for an unknown driver, track or vehicle and for malformed numbers (no path is built from them).
- Tests: `server/test/speed.test.ts` (stored ghost advertised, served, wrong track, vehicle, driver and malformed input).

## Open

- Done in RPCS3 (above). Not seen on a real PS3.
- Whether a ghost belongs to a lap (the game stores the best lap of the session) and how the splits are laid out inside the data: not needed for serving.
- Weekend runs have no ghost; the one Weekend race seen had no `ghostLength`.
