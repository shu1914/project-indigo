# project-indigo

## Toolchain facts (from `CMakeLists.txt` and `external/lvgl`)
- C++17 is required (`CMAKE_CXX_STANDARD 17`, `CMAKE_CXX_STANDARD_REQUIRED ON`). Do not use C++20 features such as `std::span`.
- C is configured as C11.
- LVGL 9.5, vendored as the git submodule `external/lvgl`, configured by `config/lv_conf.h`.
- Tests live in `tests/` and are built when `BUILD_TESTING` is ON.

## Code review and code changes
When reviewing code (`/code-review`, `/simplify`) or writing code, check it against the Keystone skills:

- C++ in `src/` and `tests/`: apply the `cpp17-development` skill.
- UI code in `src/ui/` and anything calling `lv_*`: apply the `lvgl-development` skill. Verify every LVGL API against the headers in `external/lvgl` (version 9.5) rather than assuming it exists.
- C code: apply the `c-development` skill.
- Everything else: apply the `coding-standards` skill, and follow the conventions already used in the surrounding code.

Do not modify `external/lvgl`.
