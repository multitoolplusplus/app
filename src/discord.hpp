#include <iostream>
#include "ansi.hpp"

#ifndef DISCORD_HPP
#define DISCORD_HPP
namespace discord {
    inline void send_webhook(const std::string& webhook_url, const std::string& message) {
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
#endif