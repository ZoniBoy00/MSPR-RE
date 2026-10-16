"""Medius TCP man-in-the-middle for your own MotorStorm client.

    game  <--(session key A)-->  proxy  <--(session key B)-->  Medius server

The proxy plays the server for the game and the client for the real server. SCE-RT's key exchange is
unauthenticated: the server's RSA key is the public SCERT default (its private half is public knowledge),
so the proxy can read the game's RSA key, hand the game its own session key, and run a second handshake
upstream with a key of its own. Every frame is decrypted, written to a JSONL log, optionally changed by a
hook, and encrypted again for the other side.

Scope: TCP only (MUIS, MAS, MLS, MMS ...). DME's UDP game data is not touched, and a server that hands out the
DME address will still hand out the real one. Point the game at the proxy through DNS or a hosts file and
use it only with your own client and a server you may talk to.

Hook file: a Python module with

    def on_message(direction, mid, payload, ctx):   # direction "C->S" or "S->C"
        return payload          # unchanged; return other bytes to change it, None to drop the frame

Usage:
    python -m mspr_proxy.proxy --listen 0.0.0.0:10071 --upstream <server-ip>:10071 --log session.jsonl
        [--keylog keys.jsonl] [--hook hook.py]
"""

from __future__ import annotations

import argparse
import asyncio
import importlib.util
import json
import os
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "scert"))
from rt import (RCQ, RSA, RT_NAMES, SERVER_RSA, Frame, gen_rsa512, medius_label,  # noqa: E402
                seal, split_frames)

RSA_CTX = 7


class FrameReader:
    def __init__(self, reader: asyncio.StreamReader):
        self.r, self.buf, self.queue = reader, b"", []

    async def next(self):
        while not self.queue:
            frames, self.buf = split_frames(self.buf)
            if frames:
                self.queue.extend(frames)
                break
            chunk = await self.r.read(65536)
            if not chunk:
                return None
            self.buf += chunk
        return self.queue.pop(0)


class Proxy:
    def __init__(self, upstream, log=None, keylog=None, hook=None):
        self.upstream, self.log, self.keylog, self.hook = upstream, log, keylog, hook
        self.conn_no = 0

    @staticmethod
    def _write(f, rec):
        if f:
            f.write(json.dumps(rec) + "\n")
            f.flush()

    async def handle(self, d_r, d_w):
        self.conn_no += 1
        cid = self.conn_no
        peer = d_w.get_extra_info("peername")
        try:
            u_r, u_w = await asyncio.open_connection(*self.upstream)
        except OSError as e:
            print("[%d] upstream %s:%d unreachable: %s" % (cid, self.upstream[0], self.upstream[1], e))
            d_w.close()
            return
        down, up = FrameReader(d_r), FrameReader(u_r)
        try:
            keys = await self._handshake(cid, down, d_w, up, u_w)
            if keys is None:
                return
            k_down, k_up = keys
            print("[%d] %s: handshake relayed, session keys established" % (cid, peer))
            await asyncio.gather(
                self._pump(cid, "C->S", down, u_w, k_down, k_up),
                self._pump(cid, "S->C", up, d_w, k_up, k_down))
        except (ConnectionError, asyncio.IncompleteReadError):
            pass
        finally:
            for w in (d_w, u_w):
                w.close()
            print("[%d] closed" % cid)

    async def _handshake(self, cid, down, d_w, up, u_w):
        f = await down.next()                                   # CLIENT_HELLO, forwarded as it is
        if f is None or f.mid != 0x24:
            print("[%d] expected CLIENT_HELLO, got %r" % (cid, f and hex(f.mid)))
            return None
        u_w.write(f.pack())
        g = await up.next()                                     # SERVER_HELLO (carries the SCERT default key)
        if g is None or g.mid != 0x25:
            return None
        d_w.write(g.pack())
        await d_w.drain()

        f = await down.next()                                   # CLIENT_CRYPTKEY_PUBLIC: the game's RSA key
        if f is None or f.mid != 0x12:
            return None
        body, ok = SERVER_RSA.decrypt(f.body, f.hash)
        if not ok:
            print("[%d] could not read the game's key (server key differs from the SCERT default?)" % cid)
            return None
        game_rsa = RSA(int.from_bytes(body[:64], "little"), 17)

        me = gen_rsa512()                                       # our identity towards the real server
        u_w.write(seal(0x12, me.n.to_bytes(64, "little"), SERVER_RSA).pack())
        g = await up.next()                                     # SERVER_CRYPTKEY_PEER: session key B under our key
        if g is None or g.mid != 0x13:
            return None
        peer, ok = me.decrypt(g.body, g.hash)
        if not ok:
            print("[%d] upstream key exchange failed" % cid)
            return None
        k_up = peer[:64]
        k_down = bytearray(os.urandom(len(peer)))
        k_down[-1] &= 0x7F                                      # keep the value below the game's 512-bit modulus
        k_down = bytes(k_down)
        d_w.write(seal(0x13, k_down, game_rsa).pack())
        await d_w.drain()
        self._write(self.keylog, {"t": time.time(), "conn": cid, "client_n": game_rsa.n.to_bytes(64, "little").hex(),
                                  "k_down": k_down[:64].hex(), "k_up": k_up.hex()})
        return k_down[:64], k_up

    async def _pump(self, cid, direction, src, dst_w, k_src, k_dst):
        while True:
            f = await src.next()
            if f is None:
                dst_w.close()
                return
            plain, ok, ctx = f.body, True, f.ctx
            if f.sealed and ctx != RSA_CTX:
                plain, ok = RCQ(k_src, ctx).decrypt(f.body, f.hash)
            out = plain
            if self.hook and ok:
                out = self.hook(direction, f.mid, plain, ctx)
            self._write(self.log, {"t": time.time(), "conn": cid, "dir": direction, "id": f.mid,
                                   "name": RT_NAMES.get(f.mid, "?"), "ctx": ctx, "sealed": f.sealed, "hash_ok": ok,
                                   "medius": medius_label(plain) if f.mid in (0x0a, 0x0b) else None,
                                   "len": len(plain), "payload": plain.hex(),
                                   "changed": None if out == plain else (out.hex() if out is not None else "dropped")})
            if out is None:
                continue
            if f.sealed and ctx != RSA_CTX and ok and out:
                c, h = RCQ(k_dst, ctx).encrypt(out)
                nf = Frame(f.mid, True, h, c)
            elif f.sealed and ctx != RSA_CTX and ok:
                nf = Frame(f.mid, False, b"", b"")              # an empty payload is never encrypted
            else:
                nf = Frame(f.mid, f.enc, f.hash, out)
            dst_w.write(nf.pack())
            await dst_w.drain()


def load_hook(path):
    spec = importlib.util.spec_from_file_location("mspr_hook", path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod.on_message


def hostport(s, default_host=""):
    h, _, p = s.rpartition(":")
    return (h or default_host, int(p))


async def serve(listen, upstream, log_path=None, keylog_path=None, hook_path=None):
    log = open(log_path, "a", encoding="utf-8") if log_path else None
    keylog = open(keylog_path, "a", encoding="utf-8") if keylog_path else None
    proxy = Proxy(upstream, log, keylog, load_hook(hook_path) if hook_path else None)
    server = await asyncio.start_server(proxy.handle, *listen)
    print("mspr_proxy listening on %s:%d -> %s:%d" % (listen[0], listen[1], upstream[0], upstream[1]))
    async with server:
        await server.serve_forever()


def main():
    ap = argparse.ArgumentParser(description="Medius (SCE-RT) man-in-the-middle for your own client")
    ap.add_argument("--listen", default="0.0.0.0:10071")
    ap.add_argument("--upstream", required=True, help="host:port of the real Medius server")
    ap.add_argument("--log", help="JSONL file for every decrypted frame")
    ap.add_argument("--keylog", help="JSONL file for the session keys (lets mspr_capture decode a pcap of the same session)")
    ap.add_argument("--hook", help="Python file with on_message(direction, mid, payload, ctx)")
    a = ap.parse_args()
    try:
        asyncio.run(serve(hostport(a.listen, "0.0.0.0"), hostport(a.upstream), a.log, a.keylog, a.hook))
    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    main()
