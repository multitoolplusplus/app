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

## FAQ

**Q**: It's detected as malware by Antivirus!  

**A**: Antivirus engines will probably flag new and/or unsigned files.

**Q**: Will there be a native macOS binary?  

**A**: Too complicated to implement.

---
© 2025 multitool++ contributors. Licensed under the [GNU GPL v3.0](./LICENSE).
