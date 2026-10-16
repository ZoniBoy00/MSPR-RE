"""Local report writer with restrictive file permissions.

Files are written locally only. JSON is written with a restrictive ACL
(owner-only where the OS supports it). Nothing is uploaded anywhere.
"""

from __future__ import annotations

import json
import os
import sys
from pathlib import Path


def _restrict_permissions(path: Path) -> None:
    """Best-effort owner-only permissions on Windows and POSIX."""
    try:
        if os.name == "nt":
            # Remove inheritance and grant only the current user full control.
            os.system(f'icacls "{path}" /inheritance:r /grant:r "{os.environ.get("USERNAME", "%USERNAME%")}:(R,W)" >nul 2>&1')
        else:
            os.chmod(path, 0o600)
    except Exception:
        pass  # never fail the run over ACL cosmetics


def write_reports(summary: dict, json_path: Path) -> None:
    with open(json_path, "w", encoding="utf-8") as f:
        json.dump(summary, f, indent=2, ensure_ascii=False, default=str)
    _restrict_permissions(json_path)
