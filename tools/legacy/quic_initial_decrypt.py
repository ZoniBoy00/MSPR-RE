"""Decrypt the QUIC Initial packet's ClientHello (RFC 9001) - passive analysis.

QUIC Initial packets are protected with a key derived from the connection
ID, as published in RFC 9001. This is NOT secret-key decryption and NOT
cracking: every QUIC endpoint (and Wireshark) performs this operation to
read the embedded TLS ClientHello (SNI, ALPN). Session data after the
handshake remains encrypted and is intentionally not touched here.
"""

import hashlib
import hmac
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from scapy.all import PcapReader, IP, UDP
from cryptography.hazmat.primitives.ciphers.aead import AESGCM
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives import hashes
import _paths as P

# RFC 9001 section 5.2 - Initial salt for QUIC v1
INITIAL_SALT = bytes.fromhex("38762cf7f55934b34d179ae6a4c80cadccbb7f0a")

def hkdf_extract(salt: bytes, ikm: bytes) -> bytes:
    return hmac.new(salt, ikm, hashlib.sha256).digest()


def hkdf_expand(prk: bytes, info: bytes, length: int) -> bytes:
    out = b""
    t = b""
    i = 1
    while len(out) < length:
        t = hmac.new(prk, t + info + bytes([i]), hashlib.sha256).digest()
        out += t
        i += 1
    return out[:length]


def hkdf_expand_label(secret, label, context, length):
    full_label = b"tls13 " + label
    info = length.to_bytes(2, "big") + bytes([len(full_label)]) + full_label + bytes([len(context)]) + context
    return hkdf_expand(secret, info, length)

def parse_varint(data, off):
    b = data[off]
    prefix = b >> 6
    length = 1 << prefix
    val = b & 0x3F
    for i in range(1, length):
        val = (val << 8) | data[off + i]
    return val, off + length

def decrypt_initial(payload: bytes):
    if not payload or not (payload[0] & 0x80):
        raise ValueError("not a long header packet")
    version = int.from_bytes(payload[1:5], "big")
    if version != 1:
        raise ValueError(f"unsupported QUIC version {version:#x}")
    off = 5
    dcid_len = payload[off]; off += 1
    dcid = payload[off:off + dcid_len]; off += dcid_len
    scid_len = payload[off]; off += 1 + scid_len  # skip SCID (length byte + value)
    token_len, off = parse_varint(payload, off)
    off += token_len
    pkt_len, off = parse_varint(payload, off)  # length: pn + payload + tag
    pn_offset = off

    # Initial secrets (RFC 9001 5.1/5.2)
    initial_secret = hkdf_extract(INITIAL_SALT, dcid)
    client_secret = hkdf_expand_label(initial_secret, b"client in", b"", 32)
    key = hkdf_expand_label(client_secret, b"quic key", b"", 16)
    iv = hkdf_expand_label(client_secret, b"quic iv", b"", 12)
    hp = hkdf_expand_label(client_secret, b"quic hp", b"", 16)

    # Header protection removal (RFC 9001 5.4)
    sample = payload[pn_offset + 4: pn_offset + 20]
    cipher = Cipher(algorithms.AES(hp), modes.ECB())
    enc = cipher.encryptor()
    mask = enc.update(sample) + enc.finalize()
    first = payload[0] ^ (mask[0] & 0x0F)  # long header: low 4 bits
    pn_len = (first & 0x03) + 1
    pn_bytes = bytes(a ^ b for a, b in zip(payload[pn_offset:pn_offset + pn_len], mask[1:pn_len + 1]))
    pn = int.from_bytes(pn_bytes, "big")

    header_wo_payload = bytearray(payload[:pn_offset])
    header_wo_payload[0] = first & 0x0F if False else first  # keep masked-first value
    aad = bytes(header_wo_payload) + pn_bytes
    body = payload[pn_offset + pn_len: pn_offset + pkt_len]
    nonce = bytes(a ^ b for a, b in zip(iv, pn.to_bytes(12, "big")[-12:]))
    plain = AESGCM(key).decrypt(nonce, body, aad)
    return first, pn, plain

def _label_info(label, length):
    full = b"tls13 " + label if not label.startswith(b"tls13 ") else label
    return length.to_bytes(2, "big") + bytes([len(full)]) + full + b"\x00"

def extract_clienthello(plain: bytes) -> bytes:
    """Concatenate CRYPTO frame data from decrypted Initial plaintext."""
    off = 0
    crypto = b""
    while off < len(plain):
        ftype = plain[off]
        if ftype == 0x00:  # PADDING
            off += 1
        elif ftype == 0x01:  # PING
            off += 1
        elif ftype in (0x02, 0x03):  # ACK / ACK_ECN
            off += 1
            _, off = parse_varint(plain, off)  # largest acked
            _, off = parse_varint(plain, off)  # ack delay
            if ftype == 0x02:
                n, off = parse_varint(plain, off)  # ACK Range Count
                for _ in range(max(0, n - 0)):  # ranges
                    _, off = parse_varint(plain, off)  # gap
                    _, off = parse_varint(plain, off)  # range
                _, off = parse_varint(plain, off)  # ECN count (unprotected)
            else:
                for _ in range(5):  # LA, delay, ECT0, ECT1, CE
                    _, off = parse_varint(plain, off)
        elif ftype == 0x06:  # CRYPTO
            fo, off = parse_varint(plain, off + 1)
            fl, off = parse_varint(plain, off)
            crypto += plain[off:off + fl]
            off += fl
        elif ftype == 0x1C or ftype == 0x1D:  # CONNECTION_CLOSE
            break
        else:
            # Unknown/unsupported frame in Initial - stop; crypto data gathered so far.
            break
    return crypto

def parse_clienthello(tls: bytes):
    # TLS handshake: ClientHello
    assert tls[0] == 0x01, f"not ClientHello ({tls[0]:#x})"
    hs_len = int.from_bytes(tls[1:4], "big")
    ch = tls[4:4 + hs_len]
    off = 2 + 32  # version + random
    slen = ch[off]; off += 1 + slen  # session id
    cslen = int.from_bytes(ch[off:off+2], "big"); off += 2 + cslen
    cmlen = ch[off]; off += 1 + cmlen
    exts = ch[off+2:]  # skip extensions length
    out = {"cipher_suites": cslen // 2, "extensions": []}
    sni = alpn = None
    o = 0
    while o + 4 <= len(exts):
        et = int.from_bytes(exts[o:o+2], "big"); el = int.from_bytes(exts[o+2:o+4], "big")
        data = exts[o+4:o+4+el]; o += 4 + el
        out["extensions"].append(f"{et:#06x}")
        if et == 0x0000 and len(data) > 5:  # server_name
            name_len = int.from_bytes(data[3:5], "big")
            sni = data[5:5+name_len].decode(errors="replace")
        elif et == 0x0010:  # alpn
            p = 2
            while p + 1 <= len(data):
                al = data[p]; p += 1
                alpn = data[p:p+al].decode(errors="replace")
                p += al
    out["sni"] = sni
    out["alpn"] = alpn
    return out

def main():
    path = P.PCAP
    API = {"172.67.168.92", "104.21.62.140"}
    done = 0
    with PcapReader(path) as pr:
        for pkt in pr:
            ip = pkt.getlayer(IP); udp = pkt.getlayer(UDP)
            if ip is None or udp is None:
                continue
            if ip.dst in API and int(udp.dport) == 443:
                payload = bytes(udp.payload)
                if not payload or not (payload[0] & 0x80):
                    continue
                try:
                    first, pn, plain = decrypt_initial(payload)
                    print(f"decrypted: {len(plain)}B plaintext, pn={pn}")
                except Exception as e:
                    print("decrypt failed:", type(e).__name__, e)
                    continue
                tls = extract_clienthello(plain)
                if tls:
                    info = parse_clienthello(tls)
                    print(f"QUIC Initial decrypted OK (pn={pn}, {len(plain)}B plaintext)")
                    print("  SNI :", info["sni"])
                    print("  ALPN:", info["alpn"])
                    print("  cipher suites:", info["cipher_suites"], " extensions:", info["extensions"])
                    done += 1
                    if done >= 3:
                        break
    if not done:
        print("No Initial packet with ClientHello could be decrypted.")

if __name__ == "__main__":
    main()
