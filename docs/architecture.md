# Project Architecture

## Design Principles
- `main()` is the composition root.
- Dependencies are injected through constructors.
- Avoid global state and singletons.
- Introduce interfaces only when multiple implementations are required.
- Introduce factories and facades only when they simplify complexity.

## Module Overview

### application
Responsible for the application lifecycle and orchestration.

### platform
Platform-specific code (LVGL, SDL, Wayland, etc.).

### pokemon
Pokémon domain logic, models, repositories, and services.

### ui
User interface, views, widgets, and presentation logic.

### common
Shared utilities used across modules.

## Dependency Flow

main()
    ↓
Application
    ↓
UI
    ↓
Pokemon