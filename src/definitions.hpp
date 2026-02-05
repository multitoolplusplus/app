#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#if defined(__linux__) || defined(__APPLE__) || defined(__unix__) || defined(__unix)
#define PLATFORM_POSIX
#elif defined(_WIN32) || defined(_WIN64)
#define PLATFORM_WINDOWS
#endif

#define APP_VERSION "1.3.0"

#endif
