# The game's data archive

Notes on `PS3_GAME/USRDIR/ms2.psarc`, the 4.8 GB archive on the game disc. It holds everything the game loads besides the EBOOT, including the online rules. Evidence tag **[DISC]**: read from the files themselves.

The archive is a PSARC (version 1.3, zlib, 64 kB blocks, 5004 files). The extractor `tools/game-data/psarc.py` in this repository lists and extracts files (`list`, `get`, `extract`, `sizes`). Extracted game files are not stored in either repository.

## What is inside

| Folder | Files | Size | Content |
|---|---|---|---|
| `split_vehicles`, `packed_vehicles` | 1284, 105 | 6.4 GB, 2.7 GB | vehicle models and textures (`.rpk`) |
| `worlds`, `env` | 115, 72 | 1.3 GB, 0.4 GB | track geometry and environments |
| `audio`, `characters`, `animations`, `EffectMaps` | 239, 258, 55, 187 | | sound, drivers, animation, effects |
| `gui` | 275 | 0.5 GB | the menus (`.gui`), texture packs, videos |
| `data` | 2342 | 374 MB | tracks, tickets, databases, cameras, AI |
| `Configs`, `scripts` | 37, 19 | small | game options and Lua scripts |

## `data/databases`

| File | Content |
|---|---|
| `tickets.csv` | the 68 single-player tickets: zone, ticket name, unlock rule, XP needed, medal rule, track, vehicle class |
| `vehicles.csv` | 35 vehicles: class, number, three upgrade slots, availability |
| `rewards.csv` | 21 unlocks (the 3rd, 4th and 5th vehicle of each class) with their thresholds |
| `Stats.xml` | thresholds of the Speed, Skill and Aggression ratings (`SAS_Rank_Level`, `Skill_Ranking`, `Speed_Ranking`, `Aggression_Ranking`) and the weight class of each vehicle class |
| `playlist.csv` | the 45 licensed songs (46 lines) and their MP3 files |
| `characters.csv`, `grid-*.csv`, `boost*.csv`, `sideattack.csv`, `VehDeformationParams.xml`, `damagedefs.xml`, `plantdefs.xml` | driver, grid, boost, side attack and damage tuning |

`data/onlinerankings/rankings.xml` is the Ranked rule set, described in [ranked-xp](ranked-xp.md).

## Tracks and Weekend content

- `data/track_<name>/` holds the AI and world data of a track. Sixteen tracks have a `_speed` variant (`Xbeach`, `blackRock`, `calderaRidgeRace`, `coastlinerun`, `colossus_canyon`, `davetona`, `edge`, `happy_jungle`, `jurassicwaterfall`, `mudslide`, `raingod_spire`, `reborn`, `rift`, `scorched`, `sugarplant`, `volcanicwastelands`) and five a `_skill` variant (`colossus_canyon`, `davetona`, `scorched`, `sugarplant`, `volcanicwastelands`). These are the courses of the Speed Weekend and the skill events; the Weekend race of the live server (Rain God Spires, bike) is `track_raingod_spire_speed`. **[DISC, INFERENCE]**
- `data/events/tickets/` has 258 `.ticket` files (XML: title, number of gags, world, environment, vehicle class, difficulty) and `.gags`/`.packman` files for the rules of each event. There is no file named after the Speed Weekend: its tickets, targets and the festival schedule are not in the archive; the EBOOT and the save file have them. **[DISC]**
- `data/events/tickets/*.ticket` has no online ticket. The online modes do not read the archive for their rules besides the ranking table.

## Settings that matter for a server

- `Configs/Includes/ms2_BuildOptions.cfg` has the debug options `useSVO` (true), `svoSSL` (false), `svoDebug`, and two commented-out lines: `mediusUniverse` and **`svoUrl`** (`http://192.0.2.13:10070/MOTORSTORM2PS3_XML/`). The EBOOT has the matching log line `Setting override SVO URL %s`. The EBOOT reads the whole `DebugOptions` block unconditionally (`0x1a2b20`: `useSVO`, `svoDebug`, `svoSSL`, `mediusUniverse`, `svoUrl`; no check of `productionVersion` in that function), and the SVO setup (`0x27bd88`) uses a set `svoUrl` instead of the address from the universe information (`Setting override SVO URL %s` against `Using SVO URL from universe %s`). So the retail game should honour an `svoUrl` that is made active in `ms2_BuildOptions.cfg`. The value has the same form as the universe's: `http://<host>:10060/motorstormpr/index` (the game adds `?languageID=N`). **[DISC, EBOOT]** Not tried in the game.

The use is limited: the Medius address still comes from DNS (`motorstorm2ps3.online.scee.com`), and this server's universe information already sends the SVO address. The override helps when the SVO host name cannot be resolved (the SVO resolver wedge) or to point one client at another SVO server without touching DNS.

How to try it (on a copy of the game's archive, the tools are in this repository): `python tools/game-data/svo_url_override.py ms2.psarc http://<server-ip>:10060/motorstormpr/index --undo undo.json` changes only the 379-byte block of the config file in place; `python tools/game-data/psarc_patch.py ms2.psarc restore undo.json` puts the original bytes back (verified byte for byte on a copy of the real archive). Then start the game and watch the SVO log: the requests should arrive when the DNS name of the SVO host does not point to the server.
- `Configs/Includes/*GameOptions.cfg` has an `OnlineOptions` block with the online boost rubber band (`onlineBoostCatchupMinThreshold` 10, `...MaxThreshold` 35, `onlineBoostSlowdown...`). These are game rules, not server settings.
- `scripts/game_config.xml` has the `Lib Online` option.

## The update archive and the texts of the game

The installed 1.03 update adds `ms2patch.psarc` next to the disc archive (3,570 entries; it replaces files of `ms2.psarc`, among them `gui/`, `data/onlinerankings/rankings.xml` and `scripts/host.lua`). `common.psarc`, `pack01.psarc` and `pack02.psarc` hold downloadable tracks (among them the Speed and Volcano Weekend tracks). Read the update archive first and the disc archive for what it does not have.

**The texts.** `gui/text_<Language>.lang` holds every text of the game in 17 languages. The format is simple: two big-endian counts (the number of strings, twice), then that many pairs of (string id, offset), then the strings, zero-terminated UTF-8. The disc has 2,621 English strings, the update 2,920 (the Speed Weekend, the Volcano Weekend, the new trophies and the Microbadges came with the update). The ids are what the menus (`.gui` files, a packed resource format with `.lyt` layouts) refer to. What they say about the online side:

| Id | Text (shortened) | What it tells |
|---|---|---|
| 4200 | `Your Best Time has been beaten -` | The text of the Speed Weekend notice that `speed-weekend/beaten` feeds (what follows it, presumably the name and the time, comes from the data). |
| 4191, 4199 | A red helmet on the Speed Weekend progress bar means a *friend* has beaten your time; it clears when you have viewed the leaderboard. | The marker is about the friends board, and viewing it is what `speed-weekend/viewed` reports. |
| 4183 | If you try this race again, your new Target Time will be the Result Time of your closest rival on the leaderboard. | The Weekend reads the leaderboard to set a target. |
| 2750, 2751 | `There was a problem posting a score to / retrieving scores from the PlayStation Network server` | The game has a separate score post to **PSN** (NP Score) besides the SVO result; see [findings](findings.md) section 7. |
| 2747, 2749, 2748 | problems downloading stats, logging in to the SVO server, downloading the Location ID | The error texts of the SVO actions. |
| 2716, 1450 | `An error occurred while communicating with the server.` | The dialog that appears now and then in the menu (not tied to a fault of the server). |
| 2727, 2729 | the server has no account details for you / reports that your account is banned | What the login answers can say. |
| 3975, 3977, 4101 | Volcano Weekend: a festival, a duel race, the page title | The Volcano Weekend exists in the game (game mode 10 is still inferred). |

**Regions.** `data/onlinelocations/locationmap.xml` maps a country code to a region number: 1 for the United States, 2 for Canada, 3 for Europe and most others, 4 for Australia and New Zealand, 5 for Japan, Korea, Taiwan, Hong Kong and Iceland. It is presumably where the Location ID and the region filter of the leaderboards come from (the game has the texts "Location ID" and "Region Select"); this is inferred, not traced in the code.

**Vehicles.** The class order of `vehicles.csv` and `vehicleselectparams.csv` is Bike, ATV, Buggy, Rally Car, Racing Truck, Mud Plugger, Big Rig (the Monster Truck class comes with the downloadable content). The wire value `location.vehicle` counts these from 1; the game keeps it from 0, which is the "minus one" of the `beaten` parser. The server's table (1 Bike ... 7 Big Rig, 8 Monster Truck) is right.

**Scripts.** `scripts/*.lua` are tuning files (vehicle definitions, particles, cameras, logging) and contain no online logic. `logging.lua` switches `LibOnline(true)` on.

## Ideas that follow

- Check the Speed and Volcano Weekend times against the real courses: the length of a `_speed` course gives a lower bound for a plausible time.
- Read the unlocks (`rewards.csv`) and the ticket list to show the career data of a driver on the status site (the game keeps these in the save, not on the server).
- Test the `svoUrl` override in an RPCS3 game folder copy.
