#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#if defined(__linux__) || defined(__APPLE__) || defined(__unix__) || defined(__unix)
#define PLATFORM_POSIX
#else
#error "multitool++ supports POSIX systems only. Use Linux, macOS, BSD, or WSL."
#endif

#define APP_VERSION "1.6.0"

#endif
