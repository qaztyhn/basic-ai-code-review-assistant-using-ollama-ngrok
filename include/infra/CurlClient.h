/**
 * @file CurlClient.h
 * @brief Declaration of the CurlClient class for HTTP operations.
 * @details This file contains the concrete implementation of the IHttpClient interface
 * using the libcurl library to handle network requests.
 */

#ifndef _CURLCLIENT_H
#define _CURLCLIENT_H

#include "infra/IHttpClient.h"
#include <curl/curl.h>
#include <string>

/**
 * @class CurlClient
 * @brief A concrete implementation of IHttpClient using libcurl.
 *
 * The CurlClient class wraps the C-style libcurl API to provide
 * object-oriented HTTP request capabilities, specifically handling
 * POST requests with JSON payloads.
 */
class CurlClient : public IHttpClient {
public:
    /**
     * @brief Default constructor.
     *
     * Initializes the underlying cURL global environment (if required)
     * and sets up the client instance.
     */
    CurlClient();

    /**
     * @brief Destructor.
     *
     * Cleans up any resources allocated by cURL and performs necessary global cleanup.
     */
    ~CurlClient();

    /**
     * @brief Sends an HTTP POST request to the specified URL.
     *
     * @param url The target URL string where the request will be sent.
     * @param jsonPayload The JSON formatted string to be sent in the body of the request.
     * @return std::string The response body received from the server.
     * @throw std::runtime_error May throw if the cURL request fails or initialization fails.
     */
    std::string post(const std::string& url, const std::string& jsonPayload) override;

private:
    /**
     * @brief Static callback function used by libcurl to write received data.
     *
     * This function is called by libcurl as soon as there is data received
     * that needs to be saved.
     *
     * @param contents Pointer to the delivered data.
     * @param size Size of one data item.
     * @param nmemb Number of data items.
     * @param userp Pointer to the user-defined data structure (usually a std::string*) where data will be appended.
     * @return size_t The number of bytes actually taken care of (size * nmemb).
     */
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

#endif // _CURLCLIENT_H