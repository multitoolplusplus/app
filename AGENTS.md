# AGENTS.md

Guidance for coding agents working in this repository.

## Project Overview

`multitool++` is a POSIX-only C++17 terminal utility built with CMake. The executable provides a keyboard-driven menu for:

- Exiting the app.
- Running a timer.
- Sending Discord webhook messages with libcurl.
- Sending Telegram bot messages with libcurl.
- Generating a secure password.
- Opening a small calculator shell.

The app uses ANSI escape sequences and an alternate terminal screen for its UI.

## Repository Layout

- `CMakeLists.txt`: CMake project definition, C++17 requirement, libcurl lookup/linking, release flags.
- `build.sh`: POSIX build helper. Creates `build/`, configures CMake, and builds.
- `src/main.cpp`: Main menu loop, banner, and option handlers.
- `src/discord.hpp`: Discord webhook helper and JSON escaping.
- `src/telegram.hpp`: Telegram sendMessage helper.
- `src/calculator_shell.hpp`: Recursive calculator command shell.
- `src/console.hpp`: Screen clear and alternate-screen helpers.
- `src/char.hpp`: POSIX single-character input helper.
- `src/ansi.hpp`: ANSI style/color constants.
- `src/definitions.hpp`: POSIX platform guard and `APP_VERSION`.
- `assets/`: README screenshots.

## Build Commands

Preferred POSIX build:

```sh
sh build.sh
```

Equivalent manual build:

```sh
cmake -S . -B build
cmake --build build
```

The executable is written to `build/multitool++`.

## Dependencies

- CMake 3.10 or newer.
- A C++17 compiler.
- libcurl development files discoverable by CMake.
- bc.

Native Windows builds are not supported. Use Linux, macOS, BSD, or WSL.

## Testing And Verification

There are currently no checked-in automated tests. `enable_testing()` is present in CMake, but no tests are registered.

For changes, at minimum run:

```sh
sh build.sh
```

For UI or input-flow changes, manually run `build/multitool++` in an interactive terminal. The program switches to the terminal alternate screen, uses `W`/`S` for navigation, and `E` to select.

## Coding Notes

- Keep the project C++17-compatible.
- Most helpers are inline functions in headers; adding new `.cpp` files is supported by `file(GLOB_RECURSE SOURCES "src/*.cpp")`, but prefer matching the existing style for small helpers.
- Keep the project POSIX-only. Do not add native Windows branches unless project policy changes.
- If adding menu items, update `check_Vector`, navigation bounds, display text, and the `switch` cases together.
- When sending JSON payloads, avoid hand-built strings unless values are escaped. `discord::escape_json` exists for Discord payload content; Telegram currently builds its JSON directly.
- Avoid logging secrets such as webhook URLs, bot tokens, or chat IDs.
- The calculator shell and main menu use recursive calls for control flow. Be careful not to introduce unbounded recursion in new loops.

## Generated Files

Do not commit local build outputs from `build/` unless the project policy changes.
