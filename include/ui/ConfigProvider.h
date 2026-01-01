/**
 * @file ConfigProvider.h
 * @brief Configuration management class.
 * @details This file defines a simple provider for application settings,
 * abstracting the source of configuration (e.g., hardcoded values, environment
 * variables, or configuration files) from the rest of the application.
 */

#ifndef _CONFIGPROVIDER_H
#define _CONFIGPROVIDER_H

#include <string>

/**
 * @class ConfigProvider
 * @brief Static provider for application configuration settings.
 *
 * This class serves as a central point to access configuration parameters
 * required by the application, such as the AI service endpoint or the 
 * default target file path.
 */
class ConfigProvider {
public:
    /**
     * @brief Retrieves the AI service URL.
     *
     * Returns the endpoint URL for the AI model API (e.g., Ollama or a remote server).
     * This might be loaded from an environment variable like `AI_SERVICE_URL` or default 
     * to a localhost address.
     *
     * @return std::string The full URL string.
     */
    static std::string getURL();

    /**
     * @brief Retrieves the target file path.
     *
     * Returns the path of the file to be processed or reviewed. This could
     * be a default path or one specified via arguments/environment.
     *
     * @return std::string The file system path as a string.
     */
    static std::string getFilePath();
};

#endif // _CONFIGPROVIDER_H