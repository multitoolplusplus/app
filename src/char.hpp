#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#elif defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
#endif

#ifndef CHAR_HPP
#define CHAR_HPP
namespace char_utils {
    inline char get_char() {
#ifdef _WIN32
        return _getch();
#elif defined(__linux__)
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
#else
        return '\0';
#endif
    }
}
#endif