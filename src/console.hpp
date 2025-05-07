#include <iostream>
#include <cstdlib>

#ifndef CONSOLE_HPP
#define CONSOLE_HPP
namespace console {
    inline void clear() {
#ifdef _WIN32
        system("cls");
#elif defined(__linux__) || defined(__APPLE__) || defined(__unix__)
        system("clear");
#else
        std::cout << "Unsupported OS. Please make sure you have modified the source code before compiling for another OS.";
        exit(10);
#endif
    }
}
#endif