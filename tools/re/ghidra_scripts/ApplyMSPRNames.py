# Apply verified MSPR v1.03 names/comments to the currently open Ghidra program.
# Run from Ghidra's Script Manager with the MSPR v1.03 EBOOT program active.
# This only changes analysis metadata; it does not change the executable bytes.

from ghidra.program.model.symbol import SourceType

ENTRIES = [
    (0x87ed48, "MSPR_SetRankedOption", "EBOOT v1.03: sets the matchmaking ranked flag. Evidence: docs/research/reverse-engineering.md; docs/ranked-casual.md."),
    (0x87ed58, "MSPR_SetCasualOption", "EBOOT v1.03: clears the matchmaking ranked flag. Evidence: docs/research/reverse-engineering.md; docs/ranked-casual.md."),
    (0x87ed68, "MSPR_RankedOptionSelected", "EBOOT v1.03: reads the selected ranked flag. Evidence: docs/research/reverse-engineering.md; docs/ranked-casual.md."),
    (0x884f58, "MSPR_SelectMatchmakingSuperset", "EBOOT v1.03: selects/stores the Matchmaking Superset ID (1 or 2). Static analysis; live capture observed SupersetID 1. Evidence: docs/research/reverse-engineering.md."),
    (0x27d9e8, "MSPR_BuildMatchPartyRequest2", "EBOOT v1.03: builds LobbyExt MatchPartyRequest2 (0x78). Evidence: research/re/v103/decomp/matchmaking.c; docs/ranked-casual.md."),
    (0x2801d8, "MSPR_HandleMatchPartyResponse", "EBOOT v1.03: callback handles MatchPartyResponse status branches, including Referral (8), JoinAssignedGame (6), and NoResult (1). Evidence: research/re/v103/decomp/matchmaking.c; docs/ranked-casual.md."),
    (0x281688, "MSPR_MatchMadeGameTypeString", "EBOOT v1.03: vtable-bound MatchMadeGameTypeString entry. The name is supported by vtable mapping; full body semantics are not independently decompiled. Evidence: docs/ranked-casual.md."),
    (0x6714a8, "MSPR_PackMatchPartyRequest2", "EBOOT v1.03 Medius serializer for LobbyExt 0x78. Evidence: research/re/v103/decomp/match_wire.c; research/re/v103/medius_registry.json."),
    (0x6720e0, "MSPR_UnpackMatchPartyResponse", "EBOOT v1.03 Medius deserializer for LobbyExt 0x60. Evidence: research/re/v103/decomp/match_wire.c; research/re/v103/medius_registry.json."),
    (0x6728e0, "MSPR_UnpackMatchGetSupersetListResponse", "EBOOT v1.03 Medius deserializer for LobbyExt 0x5E. Evidence: research/re/v103/decomp/match_wire.c; research/re/v103/medius_registry.json."),
    (0x648f18, "MSPR_ReadSvoUrl", "EBOOT v1.03 reads the SVO URL field (length-prefixed bytes including NUL). Evidence: docs/ranked-casual.md."),
]

fm = currentProgram.getFunctionManager()
renamed = 0
skipped = []
for address, name, comment in ENTRIES:
    addr = toAddr(address)
    fn = fm.getFunctionAt(addr)
    if fn is None:
        fn = fm.getFunctionContaining(addr)
    if fn is None:
        skipped.append((address, "no function at or containing address"))
        continue
    try:
        fn.setName(name, SourceType.USER_DEFINED)
        fn.setComment(comment)
        renamed += 1
        println("renamed 0x%x -> %s" % (address, name))
    except Exception as exc:
        skipped.append((address, str(exc)))

println("MSPR annotations applied: %d; skipped: %d" % (renamed, len(skipped)))
for address, reason in skipped:
    println("SKIP 0x%x: %s" % (address, reason))
