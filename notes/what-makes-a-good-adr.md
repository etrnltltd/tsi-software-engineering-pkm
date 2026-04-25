---
title: What Makes a Good ADR
tags: process, decisions, writing
---

# What Makes a Good ADR

An Architectural Decision Record is not a design document. It is a record of a *moment of choice* — what was on the table, what I picked and why.

## The four sections that matter

1. **Context.** What was the situation? What forced the decision? Without this, future-me cannot tell whether the decision still applies.
2. **Options.** What alternatives were considered? Listing only the chosen option hides the reasoning.
3. **Decision.** What was chosen. One sentence, ideally.
4. **Consequences.** What this commits me to — both good and bad. The bad part is the most important and the most often skipped.

## Common failure modes

- **Writing the ADR after the decision is already implemented.** It becomes a justification, not a record. The "Options" section becomes fiction.
- **Leaving out the "bad" consequences.** A decision with no downsides is a decision that was not actually examined.
- **Editing accepted ADRs.** Once accepted, an ADR is immutable. If the decision changes, a new ADR supersedes it. Otherwise, the history lies.

## Test for whether it's worth an ADR

Ask: *"In six months, if someone (including me) reverses this decision, would they need to know why it was made?"* If yes — write the ADR. If no — it's just an implementation detail.
