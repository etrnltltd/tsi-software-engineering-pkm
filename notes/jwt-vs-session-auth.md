---
title: JWT vs Session Authentication
tags: security, backend, auth
---

# JWT vs Session Authentication

The question "JWT or sessions?" is bad. The honest answer is: it depends on what your system actually needs.

## Sessions

The server stores session state (typically in a database). The client holds an opaque session ID in a cookie. To log a user out, you delete the session record. Simple, revocable, server-controlled.

**Cost:** every authenticated request hits the session store. At scale, this is real load.

## JWT

The server signs a token containing the user's claims. The client sends it back. The server verifies the signature without any database lookup. Stateless.

**Cost:** revocation is hard. A signed token is valid until it expires. To log someone out *immediately*, you need a blocklist — at which point you have reintroduced the state you used JWT to avoid.

## What I am using for TaskMaster and why

JWT with a short access-token lifetime (15 min) and a longer-lived refresh token. For a course project with a single backend, sessions would actually be simpler. But:

- I want hands-on practice with the patterns I will face at work, where services are split.
- The pain of refresh-token rotation is itself something worth learning.
- If I add a mobile client later, JWT scales to that without redesign.

## What I'd reconsider

For a banking app or anything with a real "log them out *now*" requirement, I would use sessions. JWT's statelessness is a feature only when you don't need fine-grained revocation.
