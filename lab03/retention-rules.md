# Clubhub Data Retention Rules

1. **Core Membership Records (`id`, `name`, `email`):**
   - **Retention Period:** Retained for the duration of the student's active club membership plus one academic semester for attendance auditing.
   - **Deletion Trigger:** Permanently purged at the end of the grace semester or immediately upon a verified student deletion request.

2. **Optional Phone Numbers (`phone`):**
   - **Retention Period:** Retained only while active SMS consent is enabled.
   - **Deletion Trigger:** Erased immediately (`std::optional::reset()`) the moment `withdrawSmsConsent()` is called.

3. **Event Attendance & Registration Logs:**
   - **Retention Period:** Retained until the end of the academic year for club activity reporting.
   - **Privacy Rule:** Logs must only store redacted identifiers (`Student{id=e2******7}`) and never raw names, emails, or phone numbers.