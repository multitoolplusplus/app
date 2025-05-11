# multitool++

## Cross-platform multitool written in C++

[![Security Policy](https://img.shields.io/badge/SECURITY_POLICY-navy?style=for-the-badge)](./SECURITY.md)

## Table of Contents
<details>
<summary>Installation</summary>

<ul>
<li><a href="#system-requirements">System requirements</a></li>
<li><a href="#prerequisites">Prerequisites</a></li>
<li><a href="#installing-dependencies">Installing dependencies</a></li>
<li><a href="#building-multitool">Building multitool++</a></li>
<li><a href="#building-a-multitool-release-older-than-v050">Building a multitool++ release older than v0.5.0</a></li>

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

You should then install [Git](https://git-scm.com/downloads/win).

#### Linux

Using your distro's package manager, install CMake, GCC, Git and curl.

- **Debian-based**

```bash
sudo apt install build-essential gcc cmake curl git
```

- **Arch-based**

```bash
sudo pacman -S gcc cmake curl git
```

- **Red Hat-based**

```bash
sudo dnf install gcc gcc-c++ cmake curl git
```

- **OpenSUSE**

```bash
sudo zypper install gcc gcc-c++ cmake curl git
```

#### macOS

macOS support is unplanned.

### Building multitool++

[![tarball](https://img.shields.io/badge/tarball-v1.0.0-green?style=for-the-badge)](https://codeberg.org/multitoolplusplus/app/archive/v1.0.0.tar.gz)
[![zipball](https://img.shields.io/badge/zipball-v1.0.0-blue?style=for-the-badge)](https://codeberg.org/multitoolplusplus/app/archive/v1.0.0.zip)

We generously provide a build.sh and a build.bat to build the software for you.

After you run the proper build script for your Operating System, the executable will be in the build directory.

You may also build it manually:

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

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
- [ ] Send message to Slack bot (see [issue #45](https://codeberg.org/multitoolplusplus/app/issues/45))
- [x] Generate secure password
- [x] Calculator shell (not in v1.0.0)

### FAQ

**Q**: Why is the software called "multitool++"?

**A**: This is because the software is written in C++.

---
© 2025 multitool++ contributors. Multitool++ is free software licensed under the [GNU GPL v3.0](./LICENSE).
