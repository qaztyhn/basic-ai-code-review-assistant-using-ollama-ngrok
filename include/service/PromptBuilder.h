/**
 * @file PromptBuilder.h
 * @brief Utility for constructing AI system prompts.
 * @details This file defines a factory-style class responsible for selecting
 * and generating the appropriate instructional prompts (system prompts)
 * for the AI model based on the requested review mode.
 */

#ifndef _PROMPTBUILDER_H
#define _PROMPTBUILDER_H

#include "common/Types.h"
#include <string>

/**
 * @class PromptBuilder
 * @brief Helper class to generate context-specific AI prompts.
 *
 * This class isolates the logic for prompt engineering. It ensures that the
 * AI receives the correct instructions (e.g., "Act as a security expert" vs
 * "Act as a clean code advocate") depending on the user's selected mode.
 */
class PromptBuilder {
public:
    /**
     * @brief Builds the system prompt for a specific review mode.
     *
     * Selects a predefined template string based on the provided `mode`.
     * For example, if the mode is `ReviewMode::Security`, it returns a prompt
     * emphasizing vulnerability detection and OWASP guidelines.
     *
     * @param mode The specific aspect of the code to review (Security, Performance, etc.).
     * @return std::string The complete system instruction string for the AI model.
     */
    static std::string buildReviewPrompt(ReviewMode mode);
};

#endif // _PROMPTBUILDER_H