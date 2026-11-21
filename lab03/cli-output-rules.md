# CLI Output Rules · ITC Club Hub
Version 1.0 · 2026-11-17 · Authors: Sinath Naihouy

### Rule 1: Never use colour alone
Status indicators must always include an uppercase text label inside brackets; ANSI colours only reinforce the text.
- **bad :** `E-017  Git Workshop      (shown in red)`
- **good:** `E-017  Git Workshop      [CANCELLED]`

### Rule 2: Honour `NO_COLOR` and `--no-color`
Disable all ANSI escape sequences whenever the `NO_COLOR` environment variable is set or the `--no-color` CLI flag is passed.
- **bad :** `\033[31m[CANCELLED]\033[0m` printed when `NO_COLOR=1`
- **good:** `[CANCELLED]` printed cleanly without escape codes when `NO_COLOR=1` or `--no-color` is active

### Rule 3: Errors say what failed, why, and the next step
Never output raw error codes or stack traces; give the user a concrete command or action to recover.
- **bad :** `ERR_CAP`
- **good:** `Error: cannot register for E-017: the event is full (40 of 40 seats).`
  `Next step: clubhub waitlist E-017`

### Rule 4: Return non-zero exit codes on error
Any failed command must exit with a non-zero status code (`1` or higher) so scripts and assistive tools detect failure.
- **bad :** Printing `Error: event not found` and returning exit code `0`
- **good:** Printing the error message to `stderr` and returning exit code `1`

### Rule 5: Prompts state the expected format
Interactive input prompts must show an example or format constraint before waiting for user input.
- **bad :** `Enter date:`
- **good:** `Enter event start date and time (YYYY-MM-DD HH:MM, e.g., 2026-11-20 14:00):`

### Rule 6: Use unambiguous ISO-8601 dates and times
Always format dates as `YYYY-MM-DD HH:MM` in 24-hour time to prevent day/month confusion.
- **bad :** `11/12/26 5:30 PM`
- **good:** `2026-11-12 17:30`