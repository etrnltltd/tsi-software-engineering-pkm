# ADR-001: Adopt a Cognitive PKM Structure Based on Folders + Git

- **Tags:** meta, knowledge-management

## Context

I have been keeping notes for years — across Notion, plain text files and the margins of textbooks — but the system has never survived more than a few months. The reason, I think, is that every previous attempt optimized for **capture** instead of **thinking**. I ended up with archives I never returned to.

Now I am a 3rd year student at TSI and Middle Full-Stack Developer, transitioning into a Team Lead role at ClarityLabs, and aiming for Senior in two years. I cannot afford another system that just collects.

## Options Considered

1. **Notion with a tag-based structure.** Excellent UX, weak versioning. The history of my thinking is invisible.
2. **A single long Markdown journal.** Simple, but no separation between transient notes and durable knowledge. Decisions get buried.
3. **Folder-based PKM in Git, modeled after the course's illustrative example.** Forces structure, gives me a real history of how my understanding evolved, and integrates with the tools I already use daily.

## Decision

Option 3. A Git repository with separate folders for `decisions/`, `notes/`, `experiments/`, `literature/`, `journal/`, and `questions/`. Rules defined in the README.

## Consequences

- **Positive:** Decisions become traceable. I can `git log` my own thinking. The repo doubles as evidence of growth for the course and for my career.
- **Negative:** Higher friction than tag-based tools. No mobile-friendly editor. I have to commit deliberately, which I expect to fail at sometimes.
- **Mitigation:** Weekly review on Sundays. If after one month I am not committing at least 3 times a week, I will reduce the structure rather than abandon it.


# ADR-002: Use Vue 3 + Spring Boot for the TaskMaster Course Project

- **Tags:** taskmaster, architecture, stack

## Context

The Software Engineering course requires me to develop a software product across the semester. I chose TaskMaster — a gamified task management app — because the domain is familiar, the scope is realistic for one semester, and it gives me a chance to deepen skills I already use at work.

The decision is *which* stack to commit to. I have professional experience with several, and the temptation is to pick something new "to learn." But the goal of the course project is to ship a complete, well-engineered product — not to maximize novelty.

## Options Considered

1. **Vue 3 (Composition API) + Spring Boot + MySQL.** What I use at work. Highest velocity, lowest risk.
2. **React + Node.js (NestJS) + PostgreSQL.** Industry-popular, would broaden my profile, but I would lose 3–4 weeks to ramp-up.
3. **Vue 3 + Go (Gin) + PostgreSQL.** Compromise — keep the frontend familiar, learn Go on the backend.

## Decision

Option 1. Vue 3 with Composition API, Spring Boot 3.4.3, Spring Security, Spring Data JPA, MySQL.

## Rationale

- The course is graded on engineering quality and the depth of the report, not on stack novelty.
- I want this project to be **portfolio-grade**. Familiar tools mean I can spend my time on architecture, testing, and writing — not on fighting the framework.
- I will get my "learn something new" need met through the *engineering practices* introduced by the course (CI/CD, ADRs, formal testing strategy), not through the stack.

## Consequences

- **Positive:** Faster delivery. More time for documentation and the report. Lower risk of unfinished features.
- **Negative:** No new stack on my CV from this project. I will need to compensate with side projects or the next course.
- **Follow-up:** After the course ends, start a side project in Go or Rust to address the gap.
