#include "service/FileService.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

std::string FileService::readContent(const std::string& filePath) {
    std::ifstream file(filePath);
    
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filePath);
    }

    // Đọc vào buffer
    std::stringstream buffer;
    buffer << file.rdbuf();
    
    return buffer.str();
}
bool FileService::writeContent(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath);
    
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file for writing: " + filePath);
    }
    file << content;
    file.close();
    return true;
}

