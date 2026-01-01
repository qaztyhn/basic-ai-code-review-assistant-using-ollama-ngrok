/**
 * @file AIService.h
 * @brief Service class for interacting with the AI backend.
 * @details This file defines the high-level service responsible for orchestrating
 * code reviews. It bridges the gap between the domain-specific data structures
 * (ReviewRequest/Response) and the lower-level network interface (IHttpClient).
 */

#ifndef _AISERVICE_H
#define _AISERVICE_H

#include "infra/IHttpClient.h"
#include "model/ReviewResponse.h"
#include "model/ReviewRequest.h"
#include "common/Types.h"
#include <string>
#include <memory>

/**
 * @class AIService
 * @brief High-level service handling AI code review interactions.
 *
 * The AIService class acts as a facade for the AI operations. It takes high-level
 * request objects, serializes them, uses the injected HTTP client to communicate
 * with the AI server (e.g., Ollama), and deserializes the results into structured responses.
 */
class AIService {
private:
    /**
     * @brief Pointer to the HTTP client implementation.
     *
     * Used to perform the actual network transmission. The service does not own
     * this pointer and assumes the caller manages its lifecycle (dependency injection).
     */
    std::unique_ptr<IHttpClient> httpClient;

    /**
     * @brief The endpoint URL of the AI server.
     *
     * Example: "http://localhost:11434/api/generate" for a local Ollama instance.
     */
    std::string serverUrl;

    /**
     * @brief The name of the model to use for reviews.
     *
     * This acts as a default or configuration for the service, though individual
     * requests might override it depending on implementation details.
     */
    std::string modelName;

public:
    /**
     * @brief Constructs the AIService.
     *
     * @param client Pointer to a concrete implementation of IHttpClient.
     * @param url The base URL for the AI API endpoint.
     * @param model The default model name (e.g., "llama3").
     */
    AIService(std::unique_ptr<IHttpClient> client, std::string url, std::string model);

    /**
     * @brief Initiates a code review process.
     *
     * This method serializes the `request` object, sends it via the `httpClient`,
     * and processes the raw JSON response into a `ReviewResponse` object.
     *
     * @param request The structured request containing code and prompt details.
     * @return ReviewResponse The result of the review operation.
     */
    ReviewResponse reviewCode(ReviewRequest request);
};

#endif // _AISERVICE_H