#ifndef _CHATSESSION_H
#define _CHATSESSION_H
#include "service/AIService.h"
#include <string>
/**
 * @brief Manages a chat session for follow-up questions regarding a code review.
 *
 * This class maintains the context of the conversation and interacts with the AIService
 * to provide answers based on the initial code review report and any subsequent queries.
 */

class ChatSession {
private:
/**
     * @brief Reference to the AIService used for generating responses.
     *
     * This service is used to send follow-up questions and receive answers
     * based on the context of the initial code review.
     */
    AIService& aiService; 
    /**
     * @brief The accumulated context history of the chat session.
     *
     * This string contains the previous interactions and is used to provide
     * context for generating relevant responses.
     */
    std::string contextHistory; 
    /**
     * @brief The file path where the chat log will be saved.
     *
     * This allows for persistence of the chat history for future reference.
     */
    std::string reportFilePath;

public:
/**
     * @brief Constructs a ChatSession.
     *
     * @param service Reference to an AIService instance for handling requests.
     * @param initialContext The initial context to start the chat session with.
     * @param logPath The file path to save the chat log.
     */
    ChatSession(AIService& service, std::string initialContext, std::string logPath);
    /**
     * @brief Starts the chat session, allowing for follow-up questions.
     *
     * This method enters a loop where the user can input questions related
     * to the code review. It sends these questions to the AIService and
     * displays the responses, maintaining context throughout the session.
     */
    void start();
};

#endif