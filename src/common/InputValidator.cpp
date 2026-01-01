#include "common/InputValidator.h"
#include <regex>
#include <filesystem>

bool InputValidator::isValidFilePath(const std::string& path) {
    return std::filesystem::exists(path) && std::filesystem::is_regular_file(path);
}

bool InputValidator::isValidURL(const std::string& url) {
    std::regex urlRegex(R"(^https?://[^\s/$.?#].[^\s]*$)");
    return std::regex_match(url, urlRegex);
}

bool InputValidator::isValidChoice(int choice) {
    return choice >= 0 && choice <= 7;
    
}
bool InputValidator::isValidInteger(const std::string& input) {
    std::regex intRegex(R"(\d+$)");
    return std::regex_match(input, intRegex);
}
