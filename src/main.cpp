#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>
#include "discord.hpp"
#include "telegram.hpp"
#include "console.hpp"

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
    * telegram::send_message(...) - SEND MESSAGE TO TELEGRAM BOT
    * ansi::[...] - ANSI ESCAPE CODES FOR COLORING
    * If you're reading this section, you may want to make a pull request to expand it
*/

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
    std::cout << "--     OPTIONS:       --\n";
    std::cout << "1. exit                 \n";
    std::cout << "2. timer                \n";
    std::cout << "3. send Discord message \n";
    std::cout << "4. send Telegram message\n"; 
    std::cout << "--                    --\n";
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
    else if (input == "4") {
        std::cout << ansi::GREEN << "Valid choice!" << ansi::RESET << "\n";
        std::cout << ansi::CYAN << "Enter Telegram Bot Token ID: " << ansi::RESET;
        std::string token_id;
        std::getline(std::cin, token_id);

        std::cout << ansi::CYAN << "Enter Telegram Chat ID: " << ansi::RESET;
        std::string chat_id;
        std::getline(std::cin, chat_id);

        std::cout << ansi::CYAN << "Enter message to send: " << ansi::RESET;
        std::string message;
        std::getline(std::cin, message);

        telegram::send_message(token_id, chat_id, message);
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
