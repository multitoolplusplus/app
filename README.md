# multitool++

## Cross-platform multitool written in C++

## Installation

### Prerequisites
- C++ Compiler (if you won't use a precompiled binary)
- Linux or Windows system (you may be able to run the software on macOS via WINE)

### Using a compiler
You will first have to download the source code. We recommend using a GitHub release for stability.

[![see releases](https://img.shields.io/badge/See%20releases-8A2BE2)](https://github.com/benja2998/multitoolplusplus/releases)

It's as simple as compiling `main.cpp`. For example, if you are on Windows and using G++:

```sh
g++ -o main.exe main.cpp
```

### Using the precompiled binaries
You can easily download and run a precompiled binary from the releases.

[![download for linux](https://img.shields.io/badge/Linux-Download_precompiled_binary-green)](https://github.com/benja2998/multitoolplusplus/releases/latest/download/main-linux)
[![download for windows](https://img.shields.io/badge/Windows-Download_precompiled_binary-blue)](https://github.com/benja2998/multitoolplusplus/releases/latest/download/main-windows.exe)

## IMPORTANT ANNOUNCEMENT

![virustotal scan screenshot](./assets/virustotal_scan.png)

As of this being wrote, our Windows binary is currently detected by multiple antivirus engines on VirusTotal. If you have the time, please report this as a false positive! The program is **NOT** malware. 

[![anyrun report proving it isn't malware](https://img.shields.io/badge/AnyRun-Report-navy)](https://web.archive.org/web/20250505193713/https://any.run/report/bfeb2d8a414bfedc9124072c483acee0a62a9c4f28174ef483b97fba27165b2f/248a5c03-3969-4b37-833a-00c973f34281)

## FAQ

**Q**: It's detected as malware by Antivirus!  
**A**: Antivirus engines will probably flag files that barely do anything.

**Q**: Will there be a native macOS binary?  
**A**: Too complicated to implement.

---
© 2025 multitool++ contributors. Licensed under the [GNU GPL v3.0](./LICENSE).
