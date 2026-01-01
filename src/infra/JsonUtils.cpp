#include "infra/JsonUtils.h"
#include "common/Utils.h"

#include <sstream>
#include <iomanip>
#include <iostream>


std::string JsonUtils::escape(const std::string& input) {
    std::ostringstream o;
    for (char c : input) {
        switch (c) {
            case '"': o << "\\\""; break;
            case '\\': o << "\\\\"; break;
            case '\b': o << "\\b"; break;
            case '\f': o << "\\f"; break;
            case '\n': o << "\\n"; break;
            case '\r': o << "\\r"; break;
            case '\t': o << "\\t"; break;
            default:
                if ('\x00' <= c && c <= '\x1f') {
                    o << "\\u" << std::hex << std::setw(4) << std::setfill('0') << (int)c;
                } else {
                    o << c;
                }
        }
    }
    return o.str();
}
std::string JsonUtils::extractField(const std::string& json, const std::string& key) {
    std::string searchKey = "\"" + key + "\":\"";
    size_t startPos = json.find(searchKey);
    if (startPos == std::string::npos) return ""; 
    
    startPos += searchKey.length();
    size_t endPos = startPos;
    

    while (endPos < json.length()) {
        if (json[endPos] == '"' && json[endPos - 1] != '\\') break;
        endPos++;
    }

    std::string content = json.substr(startPos, endPos - startPos);
    
    std::string cleanContent;
    for (size_t i = 0; i < content.length(); ++i) {
        if (content[i] == '\\' && i + 1 < content.length()) {
            char next = content[i+1];
            if (next == 'u' && i + 5 < content.length()) {
                std::string hexCode = content.substr(i + 2, 4);
                cleanContent += Utils::HexChar::hexToChar(hexCode);
                i += 5;
            }
            else if (next == 'n') { cleanContent += '\n'; i++; }
            else if (next == 't') { cleanContent += '\t'; i++; }
            else if (next == 'r') { i++; }
            else if (next == '"') { cleanContent += '"'; i++; }
            else if (next == '\\') { cleanContent += '\\'; i++; }
            else { 
                cleanContent += next; 
                i++;
            }
        } else {
            cleanContent += content[i];
        }
    }
    return cleanContent;
}