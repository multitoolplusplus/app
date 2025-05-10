#include <cstdlib>

#ifndef CONSOLE_HPP
#define CONSOLE_HPP
namespace console {
    inline void clear() {
#ifdef _WIN32
        system("cls");
#elif defined(__linux__)
        system("clear");
#else
        #include <iostream>
        std::cout << "Unsupported OS. Please make sure you have modified the source code before compiling for another OS.\n";
        exit(10);
#endif
    }
}
#endif