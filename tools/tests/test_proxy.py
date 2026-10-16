"""mspr_proxy end to end: a fake game, the proxy and a fake Medius server on loopback."""

import asyncio
import os
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS))
sys.path.insert(0, str(TOOLS / "scert"))

from mspr_capture.medius_decode import decode_stream  # noqa: E402
from mspr_proxy.proxy import FrameReader, Proxy  # noqa: E402
from rt import RCQ, RSA, SERVER_RSA, gen_rsa512, seal, split_frames, Frame  # noqa: E402

CLIENT_SESSION, SERVER_SESSION = 3, 1


async def fake_server(reader, writer, seen, reply):
    fr = FrameReader(reader)
    f = await fr.next()                                              # CLIENT_HELLO
    writer.write(Frame(0x25, False, b"", b"hello" * 10).pack())
    f = await fr.next()                                              # CLIENT_CRYPTKEY_PUBLIC
    body, ok = SERVER_RSA.decrypt(f.body, f.hash)
    assert ok
    client = RSA(int.from_bytes(body[:64], "little"), 17)
    key = bytearray(os.urandom(64))
    key[-1] &= 0x7F
    key = bytes(key)
    writer.write(seal(0x13, key, client).pack())
    await writer.drain()
    while True:
        f = await fr.next()
        if f is None:
            return
        plain, ok = RCQ(key, f.ctx).decrypt(f.body, f.hash)
        assert ok
        seen.append((f.mid, plain))
        c, h = RCQ(key, SERVER_SESSION).encrypt(reply(plain))
        writer.write(Frame(0x0a, True, h, c).pack())
        await writer.drain()


async def run_session(hook, seen, keylog):
    server = await asyncio.start_server(lambda r, w: fake_server(r, w, seen, lambda p: b"\x01\x02" + p[2:] + b"!"), "127.0.0.1", 0)
    up_port = server.sockets[0].getsockname()[1]
    proxy = Proxy(("127.0.0.1", up_port), None, keylog, hook)
    pserver = await asyncio.start_server(proxy.handle, "127.0.0.1", 0)
    p_port = pserver.sockets[0].getsockname()[1]

    r, w = await asyncio.open_connection("127.0.0.1", p_port)         # the fake game
    fr = FrameReader(r)
    w.write(Frame(0x24, False, b"", b"x" * 20).pack())
    g = await fr.next()
    assert g.mid == 0x25
    me = gen_rsa512()
    w.write(seal(0x12, me.n.to_bytes(64, "little"), SERVER_RSA).pack())
    g = await fr.next()
    peer, ok = me.decrypt(g.body, g.hash)
    assert ok
    key = peer[:64]
    c, h = RCQ(key, CLIENT_SESSION).encrypt(b"\x01\x58hello world")
    w.write(Frame(0x0b, True, h, c).pack())
    g = await fr.next()
    reply, ok = RCQ(key, g.ctx).decrypt(g.body, g.hash)
    assert ok
    w.close()
    server.close()
    pserver.close()
    return reply


def test_relay_unchanged():
    seen = []
    reply = asyncio.run(run_session(None, seen, None))
    assert seen == [(0x0b, b"\x01\x58hello world")]
    assert reply == b"\x01\x02hello world!"


def test_hook_changes_both_directions():
    def hook(direction, mid, payload, ctx):
        if direction == "C->S":
            return payload.replace(b"hello", b"HELLO")
        return payload + b"?"
    seen = []
    reply = asyncio.run(run_session(hook, seen, None))
    assert seen == [(0x0b, b"\x01\x58HELLO world")]
    assert reply == b"\x01\x02hello world!?" or reply.endswith(b"!?")


def test_keylog_decodes_stream():
    import io
    import json
    log = io.StringIO()
    asyncio.run(run_session(None, [], log))
    rec = json.loads(log.getvalue().splitlines()[0])
    key = bytes.fromhex(rec["k_down"])
    c, h = RCQ(key, CLIENT_SESSION).encrypt(b"\x01\x58abc")
    stream = Frame(0x0b, True, h, c).pack()
    out = list(decode_stream(stream, [key], "C"))
    assert out[0]["ok"] and bytes.fromhex(out[0]["payload"]) == b"\x01\x58abc" and out[0]["medius"] == "1:0x58"
    assert list(decode_stream(stream, [bytes(64)], "C"))[0]["ok"] is False      # a wrong key never "decrypts"


def test_split_frames_keeps_partial():
    data = Frame(0x0b, False, b"", b"abc").pack()
    frames, rest = split_frames(data + data[:2])
    assert len(frames) == 1 and rest == data[:2]
