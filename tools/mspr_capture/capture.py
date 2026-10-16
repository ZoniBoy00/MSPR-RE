"""Packet capture backend for mspr_capture.

Passive sniffing only: packets are read, never injected. Capture stops
cleanly on duration limit, size limit, or Ctrl-C, then flushes PCAPNG.
"""

from __future__ import annotations

import signal
from typing import Optional

from scapy.all import PcapNgWriter, conf  # type: ignore
from scapy.arch.windows import get_windows_if_list  # type: ignore

MAX_PACKETS_HARD_LIMIT = 10_000_000


def list_interfaces() -> list[dict]:
    """Return locally-known interfaces in a CLI-friendly form."""
    out = []
    for i, iface in enumerate(conf.ifaces.data.values()):
        desc = getattr(iface, "description", "") or ""
        name = getattr(iface, "name", "") or str(iface)
        out.append({"index": i, "name": name, "description": desc, "guid": getattr(iface, "guid", None)})
    return out


def find_interface(selectors: Optional[str]) -> Optional[str]:
    """Resolve an interface by name fragment (case-insensitive)."""
    ifaces = list_interfaces()
    if selectors is None:
        return None
    sel = selectors.lower()
    for it in ifaces:
        if sel == it["name"].lower() or sel in it["description"].lower() or sel in it["name"].lower():
            return it["name"]
    return None


class CaptureSession:
    """Runs a bounded passive capture and writes PCAPNG incrementally."""

    def __init__(
        self,
        interface: str,
        output_pcapng: str,
        duration_s: float,
        max_mb: float = 200,
        bpf_filter: str = "ip and (tcp or udp)",
        live_analyzer=None,
        stop_flag=None,
    ) -> None:
        self.interface = interface
        self.output_pcapng = output_pcapng
        self.duration_s = duration_s
        self.max_bytes = int(max_mb * 1024 * 1024)
        self.bpf_filter = bpf_filter
        self.live_analyzer = live_analyzer
        self.stop_flag = stop_flag  # set True externally (web UI stop button)
        self.packets_captured = 0
        self.bytes_captured = 0
        self._stop_reason = "completed"
        self._writer = None

    def run(self) -> str:
        """Blocking run. Returns the stop reason."""
        from scapy.all import sniff  # type: ignore

        self._writer = PcapNgWriter(self.output_pcapng)

        self._install_sigint()

        try:
            sniff(
                iface=self.interface,
                filter=self.bpf_filter,
                timeout=self.duration_s,
                prn=self._on_packet,
                store=False,
                stop_filter=self._stop_filter,
            )
        except KeyboardInterrupt:
            self._stop_reason = "interrupted"
        finally:
            self._writer.close()
        return self._stop_reason

    def _install_sigint(self) -> None:
        def handler(signum, frame):
            raise KeyboardInterrupt

        signal.signal(signal.SIGINT, handler)

    def _on_packet(self, pkt) -> None:
        self.packets_captured += 1
        self.bytes_captured += len(pkt)
        if self.packets_captured % 5000 == 0:
            flows = len(self.live_analyzer.flows) if self.live_analyzer else 0
            print(
                f"[mspr_capture] … {self.packets_captured} pkts, "
                f"{self.bytes_captured // 1024} kB, {flows} flows"
            )
        # Live analysis: feed the analyzer inline so no second pass is needed.
        if self.live_analyzer is not None:
            try:
                self.live_analyzer.add_packet(pkt)
            except Exception:
                pass  # analysis must never break the capture
        try:
            self._writer.write(pkt)
        except Exception:
            # A malformed packet must never crash a capture session.
            pass

    def _stop_filter(self, pkt) -> bool:
        if self.stop_flag is not None and self.stop_flag():
            self._stop_reason = "stopped by user (web)"
            return True
        if self.packets_captured >= MAX_PACKETS_HARD_LIMIT:
            self._stop_reason = "hard packet limit"
            return True
        if self.bytes_captured >= self.max_bytes:
            self._stop_reason = "size limit reached"
            return True
        return False
