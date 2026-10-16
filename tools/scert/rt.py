"""SCE-RT framing helpers shared by the Medius decoder and the proxy.

A frame is `id(1) len(2, LE) [hash(4)] payload`. Bit 7 of the id marks an encrypted frame; it then carries a
4-byte hash whose top 3 bits name the cipher context (7 = RSA key exchange, otherwise the session RCQ cipher).
"""

from __future__ import annotations

import random
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from scert_crypto import RCQ, RSA, SERVER_RSA, hash_is_empty, RSA_AUTH  # noqa: E402,F401

RT_NAMES = {
    0x00: "CLIENT_CONNECT_TCP", 0x06: "SERVER_CONNECT_REJECT", 0x07: "SERVER_CONNECT_ACCEPT_TCP",
    0x0a: "SERVER_APP", 0x0b: "CLIENT_APP_TOSERVER", 0x11: "SERVER_FORCED_DISCONNECT",
    0x12: "CLIENT_CRYPTKEY_PUBLIC", 0x13: "SERVER_CRYPTKEY_PEER", 0x14: "SERVER_CRYPTKEY_GAME",
    0x1a: "SERVER_CONNECT_COMPLETE", 0x1c: "SERVER_SYSTEM_MESSAGE", 0x1d: "SERVER_CHEAT_QUERY",
    0x20: "CLIENT_DISCONNECT_WITH_REASON", 0x21: "CLIENT_CONNECT_READY_TCP",
    0x22: "SERVER_CONNECT_REQUIRE", 0x23: "CLIENT_CONNECT_READY_REQUIRE",
    0x24: "CLIENT_HELLO", 0x25: "SERVER_HELLO",
}


class Frame:
    __slots__ = ("mid", "enc", "hash", "body")

    def __init__(self, mid: int, enc: bool, h: bytes, body: bytes):
        self.mid, self.enc, self.hash, self.body = mid, enc, h, body

    @property
    def ctx(self) -> int:
        return self.hash[3] >> 5 if self.enc else -1

    @property
    def sealed(self) -> bool:
        """True when the body is actually encrypted (an encrypted frame may carry an empty hash = plaintext)."""
        return self.enc and not hash_is_empty(self.hash)

    def pack(self) -> bytes:
        if self.enc:
            return bytes([self.mid | 0x80]) + struct.pack("<H", len(self.body)) + self.hash + self.body
        return bytes([self.mid]) + struct.pack("<H", len(self.body)) + self.body


def split_frames(buf: bytes):
    """Returns (frames, rest). `rest` is an incomplete trailing frame."""
    out, pos = [], 0
    while len(buf) - pos >= 3:
        mid = buf[pos]
        ln = struct.unpack("<H", buf[pos + 1:pos + 3])[0]
        enc = bool(mid & 0x80)
        hdr = 7 if enc else 3
        if len(buf) - pos < hdr + ln:
            break
        h = buf[pos + 3:pos + 7] if enc else b""
        out.append(Frame(mid & 0x7F, enc, h, buf[pos + hdr:pos + hdr + ln]))
        pos += hdr + ln
    return out, buf[pos:]


def seal(mid: int, plain: bytes, cipher) -> Frame:
    """Encrypts `plain` with an RCQ/RSA cipher (empty payloads are never encrypted)."""
    if not plain or cipher is None:
        return Frame(mid, False, b"", plain)
    c, h = cipher.encrypt(plain)
    return Frame(mid, True, h, c)


def gen_rsa512(rng=random) -> RSA:
    """Dependency-free RSA-512 key (e=17), as the game uses for its key exchange."""
    def is_prime(n):
        for p in (2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37):
            if n % p == 0:
                return n == p
        d, s = n - 1, 0
        while d % 2 == 0:
            d //= 2
            s += 1
        for _ in range(24):
            a = rng.randrange(2, n - 2)
            x = pow(a, d, n)
            if x in (1, n - 1):
                continue
            for _ in range(s - 1):
                x = pow(x, 2, n)
                if x == n - 1:
                    break
            else:
                return False
        return True

    def prime(bits):
        while True:
            p = rng.getrandbits(bits) | (1 << (bits - 1)) | 1
            if is_prime(p) and (p - 1) % 17:
                return p

    while True:
        p, q = prime(256), prime(256)
        n = p * q
        if n.bit_length() == 512:
            return RSA(n, 17, pow(17, -1, (p - 1) * (q - 1)))


def medius_label(payload: bytes) -> str:
    """The first two bytes of a CLIENT_APP / SERVER_APP payload are the Medius class and message type."""
    return "%d:0x%02x" % (payload[0], payload[1]) if len(payload) >= 2 else "-"
