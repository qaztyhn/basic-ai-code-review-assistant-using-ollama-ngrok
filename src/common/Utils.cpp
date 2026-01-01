#include <sstream>
#include <string>

#include "common/Utils.h"

namespace Utils {
    char HexChar::hexToChar(const std::string& hex) {
        int x;
        std::stringstream ss;
        ss << std::hex << hex;
        ss >> x;
        return (char)x;
    }
}