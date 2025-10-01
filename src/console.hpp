#ifndef CONSOLE_HPP
#define CONSOLE_HPP
#include <iostream>

namespace console {
    inline void clear() {
        // ANSI escape sequence to clear screen and reset cursor
        std::cout << "\x1B[2J\x1B[H" << std::flush;
    }
}

#endif
