# Findings

What was learned from live play on the running server (RPCS3 with RPCN accounts), from the first real PS3 login attempts and from the move of Horizon to .NET 10. Evidence tags as in the [reverse engineering report](reverse-engineering.md): **[EBOOT]** decompiled game code, **[LIVE]** seen on the wire or in the logs, **[INFERENCE]**.

## 1. Ghost download: the request is `leaderboard/ghost` **[LIVE]**

The request of the game is

```text
GET /motorstormpr/leaderboard/ghost?location.gameMode=9&location.vehicle=4&location.track=6&account=61025
```

not `/motorstormpr/ghost` as it was inferred from the code. The address is the Time Attack leaderboard address with `/ghost` added, so a server that treats every `leaderboard/*` path as a leaderboard answers it with an empty leaderboard and the game shows "An error occurred while communicating with the server". Answered with

```xml
<XML>
    <ghost>
        <data>BASE64 of the stored ghost</data>
    </ghost>
</XML>
```

the game accepts the ghost, saves it and lists it in Time Attack (verified with a second account in RPCS3, Colossus Canyon, Rally Car, a 68 800-byte ghost). The upload (`finishGame` body, `ghostLength`) is unchanged. Fix: commit `2d47d76`.

## 2. Speed and Volcano Weekend, verified **[LIVE]**

**The result.** A Speed Weekend race is `finishGame` with `location.gameMode=11` (Volcano Weekend is 10, not seen yet). The fields of a won run:

```text
location.track=14  location.vehicle=1  endState=1  endNormal=1  won=1  position=1  laps=1
bestTime=32868  timeRemaining=32868   (milliseconds left on the countdown, more is better)
totalRaceTime=72132  totalRaceTimeInFirst=72132  boostDistance  distanceTravelled  furthestBoostDistance  version=2
```

`position` is 1 for a win; the finishing place of a run against the clock is only `won` (1 or not). A run that was lost or abandoned reports `position=100`, `bestTime=0`, `laps=0` and a short `totalRaceTime`. **Position 100 means "did not finish"** in every mode.

**The bookkeeping report.** About a second after a won Weekend race (and again after a later login) the game posts a second `finishGame` with only `bestTime`, `position=100`, `laps=0` and `version=2`, no `totalRaceTime`. It repeats the best time, it is not a race. The server stores it but does not list it (`isRace` in `server/src/db/types.ts`).

**The board.** After the race the game asks `leaderboard/speed?...&location.track=14&location.vehicle=1&stat.timeRemaining=32868&stat.vehicle=1`, with and without `friends=true`. Rows are `accountName`, `accountId`, `timeRemaining`, `rank`, `vehicle`, `currentPlayer`, `estimated`, most time left first. Seen working with two accounts. On opening the menu it asks the board of every Weekend track; `myPosition=true` came with the Time Attack boards too and the answer without it was accepted.

**"Somebody beat your time".** At every login the game asks `GET speed-weekend/beaten?` (no parameters). Answered with

```xml
<XML>
    <beaten_times>
        <time accountName="RacerTwo" account="61027" time="34874" oldTime="32868" track="14" vehicle="1"/>
    </beaten_times>
</XML>
```

the game marks the ticket of that track with a **red** marker and bar (under "Target Time"). While the player looks at that board the game calls `speed-weekend/viewed?location.track=14&location.vehicle=1` about every four seconds; after that the marker is **green** at the next look. The server therefore answers `beaten` with the fastest other time that is better than the player's best and was posted after the player's own race or last `viewed`, and `viewed` clears it (`weekend_views` table). An empty list is PS Rewired's idle answer (`status` 20407). The text the game shows for a beaten time was not read, so the numbering of `vehicle` (the decompiled parser stores it minus one) is still unconfirmed; the server sends the same number as in the leaderboard rows.

## 3. Online races with two players **[LIVE]**

Custom and Ranked races between two RPCS3 accounts ran to the end; both accounts posted a result, the summary said "everyone posted a result". The race list needs `placedN` / `playersBeatenBy` for the place; the `position` of both racers of a two-player race is 2. Against the clock (Time Attack, Speed and Volcano Weekend) there is no place.

## 4. The NP ticket and its signature **[LIVE, EBOOT]**

The ticket the game posts to `https:ticket/login` (and sends in the Medius `TicketLoginRequest`) is an XI5 ticket:

| Part | Content |
|---|---|
| header (8 bytes) | version (2 bytes, `2101` = 2.1), 4 bytes, ticket length (2 bytes) |
| body field | `0x3000`, length (2), the body: serial, issuer, issue and expiry time, user id, online id (32 bytes), country, domain, service id, title id ... |
| footer field | `0x3002`, length (2): a binary field with the signer name (`RPCN`, or a key id for a PSN ticket) and a binary field with the signature |

Signatures, as Horizon checks them at the Medius login:

- **RPCN** (signer `RPCN`): ECDSA on the curve secp224k1, hash SHA-224 of the **whole body field including its 4-byte field header** (bytes 8 to 8 + 4 + length), RPCN's public key `ME4wEAYH...` (in `XI5Ticket.cs`). The signature is a DER sequence of two integers.
- **PSN** (a real PS3, signature of 56 bytes): ECDSA secp192r1, SHA-1 of **everything before the signature** (header included), Sony's title key (`DefaultSigningKey`, X `39c62d06...`, Y `a5d578b5...`). The signature may carry one or two stray bytes behind the DER sequence.
- Ticket version 4.0 has a 10-byte header and an unsolved hash; it is not checked.

`server/src/svo/ticket.ts` does the same check for the SVO login and writes `ticket: {signer, valid, reason}` into the `login` event; it only logs by default (`svo.requireSignedTickets`). Six RPCS3 logins verified (`signer: rpcn, valid: true`). The ticket in `server/test/fixtures/svo` does **not** verify (the captured ticket was altered, probably redacted), so the tests build tickets with their own keys. The PSN path is not yet seen on a real ticket.

**The ticket is the only way to tell RPCS3 from a real PS3.** Both send `SVO-Platform: PS3`, the same `Content-Type` and no User-Agent.

## 5. First observations of a real PS3 **[LIVE]**

- A real PS3 (PSN id, signer a PSN key) logs in to SVO, accepts the EULA and loads the leaderboards like RPCS3.
- It asks this server's DNS for about 250 PlayStation Network names (profiles, authentication, matching, STUN). RPCS3 asks for none. `dns.forwardNames` now forwards `playstation.net`, `playstation.com` and `sonyentertainmentnetwork.com` upstream; names of anything else are refused.
- Ranked games with a PS3 player ended with "NO RESULT": the results arrive only right after the next SVO login (`result.queued` events). Not caused by the DNS rate limit (the firewall limit dropped no packet). The cause is still open; a full PS3 race with the request log is needed.
- A PS3 player was banned automatically by the anti-cheat because the saved results after login looked like impossible races; see diagnostics. The anti-cheat is off on the live server.

## 6. Horizon on .NET 10 **[LIVE]**

.NET 6 is out of support. Horizon builds for `net10.0` with these changes and pitfalls:

- C# 14 makes `field` a keyword inside a property accessor (`CookieParser.cs`): rename the variable.
- `XI5Ticket` uses `[GeneratedRegex]` on .NET 7+, so the class must be `partial`.
- **Enumerating an empty `DefaultChannelGroup` never ends on .NET 8+** (dotnet/runtime #105576). `MMS.Tick` did it as soon as the last MMS client left, spun one thread at 100 % and stopped the whole Medius tick loop; every answer of every server stopped, and the game stayed on "Searching for Ranked Game". Always take `Group.ToArray` first (the other servers already did, MMS did not).
- Named machine-wide mutexes (`Global\...`) cannot be created in the hardened systemd service (`The system cannot open the device or file specified`); GeoIP and the certificate chain were never initialised. `MultiServerLibrary/InitLock.cs` falls back to a process-local mutex.
- Finding such a hang: `dotnet-stack report -p <pid>` shows the managed stacks. With `PrivateTmp=yes` the diagnostic socket is in the service's private `/tmp`; point `TMPDIR` at a short symlink to it (the socket path is limited to 108 characters). A thread at 100 % CPU in `top -H` is the one to look for.

## 7. How the game sends a race result **[EBOOT]**

Read while looking for why a real PS3 posts its Ranked results only at the next SVO login (section 5). Decompiled with Ghidra from the v1.03 EBOOT; the cause is **not found yet**, but the path is now mapped.

- **The request.** `FUN_002c8328` builds the `finishGame` parameters from the *current stats* of the stats manager: `location.gameMode`, `location.track`, `location.vehicle`, `endState`, `gameName`, `gameId` and one parameter per stat (log line `Submitting pending race stats for game mode %d.`). Without current stats it fails with `No current stats available` and sends nothing.
- **The senders.** `0x2c8760` (a Time Attack result: logs `Posting ghost data`, adds `ghostLength` and the ghost as an `application/octet-stream` body) and `0x2c89a0` (every other result) call the SVO client's submit method (virtual slot +0x14) with the action name `finishGame`, and set a "sent" flag in the action (+0x38). Nothing in them queues or retries: the request goes out when they are called.
- **The decision to post.** Three state-machine handlers (`0x851258`, `0x852da0`, `0x85acd8`; table entries at `0xe7b768`, `0xe7b838`, `0xe7b9d8`) log `No pending stats, skipping score post.` and do nothing when the stats manager holds no pending stats. When it does, the first two (`0x851258`, `0x852da0`) ask the owning object a virtual question (**slot +0x224, returns a bool**) and only if the answer is true queue event `0x24` (the score post, judging by the log lines around it). The third, `0x85acd8`, is the dropout handler (`SM_Dropout callback is now CB_DropoutStartSVO`): it asks nothing and queues `0x20`, `0x55`, `0x51`, `0x5f` and `0x24`.
- **The offline path.** `0x8ea10` logs `** Updating Online Profile with offline stats etc **` and applies the `Online.ranked.*` counters of results that were kept offline.
- **What this means.** The condition of the post (slot +0x224) turned out to be the "StartSVO" step and a flag that is true everywhere (see the post-race flow below), so it is not what keeps a real PS3's results back. The game's own texts add a second candidate: it has a separate "problem posting a score to the PlayStation Network server" message (see [game-data.md](game-data.md)), so the Ranked score also goes to PSN (NP Score), which a replacement server does not see.
- **The NP Score path.** Besides the SVO result the game posts scores to the PlayStation Network itself. A class `cNpScore` (strings `InitNpScoreboards`, `Started cNpScore`) has two boards, `NPSCORE_BOARD_RANKED` and `NPSCORE_BOARD_TIMEATTACK`. `0x29d200` (`Setting Ranked score`) fills the score record and calls the post callback (`CallPostNpScoreCB`) unconditionally; `0x29d040` (`Setting Time Attack score`) does the same only when the new time is better than the best known one (`Score is not better, so not posting to Ranking Scoreboards`) and also calls a ghost post callback. `0x857f38` (`Posting NP scores Ms2Online`) is the state-machine step that queues the score post (events `0x54`, `0x22`). This goes to Sony's servers (RPCN on RPCS3), not to the SVO server. How the two posts, the NP score and the SVO `finishGame`, depend on each other is not traced yet; if the game waits for the NP score post of a real PS3 to finish before the SVO result is sent, a failing or slow PSN score service would explain the late results.
- **The post-race flow (mini state machines).** The game runs its online steps as small, **data-driven state machines**. The class `Ms2Online` (vtable `0xe586c8`) keeps a queue of 16-byte events (`0x850ba0` appends one: event id, sequence number, flag, **continuation function**; log line `Queuing mini statemachine %s`). The runner (`0x852300`) takes the next event, creates a task for its id (`0x2c18d0`, `Created MiniStateMachine %s`), polls it (`0x2c16b8`) and, when the task has finished, calls the continuation with the task's **result record** `{code, state}`: code `0x5c` means ok, `0x5b` means failed (set by `0x2c18b8` and `0x2c1880`), and `0x26eba8` turns a finished task into `0x5c`/`3` (or `0x5b`/`3` after an error). The states of a task and its transitions are tables in the EBOOT (state records at `0xd08f80`..., action functions at `0xe5bb80`, condition functions at `0xe5bee0`; the conditions are "record state is 0" = step ok, "record state is 1" = step failed, "retry" and "cancel" after the error dialog `0x2731f0`). A step is a call to a virtual method of the global online object.
  That object must be, in an online game, **`cOnlineOnline`** (vtable `0xe58e18`; this is inferred from the fact that `cOnline` and `cOnlineNP`, the other classes with the same slots, have empty stubs for all of these steps and the tasks would never finish; the allocation of the object was not traced). It owns the SVO manager at +0x16a0, and every SVO step runs only while the `useSVO` flag (`0xf35ac0`, `SVO is enabled.`) is true, which it is on the disc. The step **`Posting SVO Scores` (`0x857450`)** first asks `cOnlineOnline` slot +0x2c, which returns **true** (`0x137f0`). So the game does *not* restart SVO after a race: it queues events `0x50` and `0x4d`, the continuation `0x852da0` checks that the stats manager holds pending stats and that `StartSVO` (`0x85d188`, slot +0x224 of `Ms2Online`) is fine, and then queues event `0x24`. **Task `0x24` is the real post:** one step, `cOnlineOnline` slot +0xd54 = `0x881570` = the SVO manager runs the `finishGame` action (`0x2c29a8`), then success or the error dialog. The `finishGame` builder is `0x2c8328` (see above). Only when that first question is false (not the case for this class) would the dropout path run: `CB_DropoutStartSVO`, tasks `0x20`, `0x55`, `0x51`, `0x5f` and then `0x24` (a restart of SVO: NP ticket, then the SVO actions).
  Task `0x5f`, the SVO start, is a chain of seven steps with a retry loop: the NP ticket (`0x882b68`, `0x882b38`, log line `DownloadNPTicket()`), then the SVO manager actions `+0xd40`, `+0xd44`, `+0xd48`, `+0xd50` (`0x2c1ee8`..`0x2c20a0`, each runs one entry of the SVO manager's table of actions), with the condition `0x2c27b8` choosing whether the NP ticket part is needed. Each step ends in "ok" or the error dialog (`Unable to login to the SVO server` and the other texts of [game-data.md](game-data.md)); "cancel" ends the task with `0x5b` and the continuation prints `SVO STart failed, stopping.`.
  What this leaves: the post of a race is **task `0x24` against the existing SVO session**, so a result that arrives only after a new login means that this task failed or never ran on the PS3: its `finishGame` request was not sent or not answered ok, the game kept the stats pending, and posted them after the next SVO start. The next facts to get are therefore on the wire: whether a `finishGame` arrives at the end of the race at all (the `result.received` event answers that) and, if it does, how the server's answer differs from what the game takes as ok. The game's own log lines cannot show this: the logging function (`0x27c1b8`) is an empty function in the retail build and the RPCS3 TTY log has none of them. Only a debugger on RPCS3 (breakpoints on `0x881570`, `0x2c29a8` and `0x2c8328`) would show the order.
- **Server side, meanwhile.** Every `finishGame` now writes a `result.received` event with the cookie names, how the player was recognised (session cookie, last login of the address, nobody) and the time since the login. A PS3 race with that event in the journal shows whether the request arrives at all.

## 8. Other projects that revive this game **[research]**

No public project documents this game's SVO or Medius protocol in detail; what is known here is ahead of what could be found.

| Project | What it offers |
|---|---|
| PS Rewired (psrewired.com, title 21624) | Real PS3 works with DNS only (67.222.156.250 plus 8.8.8.8, UPnP on); custom match worked in 2022, Ranked/Casual not confirmed. Closed source as far as could be verified. RPCS3 host `motorstorm2ps3.online.scee.com`. |
| PSONE | DNS 185.194.142.4, real PS3 and PSN account, no jailbreak; MotorStorm among the games; closed. |
| PSORG (`PSOnlineReturnalGaming`) and `GitHubProUser67/PSHome-MultiServer` | MitmDNS, ApacheNet, Horizon (Jump-Suit fork), SVO; lists MotorStorm PR as RPCS3 cross-play only; the RPCS3 wiki says its SVO does not work for this game. `packet-captures` (PS3 folder) and `uya-medius-encryption` are Medius helpers. |
| `xtvaser/clank` (deprecated), `LittleBigRefresh/NPTicket` | A Medius 1.5-1.8 emulator; a C# NP ticket reader and verifier. |
| `RipleyTom/rpcn` | RPCN, the RPCS3 NP server; its FAQ says it does not work for real consoles. |

RPCS3 issue 13126 (a player's bug report, later closed): with ten or more players in a Ranked or Custom lobby the match failed to start for players on RPCS3, reportedly not for real PS3s. Its author said later that it was fixed and multiplayer works. The "An error occurred while communicating with the server" dialog mentioned in the report is a different thing: it appears now and then in the menu for everybody, real PS3s included, and can be declined without effect, so it is not related.
