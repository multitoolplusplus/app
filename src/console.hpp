#ifndef CONSOLE_HPP
#define CONSOLE_HPP
#include <iostream>

namespace console {
  inline void clear() {
    // ANSI escape sequence to clear screen and reset cursor
    std::cout << "\x1B[2J\x1B[H" << std::flush;
  }
  inline void enter_alt() { std::cout << "\033[?1049h\033[2J\033[H"; }
  inline void leave_alt() { std::cout << "\033[?1049l"; }
}

#endif
