# mspr_proxy

A Medius (SCE-RT) TCP man-in-the-middle for your own MotorStorm client.

```
game <-- session key A --> mspr_proxy <-- session key B --> Medius server
```

SCE-RT's key exchange is unauthenticated and the server's RSA key is the public SCERT default, so the proxy can read the game's RSA key, give the game its own session key and run a second handshake upstream. Each frame is decrypted, logged as JSON, optionally changed by a hook and encrypted again.

```powershell
python -m mspr_proxy.proxy --listen 0.0.0.0:10071 --upstream <server-ip>:10071 --log session.jsonl --keylog keys.jsonl
```

Run one proxy per Medius port (10071 MUIS, 10075 MAS, 10078 MLS, 10079 MMS ...); the servers tell the game which addresses to use next, so for a full session the DNS or the server's answers must point at the proxy as well.

## Hooks

```python
def on_message(direction, mid, payload, ctx):   # direction "C->S" or "S->C"
    return payload      # unchanged; return other bytes to change the frame, None to drop it
```

`mid` is the SCE-RT id (0x0b client app message, 0x0a server app message); for those the first two bytes of `payload` are the Medius class and type.

## Limits

- TCP only. DME's UDP game data and the DME session keys (`SERVER_CRYPTKEY_GAME`) are relayed untouched, so a race through the proxy is not expected to work.
- Tested against a live Horizon server with `tools/medius/medius_testclient.py` (in the MSPR-Server repository) and against a fake server in `tests/test_proxy.py`; not yet with a real game.
- Use it only with your own client and a server you are allowed to talk to. It does not break TLS and does not work on any server that authenticates its key.
- `--keylog` stores session keys: anyone with the log and a capture can read that session.
