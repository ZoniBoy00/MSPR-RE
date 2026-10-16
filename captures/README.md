# Captures

Material from reverse engineering the game and the former PS Rewired service.

- `captures/` holds redacted summaries of two network captures (a Ranked and a Custom Game session) and the HTTP objects extracted from them. The raw PCAPNG files, the game's EBOOT, the Ghidra project and decompiled sources are not in the repository.
- `live-traffic.md`: request-log excerpts of the running server (ghost download, Speed Weekend, `beaten`, NP ticket check, first real PS3, the .NET 10 hang), names of other players removed.
- The [reverse engineering report](../analysis/reverse-engineering.md) consolidates what is known about the protocol. Some of its evidence paths point at those local files.
- The tools that produced and analyse this material are in `../tools`.

The SVO requests and responses of the captures are also the test fixtures of the [MSPR-Server](https://github.com/ZoniBoy00/MSPR-Server) tests (`server/test/fixtures/svo`). Names of other players from the leaderboards are replaced by placeholders.

The summaries are filtered to the game: only traffic to or from the PS Rewired servers (SVO, Medius, API), np.rpcs3.net and the local test server remains. Everything else the capturing PC sent (browsers, chat, updates, VPN and so on) was removed.
