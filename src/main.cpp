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
#include "definitions.hpp"

#ifdef PLATFORM_WINDOWS
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

std::vector<std::string> check_Vector = {"[x]","[ ]","[ ]","[ ]","[ ]","[ ]" };

int check_Vector_Size = check_Vector.size();
int check_ID = 0;


void initialize();
void banner() {
  /* Using raw string literals for multiline strings. */
  const char* banner = R"(
              .__   __  .__  __                .__                           
  _____  __ __|  |_/  |_|__|/  |_  ____   ____ |  |      .__         .__     )";

  const char* banner2 = R"(
 /     \|  |  \  |\   __\  \   __\/  _ \ /  _ \|  |    __|  |___   __|  |___ 
|  Y Y  \  |  /  |_|  | |  ||  | (  <_> |  <_> )  |__ /__    __/  /__    __/ )";

  const char *banner3 = R"(
|__|_|  /____/|____/__| |__||__|  \____/ \____/|____/    |__|        |__|    
      \/                                                       )";

  /* Print using ansi color codes for a fade effect from white to blue. */
  std::cout << ansi::BG_BLACK;
  std::cout << ansi::BOLD << ansi::BRIGHT_WHITE << banner << ansi::RESET;
  std::cout << ansi::BG_BLACK;
  std::cout << ansi::BOLD << ansi::BRIGHT_CYAN << banner2 << ansi::RESET;
  std::cout << ansi::BG_BLACK;
  std::cout << ansi::BOLD << ansi::BRIGHT_BLUE << banner3 << ansi::RESET;
  /* Print the version. */
  std::cout << ansi::BG_BLACK;
  std::cout << ansi::BOLD << ansi::BRIGHT_BLUE << "version " << APP_VERSION << " " << ansi::RESET << "\n" << "\n";
}

void option_exit() {
  std::cout << ansi::BRIGHT_GREEN << "Valid choice!" << ansi::RESET << "\n";
  console::leave_alt();
  exit(0);
}

void option_timer() {
  std::cout << ansi::BRIGHT_GREEN << "Valid choice!" << ansi::RESET << "\n";
  std::cout << ansi::BRIGHT_CYAN << "Enter a number of seconds: " << ansi::BRIGHT_WHITE;
  std::string seconds;
  std::getline(std::cin, seconds);
  int seconds_int;
  try {
    seconds_int = std::stoi(seconds);
  }
  catch (std::invalid_argument& e) {
    std::cerr << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    initialize();
  }
  catch (std::out_of_range& e) {
    std::cerr << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    initialize();
  }
  int timer = seconds_int;
  while (timer > 0) {
    std::cout << ansi::BRIGHT_WHITE << timer << ansi::RESET << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    timer--;
  }
  initialize();
}

void option_discord() {
  std::cout << ansi::BRIGHT_GREEN << "Valid choice!" << ansi::RESET << "\n";
  std::cout << ansi::BRIGHT_CYAN << "Enter Discord webhook URL: " << ansi::BRIGHT_WHITE;
  std::string webhook_url;
  std::getline(std::cin, webhook_url);

  std::cout << ansi::BRIGHT_CYAN << "Enter message to send: " << ansi::BRIGHT_WHITE;
  std::string message;
  std::getline(std::cin, message);

  discord::send_webhook(webhook_url, message);
  initialize();
}

void option_telegram() {
  std::cout << ansi::BRIGHT_GREEN << "Valid choice!" << ansi::RESET << "\n";
  std::cout << ansi::BRIGHT_CYAN << "Enter Telegram bot token: " << ansi::BRIGHT_WHITE;
  std::string bot_token;
  std::getline(std::cin, bot_token);

  std::cout << ansi::BRIGHT_CYAN << "Enter Telegram chat ID: " << ansi::BRIGHT_WHITE;
  std::string chat_id;
  std::getline(std::cin, chat_id);

  std::cout << ansi::BRIGHT_CYAN << "Enter message to send: " << ansi::BRIGHT_WHITE;
  std::string message;
  std::getline(std::cin, message);

  telegram::send_message(bot_token, chat_id, message);
  initialize();
}

#ifdef PLATFORM_POSIX
void option_password() {
  std::cout << ansi::BRIGHT_GREEN << "Valid choice!" << ansi::RESET << "\n";
  std::cout << ansi::BRIGHT_GREEN << "Generated password: " << ansi::BRIGHT_WHITE << "\n";
  int success = system("head -c 1000 /dev/urandom | tr -dc 'A-Za-z0-9' | head -c 32; echo"); // More secure than using a timestamp seed
  std::cout << ansi::BRIGHT_CYAN << "Press any key to continue...\n" << ansi::RESET;
  char_utils::get_char();
  initialize();
}
#endif

void menu() {
  console::clear();
  banner();
  std::cout << ansi::BOLD << ansi::ITALIC << ansi::UNDERLINE << ansi::BG_BRIGHT_BLUE << ansi::BRIGHT_CYAN;
  std::cout << "OPTIONS:                    \n";
  std::cout << ansi::RESET;
  std::cout << ansi::UNDERLINE << ansi::BG_BRIGHT_BLUE << ansi::BRIGHT_CYAN;
  std::cout << check_Vector[0] << " exit                    \n";
  std::cout << check_Vector[1] << " timer                   \n";
  std::cout << check_Vector[2] << " send Discord message    \n";
  std::cout << check_Vector[3] << " send Telegram message   \n";
#ifdef PLATFORM_POSIX
  std::cout << check_Vector[4] << " generate secure password\n";
  std::cout << check_Vector[5] << " calculator shell        \n";
#elif defined(PLATFORM_WINDOWS)
  std::cout << check_Vector[4] << " calculator shell        \n";
#endif
  std::cout << "\n";
  std::cout << ansi::RESET;
  std::cout << ansi::BRIGHT_CYAN << "Use W/S to navigate, E to select.\n" << ansi::RESET;
}

void read() {
  char check = char_utils::get_char();
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
	    check_Vector[i] = "[ ]";
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
	    check_Vector[i] = "[ ]";
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
#ifdef PLATFORM_POSIX
      case 4:
	option_password();
	break;
      case 5:
	std::cout << ansi::BRIGHT_GREEN << "Valid choice!" << ansi::RESET << "\n";
	std::cout << ansi::BOLD << ansi::ITALIC << ansi::BRIGHT_CYAN << "Welcome to the calculator shell, type 'help' for commands.\n" << ansi::RESET;
	option_shell();
	initialize();
	break;
#elif defined(PLATFORM_WINDOWS)
      case 4:
	std::cout << ansi::BRIGHT_GREEN << "Valid choice!" << ansi::RESET << "\n";
	std::cout << ansi::BOLD << ansi::ITALIC << ansi::BRIGHT_CYAN << "Welcome to the calculator shell, type 'help' for commands.\n" << ansi::RESET;
	option_shell();
	initialize();
	break;
#endif
      default:
	break;
      }
  }
  else {
    std::cerr << ansi::BRIGHT_RED << "Invalid choice." << ansi::RESET << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    initialize();
  }
}

/* Helps a lot for returning to the main menu. */
void initialize() {
  console::clear();
  menu();
  read();
}

void checkCurlIsInstalled() {
#ifdef PLATFORM_WINDOWS
  int curl = system("curl --version >nul 2>&1");
  if (curl != 0) {
    std::cout << "Curl not installed. Install it by running: winget install cURL.cURL\n";
    exit(1);
  }
#elif defined(PLATFORM_POSIX)
  int curl = system("curl --version >/dev/null 2>&1");
  if (curl != 0) {
    std::cout << "Curl not installed.\n";
    exit(1);
  }
#else
  std::cout << "No.\n";
  exit(1);
#endif
}

int main() {
  checkCurlIsInstalled();
  console::enter_alt();
  initialize();
  console::leave_alt();
}
