# 0003. Screen navigation stack and explicit screen teardown

- Status: Proposed
- Date: 2026-10-31
- Related requirements: IND-044, IND-061, IND-114, IND-062

## Context
`ScreenManager::show<T>` keeps a single `unique_ptr<IScreen>` and replaces it (`src/ui/screens/ScreenManager.h`). Two needs are unmet and one hazard exists:
1. Back navigation with kept state (IND-061) needs history.
2. A screen cannot request navigation: `HomeScreen`'s button only logs (IND-114).
3. `IScreen::~IScreen` deletes the LVGL tree after derived members (the `WidgetStyle`s) are destroyed, so every screen with styles must repeat `HomeScreen`'s destructor workaround; `TempScreen` does not (architecture.md P1).

## Decision
1. `ScreenManager` holds a stack: `push<T>(args...)`, `pop()`, `replace<T>(args...)`; `show<T>` stays as an alias of `replace<T>` during migration. `clear()` empties the stack.
2. Screens that navigate receive an `INavigator&` through their constructor arguments; they never see the manager type. `INavigator` exposes **named operations for concrete destinations** (for example `showPokemonList()`, `back()`), not a generic `push<T>()`, because a non-template interface cannot express arbitrary types. `ScreenManager` implements it by calling its own templates. The navigator is owned by `UserInterface`, outlives every screen, and is passed by reference. If many destinations make the named list unwieldy, replace it with a `std::function<std::unique_ptr<IScreen>()>` factory, owned by the manager.
3. `IScreen` gains a public non-virtual `destroy()` that deletes and nulls the LVGL root. The base destructor remains as a fallback; per-screen destructor workarounds are removed.
4. Active-screen handoff. Before `destroy()` deletes the screen that LVGL currently displays, the manager first loads a replacement: `pop()` and `replace()` load the destination screen, and `clear()` loads a temporary empty screen (as `ScreenManager::clear()` does today) and deletes it afterwards.
5. Teardown happens while LVGL is initialized. `pop()`, `replace()`, `clear()` and `ScreenManager`'s destructor each call `destroy()` on every screen they remove, then release the objects, in top-to-bottom order. `UserInterface::shutdown()` calls `clear()`, which `Application` runs before `IPlatform::shutdown()` (`lv_deinit`). The default destruction of the stack container must therefore never be the first thing to delete an LVGL tree.
6. Screens below the top of the stack stay alive (state kept), decided by the project owner. Revisit if memory budgets (IND-122) are at risk.

## Alternatives considered
- Use LVGL's own screen loading and `lv_screen_load_anim` only — no ownership of C++ screen objects and no history; does not solve teardown order.
- Rebuild screens on `pop()` — simpler memory use, but loses scroll position and search text (IND-061 "state kept").
- Global navigator singleton — conflicts with ADR-0001 and ADR-0002.
- Make `WidgetStyle` shared/ref-counted — hides the lifetime rule instead of removing it; larger change.

## Consequences
- Positive: one place enforces teardown order; navigation requirements get a seam; the rule "screen owns its styles" is safe by construction.
- Negative: kept-alive screens cost LVGL memory; `INavigator` adds one small interface; `ScreenManager` stays header-only template code, which must still avoid including screen headers.
- Follow-up: tests for push/pop/replace and teardown order (needs an LVGL headless display or a fake `IScreen`).
