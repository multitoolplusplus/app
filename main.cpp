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
        exit(10)
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
    std::cout << banner << "\n";
}

void menu()
{
    std::cout << "-- OPTIONS: --\n";
    std::cout << "1. exit\n";
    std::cout << "2. timer\n";
    std::cout << "--          --\n";
}

void read()
{
    std::string input;
    std::cout << "Enter an option: ";
    std::getline(std::cin, input);
    std::cout << "You chose: " << input << "\n";
    std::cout << "Validating choice... ";
    if (input == "1")
    {
        std::cout << "Valid choice!\n";
        exit(0);
    }
    else if (input == "2") 
    {
        std::cout << "Valid choice!\n";
        std::cout << "Enter a number of seconds: ";
        std::string seconds;
        std::getline(std::cin, seconds);
        int seconds_int = std::stoi(seconds);
        int timer = seconds_int;
        while (timer > 0)
        {
            std::cout << timer << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            timer--;
        }
        initialize();
    }
    else 
    {
        std::cout << "Invalid choice.\n";
        exit(1);
    }
}

void initialize()
{
    console::clear();
    std::cout << "Hello from Multitool++!\n";
    std::cout << "C++ is a great language!\n";

    banner();
    menu();
    read();
}

int main()
{
    initialize();
}
