# Embedded Targets

Notes for running Project Indigo on an embedded device. The project is desktop-only today (SDL2). This document records the plan so a device can be added later with minimal changes (`IND-125`, `IND-131` to `IND-137` in [milestones.md](milestones.md)).

> **Prices and specs below are approximate and unverified.** They come from general knowledge, and a web search did not return current vendor prices. Check the vendor page before buying.

## Terms

| Term | Meaning |
|------|---------|
| Bare-metal | No operating system. The program is the firmware, on a microcontroller (e.g. ESP32-S3, STM32). Boots in milliseconds. Not planned for this project. |
| Embedded Linux, boot-to-app | A minimal Linux image (Buildroot or Yocto) that starts the app as the only program. Boots in a few seconds. This is the planned target. |
| DRM/KMS | Linux's display interface. LVGL draws to it directly, so no desktop or Wayland compositor is needed. |
| evdev | Linux's input interface for touch, keyboard and buttons. |

## Display and input

- **Orientation:** landscape only. Lists and detail pages use the width well, and 800×480 matches the desktop simulator and many low-cost 5 and 7 inch panels. 480×320 is the supported small size. Layouts must adapt to the size (`IND-134`).
- **Input:** touch screen and a power button only. There is no physical keyboard, so text entry uses an on-screen keyboard (`IND-140`, `IND-141`).

## Build system: Yocto

The OS image will be built with Yocto once a device is chosen. Until then the app stays stand-alone and builds with CMake only. The Yocto recipe will build the CMake project, so these must hold:

- SDL2 is optional (`IND-125`), because the device uses DRM/KMS.
- Tests are not built for the target (`BUILD_TESTING` can be turned off).
- Dependencies available as Yocto recipes: `fmt`, `nlohmann-json`, SQLite and LVGL (vendored as a submodule).

Yocto support differs by board. The Raspberry Pi has an official-style layer (`meta-raspberrypi`). Cheaper boards often ship a Buildroot-based vendor SDK, with Yocto support that is community-made or missing, so check this before buying.

## Why embedded Linux and not bare-metal

The app uses C++17 and the standard library, SQLite, JSON configuration and HTTP downloads, with artwork and audio for 386 Pokémon. That runs almost unchanged on embedded Linux. A microcontroller would need a different build and storage design.

LVGL 9.5 (`external/lvgl/src/drivers/`) includes `drm`, `fb`, `evdev` and `wayland` drivers. They are all disabled in `config/lv_conf.h` (`LV_USE_LINUX_DRM`, `LV_USE_LINUX_FBDEV`, `LV_USE_EVDEV`, `LV_USE_WAYLAND` are 0). Wayland is the alternative if a compositor is ever needed.

## Candidate boards (shortlist)

| Board | Why it is on the list | Watch out for |
|-------|----------------------|---------------|
| Raspberry Pi Zero 2 W | Best documented, with mainline DRM/KMS and Buildroot support. Quad-core Cortex-A53, 512 MB RAM, built-in Wi-Fi for the sync step. Roughly US$15 for the board alone (a retail kit listing was about US$31). | No audio jack and no DSI display port. Use HDMI or an SPI display, and an I2S amplifier or USB sound for audio. Stock may be limited. |
| Luckfox Pico family (Rockchip RV1103/RV1106) | Very cheap (roughly US$10 to US$20) with a Buildroot SDK. Boots fast. | Single Cortex-A7 with 64 to 256 MB RAM, so memory budgets in `IND-122` matter. Display and DRM support depend on the vendor kernel. Not verified here. |
| Orange Pi Zero 2W | More RAM options, Wi-Fi, roughly US$20 to US$30. | Display support depends on a vendor kernel. Less documentation than the Pi. |

My suggested first target is the **Raspberry Pi Zero 2 W** with a small HDMI display. It has the lowest porting risk, and the code stays portable to the others. I can't pick a final board without your screen size and budget (OQ-5).

## Display connection on the Raspberry Pi Zero 2 W

> Port details are from general knowledge and the mini-HDMI port was confirmed by the project owner. Check the vendor page before buying.

The board has no screen, so a separate display is needed. It has **no MIPI DSI display connector**. Its CSI connector is for cameras only.

| Port | Use |
|------|-----|
| Mini-HDMI | Video output. Needs a mini-HDMI to HDMI cable or adapter. |
| 40-pin GPIO header (may be unpopulated) | SPI or parallel DPI displays. |
| Two micro-USB ports (power, and data/OTG) | The data port is the only one for peripherals, so a micro-USB OTG adapter or a small hub is needed for USB touch. |

| Option | Fit | Notes |
|--------|-----|-------|
| HDMI display, 5 to 7 inch, 800×480 | **Recommended first target** | Standard DRM/KMS path (`IND-125`). Matches the primary size (`IND-134`). Touch is usually USB HID, which Linux exposes as evdev. Check that the touch is USB HID and not a vendor protocol. HDMI audio is a free option (`IND-136`). |
| SPI display, about 3.5 inch, 480×320 | Not for a first target | Slow for LVGL; the 30 FPS goal (`IND-122`) is at risk; Yocto driver support varies. |
| DPI (parallel RGB on GPIO) | Advanced | Fast, but uses most pins and needs a device-tree overlay. |

## Boards ruled out

| Board | Reason |
|-------|--------|
| ESP32-S3 boards (e.g. the JC4827W543 module) | A microcontroller with no MMU. Mainline Linux and Yocto do not support it, so it is the bare-metal case that this project does not plan for. The app needs the C++ standard library, SQLite and a 64 MB budget (`IND-122`); the ESP32-S3 has about 512 KB internal RAM plus optional PSRAM. The module's 4.3 inch panel is, from memory, 480×272, which is outside the supported sizes. Treat it as a separate project. |

## Audio (optional)

Audio is nice to have (`IND-078`, `IND-136`). The app must run silently on a device with no audio output.

| Option | Notes |
|--------|-------|
| I2S amplifier (e.g. MAX98357A) with a small speaker | Typically a few US dollars. Needs a device-tree overlay on Linux. |
| USB sound adapter or USB speaker | Works with no hardware changes. Slightly larger. |
| HDMI audio | Free if the display has speakers. Quality varies. |

## Keeping the code device-agnostic

These rules are tracked as requirements so that adding a device needs a new backend and configuration only.

1. Only `src/platform/` may depend on a display or input backend (`IND-133`).
2. The display size comes from configuration, and layouts adapt to it (`IND-104`, `IND-134`).
3. Database, user-data and asset paths come from configuration, and the root file system may be read-only (`IND-135`).
4. Audio sits behind an interface with a no-op implementation (`IND-136`).
5. The build can select the backend at configure time and cross-compile with a toolchain file (`IND-125`, `IND-132`).

## Steps to add a device (planned)

1. Add a platform class implementing `IPlatform` for the new backend (e.g. `DRMPlatform`).
2. Enable the matching driver in `config/lv_conf.h` (e.g. `LV_USE_LINUX_DRM`, `LV_USE_EVDEV`).
3. Select the backend in CMake and add a toolchain file for the target.
4. Build the image with Buildroot or Yocto and start the app at boot (`IND-131`).
5. Provide the database and assets, and set the paths in `config.json`.
6. Measure against the budgets in `IND-122`.

## Not decided

- Final board, screen size and resolution, and input type (OQ-5).
- Audio hardware.
- Exact panel and touch controller.
