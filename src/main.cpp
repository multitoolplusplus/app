#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>

/* DOCUMENTATION
    * exit(0) - EXIT SUCCESS
    * exit(1) - EXIT FAILURE
    * exit(10) - UNSUPPORTED OPERATING SYSTEM
    * std::cout << string; - CHARACTER OUTPUT
    * std::getline(...) - READ LINE FROM USER
    * std::stoi(string) - CONVERT STRING TO INTEGER
    * system(...) - RUN A SYSTEM COMMAND
    * console::clear() - CLEAR THE CONSOLE
    * discord::send_webhook(...) - SEND MESSAGE TO DISCORD WEBHOOK
    * If you're reading this section, you may want to make a pull request to expand it
*/

namespace console {
    void clear() {
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

namespace discord {
    void send_webhook(const std::string& webhook_url, const std::string& message) {
        std::string escaped_message;
        for (char c : message) {
            if (c == '"' || c == '\\' || c == '`' || c == '$') {
                escaped_message += '\\';
            }
            escaped_message += c;
        }

        std::string command = "curl -s -H \"Content-Type: application/json\" -X POST -d \"{\\\"content\\\": \\\"" + 
                             escaped_message + "\\\"}\" " + webhook_url;

        int result = system(command.c_str());
        
        if (result != 0) {
            std::cerr << "\033[31mFailed to send message (curl error)\033[0m" << std::endl;
        } else {
            std::cout << "\033[32mMessage sent successfully!\033[0m" << std::endl;
        }
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
    std::cout << "\033[32m3. send Discord message\033[0m\n";
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
    else if (input == "3")
    {
        std::cout << "\033[32mValid choice!\033[0m\n";
        std::cout << "\033[35mEnter Discord webhook URL: \033[0m";
        std::string webhook_url;
        std::getline(std::cin, webhook_url);
        
        std::cout << "\033[35mEnter message to send: \033[0m";
        std::string message;
        std::getline(std::cin, message);
        
        discord::send_webhook(webhook_url, message);
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
