#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>

/* DOCUMENTATION
    * exit(0) - EXIT SUCCESS
    * exit(1) - EXIT FAILURE
    * std::cout << string; - CHARACTER OUTPUT
    * std::getline(...) - READ LINE FROM USER
    * std::stoi(string) - CONVERT STRING TO INTEGER
    * system(...) - RUN A SYSTEM COMMAND
    * console::clear() - CLEAR THE CONSOLE
    * If you're reading this section, you may want to make a pull request to expand it
*/

namespace console {
    void clear() {
#ifdef _WIN32
        system("cls");
#elif defined(__linux__) || defined(__APPLE__) || defined(__unix__)
        system("clear");
#else
        exit(10);
#endif
    }
}

void initialize();

void banner()
{
    const char* banner = R"(
                  .__   __  .__  __                .__                           
  _____  __ __|  |_/  |_|__|/  |_  ____   ____ |  |      .__         .__     
 /     \|  |  \  |\   __\  \   __\/  _ \ /  _ \|  |    __|  |___   __|  |___ 
|  Y Y  \  |  /  |_|  | |  ||  | (  <_> |  <_> )  |__ /__    __/  /__    __/ 
|__|_|  /____/|____/__| |__||__|  \____/ \____/|____/    |__|        |__|    
      \/                                                                     

)";
    std::cout << "\033[33m" << banner << "\033[0m\n";
}

void menu()
{
    std::cout << "\033[36m-- OPTIONS: --\033[0m\n";
    std::cout << "\033[32m1. exit\033[0m\n";
    std::cout << "\033[32m2. timer\033[0m\n";
    std::cout << "\033[36m--          --\033[0m\n";
}

void read()
{
    std::string input;
    std::cout << "\033[35mEnter an option: \033[0m";
    std::getline(std::cin, input);
    std::cout << "\033[33mYou chose: \033[0m" << input << "\n";
    std::cout << "Validating choice... ";
    if (input == "1")
    {
        std::cout << "\033[32mValid choice!\033[0m\n";
        exit(0);
    }
    else if (input == "2") 
    {
        std::cout << "\033[32mValid choice!\033[0m\n";
        std::cout << "\033[35mEnter a number of seconds: \033[0m";
        std::string seconds;
        std::getline(std::cin, seconds);
        int seconds_int = std::stoi(seconds);
        int timer = seconds_int;
        while (timer > 0)
        {
            std::cout << "\033[33m" << timer << "\033[0m\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            timer--;
        }
        initialize();
    }
    else 
    {
        std::cout << "\033[31mInvalid choice.\033[0m\n";
        exit(1);
    }
}

void initialize()
{
    console::clear();
    std::cout << "\033[34mHello from Multitool++!\033[0m\n";
    std::cout << "\033[34mC++ is a great language!\033[0m\n";
    banner();
    menu();
    read();
}

int main()
{
    initialize();
}
