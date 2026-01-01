#ifndef _INPUTVALIDATOR_H
#define _INPUTVALIDATOR_H
#include <string>
/**
 * @class InputValidator
 * @brief Utility class for validating user inputs.
 *
 * This class provides static methods to validate various types of user inputs,
 * such as file paths, URLs, menu choices, and integer values.
 */
class InputValidator {
public:
    /**
     * @brief Checks if a file path is valid.
     */
    static bool isValidFilePath(const std::string& path);
    /**
     * @brief Checks if a URL is valid.
     */
    static bool isValidURL(const std::string& url);
    /**
     * @brief Checks if a menu choice is valid (between 0 and 3).
     */
    static bool isValidChoice(int choice);
    /**
     * @brief Checks if a string represents a valid integer.
     */
    static bool isValidInteger(const std::string& input);
};
#endif