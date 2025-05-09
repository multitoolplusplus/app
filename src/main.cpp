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
  _____  __ __|  |_/  |_|__|/  |_  ____   ____ |  |      .__         .__ )";

    const char* banner2 = R"(
 /     \|  |  \  |\   __\  \   __\/  _ \ /  _ \|  |    __|  |___   __|  |___ 
|  Y Y  \  |  /  |_|  | |  ||  | (  <_> |  <_> )  |__ /__    __/  /__    __/ )";

    const char* banner3 = R"(
|__|_|  /____/|____/__| |__||__|  \____/ \____/|____/    |__|        |__|    
      \/                                                                     )";
    std::cout << ansi::BOLD << ansi::WHITE << banner << ansi::RESET;
    std::cout << ansi::BOLD << ansi::CYAN << banner2 << ansi::RESET;
    std::cout << ansi::BOLD << ansi::BLUE << banner3 << ansi::RESET << "\n" <<  "\n";
}

void menu() {
    std::cout << ansi::BOLD << ansi::ITALIC << ansi::UNDERLINE << ansi::BG_BLUE << ansi::CYAN;
    std::cout << "OPTIONS:                   \n";
    std::cout << ansi::RESET;
    std::cout << ansi::UNDERLINE << ansi::BG_BLUE << ansi::CYAN;
    std::cout << "1. exit                    \n";
    std::cout << "2. timer                   \n";
    std::cout << "3. send Discord message    \n";
    std::cout << "4. send Telegram message   \n"; 
    std::cout << "5. generate secure password\n";
    std::cout << "\n";
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
    else if (input == "5") {
        std::cout << ansi::GREEN << "Valid choice!" << ansi::RESET << "\n";
        std::cout << ansi::CYAN << "Enter a password length: " << ansi::RESET;
        std::string password_length;
        std::getline(std::cin, password_length);
        int password_length_int = std::stoi(password_length);
        std::string password = "";
        for (int i = 0; i < password_length_int; i++) {
            const std::string charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_+-=[]{}|;:,.<>?";
            password += charset[rand() % charset.length()];
        }
        std::cout << ansi::CYAN << "Generated password: " << ansi::RESET << password << "\n";
        std::cout << ansi::CYAN << "Press enter to continue..." << ansi::RESET << "\n";
        std::cin.get();
        initialize();
    }
    else {
        std::cout << ansi::RED << "Invalid choice." << ansi::RESET << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        initialize();
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

void checkCurlIsInstalled() {
#ifdef _WIN32
    std::string curlPath = "C:\\Windows\\System32\\curl.exe";
    int curl = system("curl --version >nul 2>&1");
    if (curl != 0) {
        std::cout << "Curl not installed. Install it by running: winget install cURL.cURL\n";
        exit(1);
    }
#elif defined(__linux__)
    std::string curlPath = "/usr/bin/curl";
    int curl = system("curl --version >/dev/null 2>&1");
    if (curl != 0) {
        std::cout << "Curl not installed. Install it by running: sudo <your package manager> install curl\n";
        exit(1);
    }
#else
    std::cout << "Unsupported OS. Please make sure you have modified the source code before compiling for another OS.";
    exit(10);
#endif
}

int main() {
    checkCurlIsInstalled();
    initialize();
}
