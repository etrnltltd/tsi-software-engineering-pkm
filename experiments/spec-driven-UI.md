# Experiment: Spec-Driven UI Generation for the Achievements Page

- **Tags:** ai, taskmaster, ui, sdd, design-system

## Goal

Test whether a strict `DESIGN.md` contract makes AI-generated UI code production-ready, instead of the usual "Tailwind Blue" generic dashboard look.

The target was the achievements feature in TaskMaster: redesign `AchievementsPage.vue` and `AchievementsNotification.vue` so they connect to the existing backend (the Strategy-pattern achievement engine from Task 4) and follow a strict design system.

## Method

1. Wrote `docs/DESIGN.md` first — color tokens, spacing scale, typography, component rules, accessibility requirements, what NOT to do.
2. Pasted `DESIGN.md` plus the existing `AchievementsPage.vue` (template + script section) into the AI assistant.
3. Asked the AI to rewrite the `<style scoped>` block and adjust class names in the template, without touching the script.
4. Ran two attempts:
   - **Attempt 1:** "Restyle this page to be modern and clean."
   - **Attempt 2:** Same code, but with the strict `DESIGN.md` as context and an explicit instruction to follow it.

## Results

### Attempt 1 — vague prompt

The AI produced something that looked fine in isolation but was a disaster in context:
- Used Tailwind classes (`bg-gray-900`, `rounded-lg`, `p-4`). This codebase doesn't use Tailwind.
- Picked colors from thin air: `#3b82f6`, `#1f2937`, `#10b981`. None matched the rest of the app.
- Mixed spacing values: `padding: 12px 18px 14px 16px`. Off-grid, no consistency.
- Added `box-shadow: 0 4px 6px rgba(0,0,0,0.1)` everywhere. The design contract explicitly bans this for dark UIs.
- No focus styles. Locked achievement cards were fully tabbable, which is wrong.
- Hardcoded English strings in the markup despite the project using `vue-i18n`.

This was the textbook "Tailwind Blue" problem. The output looked plausible. It was unusable.

### Attempt 2 — with `DESIGN.md` as context

Much better, but not perfect:
- All colors became `var(--name)` references. ✅
- Spacing landed on the 8-point scale (`var(--space-4)`, `var(--space-6)`). ✅
- No Tailwind classes. ✅
- Used `:focus-visible` with the right outline. ✅
- Notification toast got `role="status"` and `aria-live="polite"`. ✅

What still needed manual fixes:
1. The AI initially used `box-shadow` for the unlocked-card "glow" effect, which the design contract bans. I had to remind it that elevation comes from border + background contrast, not shadows. After flagging it, it correctly switched to `border-width: 2px` with the category color.
2. The first version had **two primary buttons** in the filter bar (an active filter and a "Refresh" button styled identically). DESIGN.md says no two primary buttons next to each other. I had to point at the rule. The fix: filter buttons became toggleable (active = primary, inactive = secondary).
3. Some hardcoded English text leaked through in empty states ("No achievements yet"). I asked it to route everything through `$t()`. It did.

So: 3 follow-up corrections after the initial pass. All three corresponded to specific rules that were *in* the DESIGN.md but the AI didn't apply on the first try.

## How many prompts to a working connection?

Zero — the connection was already there. This was the cleanest part of the experiment.

The existing `services/achievements.js` calls `apiService.getAllAchievements(userId)`, which hits `/api/achievements` on the backend. That endpoint is served by `AchievementController.getAllAchievementsForUser()`, which calls `AchievementService.getAllAchievementsForUser()`. None of those changed during the Strategy refactor in Task 4. The achievement check that gets triggered when a task is completed (`AchievementService.checkAndGrantAchievements`) was rewritten to use `UserStatsBuilder + AchievementChecker`, but the *read* endpoints didn't change.

So the new UI calls the same endpoints as before, gets the same data shape, and renders the achievements that the new Strategy module unlocks. The chain works end-to-end without any frontend rewiring.

## Was the result accessible and structurally sound?

Mostly yes, after corrections:

- **Semantic HTML:** Used `<article>` for cards, `<h3>` for titles. ✅
- **Keyboard navigation:** Filter buttons reachable, focus-visible outlines present. ✅
- **Screen readers:** Notification has `role="status"` + `aria-live="polite"`, icon-only close button has `aria-label`. ✅
- **Color contrast:** Checked the palette against WCAG AA. Body text on card background hits 9.4:1. Secondary text on card hits 5.8:1. Both pass. ✅
- **One issue I caught manually:** the AI tried to make locked achievement cards into `<button>` elements "for consistency." Bad call — they're not interactive. I had it switch to `<article>` with no tabindex.

## Did `DESIGN.md` actually help?

Yes, decisively. The difference between Attempt 1 and Attempt 2 wasn't subtle — it was the difference between unusable and shippable.

The most useful sections turned out to be:
- **§2 Color palette with `--name` enforcement.** This single rule killed the Tailwind Blue problem.
- **§4 Spacing on a fixed scale.** Eliminated all the off-grid `13px` and `22px` values.
- **§10 What NOT to do.** Negative rules ("no box-shadow on dark UIs") prevented several specific bad outputs.

The least useful section was the typography table — the AI mostly got that right even on Attempt 1.

## Takeaways

1. **`DESIGN.md` is the single highest-leverage frontend artifact I've written this semester.** Every future UI prompt for this project will reference it.
2. **Negative rules matter more than positive ones.** "Use the 8-point scale" got partially obeyed. "Never use values outside this scale" got fully obeyed. AI follows specific bans more reliably than general guidelines.
3. **The AI defaults to Tailwind even when the codebase clearly doesn't use it.** This has to be explicitly forbidden, not just left unmentioned.
4. **Accessibility is the easiest thing for the AI to skip.** It got `role`, `aria-live`, and focus styles right only because they were called out specifically. Without the contract, none of them would have appeared.
5. **Connection-to-backend was a non-issue.** The Strategy refactor in Task 4 left the read endpoints untouched, so the new UI plugged in for free. This is itself an argument for stable API contracts: when the *interface* doesn't move, swapping the *implementation* is invisible to the frontend.

## Follow-up

- Add a section to `AGENTS.md` in the product repo: "When generating UI, always load `docs/DESIGN.md` as context first. Never propose Tailwind."
- Consider promoting the color palette + spacing scale into a shared CSS file (`frontend/src/styles/tokens.css`) so the variables don't need to be redeclared in every component.
- Run the same DESIGN.md-driven approach on the timer module UI when Sprint 4 work begins.
