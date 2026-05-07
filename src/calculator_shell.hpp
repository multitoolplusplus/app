#include <array>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
#include "console.hpp"
#include "definitions.hpp"
#include "ansi.hpp"
#include "char.hpp"

#ifndef CALCULATOR_SHELL_HPP
#define CALCULATOR_SHELL_HPP
inline void option_shell();

inline std::string calculator_read_number(const std::string& prompt) {
  std::cout << ansi::BRIGHT_CYAN << prompt << ansi::BRIGHT_WHITE;
  std::string number;
  std::getline(std::cin, number);
  return number;
}

inline bool calculator_is_valid_bc_number(const std::string& number) {
  if (number.empty()) {
    return false;
  }

  std::size_t i = 0;
  if (number[i] == '+' || number[i] == '-') {
    ++i;
  }

  bool has_digit = false;
  bool has_dot = false;
  for (; i < number.size(); ++i) {
    const char ch = number[i];
    if (ch >= '0' && ch <= '9') {
      has_digit = true;
    }
    else if (ch == '.' && !has_dot) {
      has_dot = true;
    }
    else {
      return false;
    }
  }

  return has_digit;
}

inline std::string calculator_bc(const std::string& num1, const std::string& num2, char operation) {
  if (!calculator_is_valid_bc_number(num1) || !calculator_is_valid_bc_number(num2)) {
    throw std::invalid_argument("Invalid number.");
  }

  const std::string command = "printf 'scale=10; " + num1 + " " + operation + " " + num2 + "\\n' | bc 2>&1";
  std::array<char, 128> buffer{};
  std::string result;
  FILE* pipe = popen(command.c_str(), "r");
  if (pipe == nullptr) {
    throw std::runtime_error("Failed to start bc.");
  }

  while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe) != nullptr) {
    result += buffer.data();
  }

  const int status = pclose(pipe);
  while (!result.empty() && (result.back() == '\n' || result.back() == '\r')) {
    result.pop_back();
  }

  if (status != 0 || result.empty()) {
    throw std::runtime_error(result.empty() ? "bc failed." : result);
  }

  return result;
}

inline void calculator_run_operation(char operation) {
  const std::string num1 = calculator_read_number("Enter first number: ");
  const std::string num2 = calculator_read_number("Enter second number: ");

  try {
    const std::string result = calculator_bc(num1, num2, operation);
    std::cout << ansi::BRIGHT_GREEN << "Result: " << ansi::RESET << ansi::BRIGHT_WHITE << result << "\n";
  }
  catch (const std::exception& e) {
    std::cerr << ansi::BRIGHT_RED << e.what() << ansi::RESET << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  std::cout << ansi::BRIGHT_CYAN << "Press any key to continue...\n" << ansi::RESET;
  char_utils::get_char();
  option_shell();
}

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
    calculator_run_operation('-');
  }
  else if (command == "add") {
    calculator_run_operation('+');
  }
  else if (command == "mul") {
    calculator_run_operation('*');
  }
  else if (command == "div") {
    calculator_run_operation('/');
  }
  else {
    option_shell();
  }
}
#endif
