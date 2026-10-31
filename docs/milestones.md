# Project Indigo Roadmap

> *"The journey to the Indigo Plateau begins in Pallet Town."*

---

# About this document

This is the single source of truth for Project Indigo requirements and progress. Each milestone is a Kanto city; completing a gym city earns its badge.

## Vision
*Provenance: Inferred from the code and README, please confirm or correct.*

Project Indigo is an offline atlas ("Pokédex") for pocket monsters. It is a C++17 application on LVGL 9.5 with a desktop SDL2 simulator (800×480). The UI is written in C++ on a component layer (`WidgetBuilder`, `WidgetStyle`, `WidgetBehavior`), not LVGL XML. Pokémon data is served by local repositories, and the long-term plan is to import PokéAPI data (details, artwork, cries) into a local database for fully offline use. Version 1.0 is also a portfolio piece.

## How to read this document

- **ID:** `IND-NNN`, permanent. IDs are never renumbered or reused. New items take the next free number, so a milestone's table may not be in ID order.
- **Category:** Functional · Non-functional · Technical constraint · Design constraint · Quality.
- **Priority:** Must · Should · Could.
- **Status:** Not Started · In Progress · Blocked · Completed · Not Applicable. Completed requires evidence in Notes.
- **Verification:** Test · Inspection · Demonstration · Analysis.
- **Notes tags:** `Confirmed` (from the original roadmap or you), `Inferred` (derived from code or context, needs confirmation), `Open question` (see [Decisions and open questions](#decisions-and-open-questions)), `Defect` (existing problem found in the code).
- Original roadmap wording is kept in Notes as *Original: "..."* when the requirement was reworded.
- Releases follow `docs/development/versioning.md`: Milestone N maps to `v0.(N+1).0`, and Milestone 9 maps to `v1.0.0`.
- Evidence was gathered on branch `feat/home-screen` (commit `afe5191`). No build or test run was performed for this review.

---

# Milestone 0 - Pallet Town

## Objective
Lay the project foundation. *Release: v0.1.0 (tagged).*

### Repository
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-001 | The project shall be hosted in a GitHub repository. | Quality | Repository exists with remote `origin`. | Must | Completed | — | Inspection | Confirmed. Original: "Create GitHub repository". Evidence: `origin` remote in git config. |
| IND-002 | The repository shall contain a README. | Quality | `README.md` describes the project and links the changelog. | Must | Completed | — | Inspection | Confirmed. Original: "Write README". Evidence: `README.md` (4 lines; build instructions are tracked in IND-089). |
| IND-003 | The repository shall contain a LICENSE. | Quality | `LICENSE` present at the root. | Must | Completed | — | Inspection | Confirmed. Original: "Add LICENSE". Evidence: `LICENSE`. |
| IND-004 | Build output and temporary files shall be excluded from version control. | Quality | `.gitignore` excludes `build/` and object files. | Must | Completed | — | Inspection | Confirmed. Original: "Configure .gitignore". Evidence: `.gitignore`. See IND-111 for a conflict. |

### Build System
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-005 | The project shall build with CMake. | Technical constraint | `cmake --preset debug` configures without error. | Must | Completed | — | Demonstration | Confirmed. Original: "Configure CMake". Evidence: `CMakeLists.txt`, `CMakePresets.json`. |
| IND-006 | The project shall provide a Debug build. | Technical constraint | `make debug` produces `build/debug/project_indigo`. | Must | Completed | IND-005 | Demonstration | Confirmed. Original: "Debug build". Evidence: preset `debug`, `Makefile`. |
| IND-007 | The project shall provide a Release build. | Technical constraint | `make release` produces `build/release/project_indigo`. | Must | Completed | IND-005 | Demonstration | Confirmed. Original: "Release build". Evidence: preset `release`, `.github/workflows/build.yml` (Release matrix). |

### Project Structure
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-008 | The repository shall have a defined project skeleton. | Design constraint | `src/`, `tests/`, `docs/`, `config/` and `external/` exist. | Must | Completed | — | Inspection | Confirmed. Original: "Create project skeleton". |
| IND-009 | The project shall have an `application` module. | Design constraint | `src/application/` builds as its own CMake target. | Must | Completed | IND-008 | Inspection | Confirmed. Original: "Create application module". Evidence: `src/application/CMakeLists.txt`. |
| IND-010 | Source modules shall live under a common source directory. | Design constraint | All modules are subdirectories of `src/`. | Should | Completed | IND-008 | Inspection | Confirmed. Original: "Create modules directory". Evidence: `src/`. |
| IND-011 | Project documentation shall live in `docs/`. | Quality | `docs/` exists and holds the project documents. | Should | Completed | IND-008 | Inspection | Confirmed. Original: "Create docs directory". |

### Application
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-012 | The system shall provide an `Application` class. | Design constraint | `indigo::Application` exists and is constructed in `main()`. | Must | Completed | IND-009 | Inspection | Confirmed. Original: "Create `Application`". Evidence: `src/application/Application.h`, `src/main.cpp`. |
| IND-013 | `Application::run()` shall execute the application lifecycle. | Functional | `run()` initializes, loops, then shuts down. | Must | Completed | IND-012 | Test | Confirmed. Original: "Implement `Application::run()`". Evidence: `Application.cpp:run()`. No automated test (see IND-126). |
| IND-014 | The application shall log a startup message. | Functional | A "Hello Project Indigo." log line appears on startup. | Could | Completed | IND-013 | Demonstration | Confirmed. Original: "Display \"Hello Project Indigo\"". Evidence: `DEBUG("Hello Project Indigo.")` in `Application.cpp`. |

---

# Milestone 1 - Pewter City · Boulder Badge

## Objective
Establish the core architecture. *Release: v0.2.0 (tagged).*

### Architecture
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-015 | Module boundaries shall be defined. | Design constraint | `application`, `platform`, `ui`, `pokedex` and `common` are documented. | Must | Completed | — | Inspection | Confirmed. Original: "Design module boundaries". Evidence: `docs/architecture.md` (now out of date, see IND-128). |
| IND-016 | The initial modules shall exist. | Design constraint | Each module has sources and a CMake target. | Must | Completed | IND-015 | Inspection | Confirmed. Original: "Create initial modules". |
| IND-017 | Each module shall have its own CMake file. | Design constraint | Every module directory has a `CMakeLists.txt`. | Should | Completed | IND-016 | Inspection | Confirmed. Original: "Configure module CMake files". |
| IND-018 | The module dependency flow shall be defined. | Design constraint | Flow `main → Application → Platform/UI → Pokedex` documented. | Must | Completed | IND-015 | Inspection | Confirmed. Original: "Define dependency flow". Evidence: `docs/architecture.md`. |

### Dependency Injection
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-019 | Modules shall be constructed in `main()`. | Design constraint | All module objects are created in `main()` and nowhere else. | Must | Completed | IND-018 | Inspection | Confirmed. Original: "Construct modules in `main()`". Evidence: `src/main.cpp`. |
| IND-020 | Dependencies shall be injected through constructors. | Design constraint | Each module receives collaborators by constructor reference. | Must | Completed | IND-019 | Inspection | Confirmed. Original: "Inject dependencies through constructors". Evidence: `Application(IConfiguration&, IPlatform&, IUserInterface&)`. |
| IND-021 | The code shall avoid unnecessary global state. | Design constraint | No singletons or mutable globals other than those justified in Notes. | Should | Completed | IND-019 | Inspection | Confirmed. Original: "Eliminate unnecessary global state". Inferred: `Log` is a static facade initialized in `main()` (`Log::initialize`), which is a global by design. Accepted exception, to be documented in `docs/architecture.md` (OQ-8, delegated). |

### Application
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-022 | `main()` shall be the application composition root. | Design constraint | `main()` wires all modules and calls `Application::run()`. | Must | Completed | IND-019 | Inspection | Confirmed. Original: "Establish the application composition root". Evidence: `src/main.cpp`. |
| IND-023 | The application shall start up successfully. | Functional | Running the binary reaches the event loop without error. | Must | Completed | IND-013 | Demonstration | Confirmed. Original: "Verify application startup". No automated test found. |
| IND-024 | The application shall shut down cleanly. | Functional | Closing the window calls `Application::shutdown()` and exits with code 0. | Must | Completed | IND-013 | Demonstration | Confirmed. Original: "Verify application shutdown". Evidence: `SDLPlatform` close callback, `Application::shutdown()`. No automated test found. |

### Utilities
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-025 | The system shall provide logging. | Functional | `TRACE`/`DEBUG`/`USER`/`ERROR` macros write via `ILogger`. | Must | Completed | — | Test | Confirmed. Original: "Logging". Evidence: `src/common/logger/`. No tests. |
| IND-026 | The system shall load configuration from a file. | Functional | `Configuration::load()` reads `config/config.json`. | Must | Completed | — | Test | Confirmed. Original: "Configuration". Evidence: `src/common/config/`. No tests. |
| IND-027 | The system shall report failures through a common error type. | Functional | Failures return `Result` with an `Error` code and message. | Must | Completed | — | Test | Confirmed. Original: "Basic error handling". Evidence: `src/common/error/Result.h`. No tests. |

---

# Milestone 2 - Cerulean City · Cascade Badge

## Objective
Build the Pokémon domain. *Release: v0.3.0 (tagged).*

### Domain
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-028 | The domain shall model a Pokémon. | Functional | `Pokemon` exposes id and name. | Must | Completed | — | Test | Confirmed. Original: "Create Pokémon model". Evidence: `src/pokedex/model/pokemon/`. |
| IND-029 | The domain shall model a Type. | Functional | `Type` model exists. | Must | Completed | — | Inspection | Confirmed. Original: "Create Type model". Evidence: `src/pokedex/model/type/`. |
| IND-030 | The domain shall model an Ability. | Functional | `Ability` model exists. | Must | Completed | — | Inspection | Confirmed. Original: "Create Ability model". Evidence: `src/pokedex/model/ability/`. |
| IND-031 | The domain shall model an Evolution. | Functional | `Evolution` and `EvolutionMethod` models exist. | Must | Completed | — | Test | Confirmed. Original: "Create Evolution model". Evidence: `src/pokedex/model/evolution/`. |
| IND-032 | The domain shall model Pokémon details. | Functional | `PokemonDetails` model exists. | Must | Completed | IND-028, IND-029, IND-030 | Inspection | Confirmed. Original: "Create PokemonDetails model". Evidence: `src/pokedex/model/pokemon_details/`. |

### Repository
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-033 | Repository interfaces shall be defined: `IPokemonRepository`, `IEvolutionRepository`. | Design constraint | Both interfaces exist and `Pokedex` depends only on them. | Must | Completed | IND-028, IND-031 | Inspection | Confirmed. Original: "Design repository interface" with the two sub-items. Evidence: `src/pokedex/repository/*/I*Repository.h`. |
| IND-034 | Local repository implementations shall be provided: `PokemonRepository`, `EvolutionRepository`. | Functional | Both implement their interfaces from in-code data. | Must | Completed | IND-033 | Test | Confirmed. Original: "Local repository implementation" with the two sub-items. Evidence: `src/pokedex/repository/`. |

### Sample Data
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-035 | The system shall load sample Pokémon. | Functional | Repositories return the sample set (e.g. id 1 = Bulbasaur). | Must | Completed | IND-034 | Test | Confirmed. Original: "Load sample Pokémon". Evidence: `src/pokedex/data/Pokemons.cpp`. |
| IND-036 | Data access through the repositories shall be verified. | Quality | Lookup by valid id returns data; unknown id returns nothing. | Must | Completed | IND-035 | Test | Confirmed. Original: "Verify data access". Evidence: `PokemonRepositoryTests.cpp`. |
| IND-037 | The repositories shall have unit tests. | Quality | Catch2 tests cover both repositories and run in CI. | Must | Completed | IND-034 | Test | Confirmed. Original: "Unit test repository". Evidence: `tests/pokedex/repository/{pokemon,evolution}/`, `.github/workflows/build.yml`. |

---

# Milestone 3 - Vermilion City · Thunder Badge

## Objective
Integrate LVGL and establish the UI foundation. *Release: v0.4.0.*

### LVGL
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-038 | LVGL shall be built as part of the project. | Technical constraint | Configure and build with LVGL 9.5 from `external/lvgl` and `config/lv_conf.h`. | Must | Completed | IND-005 | Demonstration | Confirmed. Original: "Build LVGL". Evidence: `external/lvgl` (v9.5.0), `CMakeLists.txt`. |
| IND-039 | ~~LVGL XML shall be integrated.~~ | Technical constraint | — | — | Not Applicable | — | — | Confirmed. Original: "~~Integrate LVGL XML~~ (Decided not to adopt for Project Indigo. XML generation does not align with the project's component-oriented C++ architecture. UI will be implemented in C++ while following LVGL best practices. LVGL Pro will be explored separately in a dedicated project.)" |
| IND-040 | The system shall have a UI module. | Design constraint | `src/ui/` builds as the `ui` target and implements `IUserInterface`. | Must | Completed | IND-038 | Inspection | Confirmed. Original: "Create UI module". Evidence: `src/ui/UserInterface.cpp`. |
| IND-041 | The system shall initialize a display. | Functional | Starting the app opens an 800×480 SDL window. | Must | Completed | IND-038 | Demonstration | Confirmed. Original: "Initialize display". Evidence: `lv_sdl_window_create` in `SDLPlatform.cpp`. Size is hard-coded (IND-104). |
| IND-042 | The system shall accept pointer input. | Functional | Clicking a button in the window raises an `LV_EVENT_CLICKED`. | Must | Completed | IND-041 | Demonstration | Confirmed. Original: "Initialize input". Evidence: `lv_sdl_mouse_create` in `SDLPlatform.cpp`, merged `feat/enable-input`. Only the mouse is initialized (keyboard: IND-103). |

### UI
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-043 | The UI shall have a screen manager. | Functional | `ScreenManager::show<T>()` creates, loads and shows a screen; `clear()` releases it. | Must | Completed | IND-040 | Test | Confirmed. Original: "Screen manager". Evidence: `src/ui/screens/ScreenManager.h`. No automated test (IND-129). |
| IND-044 | The UI shall support navigation between screens. | Functional | From screen A the user reaches screen B and can return to A. | Must | In Progress | IND-043 | Demonstration | Confirmed. Original: "Navigation". Evidence so far: `show<T>()` replaces the current screen. Missing: back stack/history, and a navigation trigger (IND-114). |
| IND-045 | The UI shall display a first screen at startup. | Functional | Launching the app shows a screen without error. | Must | Completed | IND-043 | Demonstration | Confirmed. Original: "First screen". Evidence: `UserInterface::initialize()` shows `HomeScreen` (was `TempScreen`). |
| IND-046 | ~~The UI shall apply a theme chosen in configuration.~~ | Functional | — | — | Not Applicable | — | — | Confirmed. Original: "Theme". Retired 2026-10-31: merged into IND-079 (OQ-3, "themes" are set at UX). `ui.theme` exists in `config.json` but no code reading it was found. |

### Issues and housekeeping *(added)*
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-103 | The system shall accept keyboard input. | Functional | Keyboard device is registered and can focus and activate widgets. | Could | Not Started | IND-042 | Demonstration | Inferred. Gap from IND-042. Lowered from Should on 2026-10-31: the target has touch and a power button only (OQ-5). Still useful on desktop. |
| IND-104 | The display size shall come from configuration. | Design constraint | Changing the size in `config.json` changes the SDL window without recompiling. | Should | Not Started | IND-026, IND-041 | Demonstration | Inferred. Defect: `SCREEN_WIDTH`/`SCREEN_HEIGHT` are `#define`s in `SDLPlatform.cpp`. |
| IND-105 | Initialization failures in the UI and Pokedex modules shall stop startup with an error. | Functional | If `IUserInterface::initialize()` or `IPokedex::initialize()` fails, `Application::run()` logs the error and exits non-zero. | Must | Not Started | IND-027 | Test | Inferred. Defect: `Application::initialize()` ignores the result of `_ui.initialize()`; `UserInterface::initialize()` returns `bool` and ignores `_pokedex.initialize()`. |
| IND-106 | The process exit code shall be well defined. | Functional | Success returns 0; each failure returns a documented non-zero code. | Should | Not Started | IND-027 | Test | Inferred. Defect: `Application::run()` returns `static_cast<int>(result.error)` (and contains a stray `;;`). |
| IND-107 | `ScreenManager::clear()` shall release the active screen without a placeholder screen. | Quality | `clear()` leaves LVGL in a valid state and is covered by a test or documented rationale. | Could | Not Started | IND-043 | Test | Inferred. Defect (fragile): it loads and deletes a temporary `lv_obj_create(nullptr)` screen. See `fda8ca5`. |
| IND-108 | Temporary scaffolding shall be removed. | Quality | `TempScreen` and its TODO data-printing code are deleted or moved to tests. | Should | Not Started | IND-045 | Inspection | Inferred. `TempScreen.cpp` has 4 TODOs ("Remove this once actual screen is implemented"). |
| IND-110 | The configuration file path shall not depend on the current working directory. | Quality | The app finds its config when launched from any directory. | Could | Not Started | IND-026 | Test | Inferred. Defect: `main()` uses `"config/config.json"`. Works only because CMake copies `config/` next to the binary. |
| IND-111 | `.gitignore` shall not conflict with tracked files. | Quality | `git ls-files -i -c --exclude-standard` lists nothing. | Could | Not Started | IND-004 | Inspection | Inferred. Defect: `Makefile` is listed in `.gitignore` but tracked. |
| IND-112 | Development-only LVGL monitors shall not be enabled in committed config by accident. | Quality | `LV_USE_SYSMON` and `LV_USE_MEM_MONITOR` are 0 in committed `config/lv_conf.h`, or enabled only for Debug with the reason documented. | Could | Not Started | IND-038 | Inspection | Inferred. Uncommitted diff in `config/lv_conf.h` enables both. Decide: keep or discard. |
| IND-140 | The whole UI shall be operable by touch alone. | Functional | Every action (navigate, scroll, search, filter, sort, favourite, back) works with tap and drag only, and tap targets are large enough for a finger (minimum size set in the theme, e.g. 44 px). | Must | Not Started | IND-042 | Demonstration | Confirmed in intent: no buttons other than power (OQ-5). The 44 px value is a Proposed starting point. |

---

# Milestone 4 - Celadon City · Rainbow Badge

## Objective
Build the Pokédex interface. *Release: v0.5.0.*

### Screens
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-047 | The UI shall provide a Home screen. | Functional | Home shows the pokeball entry point and leads into the Pokédex. | Must | In Progress | IND-043 | Demonstration | Confirmed. Original: "Home". Evidence: `HomeScreen.cpp` draws the pokeball. Missing: the button only logs "Clicked!" (IND-114). |
| IND-048 | The UI shall provide a Pokémon List screen. | Functional | The list shows every Pokémon from `IPokedex` with name and number, and scrolls. | Must | Not Started | IND-047, IND-050 | Demonstration | Confirmed. Original: "Pokémon List". |
| IND-049 | The UI shall provide a Pokémon Details screen. | Functional | Selecting a Pokémon shows its details (types, abilities, evolutions). | Must | Not Started | IND-048, IND-032 | Demonstration | Confirmed. Original: "Pokémon Details". |

### Widgets
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-050 | The UI shall provide a Pokémon Card widget. | Functional | The card shows sprite, name and number from a `Pokemon`. | Must | Not Started | IND-040, IND-054 | Demonstration | Confirmed. Original: "Pokémon Card". Content of the card is Inferred. |
| IND-051 | The UI shall provide a Type Badge widget. | Functional | The badge shows a type name in the type's colour. | Must | Not Started | IND-040, IND-029 | Demonstration | Confirmed. Original: "Type Badge". |
| IND-052 | The UI shall provide a Search Bar widget. | Functional | The widget accepts text input and reports changes. | Must | Not Started | IND-040, IND-141 | Demonstration | Confirmed. Original: "Search Bar". Text input comes from the on-screen keyboard (IND-141), because no physical keyboard is planned. |
| IND-053 | The UI shall provide a Loading Indicator widget. | Functional | The widget animates while data loads and is removed afterwards. | Should | Not Started | IND-040 | Demonstration | Confirmed. Original: "Loading Indicator". |

### Resources
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-054 | The application shall load Pokémon images. | Functional | A sprite/artwork file renders in the UI. A missing file shows a placeholder. | Must | Not Started | IND-040 | Demonstration | Confirmed. Original: "Images". Missing-file behaviour is Inferred. |
| IND-055 | The application shall use project fonts. | Functional | Fonts render at the sizes the screens need, including accented glyphs (IND-113). | Must | Not Started | IND-040 | Demonstration | Confirmed. Original: "Fonts". |
| IND-056 | The application shall use icons. | Functional | Icons for navigation and types render. | Should | Not Started | IND-040 | Demonstration | Confirmed. Original: "Icons". |

### Issues *(added)*
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-109 | `HomeScreen` shall not hold per-instance geometry in function-level statics or unexplained numbers. | Quality | The divider points array is owned by the screen; sizes derive from named constants or the display size. | Should | Not Started | IND-047 | Inspection | Inferred. Defect: `static lv_point_precise_t points[]` in `HomeScreen::onCreate()`; magic values 220, 120, 30 and `0xEE1515`. |
| IND-113 | Text shall render accented characters in Pokémon names (e.g. "é"). | Functional | "Pokémon" displays correctly in the chosen font. | Must | Not Started | IND-055 | Demonstration | Inferred. Common glyph gap for custom/built-in fonts. |
| IND-114 | The Home pokeball button shall navigate to the Pokémon List. | Functional | Clicking the button shows the list screen. | Must | Not Started | IND-044, IND-048 | Demonstration | Inferred. Currently the callback only calls `USER("Clicked!")`. |
| IND-139 | The project shall include a placeholder asset set made of original art. | Quality | The app, screenshots and CI-run tests work with the placeholder set and no Pokémon artwork or audio. | Should | Not Started | IND-054 | Demonstration | Inferred. Lets screenshots, GIFs and tests be published (IND-095, IND-101) and run in CI, which has no downloaded assets. |
| IND-141 | The UI shall provide an on-screen keyboard for text entry. | Functional | Focusing the Search Bar shows a keyboard that types into it and can be dismissed. | Must | Not Started | IND-040, IND-042 | Demonstration | Inferred from OQ-5 (touch only). |

---

# Milestone 5 - Fuchsia City · Soul Badge

## Objective
Improve the user experience. *Release: v0.6.0.*

### Features
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-057 | The user shall be able to search Pokémon. | Functional | Typing a name or number narrows the list. | Must | Not Started | IND-048, IND-052 | Test | Confirmed. Original: "Search". Matching rules (case, partial) are Inferred. |
| IND-058 | The user shall be able to filter Pokémon. | Functional | The list can be filtered by type (including dual-type), generation (I to III) and favourites. | Should | Not Started | IND-048, IND-029, IND-060 | Test | Confirmed. Original: "Filtering". Fields per OQ-6 (delegated); an ability filter is Could. |
| IND-059 | The user shall be able to sort Pokémon. | Functional | The list can be sorted by number and by name. | Should | Not Started | IND-048 | Test | Confirmed. Original: "Sorting". |
| IND-060 | The user shall be able to mark favourites. | Functional | A Pokémon can be added to and removed from favourites and the list can show them. | Could | Not Started | IND-048 | Test | Confirmed. Original: "Favorites". Persistence is IND-115. |

### Navigation
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-061 | The user shall be able to go back to the previous screen. | Functional | A back action returns to the previous screen with its state kept. | Must | Not Started | IND-044 | Demonstration | Confirmed. Original: "Back navigation". |
| IND-062 | Screen changes shall use transitions. | Functional | Navigating plays an animation whose duration is a named constant. | Could | Not Started | IND-044 | Demonstration | Confirmed. Original: "Screen transitions". Nice-to-have, not needed now (OQ-7). |
| IND-063 | The UI shall show loading states. | Functional | A loading indicator appears while data is being fetched. | Should | Not Started | IND-053 | Demonstration | Confirmed. Original: "Loading states". |

### UI Polish
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-064 | Lists shall show an empty state. | Functional | A search with no match shows a message instead of a blank list. | Should | Not Started | IND-057 | Demonstration | Confirmed. Original: "Empty states". |
| IND-065 | The UI shall show error dialogs. | Functional | A failure (e.g. missing data) shows a dialog with a message and a dismiss action. | Should | Not Started | IND-027 | Demonstration | Confirmed. Original: "Error dialogs". |
| IND-066 | Screens shall have a consistent, readable layout. | Quality | Layout is reviewed against the 800×480 target without clipped or overlapping content. | Should | Not Started | IND-048, IND-049 | Inspection | Confirmed. Original: "Better layouts" (reworded to be reviewable). |

### Added
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-115 | Favourites shall persist across restarts. | Functional | After restart the same favourites are shown. | Should | Not Started | IND-060, IND-071 | Test | Inferred. Separate user-data file per OQ-4; the path comes from configuration (IND-135). |

---

# Milestone 6 - Saffron City · Marsh Badge

## Objective
Support offline-first data. *Release: v0.7.0.*

### PokéAPI
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-067 | The PokéAPI endpoints and data needed shall be identified. | Quality | A short document lists endpoints, fields used and approximate download size. | Must | Not Started | — | Inspection | Confirmed. Original: "Explore API". |
| IND-068 | The system shall download Pokémon data. | Functional | Running the importer fetches Pokémon #1 to #386 (Generations I to III). | Must | Not Started | IND-067, IND-116 | Test | Confirmed. Original: "Download Pokémon". Scope per OQ-2; run as a separate import step (OQ-1). |
| IND-069 | The system shall download Pokémon artwork. | Functional | Artwork for each downloaded Pokémon is stored locally. | Must | Not Started | IND-068 | Test | Confirmed. Original: "Download artwork". See IND-121 (licensing). |
| IND-070 | The system shall download Pokémon cries. | Functional | Each cry audio file is stored locally. | Could | Not Started | IND-068 | Test | Confirmed. Original: "Download cries". See IND-121. |

### Local Database
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-071 | The system shall define a local database schema. | Design constraint | Schema documented for Pokémon, types, abilities, evolutions and assets, for a SQLite database that the UI opens read-only. | Must | Not Started | IND-067 | Inspection | Confirmed. Original: "Database schema". SQLite per OQ-9 (delegated). User data is stored separately (IND-115). |
| IND-072 | The system shall import downloaded data into the database. | Functional | After import, repositories read from the database. | Must | Not Started | IND-068, IND-071 | Test | Confirmed. Original: "Importer". |
| IND-073 | The system shall synchronize local data with PokéAPI on request. | Functional | A sync updates changed records and keeps unchanged ones. | Should | Not Started | IND-072 | Test | Confirmed. Original: "Synchronization". Run explicitly as a separate step, not on every UI action (OQ-1, delegated). |
| IND-074 | The system shall validate cached data. | Functional | Corrupt or incomplete records are detected and re-fetched or reported. | Should | Not Started | IND-072 | Test | Confirmed. Original: "Cache validation". |

### Added
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-116 | The API base URL and timeout shall come from configuration. | Functional | Changing `api.baseUrl` or `api.timeoutMs` changes downloader behaviour. | Must | Not Started | IND-026 | Test | Inferred. Keys exist in `config/config.json` but no consumer was found. |
| IND-117 | Download errors shall be handled without losing local data. | Functional | A timeout, HTTP error or partial download is reported, retried within a bound, and leaves existing data intact. | Must | Not Started | IND-068, IND-027 | Test | Inferred. Retry bound is an Open question. |
| IND-118 | The importer shall respect PokéAPI usage guidelines. | Non-functional | Requests are rate-limited and each resource is fetched at most once per sync. | Should | Not Started | IND-068 | Analysis | Inferred. Check the current PokéAPI fair-use policy when implementing. |
| IND-119 | Hard-coded sample data shall be replaced by the database. | Design constraint | `src/pokedex/data/*.cpp` is removed or reduced to test fixtures. | Should | Not Started | IND-072 | Inspection | Inferred. `Evolutions.cpp` has a TODO to refactor the data. |
| IND-120 | The database shall carry a schema version and migrate older versions. | Technical constraint | Opening a database with an older version migrates it or reports a clear error. | Should | Not Started | IND-071 | Test | Inferred. |
| IND-121 | Downloaded Pokémon artwork, audio and databases shall be generated by the importer and never committed or published. | Quality | `.gitignore` excludes the asset and database directories, and the README states the assets' source and says this is an unofficial, non-commercial fan project not affiliated with Nintendo, Game Freak or The Pokémon Company. | Should | Not Started | IND-069 | Inspection | Raised from Could on 2026-10-31 because the repository is public (IND-138). Artwork, cries and names are third-party IP, so keeping them out of git and releases is Inferred. A disclaimer is not legal permission, and this is not legal advice. |
| IND-138 | The repository shall stay public while the Cubic AI reviewer is used. | Technical constraint | The repository visibility is public. | Must | Completed | — | Inspection | Confirmed: you said the reviewer needs a public repository to be free. Evidence: stated by you; visibility was not checked from here. Public visibility is why IND-121 matters. |

---

# Milestone 7 - Cinnabar Island · Volcano Badge

## Objective
Polish and optimize. *Release: v0.8.0.*

### Performance
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-075 | Resources shall be cached in memory. | Non-functional | Revisiting a screen does not reload images or fonts from disk. | Should | Not Started | IND-054 | Test | Confirmed. Original: "Resource caching". |
| IND-076 | Images shall load faster. | Non-functional | Image load time meets the target in IND-122. | Should | Not Started | IND-054, IND-122 | Analysis | Confirmed. Original: "Faster image loading" (no measurable target, see IND-122). |
| IND-077 | Memory use shall be optimized. | Non-functional | Peak memory stays within the budget in IND-122. | Should | Not Started | IND-122 | Analysis | Confirmed. Original: "Memory optimization" (no measurable target, see IND-122). |

### UX
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-078 | The application shall play audio. | Functional | A Pokémon cry plays from the details screen. | Could | Not Started | IND-070 | Demonstration | Confirmed. Original: "Audio playback". Optional on the target (OQ-5); see IND-136. |
| IND-079 | The UI shall apply a theme (dark/light) from `ui.theme` in configuration, and the user shall be able to change it in Settings. | Functional | Startup uses the configured theme, and changing it in Settings applies immediately and persists. | Should | Not Started | IND-026, IND-080 | Demonstration | Confirmed. Original: "Themes". Absorbs IND-046 (OQ-3). Screen colours (e.g. `HomeScreen` hard-codes them) move to theme styles. |
| IND-080 | The application shall have a Settings screen. | Functional | Settings shows and saves user-changeable options. | Could | Not Started | IND-026 | Demonstration | Confirmed. Original: "Settings". Contents are an Open question. |
| IND-081 | The UI shall use animations. | Functional | Defined animations play without dropping below the frame rate in IND-122. | Could | Not Started | IND-122 | Demonstration | Confirmed. Original: "Animations". |

### Code Quality
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-082 | The code shall be refactored where review finds issues. | Quality | Open findings from the review (`/code-review`, `/simplify`) are resolved. | Should | Not Started | — | Inspection | Confirmed. Original: "Refactoring". |
| IND-083 | Dead code shall be removed. | Quality | No unused functions, files or commented-out blocks remain. | Should | Not Started | IND-108 | Inspection | Confirmed. Original: "Remove dead code". |
| IND-084 | Module APIs shall be reviewed and improved. | Quality | Public headers expose only what other modules use. | Should | Not Started | — | Inspection | Confirmed. Original: "Improve module APIs". |

### Added
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-122 | Performance budgets shall be defined and measured. | Non-functional | On the target, startup to first frame is at most 3 s (desktop: 1 s); list scrolling holds at least 30 FPS (LVGL's refresh period is 33 ms); a list thumbnail loads in at most 100 ms; peak process memory is at most 64 MB. | Should | Not Started | — | Analysis | Inferred. **Proposed values, not measured.** Suggested by me per OQ-11; confirm after the first profiling run and once the device (OQ-5) is chosen. |
| IND-123 | The build shall enable compiler warnings and pass without them. | Quality | `-Wall -Wextra` (or equivalent) is on for first-party targets with zero warnings. | Should | Not Started | IND-005 | Inspection | Inferred. No warning flags are set in the CMake files. |
| IND-124 | A formatter and linter configuration shall be provided. | Quality | `.clang-format` (and optionally `.clang-tidy`) matches the existing style. | Could | Not Started | — | Inspection | Inferred. None exist. |
| IND-125 | The platform backend shall be selectable at configure time (SDL for development, Linux DRM/KMS plus evdev for the embedded target). | Technical constraint | Building without SDL2 is possible when the DRM backend is chosen, and the app starts on that backend. | Should | Not Started | IND-038 | Demonstration | Inferred, refined by OQ-5. `docs/setup.md`: SDL2 is currently always required. LVGL 9.5 has `drm`, `evdev`, `fb` and `wayland` drivers, all disabled in `config/lv_conf.h`. Wayland is the alternative. |
| IND-131 | On the embedded target the application shall start automatically at boot and be the only foreground program. | Functional | After power-on the UI appears with no login or desktop, within the startup budget of IND-122. | Could | Not Started | IND-125, IND-122 | Demonstration | Inferred from OQ-5 ("load the app immediately"). Needs a minimal Linux image. Yocto is preferred and will be set up once a device is chosen (OQ-5); the app stays stand-alone until then. Bare-metal is not planned. |
| IND-132 | The project shall support cross-compiling for the embedded target. | Technical constraint | A CMake toolchain file builds the app for the target architecture, and the build passes. | Could | Not Started | IND-125 | Demonstration | Inferred from OQ-5. Depends on the board chosen. The Yocto recipe will consume the CMake build, so the SDL2 dependency must be optional (IND-125) and tests disableable (`BUILD_TESTING`). |
| IND-133 | Only the `platform` module shall depend on a display or input backend. | Design constraint | No `#include` of SDL, DRM or evdev headers, and no backend-specific calls, outside `src/platform/`. | Must | Not Started | IND-125 | Inspection | Confirmed in intent: you want minimal changes to add a device (OQ-5). Check: `grep -rE "SDL|drm|evdev" src --exclude-dir=platform`. Today `SDLPlatform` is the only user. |
| IND-134 | UI layouts shall adapt to the display size and not assume 800×480. | Design constraint | Screens render in landscape without clipping at 800×480 (primary) and 480×320 (small) by changing configuration only. Portrait is not supported. | Should | Not Started | IND-104, IND-109 | Demonstration | Inferred from OQ-5. Landscape and these sizes are my recommendation (delegated). `HomeScreen` uses fixed pixel sizes (220, 120, 30). |
| IND-135 | The database, user-data and asset locations shall come from configuration. | Design constraint | Changing the paths in configuration moves all three, and the app runs from a read-only root file system when user data is on a writable path. | Must | Not Started | IND-026, IND-110 | Test | Confirmed in intent: OQ-4 ("works with an embedded device, Linux or not"). |
| IND-136 | Audio shall sit behind an interface with a no-op implementation. | Design constraint | On a device without audio the app runs with no errors and no sound; the desktop build plays sound through the real implementation. | Should | Not Started | IND-078 | Test | Confirmed in intent: audio is optional (OQ-5). |

---

# Milestone 8 - Viridian City · Earth Badge

## Objective
Prepare for release. *Release: v0.9.0.*

### Testing
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-085 | Unit tests shall cover first-party logic. | Quality | Line coverage on non-UI code (`common`, `pokedex`, `application`) is at least 80%, measured in CI, and all tests pass. | Must | In Progress | IND-037 | Test | Confirmed. Original: "Unit tests". Evidence so far: 2 files in `tests/` covering repositories only. Target per OQ-12 (delegated). |
| IND-086 | Integration tests shall cover the main flows. | Quality | Startup → list → details → back runs in an automated test. | Should | Not Started | IND-049, IND-129 | Test | Confirmed. Original: "Integration tests". |
| IND-087 | Manual testing shall be performed and recorded. | Quality | The QA test plan (IND-130) is run in full and the results, including every bug found, are recorded before the release candidate. | Must | Not Started | IND-049, IND-130 | Demonstration | Confirmed. Original: "Manual testing". QA is run first, then bugs are triaged (OQ-13). |

### Documentation
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-088 | Architecture shall be documented. | Quality | `docs/architecture.md` matches the code and includes a diagram. | Must | In Progress | IND-128 | Inspection | Confirmed. Original: "Architecture". `docs/architecture.md` exists but is stale. |
| IND-089 | Modules shall be documented. | Quality | Each module has a short description of its role and public API. | Should | Not Started | IND-088 | Inspection | Confirmed. Original: "Module documentation". Also: README build and run instructions. |
| IND-090 | A user guide shall be written. | Quality | The guide covers install, run and basic use. | Should | Not Started | IND-049 | Inspection | Confirmed. Original: "User guide". |

### Release
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-091 | Remaining bugs shall be fixed. | Quality | Every bug found in QA is fixed, or deferred with a written reason. | Must | Not Started | IND-087 | Inspection | Confirmed. Original: "Fix remaining bugs". |
| IND-092 | Performance shall be profiled. | Non-functional | A profiling report is compared against the budgets in IND-122. | Should | Not Started | IND-122 | Analysis | Confirmed. Original: "Performance profiling". |
| IND-093 | A release candidate shall be produced. | Functional | A tagged candidate build passes CI and manual testing. | Must | Not Started | IND-085, IND-087 | Demonstration | Confirmed. Original: "Release candidate". |

### Added
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-126 | Config, logger and `Application` shall have unit tests. | Quality | Tests cover `Configuration::load`, log levels and the `Application` lifecycle with fake `IPlatform`/`IUserInterface`. | Must | Not Started | IND-085 | Test | Inferred. These modules have no tests. |
| IND-127 | CI shall get a Catch2 v3 reliably. | Quality | CI fetches or pins Catch2 v3 independent of the runner image's apt package. | Should | Not Started | — | Inspection | Inferred. `build.yml` uses `apt install catch2`. `docs/setup.md` notes that Ubuntu 22.04 ships v2. |
| IND-128 | `docs/architecture.md` shall match the code. | Quality | Module names, dependency flow, and the `ui/screens` and `ui/widgets` layers match `src/`. | Should | Not Started | — | Inspection | Inferred. The doc lists a `pokemon` module, but the code uses `pokedex`. |
| IND-137 | Candidate embedded targets and the porting steps shall be documented. | Quality | `docs/embedded-targets.md` lists the candidate boards, audio options and the steps to add a backend, and is kept current. | Should | In Progress | IND-125 | Inspection | Confirmed: you asked to document it. Evidence: `docs/embedded-targets.md` was created 2026-10-31 (prices are unverified). |
| IND-130 | A QA test plan shall be written before manual testing starts. | Quality | The plan lists the scenarios to run (startup, navigation, search, filter, sort, favourites, shutdown, missing data) with expected results. | Must | Not Started | IND-049 | Inspection | Confirmed: you said QA is executed first, then bugs are identified (OQ-13). The scenario list is Inferred. |
| IND-129 | Screens and widgets shall be testable. | Quality | An approach (headless LVGL display or a fake) is chosen and at least `ScreenManager` and one widget are tested. | Should | Not Started | IND-043 | Test | Inferred. `tests/CMakeLists.txt` links no `ui` or `platform` target. |

---

# Milestone 9 - Indigo Plateau

## Objective
Release Version 1.0. *Release: v1.0.0.*

### Release
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-094 | Final bugs shall be fixed. | Quality | Every bug found since the release candidate is fixed, or deferred with a written reason. | Must | Not Started | IND-093 | Inspection | Confirmed. Original: "Final bug fixes". |
| IND-095 | Final screenshots shall be taken. | Quality | Screenshots of the main screens are stored in `docs/` or the README, taken with the placeholder assets (IND-139) so no Pokémon artwork is published. | Should | Not Started | IND-093, IND-139 | Inspection | Confirmed. Original: "Final screenshots". Adjusted 2026-10-31 for the public repository (IND-138). |
| IND-096 | A demo video shall be recorded. | Quality | A video covering the main flow, recorded with the placeholder assets (IND-139) if it is published. | Could | Not Started | IND-093, IND-139 | Inspection | Confirmed. Original: "Demo video". Adjusted 2026-10-31 for the public repository (IND-138). |
| IND-097 | A source-only GitHub Release shall be published. | Quality | A release exists with notes and source code only: no Pokémon artwork, audio or database is attached, and the README disclaimer from IND-121 is present. | Must | Not Started | IND-093, IND-121 | Inspection | Confirmed. Original: "GitHub Release". Narrowed to source-only 2026-10-31 because of the Pokémon IP concern (OQ-14). |
| IND-098 | The v1.0.0 tag shall be created. | Quality | Tag `v1.0.0` exists and `CHANGELOG.md` has a 1.0.0 entry. | Must | Not Started | IND-097 | Inspection | Confirmed. Original: "Version 1.0 tag". |

### Portfolio
| ID | Requirement | Category | Acceptance criteria | Priority | Status | Depends on | Verification | Notes / Source |
|----|-------------|----------|---------------------|----------|--------|------------|--------------|----------------|
| IND-099 | The README shall be polished. | Quality | README covers purpose, features, build, run and screenshots. | Should | Not Started | IND-089, IND-095 | Inspection | Confirmed. Original: "Polish README". |
| IND-100 | Architecture diagrams shall be included. | Quality | At least one module/dependency diagram is in the docs. | Should | Not Started | IND-088 | Inspection | Confirmed. Original: "Architecture diagrams". |
| IND-101 | Showcase GIFs shall be created. | Quality | GIFs of key interactions, recorded with the placeholder assets (IND-139), are embedded in the README. | Could | Not Started | IND-093, IND-139 | Inspection | Confirmed. Original: "Showcase GIFs". Adjusted 2026-10-31 for the public repository (IND-138). |
| IND-102 | Lessons learned shall be written. | Quality | A short document or README section summarises lessons learned. | Could | Not Started | — | Inspection | Confirmed. Original: "Lessons learned". |

---

# Decisions and open questions

## Decisions
*Source: your answers on 2026-10-31. "Delegated" means you asked me to decide; revisit any of them.*

| # | Decision | Source | Applied to |
|---|----------|--------|------------|
| OQ-1 | The UI reads only from the local database. PokéAPI is used by a separate import/sync step, run explicitly (not on every UI action). Runtime fetching of a missing Pokémon can be added later behind the same repository interface. Why: predictable speed, works with no network, and the embedded device then needs no network code in the UI path. | Delegated | IND-068, IND-072, IND-073 |
| OQ-2 | v1.0 covers Generations I to III (Pokédex #1 to #386). Other generations are added later without schema changes. | You | IND-068, IND-071 |
| OQ-3 | "Theme" and "Themes" are one feature, delivered in UX (Milestone 7). `IND-046` is retired as Not Applicable. | You | IND-046, IND-079 |
| OQ-6 | Filters: type (including dual-type), generation (I to III) and favourites. Ability filter is Could. Sorting: number and name. | Delegated ("whatever is possible") | IND-058, IND-059 |
| OQ-7 | Transitions and animations are nice-to-have, not needed now. Duration is a named constant, tuned later. | You | IND-062, IND-081 |
| OQ-8 | The static `Log` facade is an accepted exception to "no global state". It is set up once in `main()` and everything else is injected. Document it in `docs/architecture.md`. | Delegated | IND-021 |
| OQ-9 | SQLite for the content database. On a device it is opened read-only, and the importer runs on a desktop. User data (favourites, settings) lives in a separate small store so a re-import never wipes it. Revisit if the target becomes a bare-metal microcontroller. | Delegated | IND-071, IND-072 |
| OQ-10 | The project is personal and not a public product, so IND-121 is lowered to Could. Downloaded artwork and audio are generated by the importer and kept out of git. | You | IND-121 |
| OQ-11 | Budgets are proposed, not measured (see IND-122). Confirm after the first profiling run and once the device is chosen. | Delegated | IND-122 |
| OQ-12 | Coverage is set by risk: at least 80% line coverage on non-UI code (`common`, `pokedex`, `application`), measured in CI. UI code is covered by screen and navigation tests, with no percentage target. | Delegated | IND-085 |
| OQ-13 | QA comes first. A test plan is written and run (IND-130), then every bug found is either fixed or explicitly deferred with a reason. There is no severity cut-off. | You | IND-091, IND-094, IND-130 |
| OQ-4 | User data (favourites, settings) is stored in a separate small file whose path comes from configuration, so it works on a device with or without Linux. | You | IND-115, IND-135 |
| OQ-5 (part) | Desktop for now, designed stand-alone. Audio is optional. The device has a touch screen and a power button only. Layout is landscape, 800×480 primary and 480×320 as the small size. The embedded OS image will use Yocto, set up once a device exists. The code stays backend-agnostic, so adding a device means a new backend and configuration only. Candidate boards are in `docs/embedded-targets.md`. | You (landscape and sizes: delegated) | IND-133 to IND-137, IND-140, IND-141 |
| OQ-14 | The repository is public because the Cubic AI reviewer needs it, so no Pokémon artwork, audio or databases are committed or released. Milestone 9 releases are source-only, and published screenshots, video and GIFs use placeholder assets. | You (adjustments by me) | IND-095 to IND-097, IND-101, IND-121, IND-138, IND-139 |
| OQ-15 | A source-only release plus a fan-project disclaimer is acceptable. This is not legal advice. | You | IND-097, IND-121 |

## Open questions

| # | Question | Affects | Why it matters |
|---|----------|---------|----------------|
| OQ-5 | Which board and exact panel (size, resolution, touch controller) will you buy? Decide when you buy; the shortlist is in `docs/embedded-targets.md`. | IND-104, IND-125, IND-131, IND-132 | Fixes the first real backend. |

---

# Journey Progress

Counts are Completed / applicable requirements (Not Applicable items excluded). A milestone is ticked only when all its requirements are Completed.

- [x] 🌱 Pallet Town (no gym) — 14 / 14
- [x] 🪨 Pewter City, Boulder Badge — 13 / 13
- [x] 💧 Cerulean City, Cascade Badge — 10 / 10
- [ ] ⚡ Vermilion City, Thunder Badge — 6 / 17
- [ ] 🌈 Celadon City, Rainbow Badge — 0 / 15
- [ ] ☠️ Fuchsia City, Soul Badge — 0 / 11
- [ ] 🔮 Saffron City, Marsh Badge — 1 / 15
- [ ] 🔥 Cinnabar Island, Volcano Badge — 0 / 20
- [ ] 🌿 Viridian City, Earth Badge — 0 / 15
- [ ] 🏆 Indigo Plateau (no gym) — 0 / 9

# Change history

| Date | Change |
|------|--------|
| 2026-10-31 | Added `IND-NNN` IDs, tables, acceptance criteria and badges; evidence-based status updates in Milestone 3; added IND-103 to IND-129 (Inferred); added Open questions. Original roadmap wording preserved in Notes. |
| 2026-10-31 | Answered OQ-1 to OQ-13 (see Decisions). Retired IND-046 into IND-079. Refined IND-058, IND-062, IND-068, IND-071, IND-073, IND-085, IND-087, IND-091, IND-094, IND-121, IND-122, IND-125. Added IND-130 to IND-132. Added OQ-14. |
| 2026-10-31 | Applied answers on OQ-4, OQ-5 (part) and OQ-14. Added IND-133 to IND-139. Raised IND-121 to Should. Narrowed IND-095 to IND-097 and IND-101 for the public repository. Added OQ-15. |
| 2026-10-31 | Applied answers on OQ-5 (part) and OQ-15. Added IND-140 (touch-only) and IND-141 (on-screen keyboard). Lowered IND-103 to Could. Recorded landscape layout and Yocto preference. |
