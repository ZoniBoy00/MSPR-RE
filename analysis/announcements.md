# Announcements

Findings from the decompiled game (EBOOT v1.03) and the PS Rewired capture. Evidence tags as in the [reverse engineering report](reverse-engineering.md).

## How the game handles the text

- **[EBOOT]** The SVO client sends `GET /motorstormpr/getAnnouncement?country=..&languageCode=..` (action class `SVOActionGetAnnouncement`, `0x2ca948`) and parses the answer in `0x2c9628`: the root element must be `AnnouncementTxt`, and its child element holds the text.
- **[LIVE]** The answer of PS Rewired, and of this server, is

  ```xml
  <XML>
      <AnnouncementTxt>
          <msg>Welcome to ...</msg>
      </AnnouncementTxt>
  </XML>
  ```

- **[EBOOT]** The text goes through `cSVO::SetAnnouncementText` (`0x2c2440`) into a **1024-byte buffer**. Text of 1024 bytes or more is cut to 1023 bytes (`Cut Buffer Down to ...`). The server now cuts at that length on a character boundary.
- **[EBOOT]** The game sets the flag `Display announcements is %d` to 1 only when the text is not empty. With no text the GUI shows its own string `There are no Announcements` (`0x889398`); when the request failed it shows `Announcement Not Available` (`0x88a2c0`).
- **[EBOOT]** The GUI exposes `GetAnnouncementText`, `DisplayAnnouncements`, `SetDisplayAnnouncements` and, for Speed Weekend, `SpeedWeekendGetAnnouncementText` and `SpeedWeekendAnnouncementTextAvailable` (`0x188b0`). The Weekend screen therefore shows an announcement too; whether it is the same text or a separate one is not visible in the strings.
- **[LIVE]** The game requests the announcement while logging in (many times per session in the captures), so a change shows at the next login.

## What this server does

`server/config/announcement.txt` is read on every request, so editing the file changes the text immediately, no restart. Line breaks are kept in the XML. The text is cut to 1023 bytes. An empty file gives an empty `<msg>` (the game's "no announcements" case is expected, not verified).

## Ideas

- Season and challenge news, the current Weekend and server notices in the one text (about 1000 bytes fit).
- Generate the text from the database: the leader of the season, the latest record, the number of drivers online. A small timer that rewrites `announcement.txt`, or computing it per request.
- A different text per `languageCode` (the request carries the country and language).

## Open

- Whether the GUI wraps long text, shows line breaks and supports colour codes or icons.
- Whether an empty `<msg>` or a missing one is better for "no announcement".
- Whether the Weekend announcement is the same text.
