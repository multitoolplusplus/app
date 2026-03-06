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

        CURL *curl = curl_easy_init();

        if (curl) {
            CURLcode result;
            curl_easy_setopt(curl, CURLOPT_URL, url);
            result = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
    }
}
#endif
