# multitool++

## Cross-platform multitool written in C++

[![Build and Upload Binary](https://github.com/benja2998/multitoolplusplus/actions/workflows/build-and-upload.yml/badge.svg?event=release)](https://github.com/benja2998/multitoolplusplus/actions/workflows/build-and-upload.yml)
[![Update Copyright Year in README.md](https://github.com/benja2998/multitoolplusplus/actions/workflows/copyright.yml/badge.svg)](https://github.com/benja2998/multitoolplusplus/actions/workflows/copyright.yml)

[![Coverage Status](https://coveralls.io/repos/github/multitoolplusplus/multitoolplusplus/badge.svg?branch=main)](https://coveralls.io/github/multitoolplusplus/multitoolplusplus?branch=main)

## Table of Contents
<details>
<summary>Installation</summary>
<ul>
    <li><a href="#system-requirements">System Requirements</a></li>
    <li><a href="#prerequisites">Prerequisites</a></li>
    <li><a href="#using-a-compiler">Using a compiler</a></li>
    <li><a href="#using-the-precompiled-binaries">Using the precompiled binaries</a></li>
</ul>
</details>

<details>
<summary>Usage</summary>
<ul>
    <li><a href="#features">Features</a></li>
    <li><a href="#safety">Safety</a></li>
    <li><a href="#faq">FAQ</a></li>
</ul>
</details>

---

## Installation

### System requirements
- If you're using Windows, it must not be older than Windows 10. This is because older Windows systems don't preinstall curl. You may be able to get the software working if you install curl manually on an older Windows system.
- Any x86_64 CPU, the software is pretty lightweight.
- If your CPU is not x86_64, you may want to compile the software yourself for your architecture.

### Prerequisites
- C++ Compiler (if you won't use a precompiled binary)
- Linux or Windows system (you may be able to run the software on macOS via WINE)
- Curl installed (check output of curl command in your terminal, most Operating Systems including Windows versions above 10 will have it preinstalled. If you don't have curl, you can try finding a way to install it.)

### Using a compiler
You will first have to download the source code. We recommend using a GitHub release for stability.

[![see releases](https://img.shields.io/badge/📦_GITHUB_RELEASES-purple)](https://github.com/benja2998/multitoolplusplus/releases)

It's as simple as compiling all .cpp files. For example, if you are on Windows and using G++:

```sh
cd src # only if your downloaded source code has a src directory
```
```sh
g++ -o main.exe *.cpp
```

### Using the precompiled binaries
You can easily download and run a precompiled binary from the releases.

[![download for linux](https://img.shields.io/badge/🐧_LINUX_EXECUTABLE-green)](https://github.com/benja2998/multitoolplusplus/releases/latest/download/multitoolpp-linux)
[![download for windows](https://img.shields.io/badge/🪟_WINDOWS_EXECUTABLE-blue)](https://github.com/benja2998/multitoolplusplus/releases/latest/download/multitoolpp-windows.exe)

## Usage

### Features
- [x] Exit
- [x] Timer
- [x] Send message to Discord webhook
- [x] Send message to Telegram bot
- [ ] Send message to Slack bot (see [issue #45](https://github.com/benja2998/multitoolplusplus/issues/45))

### Safety
You can know that the software is safe as the precompiled binaries are built with this [GitHub Action](./.github/workflows/build-and-upload.yml) and not tampered with.

Additionally, you can see the analyses:

[![analyis proving it isn't malware](https://img.shields.io/badge/🔎_THREAT_INSIGHTS_PORTAL_ANALYSIS_(LINUX)-navy)](https://tip.neiki.dev/file/ed26c09a08964564c00627c4c73d3a4c0c0e905c5ac5e99dc2e71b03a775a6be)
[![analysis proving it isn't malware](https://img.shields.io/badge/🔎_THREAT_INSIGHTS_PORTAL_ANALYSIS_(WINDOWS)-navy)](https://tip.neiki.dev/file/ab49db1e1c5ba6a79b3b5534924a037b84b0ee8f2c721b2f48d57fe1197f2446)

### FAQ
**Q**: It's detected as malware by Antivirus!  

**A**: Antivirus engines will probably flag new and/or unsigned files.

**Q**: Will there be a native macOS binary?  

**A**: Too complicated to implement.

---
© 2025 multitool++ contributors. Multitool++ is free software licensed under the [GNU GPL v3.0](./LICENSE).
