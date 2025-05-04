#include <iostream>
#include <string>
#include <cstdlib>

static void banner()
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

static void menu()
{
    std::cout << "-- OPTIONS: --\n";
    std::cout << "1. exit\n";
    std::cout << "--          --\n";
}

static void read()
{
    std::string input;
    std::cout << "enter an option: ";
    std::getline(std::cin, input);
    std::cout << "You chose: " << input << "\n";
    std::cout << "Validating choice... ";
    if (input == "1")
    {
        std::cout << "Valid choice!\n";
        exit(0);
    }
    else 
    {
        std::cout << "Invalid choice.\n";
        exit(1);
    }
}

int main()
{
    std::cout << "Hello from Multitool++!\n";
    std::cout << "C++ is a great language!\n";

    banner();
    menu();
    read();
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
}
