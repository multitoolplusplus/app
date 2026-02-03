#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include "ansi.hpp"

#ifndef TELEGRAM_HPP
#define TELEGRAM_HPP
namespace telegram {
  inline void send_message(const std::string& token_id, const std::string& chat_id, const std::string& message) {
    std::string url = "https://api.telegram.org/bot" + token_id + "/sendMessage";
    std::string command = "curl -s -o /dev/null -X POST -H \"Content-Type: application/json\" -d \"{\\\"chat_id\\\": \\\"" + 
      chat_id + "\\\", \\\"text\\\": \\\"" + message + "\\\"}\" " + url;

    int result = system(command.c_str());

    if (result != 0) {
      std::cerr << ansi::RED << "Failed to send message (curl error)" << ansi::RESET << "\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
    } else {
      std::cout << ansi::GREEN << "Message sent successfully!" << ansi::RESET << "\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  }
}
#endif
