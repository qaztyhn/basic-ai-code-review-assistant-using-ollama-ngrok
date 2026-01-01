/**
 * @file FileService.h
 * @brief Utility class for file I/O operations.
 * @details This file provides static helper methods to simplify reading from and 
 * writing to the file system, abstracting away standard C++ stream boilerplate.
 */

#ifndef _FILESERVICE_H
#define _FILESERVICE_H

#include <string>

/**
 * @class FileService
 * @brief A stateless utility class for file handling.
 *
 * Provides simple synchronous methods to read a file's entire content into a string
 * or write a string to a file. Useful for loading source code for review or 
 * saving review results.
 */
class FileService {
public:
    /**
     * @brief Reads the entire content of a file into a string.
     *
     * Opens the specified file in input mode and reads all characters until EOF.
     *
     * @param filePath The relative or absolute path to the file to be read.
     * @return std::string The content of the file.
     * @throw std::runtime_error If the file cannot be opened or read.
     */
    static std::string readContent(const std::string& filePath);

    /**
     * @brief Writes string content to a file.
     *
     * Opens the specified file in output mode. If the file already exists,
     * its content is truncated (overwritten). If it does not exist, it is created.
     *
     * @param filePath The relative or absolute path where the file will be written.
     * @param content The string data to write to the file.
     * @return bool True if the write operation completed successfully, false otherwise.
     */
    static bool writeContent(const std::string& filePath, const std::string& content);
};

#endif // _FILESERVICE_H