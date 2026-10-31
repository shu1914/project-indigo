# 0002. Static `Log` facade as the one global-state exception

- Status: Accepted
- Date: 2026-10-31
- Related requirements: IND-021

## Context
IND-021 asks to avoid unnecessary global state. Logging is needed in every module, including header-only and static code, and passing an `ILogger&` through every constructor would add noise. OQ-8 in `milestones.md` accepted a static facade as an exception. `Log` holds a static `ILogger*` that `main()` sets once (`src/common/logger/Log.cpp`).

## Decision
Keep `indigo::Log` (with the `TRACE/DEBUG/INFO/USER/WARN/ERROR/FATAL` macros) as the only global mutable state. It is initialized once in `main()` before any other module is used. Nothing else may be made global on the same grounds.

## Alternatives considered
- Inject `ILogger&` everywhere — purer, but touches every constructor for a cross-cutting concern.
- Remove logging from library modules — loses diagnostics.

## Consequences
- Positive: logging is available everywhere with no wiring.
- Negative: calling a log macro before `Log::initialize` dereferences a null pointer (architecture.md P5); tests must initialize `Log` or the pointer must default to a no-op logger.
- Follow-up: make `Log` null-safe (architecture.md To-Be step 1).
