"""Locations used by the legacy scripts, so that none of them has a machine specific path.

Everything is relative to a work folder that is NOT part of the repository (it holds your own decrypted EBOOT and the
files the scripts write). Defaults can be changed with environment variables:

  MSPR_RE_WORK       work folder (default: <repository>/work, ignored by git)
  GHIDRA_INSTALL_DIR the Ghidra installation (needed by the *_driver.py scripts)
  MSPR_PCAP          the capture the pcap scripts read (default: <work>/capture.pcapng)

Expected input files in the work folder (decrypt them from your own copy of the game):
  EBOOT.ELF          the decrypted EBOOT as ELF
  EBOOT.BIN          the decrypted EBOOT as it came out of the decrypter
  EBOOT.raw.bin      raw bytes of the EBOOT (mspr_ghidra_driver.py)
  EBOOT.ghidra.elf   EBOOT.ELF with section headers fixed by fix_elf_sections.py
"""
import os
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
WORK = Path(os.environ.get("MSPR_RE_WORK", REPO / "work"))
GHIDRA_DIR = os.environ.get("GHIDRA_INSTALL_DIR", "")
PCAP = os.environ.get("MSPR_PCAP", str(WORK / "capture.pcapng"))


def work(name: str) -> str:
    """Path of a file or folder inside the work folder (the work folder is created when needed)."""
    WORK.mkdir(parents=True, exist_ok=True)
    return str(WORK / name)
