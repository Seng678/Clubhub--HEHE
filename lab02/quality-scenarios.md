# Lab-02 · Quality attribute scenarios for ITC Club Hub
Version 1.0 · 2026-10-28 · Reviewed by (Scrum Master): Mony Viseth Setha

## QAS-01 · Availability · written by Sinath Naihouy
| Part | Content |
|---|---|
| Source | 100 students |
| Stimulus | Registrations open and many students try to register at the same time |
| Environment | Friday 18:00, normal operation, peak load of about 1,500 requests in the first 10 minutes |
| Artifact | Registration service and the Club Hub server |
| Response | The system keeps accepting registrations and shows each student a confirmation or a clear error |
| Response measure | 99.5% of registration requests succeed in the first 10 minutes; unplanned downtime is at most 3.6 hours per month (99.5% of 720 hours = 3.6 hours allowed) |

## QAS-02 · Performance of check-in at the door · written by Mony Viseth Setha
| Part | Content |
|---|---|
| Source | An organiser at the door |
| Stimulus | Scans the QR code of an arriving student |
| Environment | 200 arrivals in 10 minutes at one entrance, weak Wi-Fi, one phone |
| Artifact | PWA check-in screen and the local queue |
| Response | The app shows a green tick immediately, without waiting for the network |
| Response measure | Tick shown in at most 1 second for 95% of scans; 200 scans in 10 minutes = 1 scan every 3 seconds, so the door never waits |

## QAS-03 · Usability · written by Sov Kenkimseng
| Part | Content |
|---|---|
| Source | A first-time student on an Android phone |
| Stimulus | Wants to find an event and register for it |
| Environment | Mobile data, normal load, no help or training |
| Artifact | PWA event list and registration screen |
| Response | The student finds the event and receives the registration confirmation |
| Response measure | At most 4 taps and 60 seconds from opening the app to the confirmation for 90% of 10 test users |

## QAS-04 · Security · written by Phou Sekang
| Part | Content |
|---|---|
| Source | A student who is not an organiser of the event |
| Stimulus | Tries to open the attendance list of another club's event by changing the event id in the URL |
| Environment | Normal operation, logged in as a student |
| Artifact | Attendance records API (student ID, name, e-mail, attendance) |
| Response | The system refuses access, hides the data and writes the attempt to a log |
| Response measure | 100% of 20 unauthorised test requests are rejected with an error; 0 personal records are returned; the attempt appears in the log within 1 minute |

## QAS-05 · Modifiability · written by Sinath Naihouy
| Part | Content |
|---|---|
| Source | A developer of the team |
| Stimulus | Adds the waiting list (a Should feature): a full event puts new registrations in status Waitlisted |
| Environment | Design time, after Sprint 1, core already tested |
| Artifact | RegistrationService, Registration (include/clubhub/) |
| Response | The change is made in the core only; the CLI gains one display column; existing behaviour is unchanged |
| Response measure | Done in at most 2 person-days; at most 4 files changed under include/ and src/; 0 changes in src/cli/ other than display; 100% of existing tests still pass |

## QAS-06 · Portability · written by Mony Viseth Setha
| Part | Content |
|---|---|
| Source | A student with any common phone |
| Stimulus | Opens Club Hub and installs the PWA |
| Environment | Android 12 or later with Chrome, iPhone with iOS 16 or later and Safari, normal mobile data |
| Artifact | PWA front end (decision in ADR-001) |
| Response | All main functions (browse, register, cancel, check-in) work the same on every supported device |
| Response measure | 100% of 12 test cases pass on 3 devices (1 Android, 1 iPhone, 1 desktop Chrome); checked by hand before the final demo |

## Priorities
| Scenario | Business importance | Technical risk | Protects | First? |
|---|---|---|---|---|
| QAS-01 | H | H | Students | Yes |
| QAS-02 | H | H | Organisers | Yes |
| QAS-03 | M | L | Students | No |
| QAS-04 | H | M | All users (personal data) | No |
| QAS-05 | M | M | Developers | No |
| QAS-06 | M | M | Students, organisers | No |

The architecture must satisfy QAS-01 and QAS-02 first, because the case study says the peak at the door and the Friday registration are the hardest moments.