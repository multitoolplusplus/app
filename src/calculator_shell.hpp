#include <iostream>
#include <string>
#include <thread>
#include "console.hpp"
#include "ansi.hpp"
#include "char.hpp"

#ifndef CALCULATOR_SHELL_HPP
#define CALCULATOR_SHELL_HPP
inline void option_shell() {
  std::string command;
  std::cout << ansi::BRIGHT_CYAN << ">> " << ansi::RESET << ansi::BRIGHT_GREEN;
  std::getline(std::cin, command);
  if (command == "help") {
    std::cout << ansi::BOLD << ansi::ITALIC << ansi::BRIGHT_CYAN;
    std::cout << "Commands:\n";
    std::cout << "help - show this help message\n";
    std::cout << "exit - exit the shell\n";
    std::cout << "clear - clear the screen\n";
    std::cout << "sub - substract two numbers\n";
    std::cout << "add - add two numbers\n";
    std::cout << "mul - multiply two numbers\n";
    std::cout << "div - divide two numbers\n";
    std::cout << ansi::RESET;
    option_shell();
  }
  else if (command == "exit") {
  }
  else if (command == "clear") {
    console::clear();
    option_shell();
  }
  else if (command == "sub") {
    std::cout << ansi::BRIGHT_CYAN << "Enter first number: " << ansi::BRIGHT_WHITE;
    std::string num1;
    std::getline(std::cin, num1);
    int num1_int;
    try {
      num1_int = std::stoi(num1);
    }
    catch (std::invalid_argument& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
      option_shell();
    }
    catch (std::out_of_range& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
      option_shell();
    }
    std::cout << ansi::BRIGHT_CYAN << "Enter second number: " << ansi::BRIGHT_WHITE;
    std::string num2;
    std::getline(std::cin, num2);
    int num2_int;
    try {
      num2_int = std::stoi(num2);
    }
    catch (std::invalid_argument& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
    }
    catch (std::out_of_range& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
    }
    std::cout << ansi::BRIGHT_GREEN << "Result: " << ansi::RESET << ansi::BRIGHT_WHITE << num1_int - num2_int << "\n";
    std::cout << ansi::BRIGHT_CYAN << "Press any key to continue...\n" << ansi::RESET;
    char_utils::get_char();
    option_shell();
  }
  else if (command == "add") {
    std::cout << ansi::BRIGHT_CYAN << "Enter first number: " << ansi::BRIGHT_WHITE;
    std::string num1;
    std::getline(std::cin, num1);
    int num1_int;
    try {
      num1_int = std::stoi(num1);
    }
    catch (std::invalid_argument& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
      option_shell();
    }
    catch (std::out_of_range& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
      option_shell();
    }
    std::cout << ansi::BRIGHT_CYAN << "Enter second number: " << ansi::BRIGHT_WHITE;
    std::string num2;
    std::getline(std::cin, num2);
    int num2_int;
    try {
      num2_int = std::stoi(num2);
    }
    catch (std::invalid_argument& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
    }
    catch (std::out_of_range& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
    }
    std::cout << ansi::BRIGHT_GREEN << "Result: " << ansi::RESET << ansi::BRIGHT_WHITE << num1_int + num2_int << "\n";
    std::cout << ansi::BRIGHT_CYAN << "Press any key to continue...\n" << ansi::RESET;
    char_utils::get_char();
    option_shell();
  }
  else if (command == "mul") {
    std::cout << ansi::BRIGHT_CYAN << "Enter first number: " << ansi::BRIGHT_WHITE;
    std::string num1;
    std::getline(std::cin, num1);
    int num1_int;
    try {
      num1_int = std::stoi(num1);
    }
    catch (std::invalid_argument& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
      option_shell();
    }
    catch (std::out_of_range& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
      option_shell();
    }
    std::cout << ansi::BRIGHT_CYAN << "Enter second number: " << ansi::BRIGHT_WHITE;
    std::string num2;
    std::getline(std::cin, num2);
    int num2_int;
    try {
      num2_int = std::stoi(num2);
    }
    catch (std::invalid_argument& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
    }
    catch (std::out_of_range& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
    }
    std::cout << ansi::BRIGHT_GREEN << "Result: " << ansi::RESET << ansi::BRIGHT_WHITE << num1_int * num2_int << "\n";
    std::cout << ansi::BRIGHT_CYAN << "Press any key to continue...\n" << ansi::RESET;
    char_utils::get_char();
    option_shell();
  }
  else if (command == "div") {
    std::cout << ansi::BRIGHT_CYAN << "Enter first number: " << ansi::BRIGHT_WHITE;
    std::string num1;
    std::getline(std::cin, num1);
    int num1_int;
    try {
      num1_int = std::stoi(num1);
    }
    catch (std::invalid_argument& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
      option_shell();
    }
    catch (std::out_of_range& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
      option_shell();
    }
    std::cout << ansi::BRIGHT_CYAN << "Enter second number: " << ansi::BRIGHT_WHITE;
    std::string num2;
    std::getline(std::cin, num2);
    int num2_int;
    try {
      num2_int = std::stoi(num2);
    }
    catch (std::invalid_argument& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
    }
    catch (std::out_of_range& e) {
      std::cout << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
    }
    std::cout << ansi::BRIGHT_GREEN << "Result: " << ansi::RESET << ansi::BRIGHT_WHITE << num1_int / num2_int << "\n";
    std::cout << ansi::BRIGHT_CYAN << "Press any key to continue...\n" << ansi::RESET;
    char_utils::get_char();
    option_shell();
  }
  else {
    option_shell();
  }
}
#endif
