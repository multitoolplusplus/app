#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include "ansi.hpp"
#include "char.hpp"

#ifndef TELEGRAM_HPP
#define TELEGRAM_HPP
namespace telegram {
    inline void send_message(const std::string& token_id, const std::string& chat_id, const std::string& message) {
        std::string url = "https://api.telegram.org/bot" + token_id + "/sendMessage";

        CURL *curl = curl_easy_init();

        if (curl) {
            CURLcode result;
            std::string json_data = "{\"chat_id\": \"" + chat_id + "\",\"text\": \"" + message + "\"}";
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data.c_str());

            result = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            std::cout << result << std::endl;
            char_utils::get_char();
        } else {
            std::cout << ansi::BRIGHT_RED << "Something happened\n" << ansi::RESET;
            char_utils::get_char();
        }
    }
}
#endif
