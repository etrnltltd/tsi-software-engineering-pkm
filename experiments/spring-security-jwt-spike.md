# Experiment: Minimal Spring Security + JWT Setup for TaskMaster

- **Tags:** spring-boot, security, taskmaster

## Hypothesis

I can stand up a working JWT-authenticated endpoint in Spring Boot 3.4.3 in under two hours, using only the official `spring-security` and `oauth2-resource-server` starters — no third-party JWT library.

## Method

1. New Spring Boot project, single `/api/me` endpoint.
2. Configured `SecurityFilterChain` with `oauth2ResourceServer().jwt()`.
3. Generated an RSA key pair, configured the JWK Set URI to a static endpoint.
4. Hand-crafted a token with `jjwt` *only* for testing, not for production token issuance.
5. Hit the endpoint with the token in `Authorization: Bearer ...`.

## Result

Took 2h 40min — over budget. The friction was almost entirely in JWK key configuration, not in Spring Security itself. Once the keys were right, the filter chain worked first try.

## Takeaways

1. **Spring Security 6 is genuinely cleaner than 5.** The lambda DSL for `SecurityFilterChain` reads like prose.
2. **The hard part of JWT is keys, not tokens.** Every tutorial focuses on the token; nobody talks about JWKS rotation. That is the part I will hit at work.
3. **Two hours was the wrong estimate.** I was anchoring on "I've done this before at work" — but at work, the keys infrastructure already exists. For TaskMaster I had to set it up. Lesson: when estimating, separate "do the thing" from "set up the conditions for the thing."

## Follow-up

- Write a note on JWKS rotation strategies.
- Decide whether TaskMaster needs key rotation at all for a course project. (Probably not — but the ADR should say so explicitly.)
