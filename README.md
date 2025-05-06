# multitool++

## Cross-platform multitool written in C++

[![Build and Upload Binary](https://github.com/benja2998/multitoolplusplus/actions/workflows/build-and-upload.yml/badge.svg)](https://github.com/benja2998/multitoolplusplus/actions/workflows/build-and-upload.yml)
[![Coverage Status](https://coveralls.io/repos/github/benja2998/multitoolplusplus/badge.svg?branch=main)](https://coveralls.io/github/benja2998/multitoolplusplus?branch=main)

## Installation

### Prerequisites
- C++ Compiler (if you won't use a precompiled binary)
- Linux or Windows system (you may be able to run the software on macOS via WINE)
- Curl installed (check output of curl command in your terminal, most Operating Systems including Windows versions above 10 will have it preinstalled. If you don't have curl, you can try finding a way to install it.)

### Using a compiler
You will first have to download the source code. We recommend using a GitHub release for stability.

[![see releases](https://img.shields.io/badge/📦_GITHUB_RELEASES-purple)](https://github.com/benja2998/multitoolplusplus/releases)

It's as simple as compiling `main.cpp`. For example, if you are on Windows and using G++:

```sh
g++ -o main.exe main.cpp
```

### Using the precompiled binaries
You can easily download and run a precompiled binary from the releases.

[![download for linux](https://img.shields.io/badge/🐧_LINUX_EXECUTABLE-green)](https://github.com/benja2998/multitoolplusplus/releases/latest/download/main-linux)
[![download for windows](https://img.shields.io/badge/🪟_WINDOWS_EXECUTABLE-blue)](https://github.com/benja2998/multitoolplusplus/releases/latest/download/main-windows.exe)

## IMPORTANT ANNOUNCEMENT

![virustotal scan screenshot](./assets/virustotal_scan.png)

As of this being wrote, our Windows binary is currently detected by multiple antivirus engines on VirusTotal. If you have the time, please report this as a false positive! The program is **NOT** malware. 

[![anyrun report proving it isn't malware](https://img.shields.io/badge/🔎_ANYRUN_TEXT_REPORT-navy)](https://web.archive.org/web/20250506213922/https://any.run/report/fba2ef4dfa49dd03f385f026ad7d4206d7ea510729c2c21d58a5bb60361633a9/84487d1c-696c-49e0-aeb0-3f03b69a13b6) <!-- the reason why we are using internet archive is because anyrun public reports are deleted after 2 weeks -->

## FAQ

**Q**: It's detected as malware by Antivirus!  

**A**: Antivirus engines will probably flag files that barely do anything.

**Q**: Will there be a native macOS binary?  

**A**: Too complicated to implement.

---
© 2025 multitool++ contributors. Licensed under the [GNU GPL v3.0](./LICENSE).
