"""SCE-RT (Medius) PS3 crypto in pure Python.

Port of Horizon's PS3_RCQ (symmetric "RCQ" stream cipher + 4-byte hash) and
PS3_RSA (512-bit textbook RSA on little-endian integers). Used by the test
client and by the capture decoder.
"""

from __future__ import annotations

import struct

M32 = 0xFFFFFFFF

# CipherContext ids (Horizon RT.Cryptography.ICipher.CipherContext)
ID_00, RC_SERVER_SESSION, ID_02, RC_CLIENT_SESSION, ID_04, ID_05, ID_06, RSA_AUTH = range(8)

# Public SCERT default key (also the key PS Rewired serves in SERVER_HELLO).
DEFAULT_N = 10315955513017997681600210131013411322695824559688299373570246338038100843097466504032586443986679280716603540690692615875074465586629501752500179100369237
DEFAULT_E = 17
DEFAULT_D = 4854567300243763614870687120476899445974505675147434999327174747312047455575182761195687859800492317495944895566174677168271650454805328075020357360662513


def _rol(x, n):
    return ((x << n) | (x >> (32 - n))) & M32


def _ror(x, n):
    return ((x >> n) | (x << (32 - n))) & M32


def _words_be(buf: bytes):
    """FlipWords + big-endian read == little-endian uint32 of each 4-byte group."""
    pad = (-len(buf)) % 4
    b = bytes(buf) + b"\0" * pad
    return list(struct.unpack("<%dI" % (len(b) // 4), b))


def _rc_pass(data: bytes, iv: list, sign=False, decrypt=False):
    """Returns (output_bytes or None, new_iv). Mirrors PS3_RCQ.RC_Pass."""
    r16, r17, r18, r19 = iv
    r3, r5 = 0x5B3AA654, 0x75970A4D
    words = _words_be(data)
    out = []
    for w in words:
        r19 ^= r3
        r18 = (r18 + r16) & M32
        r18 = (r18 + r19) & M32
        r18 = _rol(r18, 7)
        r17 = (r17 + r19) & M32
        r17 = (r17 + r18) & M32
        r18 ^= r5
        r17 = _rol(r17, 11)
        r16 = (r16 + r18) & M32
        r16 = (r16 + r17) & M32
        r16 = _ror(r16, 15)
        r0 = r16 & r17
        r17 = (~r17) & M32
        r6 = r18 & r17
        r0 |= r6
        r19 = (r19 + r0) & M32
        r16 = (~r16) & M32
        r0 = w
        if decrypt:
            r0 ^= r19
        r19 ^= r0
        if sign:
            out.append(r0 if decrypt else r19)
    new_iv = [r16, r17, r18, r19]
    if not sign:
        return None, new_iv
    ob = struct.pack("<%dI" % len(out), *out)[:len(data)]
    return ob, new_iv


_HASH_IV = _rc_pass(b"\0" * 16, [0, 0, 0, 0])[1]


def rcq_hash(data: bytes, context: int) -> bytes:
    _, (a, b, c, d) = _rc_pass(data, list(_HASH_IV))
    v = ((a + b + c + d) & 0x1FFFFFFF) | (context << 29)
    return struct.pack("<I", v & M32)


def hash_is_empty(h: bytes) -> bool:
    return h[0] == 0 and h[1] == 0 and h[2] == 0 and (h[3] & 0x1F) == 0


class RCQ:
    def __init__(self, key: bytes, context: int):
        self.key = bytes(key)
        self.context = context

    def _seed(self, h: bytes):
        iv_buf = self.key[:16]
        seed = list(struct.unpack("<4I", iv_buf))
        _, seed = _rc_pass(h, seed)
        iv_buf = struct.pack("<4I", *seed)
        _, seed = _rc_pass(iv_buf, seed, sign=True)
        return seed

    def encrypt(self, plain: bytes):
        h = rcq_hash(plain, self.context)
        seed = self._seed(h)
        c, _ = _rc_pass(plain, seed, sign=True)
        return c, h

    def decrypt(self, cipher: bytes, h: bytes):
        if hash_is_empty(h):
            return cipher, True
        seed = self._seed(h)
        p, _ = _rc_pass(cipher, seed, sign=True, decrypt=True)
        return p, rcq_hash(p, self.context) == h


def _le_int(b: bytes) -> int:
    return int.from_bytes(b, "little")


def _le_bytes(i: int, n: int) -> bytes:
    b = i.to_bytes((i.bit_length() + 7) // 8 or 1, "little")
    return b.ljust(n, b"\0")


class RSA:
    """PS3_RSA: textbook RSA on little-endian ints, RCQ hash with RSA_AUTH."""

    def __init__(self, n: int, e: int = 17, d: int | None = None):
        self.n, self.e, self.d = n, e, d
        self.context = RSA_AUTH

    def encrypt(self, plain: bytes):
        h = rcq_hash(plain, self.context)
        c = pow(_le_int(plain), self.e, self.n)
        return _le_bytes(c, len(plain)), h

    def decrypt(self, cipher: bytes, h: bytes):
        if hash_is_empty(h):
            return cipher, True
        m = pow(_le_int(cipher), self.d, self.n)
        for cand in (m, m + self.n):
            p = _le_bytes(cand, len(cipher))[:len(cipher)]
            if rcq_hash(p, self.context) == h:
                return p, True
        return _le_bytes(m, len(cipher))[:len(cipher)], False


SERVER_RSA = RSA(DEFAULT_N, DEFAULT_E, DEFAULT_D)
