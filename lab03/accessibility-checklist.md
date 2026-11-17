# Accessibility checklist · ITC Club Hub (planned web and mobile UI)
Target: WCAG 2.2 level AA · Version 0.1 · 2026-11-17 · Authors: Sinath Naihouy

## WCAG 2.2 Level AA Checklist (POUR)
| SC | Name | Level | Screen | How we meet it | How we test it |
|---|---|---|---|---|---|
| 1.1.1 | Non-text Content | A | Event list | Club logos and event banners have descriptive alt text | Screen reader DOM inspection |
| 1.3.1 | Info and Relationships | A | Registration form | All inputs use explicit `<label for="...">` tags | Automated axe-core scan |
| 1.4.1 | Use of Color | A | Event list | Status badges include text labels (`Full`, `Open`) alongside colors | View interface in greyscale |
| 1.4.3 | Contrast (Minimum) | AA | All screens | Body text and buttons meet at least 4.5:1 contrast ratio | WebAIM Contrast Checker |
| 2.1.1 | Keyboard | A | Navigation & forms | All buttons, links, and modals are operable via Tab and Enter | Keyboard-only navigation audit |
| 2.4.7 | Focus Visible | AA | All screens | Interactive elements display a high-contrast 2px focus ring | Tab-through visual check |
| 2.4.11 | Focus Not Obscured (Minimum) | AA | Registration form | Sticky header never overlaps focused form inputs on scroll | Keyboard navigation inspection |
| 2.5.7 | Dragging Movements | AA | Event calendar | Calendar adjustments have single-click arrow button alternatives | Single-pointer audit |
| 2.5.8 | Target Size (Minimum) | AA | Mobile navigation | All buttons and links are at least 24×24 CSS pixels | Browser DevTools box model check |
| 3.2.6 | Consistent Help | A | Footer / header | Help link stays in the bottom-right footer across all pages | Cross-page visual check |
| 3.3.7 | Redundant Entry | A | Registration form | Student ID and email auto-fill from profile during event sign-up | Form flow verification |
| 3.3.8 | Accessible Authentication (Minimum) | AA | Login | Supports password managers and paste without puzzle CAPTCHAs | Login flow test with password manager |
| 4.1.2 | Name, Role, Value | A | Modal dialogs | Custom dropdowns and modals use valid ARIA roles (`role="dialog"`) | Accessibility tree inspection |

## Screen Design Decisions & Contrast Measurements

### Screen 1: Event List
1. **Card hierarchy:** Each event card uses an `<h2>` title, clear date/time badge, and explicit seat counter (`32 / 40 seats`).
2. **Non-colour status badges:** Full events display a dark red badge with white text reading `FULL`.
3. **Keyboard card focus:** Pressing `Enter` on an event card opens details with a visible `2px` outline.
- **Measured contrast (WebAIM):**
  - Body text (`#1E293B` on `#FFFFFF`): **14.68:1** (Passes AA 4.5:1)
  - Primary badge (`#FFFFFF` on `#1D4ED8`): **6.70:1** (Passes AA 4.5:1)

### Screen 2: Student Registration Form
1. **Inline error summaries:** Validation errors appear directly below the invalid field with plain-language instructions.
2. **Large touch targets:** Submit and Cancel buttons are `44px` tall with clear spacing.
3. **Auto-filled session data:** Logged-in students do not re-type their Student ID or email when registering.
- **Measured contrast (WebAIM):**
  - Input label text (`#0F172A` on `#F8FAFC`): **17.11:1** (Passes AA 4.5:1)
  - Submit button (`#FFFFFF` on `#15803D`): **5.13:1** (Passes AA 4.5:1)