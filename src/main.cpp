/*
    * multitool++ - a command line utility for various purposes
    * Author: benja2998@noreply.codeberg.org
    * License: GPL-3.0
    * That means you must make any software that uses this source code GPL-3.0 licensed.
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <thread>
#include <vector>
#include "discord.hpp"
#include "telegram.hpp"
#include "console.hpp"
#include "char.hpp"
#include "calculator_shell.hpp"

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#elif defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
#endif

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
std::vector<std::string> check_Vector = {"[x]","[]","[]","[]","[]","[]" };

int check_Vector_Size = check_Vector.size();
int check_ID = 0;


void initialize();
// This is Banner function is made to draw the banner when you run the code 
void banner() {
    /* Using raw string literals for multiline strings. */
    const char* banner = R"(
              .__   __  .__  __                .__                           
  _____  __ __|  |_/  |_|__|/  |_  ____   ____ |  |      .__         .__     )";

    const char* banner2 = R"(
 /     \|  |  \  |\   __\  \   __\/  _ \ /  _ \|  |    __|  |___   __|  |___ 
|  Y Y  \  |  /  |_|  | |  ||  | (  <_> |  <_> )  |__ /__    __/  /__    __/ )";

    const char* banner3 = R"(
|__|_|  /____/|____/__| |__||__|  \____/ \____/|____/    |__|        |__|    
      \/                                                                     )";
    
    /* Print using ansi color codes for a fade effect from white to blue. */
    std::cout << ansi::BG_BLACK;
    std::cout << ansi::BOLD << ansi::WHITE << banner << ansi::RESET;
    std::cout << ansi::BG_BLACK;
    std::cout << ansi::BOLD << ansi::CYAN << banner2 << ansi::RESET;
    std::cout << ansi::BG_BLACK;
    std::cout << ansi::BOLD << ansi::BLUE << banner3 << ansi::RESET << "\n" <<  "\n";
}

void option_exit() {
    std::cout << ansi::GREEN << "Valid choice!" << ansi::RESET << "\n";
    exit(0);
}

void option_timer() {
    std::cout << ansi::GREEN << "Valid choice!" << ansi::RESET << "\n";
    std::cout << ansi::CYAN << "Enter a number of seconds: " << ansi::RESET;
    std::string seconds;
    std::getline(std::cin, seconds);
    int seconds_int;
    try {
        seconds_int = std::stoi(seconds);
    }
    catch (std::invalid_argument& e) {
        std::cout << ansi::RED << e.what() << ansi::RESET << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        initialize();
    }
    catch (std::out_of_range& e) {
        std::cout << ansi::RED << e.what() << ansi::RESET << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        initialize();
    }
    int timer = seconds_int;
    while (timer > 0) {
        std::cout << ansi::WHITE << timer << ansi::RESET << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        timer--;
    }
    initialize();
}

void option_discord() {
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

void option_telegram() {
    std::cout << ansi::GREEN << "Valid choice!" << ansi::RESET << "\n";
    std::cout << ansi::CYAN << "Enter Telegram bot token: " << ansi::RESET;
    std::string bot_token;
    std::getline(std::cin, bot_token);

    std::cout << ansi::CYAN << "Enter Telegram chat ID: " << ansi::RESET;
    std::string chat_id;
    std::getline(std::cin, chat_id);

    std::cout << ansi::CYAN << "Enter message to send: " << ansi::RESET;
    std::string message;
    std::getline(std::cin, message);

    telegram::send_message(bot_token, chat_id, message);
    initialize();
}

void option_password() {

    /* Use a seed */
    srand(time(NULL));

    std::cout << ansi::GREEN << "Valid choice!" << ansi::RESET << "\n";
    std::cout << ansi::CYAN << "Enter password length: " << ansi::RESET;
    std::string length;
    std::getline(std::cin, length);
    int length_int;
    try {
        length_int = std::stoi(length);
    }
    catch (std::invalid_argument& e) {
        std::cout << ansi::RED << e.what() << ansi::RESET << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        initialize();
    }
    catch (std::out_of_range& e) {
        std::cout << ansi::RED << e.what() << ansi::RESET << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        initialize();
    }
    std::string password = "";
    for (int i = 0; i < length_int; i++) {
        const std::string charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_+-=[]{}|;:,.<>?~/";
        password += charset[rand() % charset.length()];
    }
    std::cout << ansi::GREEN << "Generated password: " << ansi::RESET << password << "\n";
    std::cout << ansi::CYAN << "Press any key to continue...\n" << ansi::RESET;
    char_utils::get_char();
    initialize();
}

void menu() {
    console::clear();
    banner();
    std::cout << ansi::BOLD << ansi::ITALIC << ansi::UNDERLINE << ansi::BG_BLUE << ansi::CYAN;
    std::cout << "OPTIONS:                    \n";
    std::cout << ansi::RESET;
    std::cout << ansi::UNDERLINE << ansi::BG_BLUE << ansi::CYAN;
    std::cout << check_Vector[0] << " exit                    \n";
    std::cout << check_Vector[1] << " timer                   \n";
    std::cout << check_Vector[2] << " send Discord message    \n";
    std::cout << check_Vector[3] << " send Telegram message   \n";
    std::cout << check_Vector[4] << " generate secure password\n";
    std::cout << check_Vector[5] << " calculator shell        \n";
    /*std::cout << checked1 << " exit                    \n";
    std::cout << checked2 << " timer                   \n";
    std::cout << checked3 << " send Discord message    \n";
    std::cout << checked4 << " send Telegram message   \n"; 
    std::cout << checked5 << " generate secure password\n";
    std::cout << checked6 << " calculator shell        \n";*/
    std::cout << "\n";
    std::cout << ansi::RESET;
    std::cout << ansi::CYAN << "Use W/S to navigate, E to select.\n" << ansi::RESET;
}

void read() {
    char check = char_utils::get_char();
    /* Removed  this line below since it looks bad. */
    //std::cout << ansi::CYAN << "Validating choice... " << ansi::RESET;

    /* Horrific, janky W/S navigation. I should have used ncurses instead of writing this garbage. */
    /* But it works... */
    if (check == 'w' || check == 'W') {  

        check_ID = check_ID > 0 ? check_ID - 1 : check_ID + 0;
        for (int i = 0; i < check_Vector_Size; i++)
        {
            if (i == check_ID)
            {
                check_Vector[i] = "[x]";
            }
            else
            {
                check_Vector[i] = "[]";
            }
        }        

        initialize();
    }
    else if (check == 's' || check == 'S') {
 
        check_ID = check_ID < 5 ? check_ID + 1 : check_ID;
        for (int i = 0; i < check_Vector_Size; i++)
        {
            if (i == check_ID)
            {
                check_Vector[i] = "[x]";
            }
            else
            {
                check_Vector[i] = "[]";
            }
        }        

        initialize();
    }
    else if (check == 'e' || check == 'E') {
        switch (check_ID)
        {
        case 0:
            option_exit();
            break;
        case 1:
            option_timer();
            break;
        case 2:
            option_discord();
            break;
        case 3:
            option_telegram();
            break;
        case 4:
            option_password();
            break;
        case 5:
            std::cout << ansi::GREEN << "Valid choice!" << ansi::RESET << "\n";
            std::cout << ansi::BOLD << ansi::ITALIC << ansi::CYAN << "Welcome to the calculator shell, type 'help' for commands.\n" << ansi::RESET;
            option_shell();
            initialize();
            break;
        default:
            break;
        }
    }
    else {
        std::cout << ansi::RED << "Invalid choice." << ansi::RESET << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        initialize();
    }
}

/* Probably the most useful function in the program. */
/* Helps a lot for returning to the main menu. */
void initialize() {
    console::clear();
    menu();
    read();
}

void checkCurlIsInstalled() {
#ifdef _WIN32
    int curl = system("curl --version >nul 2>&1");
    if (curl != 0) {
        /* Either the user is not intelligent life and removed curl.exe or they are running an old version of Windows. */
        std::cout << "Curl not installed. Install it by running: winget install cURL.cURL\n";
        exit(1);
    }
#elif defined(__linux__)
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
