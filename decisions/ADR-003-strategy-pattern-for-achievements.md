# ADR-003: Apply the Strategy Pattern to the Achievement Engine

- **Tags:** taskmaster, architecture, design-patterns, sprint-5

## Context

The first version of the achievement engine in TaskMaster works, but it's a single 392-line `AchievementService` class. All 16 achievement rules are hardcoded across 7 private `check*` methods. Adding a new achievement means editing this central file, and the rule logic cannot be tested without spinning up the whole Spring context with a database.

The system is meant to grow. The MVP plan calls for at least 5 achievements; the actual implementation already has 15 active rules and one dead one (`consistency` is defined but never checked anywhere — surfaced while preparing this ADR). Post-MVP, more achievements will be added.

I need a structure that:
- Makes adding a new achievement cheap.
- Lets each rule be tested in isolation.
- Doesn't introduce heavy dependencies.

## Options I considered

1. **Keep the current `if/else` chain.** Works for now. Becomes worse with every new rule. Already painful at 15.

2. **Strategy pattern — one rule class per achievement.** Each rule is a small class implementing a common interface. Spring auto-discovers them. Adding a rule = adding a file. No edits to existing code.

3. **Chain of Responsibility.** Rules pass the request along the chain. Overkill — the rules are independent and don't depend on order.

4. **Rule engine library (Drools, Easy Rules).** Industry-grade, but massive overkill for 15 rules. New dependency, new DSL, more deployment complexity. Wrong tool for a course project.

5. **Observer pattern.** Right pattern for *notifying* about unlocks (toast, email). Wrong pattern for *deciding* unlocks. The frontend already uses event-based notifications, so Observer would be the right tool for that side later.

## Decision

Option 2 — **Strategy pattern**.

A new sub-package `com.example.demo.service.achievement` contains:
- `AchievementRule` — interface with `achievementId()` and `isMet(UserStats)`.
- `AchievementChecker` — Strategy context. Spring auto-injects `List<AchievementRule>`. Pure function: no DB, no logging, no I/O.
- `UserStats` — immutable record holding all numbers a rule could need.
- `UserStatsBuilder` — the only class allowed to read from repositories.
- `rules/` — one `@Component` class per achievement (15 files).

The existing `AchievementService.checkAndGrantAchievements(User, Task)` keeps its signature (so `TaskService` doesn't change) but its body is reduced to: build stats → call checker → loop through returned IDs and call the existing `unlockAchievement(user, id)`.

## Consequences

**Positive:**
- Adding a new achievement = adding a new class. No edits to `AchievementService`.
- Rules become unit-testable without the database.
- The `UserStats` snapshot is built once per check instead of each rule querying the DB independently. Fewer DB calls.
- The pure-function checker can be reused for a "preview my next achievement" feature later.

**Negative:**
- More files than before. For a 5-rule prototype this would be overhead. With 15+ rules it pays off.
- Slight learning curve for anyone unfamiliar with the pattern (mitigated by the module README).

**Mitigation:**
- Each rule file is ~10 lines, so file count is high but total code volume is the same.
- `consistency` is left out of the new module on purpose — it's dead code in the original. Filed as a separate follow-up: build streak tracking properly so it can actually unlock.
