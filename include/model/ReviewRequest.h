/**
 * @file ReviewRequest.h
 * @brief Definition of the ReviewRequest data structure.
 * @details This file defines the data object used to encapsulate all necessary information
 * required to initiate a code review request to the AI model.
 */

#ifndef _REVIEWREQUEST_H
#define _REVIEWREQUEST_H

#include "common/Types.h"
#include <string>

/**
 * @struct ReviewRequest
 * @brief Represents a request for code review.
 *
 * This structure acts as a Data Transfer Object (DTO) holding the configuration,
 * payload, and context required by the backend or AI service to process a review.
 */
struct ReviewRequest {
    /**
     * @brief The identifier of the AI model to be used.
     *
     * Example values might include "llama3", "mistral", or "gpt-4".
     */
    std::string modelName;

    /**
     * @brief The actual source code content to be reviewed.
     *
     * This string contains the raw code snippet or file content that needs analysis.
     */
    std::string sourceCode;

    /**
     * @brief The raw prompt or specific instructions for the review.
     *
     * This may contain system prompts or user-specific questions regarding the code.
     */
    std::string promptRaw;

    /**
     * @brief The mode of operation for the review.
     *
     * Defined in common/Types.h, this likely specifies the intent of the review
     * (e.g., Security, Performance, Style, or General).
     */
    ReviewMode mode;

    /**
     * @brief Serializes the request structure into a JSON string.
     *
     * Converts the current state of the struct members into a formatted JSON string
     * suitable for transmission via HTTP.
     *
     * @return std::string The JSON representation of the request.
     */
    std::string toJson(); 
};

#endif // _REVIEWREQUEST_H