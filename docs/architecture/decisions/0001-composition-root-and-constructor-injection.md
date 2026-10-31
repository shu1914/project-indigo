# 0001. Composition root and constructor injection

- Status: Accepted
- Date: 2026-10-31
- Related requirements: IND-019, IND-020, IND-022

## Context
The project wants testable modules and no hidden coupling. The existing code and `docs/architecture.md` already follow one wiring style; this ADR records it so later changes do not drift. Recorded retrospectively from `src/main.cpp` and the user-confirmed requirements.

## Decision
`main()` constructs every module object and passes collaborators by reference, through constructors, as interface types (`IConfiguration`, `IPlatform`, `IUserInterface`, `IPokedex`, repository interfaces). No module constructs another module or looks one up globally. Interfaces are introduced where a module has, or will plausibly have, a second implementation (platform backend, repository storage) or needs a test fake.

## Alternatives considered
- Service locator or global registry — hides dependencies and makes tests depend on global setup.
- DI container — more machinery than a five-module application justifies.

## Consequences
- Positive: every module can be tested with fakes; the dependency graph is visible in one function.
- Negative: `main()` grows with each module; lifecycle calls (`initialize`) must be kept consistent by hand (see architecture.md P2, P3).
