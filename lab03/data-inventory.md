# Clubhub Data Inventory

| Field | Required? | Purpose | Lawful Basis | Retention | Access |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Student ID (`id`) | Yes | Uniquely identify club members and registrations | Contract / legitimate academic administration | Active membership + 1 semester | Club officers (masked in logs) |
| Full Name (`name`) | Yes | Display member identity on event rosters | Contract / legitimate academic administration | Active membership + 1 semester | Club officers |
| University Email (`email`) | Yes | Account identification and essential registration confirmations | Contract / legitimate academic administration | Active membership + 1 semester | Club officers |
| Email Reminder Flag (`remindByEmail`) | Optional (default `false`) | Send optional event reminder emails | Explicit opt-in consent | Until consent is withdrawn or membership ends | Automated notification service |
| Phone Number (`phone`) | Optional (default empty) | Send optional SMS event reminders | Explicit opt-in consent | Immediately erased when SMS consent is withdrawn | Automated SMS service |
| National ID / Home Address / GPA | **Not collected** | Excluded under data minimisation (not needed for club events) | N/A | N/A | N/A |