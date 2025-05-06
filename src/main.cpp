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

namespace ansi {
    const std::string RESET     = "\033[0m";
    const std::string BOLD      = "\033[1m";
    const std::string DIM       = "\033[2m";
    const std::string ITALIC    = "\033[3m";
    const std::string UNDERLINE = "\033[4m";
    const std::string BLINK     = "\033[5m";
    const std::string REVERSE   = "\033[7m";
    const std::string HIDDEN    = "\033[8m";
    const std::string STRIKE    = "\033[9m";

    const std::string BLACK   = "\033[30m";
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string BLUE    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN    = "\033[36m";
    const std::string WHITE   = "\033[37m";

    const std::string BRIGHT_BLACK   = "\033[90m";
    const std::string BRIGHT_RED     = "\033[91m";
    const std::string BRIGHT_GREEN   = "\033[92m";
    const std::string BRIGHT_YELLOW  = "\033[93m";
    const std::string BRIGHT_BLUE    = "\033[94m";
    const std::string BRIGHT_MAGENTA = "\033[95m";
    const std::string BRIGHT_CYAN    = "\033[96m";
    const std::string BRIGHT_WHITE   = "\033[97m";

    const std::string BG_BLACK   = "\033[40m";
    const std::string BG_RED     = "\033[41m";
    const std::string BG_GREEN   = "\033[42m";
    const std::string BG_YELLOW  = "\033[43m";
    const std::string BG_BLUE    = "\033[44m";
    const std::string BG_MAGENTA = "\033[45m";
    const std::string BG_CYAN    = "\033[46m";
    const std::string BG_WHITE   = "\033[47m";

    const std::string BG_BRIGHT_BLACK   = "\033[100m";
    const std::string BG_BRIGHT_RED     = "\033[101m";
    const std::string BG_BRIGHT_GREEN   = "\033[102m";
    const std::string BG_BRIGHT_YELLOW  = "\033[103m";
    const std::string BG_BRIGHT_BLUE    = "\033[104m";
    const std::string BG_BRIGHT_MAGENTA = "\033[105m";
    const std::string BG_BRIGHT_CYAN    = "\033[106m";
    const std::string BG_BRIGHT_WHITE   = "\033[107m";
}

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
            std::cerr << ansi::RED << "Failed to send message (curl error)" << ansi::RESET << std::endl;
        } else {
            std::cout << ansi::GREEN << "Message sent successfully!" << ansi::RESET << std::endl;
        }
    }
}

void initialize();

void banner() {
    const char* banner = R"(
                  .__   __  .__  __                .__                           
  _____  __ __|  |_/  |_|__|/  |_  ____   ____ |  |      .__         .__     
 /     \|  |  \  |\   __\  \   __\/  _ \ /  _ \|  |    __|  |___   __|  |___ 
|  Y Y  \  |  /  |_|  | |  ||  | (  <_> |  <_> )  |__ /__    __/  /__    __/ 
|__|_|  /____/|____/__| |__||__|  \____/ \____/|____/    |__|        |__|    
      \/                                                                     
)";
    std::cout << ansi::CYAN << banner << ansi::RESET << "\n";
}

void menu() {
    std::cout << ansi::BG_BLUE << ansi::CYAN;
    std::cout << "--     OPTIONS:      --\n";
    std::cout << "1. exit                \n";
    std::cout << "2. timer               \n";
    std::cout << "3. send Discord message\n";
    std::cout << "--                   --\n";
    std::cout << ansi::RESET;
}

void read() {
    std::string input;
    std::cout << ansi::CYAN << "Enter an option: " << ansi::RESET;
    std::getline(std::cin, input);
    std::cout << ansi::CYAN << "Validating choice... " << ansi::RESET;
    if (input == "1") {
        std::cout << ansi::GREEN << "Valid choice!" << ansi::RESET << "\n";
        exit(0);
    }
    else if (input == "2") {
        std::cout << ansi::GREEN << "Valid choice!" << ansi::RESET << "\n";
        std::cout << ansi::CYAN << "Enter a number of seconds: " << ansi::RESET;
        std::string seconds;
        std::getline(std::cin, seconds);
        int seconds_int = std::stoi(seconds);
        int timer = seconds_int;
        while (timer > 0) {
            std::cout << ansi::WHITE << timer << ansi::RESET << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            timer--;
        }
        initialize();
    }
    else if (input == "3") {
        std::cout << ansi::GREEN << "Valid choice!" << ansi::RESET << "\n";
        std::cout << ansi::CYAN << "Enter Discord webhook URL: " << ansi::RESET;
        std::string webhook_url;
        std::getline(std::cin, webhook_url);
        
        std::cout << ansi::CYAN << "Enter message to send: " << ansi::RESET;
        std::string message;
        std::getline(std::cin, message);
        
        discord::send_webhook(webhook_url, message);
        initialize();
    }
    else {
        std::cout << ansi::RED << "Invalid choice." << ansi::RESET << "\n";
        exit(1);
    }
}

void initialize() {
    console::clear();
    std::cout << ansi::WHITE << "Hello from Multitool++!" << ansi::RESET << "\n";
    std::cout << ansi::WHITE << "C++ is a great language!" << ansi::RESET << "\n";
    banner();
    menu();
    read();
}

int main() {
    initialize();
}
