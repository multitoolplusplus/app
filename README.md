# multitool++i

## Cross-platform multitool written in C++

[![Update Copyright Year in README.md](https://github.com/benja2998/multitoolplusplus/actions/workflows/copyright.yml/badge.svg)](https://github.com/benja2998/multitoolplusplus/actions/workflows/copyright.yml)

[![Coverage Status](https://coveralls.io/repos/github/multitoolplusplus/multitoolplusplus/badge.svg?branch=main)](https://coveralls.io/github/multitoolplusplus/multitoolplusplus?branch=main)

## Table of Contents
<details
<summary>Installation</summary>
<ul>
    <li><a href="#system-requirements">System Requirements</a></li>
    <li><a href="#prerequisites">Prerequisites</a></li>
    <li><a href="#building-multitool">Building multitool++</a></li>
</ul>
</details>

<details>
<summary>Usage</summary>
<ul>
    <li><a href="#features">Features</a></li>
    <li><a href="#faq">FAQ</a></li>
</ul>
</details>

---

## Installation

### System requirements

- If you're using Windows, it must not be older than Windows 10. This is because older Windows systems don't preinstall curl. You may be able to get the software working if you install curl manually on an older Windows system.

### Prerequisites

- CMake version over 3.10
- Linux or Windows system
- Curl installed (check output of curl command in your terminal, most Operating Systems including Windows versions above 10 will have it preinstalled. If you don't have curl, you can try finding a way to install it.)
- If you're using Windows, you need to use the Visual Studio installer to install "Desktop development with C++".
- If you're using Linux, you need to install GCC which will give you G++.

### Installing dependencies

#### Windows

Install [Visual Studio](https://visualstudio.microsoft.com/downloads/) (not the code version).

In the installer for it, make sure you install "Desktop development with C++".

Then, run the following command in your terminal:
```cmd
curl --version
```
If you get an error, run the following command:
```cmd
winget install cURL.cURL
```
Then, run the following command in your terminal:
```cmd
cmake --version
```
If you get an error, visit [this page](https://cmake.org/download/) to download CMake.

#### Linux

Using your distro's package manager, install CMake and install GCC to get G++.

- **Debian-based**

```bash
sudo apt install build-essential gcc cmake
```

- **Arch-based**

```bash
sudo pacman -S gcc cmake
```

- **Red Hat-based**

```bash
sudo dnf install gcc gcc-c++ cmake
```

- **OpenSUSE**

```bash
sudo zypper install gcc gcc-c++ cmake
```

#### macOS

macOS support is unplanned.

### Building multitool++

First, get the [archive](https://github.com/multitoolplusplus/multitoolplusplus/archive/refs/tags/v1.0.0.zip).

We generously provide a build.sh and a build.bat to build the software for you.

After you run the proper build script for your Operating System, the executable will be in the build directory.

### Building a multitool++ release older than v0.5.0

Multitool++ releases older than v0.5.0 do not use CMake. For these, you should use G++ or paste the following CMakeLists.txt:

**For v0.3.0 and newer**

```cmake
cmake_minimum_required(VERSION 3.10)

project(multitool++ VERSION 0.5.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include ./src/*.cpp
file(GLOB_RECURSE SOURCES "src/*.cpp")

# add include directories
include_directories("src")

# define executable
add_executable(multitool++ ${SOURCES})
```

For v0.2.0 and older, use G++.

## Usage

### Features
- [x] Exit
- [x] Timer
- [x] Send message to Discord webhook
- [x] Send message to Telegram bot
- [ ] Send message to Slack bot (see [issue #45](https://github.com/benja2998/multitoolplusplus/issues/45))

### FAQ

**Q**: Why is the software called "multitool++"?

**A**: This is because the software is written in C++.

---
© 2025 multitool++ contributors. Multitool++ is free software licensed under the [GNU GPL v3.0](./LICENSE).
