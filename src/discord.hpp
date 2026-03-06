#ifndef DISCORD_HPP
#define DISCORD_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "char.hpp"
#include "ansi.hpp"

namespace discord {
    inline std::string escape_json(const std::string& input) {
        std::ostringstream ss;
        for (auto c : input) {
            switch (c) {
                case '"':  ss << "\\\""; break;
                case '\\': ss << "\\\\"; break;
                case '\b': ss << "\\b"; break;
                case '\f': ss << "\\f"; break;
                case '\n': ss << "\\n"; break;
                case '\r': ss << "\\r"; break;
                case '\t': ss << "\\t"; break;
                default:
                    // Escape unprintable control characters (\x00 to \x1f)
                    if ('\x00' <= c && c <= '\x1f') {
                        ss << "\\u"
                           << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(c);
                    } else {
                        ss << c;
                    }
            }
        }
        return ss.str();
    }

    inline void send_webhook(const std::string& webhook_url, const std::string& message) {
        CURL *curl = curl_easy_init();

        if (curl) {
            CURLcode result;
            
            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            
            std::string json_data = "{\"content\": \"" + escape_json(message) + "\"}";
            
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(curl, CURLOPT_URL, webhook_url.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data.c_str());
            
            std::cout << json_data << std::endl;
            
            result = curl_easy_perform(curl);
            
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
            
            std::cout << "CURL Result: " << result << std::endl;
            char_utils::get_char();
        } else {
            std::cout << ansi::BRIGHT_RED << "Failed to initialize CURL\n" << ansi::RESET;
            char_utils::get_char();
        }
    }
}
#endif
