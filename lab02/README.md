# Lab-02 · Types of Applications
Version 1.0 · 2026-11-03 · Team: HEHE

## File Table
| File | Description | Author |
| :--- | :--- | :--- |
| `lab02/app-classification.md` | Five everyday applications classified by type, architecture, and qualities | Sinath Naihouy |
| `lab02/app-quadrant.mmd` | Mermaid quadrant chart comparing timing vs. availability | Sinath Naihouy |
| `lab02/adr-001-application-type.md` | Architecture decision record for Club Hub application types | Sinath Naihouy |
| `lab02/quality-scenarios.md` | Six quality attribute scenarios with testable metrics | Sinath Naihouy |
| `lab02/context-diagram.mmd` (+ .png) | Black-box context diagram showing actors and external systems | Mony Viseth Setha |
| `lab02/architecture.mmd` (+ .png) | Three-tier architecture sketch mapping implemented components | Mony Viseth Setha |
| `include/clubhub/event.hpp` | Event domain model header and time point formatting | Sov Kenkimseng, Phou Sekang |
| `include/clubhub/event_csv.hpp` | CSV parser result structures and interface declaration | Sov Kenkimseng, Phou Sekang |
| `src/event.cpp` | Event validation logic and time string parsing implementation | Sov Kenkimseng, Phou Sekang |
| `src/event_csv.cpp` | CSV line-by-line file parser with robust error handling | Sov Kenkimseng, Phou Sekang |
| `src/cli/main.cpp` | Command-line front end interface implementing `list-events` | Sov Kenkimseng, Phou Sekang |
| `data/events.csv` | Sample event dataset including valid records and error cases | Sov Kenkimseng, Phou Sekang |

## Inputs Reused from Lab-01
| Input File | What We Used From It | Commit Hash / Version |
| :--- | :--- | :--- |
| `lab01/team-charter.md` | Problem statement, stakeholder list, and target user groups | (Run `git log -1 --format=%h -- lab01/team-charter.md` in your terminal to get this hash) |
| `lab01/decisions.md` | Team decision rules and consensus guidelines | (Run `git log -1 --format=%h -- lab01/decisions.md` in your terminal to get this hash) |

## Architecture Diagrams
### Context Diagram
![Context Diagram](context-diagram.png)

### Three-Tier Architecture
![Architecture Diagram](architecture.png)

## Change Log
| Date | Version | Description | Author |
| :--- | :--- | :--- | :--- |
| 2026-11-03 | 1.0 | Completed Lab-02 tasks 1 through 5, event core, and CLI | Team HEHE |