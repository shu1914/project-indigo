# Setup

Install the required development packages:

```bash
# To use <fmt/format.h>
sudo apt install libfmt-dev

# To use <nlohmann/json.hpp>
sudo apt install nlohmann-json3-dev
```

## Catch2

This project requires **Catch2 v3**. On Ubuntu 22.04 LTS, `sudo apt install catch2` installs Catch2 **v2.13.8**, which is not compatible with the project's `find_package(Catch2 3 REQUIRED)` requirement.

If your distribution packages Catch2 v3, you can install it with your package manager. Otherwise, install Catch2 v3 from source or another package source before configuring the project.

## LVGL Backends

This project currently requires SDL2 to build. LVGL backend features are configured via the project's `lv_conf.h` file, but disabling the SDL backend there does not remove the SDL2 build dependency.

### SDL2

SDL is usually used for simulating LVGL in your development setup. This requires the package to be installed via `sudo apt install libsdl2-dev`.

### Wayland

_Under construction_
Wayland not yet supported. Will add in later.