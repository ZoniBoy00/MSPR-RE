"""Secret redaction tests with synthetic data (no real credentials)."""

from mspr_capture.redact import REDACTED, redact_headers, redact_url, redact_value


def test_authorization_header_fully_redacted():
    out = redact_headers([("Authorization", "Bearer abc.def.ghi123456789")])
    assert out == [{"name": "Authorization", "value": REDACTED}]


def test_cookie_and_set_cookie_redacted():
    out = redact_headers([("Cookie", "npsso=SECRET; sid=xyz"), ("Set-Cookie", "session=abc123")])
    assert all(h["value"] == REDACTED for h in out)


def test_npsso_token_in_value_redacted():
    v = redact_value("login?npsso=VeryLongSecretValue1234567890abcdef")
    assert "VeryLongSecretValue" not in v
    assert "npsso=" + REDACTED in v


def test_psn_account_id_pattern_redacted():
    # 16-19 hex digits look like PSN account ids -> must be masked
    v = redact_value("accountId=12345678901234567")
    assert "12345678901234567" not in v


def test_online_id_redacted():
    v = redact_value('{"onlineId":"SomePlayerName","level":5}')
    assert "SomePlayerName" not in v
    assert '"level":5' in v or "level" in v


def test_benign_value_survives():
    v = redact_value("GET /leaderboards?page=1 HTTP/1.1")
    assert v == "GET /leaderboards?page=1 HTTP/1.1"


def test_url_query_token_redacted():
    u = redact_url("https://host/api/v1/auth?token=SuperSecret123&user=me")
    assert "SuperSecret123" not in u
    assert "user=me" in u


def test_url_userinfo_redacted():
    u = redact_url("https://user:pass@host.example/path")
    assert "user:pass" not in u
