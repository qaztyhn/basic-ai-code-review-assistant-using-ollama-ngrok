/**
 * @file JsonUtils.h
 * @brief Utility class for basic JSON string manipulation.
 * @details This file provides static helper methods to handle JSON string escaping
 * and simple field extraction, avoiding the need for a full-scale JSON library
 * for simple tasks.
 */

#ifndef _JSONUTILS_H
#define _JSONUTILS_H

#include <string>

/**
 * @class JsonUtils
 * @brief A collection of static utility functions for JSON processing.
 *
 * This class provides stateless helper functions to escape strings for
 * inclusion in JSON payloads and to parse specific fields from a JSON response.
 */
class JsonUtils {
public:
    /**
     * @brief Escapes special characters in a string for JSON compatibility.
     *
     * Converts characters like double quotes, backslashes, and control characters
     * into their escaped counterparts (e.g., " becomes \") to ensure the string
     * is valid within a JSON structure.
     *
     * @param input The raw input string to be escaped.
     * @return std::string The JSON-safe escaped string.
     */
    static std::string escape(const std::string& input);

    /**
     * @brief Extracts the value of a specific key from a JSON string.
     *
     * Locates the specified key within the JSON string and extracts its associated value.
     * Note: This is likely a lightweight parser and might not handle complex nested
     * structures or arrays depending on the implementation.
     *
     * @param json The JSON string to search.
     * @param key The key whose value needs to be extracted.
     * @return std::string The value associated with the key, or an empty string/error indicator if not found.
     */
    static std::string extractField(const std::string& json, const std::string& key);
};

#endif // _JSONUTILS_H