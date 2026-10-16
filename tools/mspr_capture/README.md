# mspr_capture — passive network observation for MSPR (RPCS3 / PS Rewired)


Safe, **passive** tool to identify which hosts, ports and protocols your own
RPCS3 MotorStorm: Pacific Rift client uses when connecting to PS Rewired
(including the new ranked matchmaking / stats / leaderboard features).

It **only listens**. It does not modify DNS, routing, firewall rules, proxies,
game files or any server, and it **never uploads anything** — every output
file stays on your disk.

## What it records (observed facts only)

- DNS queries and answers (which hostnames the client resolves)
- Network flows: source/destination IP, ports, protocol, packet/byte counts,
  first/last-seen timestamps, DNS names matched to destination IPs
- Plaintext HTTP requests/responses: method, path, status and headers —
  with `Authorization`, `Cookie`, tokens and PSN-style identifiers redacted
- An annotation when packets appear on TCP/UDP 10070–10099 (the historical
  SCERT hint range) — recorded as an *observation*, not a conclusion

TLS, SCERT and any other encrypted payload is treated as **opaque** by the capture itself; it never decrypts, proxies or extracts keys while recording.

Two separate tools work on Medius (SCERT) traffic afterwards:

- `python -m mspr_capture.medius_decode capture.pcapng --keys keys.jsonl` lists the Medius TCP frames of a capture and decrypts the ones for which it has a session key (verified by the frame hash, so a wrong key never gives output that looks right). The game's RSA public key is readable without any key; session keys come from `mspr_proxy --keylog` or your own server, because a capture holds them only under the client's RSA key.
- `mspr_proxy` (next to this package) is an active man-in-the-middle for your own client, see [its README](../mspr_proxy/README.md).

TLS is not decrypted: the game's SVO runs as plain HTTP, and the only TLS (`api.psrewired.com`) is not the game protocol.

## Requirements

- Windows 10/11
- Python 3.10+
- [Npcap](https://npcap.com) (free edition) — installed with default options
  (`wpcap.dll` must exist in `C:\Windows\System32\Npcap\`)

```powershell
pip install -r ../../requirements.txt   # scapy, pytest (from this folder)
```

Capturing requires the Npcap driver, so run the CLI from a shell that can
access the Npcap driver (by default the installed "Admin Only" option means
an elevated terminal).

## Usage

Run the commands from the `tools/` folder (the package is `tools/mspr_capture`).

List capture-capable interfaces:

```powershell
python -m mspr_capture.cli --list-interfaces
```

Run a 15-minute capture on the Ethernet interface, writing to `captures\`:

```powershell
python -m mspr_capture.cli --interface Ethernet --duration 900 --output-dir captures
```

Options:

| Option | Meaning |
|---|---|
| `--interface` (required) | explicit interface selection (name or description fragment) |
| `--duration` | seconds to capture (default 600), Ctrl-C stops cleanly anytime |
| `--max-mb` | hard size limit for the PCAPNG (default 200 MB) |
| `--bpf-filter` | BPF filter (default `ip and (tcp or udp)`) |
| `--output-dir` | where PCAPNG + JSON go (default `captures/`) |

Outputs: `mspr-<timestamp>.pcapng` (raw capture) and
`mspr-<timestamp>-summary.json` (sanitized summary, owner-only permissions).

### What v0.2 adds

- **TCP connection events** — every SYN / FIN / RST with timestamp, classified
  per protocol (dns / http-plaintext / quic-http3 / tls / scert-hint-range)
- **Flow classification + duration** — each flow is labeled by detected protocol
- **HTTP body extraction** — plaintext HTTP response/request bodies
  (JSON **and XML**, e.g. PS Rewired leaderboard XML) are reassembled from TCP
  segments regardless of port (PS Rewired serves HTTP on port 10060!) and saved
  redacted inside the summary under `http_bodies`
- **Interactive event markers** — while capturing, type a short label + Enter
  (e.g. `opened ranked`) and it is timestamped into `events` so you can
  correlate in-game actions with network activity
- **tshark enrichment (automatic when Wireshark is installed)** —
  TLS/QUIC ClientHello facts (SNI incl. ECH outer name, ALPN, version) under
  `tls_quic_handshakes`, and full HTTP object export under
  `captures/http_objects/` (sanitized, binary bodies dropped)

Re-run analysis on an existing PCAPNG offline:

```powershell
python re/reanalyze.py ../captures/mspr-XXXX.pcapng
```


## Capture procedure (ranked / leaderboard investigation)

1. Start RPCS3. **Do not** launch the game yet.
2. Start the capture:
   `python -m mspr_capture.cli --interface Ethernet --duration 900 --output-dir captures --label ranked`
3. In game: open **Ranked** → enter **matchmaking** → play one race → open the
   **leaderboard** → exit back to the menu.
4. Press `Ctrl-C` (or let the timer run out) for a clean stop.
5. Open the `*-summary.json` and check the `dns_queries`, `flows` and
   `scert_hint_range_observations` sections.

Timestamped sections let you correlate: DNS resolution → TCP connect →
matchmaking traffic → race traffic → leaderboard traffic.

## Report format

The JSON summary contains only observed facts, grouped as:

- `dns_queries` — {timestamp, query, type, answers}
- `flows` — {protocol, src/dst ip:port, packets, bytes, first/last seen, dns_names}
- `http_plaintext` — {direction, method/path or status, headers (redacted)}
- `scert_hint_range_observations` — packets seen on 10070–10099 with peer IPs
  and an explicit "purpose not confirmed" note

Nothing is labelled a "leaderboard endpoint" unless the capture itself shows
it. Inferences are kept out of the data; if you correlate flow timings with
your in-game actions, mark them as inferences in your notes, not in the file.

## Tests

```powershell
python -m pytest -q
```

Tests use **synthetic packets only** (built with scapy in-process) and cover
DNS observation, flow summaries and secret redaction. No real traffic or
credentials are used.

## Limitations

- PS Rewired game protocol traffic is expected to be **SCERT-encrypted**.
  This tool does not and cannot decode it. Payloads on game ports are counted
  (sizes, timing, endpoints) but their contents are opaque. Decoding would
  require official documentation or authorized API access from PS Rewired —
  not reverse engineering, key extraction or MITM, which this tool refuses
  to do by design.
- Plaintext HTTP is rare on modern game backends; if everything is TLS or
  SCERT, `http_plaintext` will simply be empty.
- TLS SNI (server name in the ClientHello) is not parsed in this version;
  DNS answers in the summary usually give the same host→IP mapping.
- Loopback/VPN traffic appears on other interfaces — capture the interface
  the game actually uses (check with Task Manager → Performance → Ethernet).
- 10070–10099 annotations are **hints from old captures**, not conclusions
  about the current protocol.

## Privacy & safety

- Capture only on the interface you explicitly selected
- No DNS/route/firewall/proxy changes, no packet injection
- JSON summary redacts credentials/tokens/PSN identifiers defensively
- All files stay local; nothing is uploaded
