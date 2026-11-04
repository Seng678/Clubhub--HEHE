# ADR-001 · Application types for ITC Club Hub
Version 1.0 · 2026-10-28 · Status: Accepted( 2026-11-4) · Deciders: Sinath Naihouy (Product Owner), Mony Viseth Setha, Sov Kenkimseng, Phou Sekang

## User groups
| Group | Device | Where | Connectivity | How often | Must never fail |
|---|---|---|---|---|---|
| Students (~100) | Android / iPhone | Anywhere on campus or at home | Mobile data, sometimes weak | A few times a week; peak Friday evening | Registering for an event when registration opens |
| Organisers | 1-2 phones per door | Room or hall entrance | Weak or overloaded Wi-Fi | A few events a week | Checking students in at the door (200 arrivals in 10 min) |
| Administrators (2-3) | Desktop PC | Student affairs office | Stable office network | Monthly reports, club approvals | Approving clubs and producing the monthly report |

## Options
A. Native apps (Android + iOS)
B. Cross-platform app (e.g. Flutter)
C. PWA for students and organisers, with the same web app on desktop for administrators
D. Responsive web app only (no offline support)
E. Desktop application

## Weighted comparison (score 1-5 x weight)
| Criterion (weight) | Why this weight | A | B | C | D | E |
|---|---|---|---|---|---|---|
| Cost for our team in one semester (3) | 4 students, 15 weeks, one codebase is realistic | 1 | 3 | 5 | 5 | 2 |
| Reach (3) | ~3,000 students on both Android and iPhone, no install friction | 4 | 4 | 5 | 5 | 1 |
| Offline check-in at the door (3) | Weak Wi-Fi is the core problem for organisers | 5 | 4 | 4 | 1 | 4 |
| Reminders (2) | Important, but e-mail is a fallback | 5 | 5 | 3 | 5 | 1 |
| Admin report printing / desktop use (1) | Only 2-3 users, once a month | 2 | 2 | 4 | 5 | 4 |

**Totals**
- A: 3x1 + 3x4 + 3x5 + 2x5 + 1x2 = 3 + 12 + 15 + 10 + 2 = **42**
- B: 3x3 + 3x4 + 3x4 + 2x5 + 1x2 = 9 + 12 + 12 + 10 + 2 = **45**
- C: 3x5 + 3x5 + 3x4 + 2x3 + 1x4 = 15 + 15 + 12 + 6 + 4 = **52**
- D: 3x5 + 3x5 + 3x1 + 2x5 + 1x5 = 15 + 15 + 3 + 10 + 5 = **48**
- E: 3x2 + 3x1 + 3x4 + 2x1 + 1x4 = 6 + 3 + 12 + 2 + 4 = **27**

Deal-breaker check: check-in must work without Wi-Fi.
- D fails this outright (score 1).
- C passes if we add a service worker and a local queue that syncs later.
- The remaining risk is reminders on iPhone, which need the PWA installed. We keep e-mail reminders as the fallback.

## Decision
Build one PWA for students and organisers. Administrators use the same web app in a desktop browser. Check-in is offline-first with a local queue.

## Consequences
+ One codebase for all three user groups.
+ No app-store approval, and updates reach everyone immediately.
- iPhone push reminders only work after the PWA is installed, so e-mail remains the fallback.
- Offline sync adds conflicts (same QR scanned twice, cancelled registrations) that need explicit rules.
- Fewer native device features than a native app.

## Rejected options
- A Native apps: three front ends is too much for a small team in one semester.
- B Cross-platform app: still needs app-store release and is costlier than a PWA, with no clear gain here.
- D Responsive web only: fails the deal-breaker, because check-in needs the network.
- E Desktop app: students and organisers use phones.

## How the front ends reach the C++ core
In production the C++ core (`RegistrationService`, `Event`) would sit behind an HTTP API that the PWA calls. In this course the CLI in `src/cli/` calls the core directly, and the PWA is only modelled.