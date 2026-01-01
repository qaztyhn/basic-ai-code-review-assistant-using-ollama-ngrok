/**
 * @file Utils.h
 * @brief General utility definitions.
 * @details This file contains miscellaneous helper classes and functions that 
 * are used across the application but do not fit into a specific domain service.
 */

#ifndef _UTILS_H
#define _UTILS_H

#include <string>

/**
 * @namespace Utils
 * @brief Namespace for general-purpose utility functions.
 *
 * Encapsulates helper classes to prevent naming collisions with other global symbols.
 */
namespace Utils {

    /**
     * @class HexChar
     * @brief Helper class for hexadecimal conversions.
     *
     * Provides static functionality to parse and convert hexadecimal string 
     * representations into native character data.
     */
    class HexChar {
    public:
        /**
         * @brief Converts a hexadecimal string to a single character.
         *
         * Interpretation of a 2-character hex string (e.g., "41" or "0A") 
         * into its corresponding ASCII or byte value.
         *
         * @param hex The string containing the hex representation (e.g., "20").
         * @return char The decoded character byte (e.g., ' ').
         */
        static char hexToChar(const std::string& hex);
    };
};
#endif // _UTILS_H