#include "ui/ConfigProvider.h"
#include "common/InputValidator.h"
#include <iostream>

std::string ConfigProvider::getURL() {
    std::string ngrokUrl;
    std::cout << "Enter ngrok url: " << std::endl;
    getline(std::cin, ngrokUrl);
    while (!InputValidator::isValidURL(ngrokUrl)) {
        std::cerr << "Invalid URL format. Please enter a valid URL: " << std::endl;
        getline(std::cin, ngrokUrl);
    }
    return ngrokUrl;
}

std::string ConfigProvider::getFilePath() {
    std::string input;
    
    while (true) {
        std::cout << "Drag & Drop your file here (or type path): ";
        std::getline(std::cin, input);

        const std::string whitespace = " \t\r\n";
        size_t first = input.find_first_not_of(whitespace);
        if (std::string::npos == first) {
            continue; 
        }
        size_t last = input.find_last_not_of(whitespace);
        input = input.substr(first, (last - first + 1));
        if (input.size() > 0 && input[0] == '&') {
            input.erase(0, 1);
            first = input.find_first_not_of(whitespace);
            if (std::string::npos == first) continue;
            last = input.find_last_not_of(whitespace);
            input = input.substr(first, (last - first + 1));
        }
        if (input.size() >= 2) {
            char startChar = input.front();
            char endChar = input.back();
            if ((startChar == '"' && endChar == '"') || 
                (startChar == '\'' && endChar == '\'')) {
                input = input.substr(1, input.length() - 2);
            }
        }
        if (input.empty()) {
            std::cerr << "Path cannot be empty.\n";
            continue;
        }
        if (InputValidator::isValidFilePath(input)) {
            return input; 
        }
        std::cerr << "File not found: " << input << "\n";
        std::cerr << "Please check the path and try again.\n";
    }
}