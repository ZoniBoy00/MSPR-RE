"""Redaction of secrets and personal identifiers from captured metadata.

All redaction is defensive: anything that looks like a credential,
account identifier or token is replaced with a placeholder even if we
are not sure it is one. Over-redaction is safe; under-redaction is not.
"""

from __future__ import annotations

import re
from typing import Dict, Iterable, List, Tuple

# Headers whose values must never be reported in plaintext.
SENSITIVE_HEADERS = {
    "authorization",
    "proxy-authorization",
    "cookie",
    "set-cookie",
    "x-np-token",
    "x-npsso",
    "npsso",
    "x-np-authorization",
    "x-nd-auth",
    "x-auth-token",
    "x-api-key",
    "x-session-token",
    "www-authenticate",
    "proxy-authenticate",
    "x-svomac",
}

# Generic token-ish values in query strings or bodies (long opaque strings).
_BEARER_RE = re.compile(r"(?i)\b(bearer|basic|npsso|token)\s+[\w.\-+/=]{8,}")
_KEY_VALUE_SECRET_RE = re.compile(
    r"(?i)\b(npsso|access_token|refresh_token|auth_token|api_key|apikey|session_token|sessionid|session_id|authcode|auth|token|ticket|sig|signature|npid)\s*=\s*[\w.\-+/=%]{6,}"
)
_LONG_OPAQUE_RE = re.compile(r"\b[A-Za-z0-9_\-]{40,}\b")

# PSN / Sony account identifiers (best-effort patterns; over-match is fine).
_PSN_ACCOUNT_ID_RE = re.compile(r"\b[0-9a-fA-F]{16,19}\b")
_ONLINE_ID_RE = re.compile(
    r"(?i)\b(onlineId|online_id|psn_id|accountId|account_id|npId|np_id)\"?\s*[:=]\s*\"?(?=[A-Za-z0-9_\-\.]*[A-Za-z])([A-Za-z0-9_\-\.]{3,16})"
)

REDACTED = "[REDACTED]"


def redact_header(name: str, value: str) -> Tuple[str, str]:
    """Return (name, value) with sensitive values replaced."""
    if name.lower() in SENSITIVE_HEADERS:
        return name, REDACTED
    return name, redact_value(value)


def redact_value(value: str) -> str:
    """Redact credential-looking substrings from an arbitrary string."""
    out = _BEARER_RE.sub(lambda m: m.group(1) + " " + REDACTED, value)
    out = _KEY_VALUE_SECRET_RE.sub(lambda m: m.group(1) + "=" + REDACTED, out)
    out = _ONLINE_ID_RE.sub(lambda m: m.group(1) + "=" + REDACTED, out)
    # PSN account ids are 16-19 hex digits; long opaque strings get masked too.
    out = _PSN_ACCOUNT_ID_RE.sub(REDACTED, out)
    out = _LONG_OPAQUE_RE.sub(REDACTED, out)
    return out


def redact_url(url: str) -> str:
    """Redact credentials from URLs (query strings, userinfo)."""
    if "@" in url.split("//")[-1].split("/")[0]:
        scheme_sep = url.find("//")
        at = url.find("@")
        if scheme_sep != -1 and 0 < at:
            url = url[: scheme_sep + 2] + REDACTED + url[at:]
    out = []
    for part in url.split("&"):
        if "=" in part and any(
            k in part.split("=", 1)[0].lower()
            for k in ("token", "auth", "key", "ticket", "npsso", "code", "session", "sig", "signature", "npid")
        ):
            out.append(part.split("=", 1)[0] + "=" + REDACTED)
        else:
            out.append(redact_value(part))
    return "&".join(out)


def redact_headers(headers: Iterable[Tuple[str, str]]) -> List[Dict[str, str]]:
    """Redact an iterable of (name, value) header pairs into a safe list."""
    return [{"name": n, "value": v} for n, v in (redact_header(n, v) for n, v in headers)]
