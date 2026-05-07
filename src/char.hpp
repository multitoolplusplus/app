#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#ifndef CHAR_HPP
#define CHAR_HPP
namespace char_utils {
  inline char get_char() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
  }
}
#endif
