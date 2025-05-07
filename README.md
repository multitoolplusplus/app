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

It's as simple as compiling all .cpp files. For example, if you are on Windows and using G++:

```sh
cd src # only if your downloaded source code has a src directory
```
```sh
g++ -o main.exe *.cpp
```

### Using the precompiled binaries
You can easily download and run a precompiled binary from the releases.

[![download for linux](https://img.shields.io/badge/🐧_LINUX_EXECUTABLE-green)](https://github.com/benja2998/multitoolplusplus/releases/latest/download/main-linux)
[![download for windows](https://img.shields.io/badge/🪟_WINDOWS_EXECUTABLE-blue)](https://github.com/benja2998/multitoolplusplus/releases/latest/download/main-windows.exe)

## Safety
You can know that the software is safe as the precompiled binaries are built with this [GitHub Action](./.github/workflows/build-and-upload.yml) and not tampered with.

Additionally, you can see the AnyRun text report:

[![anyrun report proving it isn't malware](https://img.shields.io/badge/🔎_ANYRUN_TEXT_REPORT-navy)](https://web.archive.org/web/20250507002358/https://any.run/report/e23035c942553c9861c1467f33ab87803a18c871991808b93a64a2b4ef51f685/0c54f169-24ed-42ec-b40b-f0f15bf6eeb6) <!-- the reason why we are using internet archive is because anyrun public reports are deleted after 2 weeks -->

## FAQ
**Q**: It's detected as malware by Antivirus!  

**A**: Antivirus engines will probably flag new and/or unsigned files.

**Q**: Will there be a native macOS binary?  

**A**: Too complicated to implement.

---
© 2025 multitool++ contributors. Licensed under the [GNU GPL v3.0](./LICENSE).
