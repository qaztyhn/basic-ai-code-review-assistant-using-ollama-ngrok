/**
 * @file IHttpClient.h
 * @brief Interface definition for HTTP client operations.
 * @details This file defines the abstract base class for making HTTP requests,
 * allowing for dependency injection and easier testing (mocking) of network layers.
 */

#ifndef _IHTPPCLIENT_H
#define _IHTPPCLIENT_H

#include <string>

/**
 * @interface IHttpClient
 * @brief Abstract interface for an HTTP client.
 *
 * This interface defines the standard contract for sending HTTP requests.
 * Implementations (like CurlClient) must define the specific logic for
 * transmission (e.g., using libcurl, sockets, or other libraries).
 */
class IHttpClient {
public:
    /**
     * @brief Virtual destructor.
     *
     * Defaults to the compiler-generated implementation. It is declared virtual
     * to ensure proper cleanup of derived classes when deleted via an IHttpClient pointer.
     */
    virtual ~IHttpClient() = default;

    /**
     * @brief Sends an HTTP POST request (Pure Virtual).
     *
     * @param url The target URL for the POST request.
     * @param jsonPayload The JSON string body to send.
     * @return std::string The server's response body.
     */
    virtual std::string post(const std::string& url, const std::string& jsonPayload) = 0;
};

#endif // _IHTPPCLIENT_H