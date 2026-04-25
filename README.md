# Cognitive PKM — Personal Knowledge Management

This repository is **not a notebook**. It is a structured environment for thinking, deciding, and learning — versioned with Git so that my reasoning can be traced over time.

Most note systems optimize for **collecting** information. This one optimizes for three things instead:

1. **Structured thinking** — ideas are forced into formats that make their structure visible.
2. **Decision traceability** — every non-trivial choice leaves a record of *why* it was made, not just *what* was chosen.
3. **Versioned learning** — Git history shows how my understanding evolved, including where I was wrong.

---

## Folder Structure
### ├── decisions/      # Architectural & personal decision records (ADRs)
### ├── notes/          # Atomic, durable notes on concepts and ideas
### ├── experiments/    # Hands-on tests, prototypes, and their results
### ├── literature/     # Notes from books, papers, articles, lectures
### ├── journal/        # Dated entries — what I worked on, what I learned
### ├── questions/      # Open questions I am tracking but cannot yet answer
### └── README.md

### `decisions/`
Records of choices I made and the reasoning behind them. Format: lightweight ADR (Architectural Decision Record).
File naming: `YYYY-MM-DD-short-title.md`
Each decision contains: **Context → Options → Decision → Consequences**.

### `notes/`
Atomic notes — one concept per file, written in my own words. Notes link to each other rather than living in deep hierarchies.
File naming: `kebab-case-title.md`

### `experiments/`
Anything I tried with my own hands: code spikes, tool comparisons, performance tests. Each experiment has a hypothesis, a method, a result, and a takeaway — even if the takeaway is "this didn't work."

### `literature/`
Notes on external sources. Each note captures the source's claims **separately** from my reaction to them, so I never confuse what an author said with what I think about it.

### `journal/`
Dated entries (`YYYY-MM-DD.md`) — short, written the same day. Used to capture friction, surprises, and questions while they are still fresh.

### `questions/`
Open questions I cannot yet answer. Promoted to a `note` or `decision` once I find the answer, with a link back to the original question.

---

## Rules of the System

1. **Write in my own words.** If I cannot rephrase it, I do not understand it yet.
2. **One idea per file.** Long, multi-topic documents are a sign that the structure is wrong.
3. **Link, don't duplicate.** Cross-reference existing notes rather than restating their content.
4. **Date everything that is time-sensitive.** Decisions, journal entries, and experiments are dated; durable notes are not.
5. **Commit often, with intent.** Commit messages describe the *thinking change*, not just the file change. Example: `Refine note on JWT vs session auth — added expiry trade-off`.
6. **Be honest about uncertainty.** If I am not sure, the note says so. Wrong notes are not deleted; they are corrected with the previous version preserved in Git history.
7. **Decisions are immutable.** Once an ADR is accepted, it is not edited. If the decision changes, a new ADR is created that supersedes the old one.
8. **Review periodically.** Once a week, I look at recent entries and promote what's worth keeping, archive what's stale.

---

## Conventions

- **Filenames:** lowercase, kebab-case, no spaces.
- **Front matter (optional but encouraged):** title, date, tags, status (`draft`, `stable`, `superseded`).
- **Tags:** flat, lowercase, hyphenated. Used sparingly — links between notes are preferred over tag taxonomies.
- **Language:** English for technical content; other languages allowed for personal reflection where it flows more naturally.

---

## Why Git?

Because thinking changes. A PKM that doesn't show *how* my understanding evolved is just a static archive. Git turns this repository into a longitudinal record of my reasoning — including the parts I later disagreed with.

---

## Status

📚 Active during the Software Engineering course and intended to continue beyond it.
