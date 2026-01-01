#include "service/ChatSession.h"
#include "common/InputValidator.h"
#include "model/ReviewRequest.h"
#include <iostream>
#include <fstream>

ChatSession::ChatSession(AIService& service, std::string initialContext, std::string logPath)
    : aiService(service), contextHistory(initialContext), reportFilePath(logPath) {}

void ChatSession::start() {
    
    while (true) {
        std::cout << "Do you have questions about this code? (Type 'exit' to finish)\n";
        
        std::string userQuestion;
        std::getline(std::cin, userQuestion);

        if (userQuestion == "exit" || userQuestion == "no") {
            break;
        }
        std::cout << "Processing...\n";

        this->contextHistory += "\n\nUser Question: " + userQuestion;
        this->contextHistory += "\nAnswer this specific question concisely:";

        ReviewRequest request;
        request.modelName = "gpt-oss:20b"; 
        request.promptRaw = this->contextHistory;
        request.sourceCode = ""; 
        request.mode = ReviewMode::ReviewOnly;

        ReviewResponse response = this->aiService.reviewCode(request);

        if (response.success) {
            this->contextHistory += "\n\nAI Answer:\n" + response.content;
            std::ofstream file(this->reportFilePath, std::ios::app);
            if (file.is_open()) {
                file << "\n\n======================================================================\n";
                file << "\n\nQUESTION: " << userQuestion << "\n\nANSWER: " << response.content;
                file.close();
            }
        std::string cmd = "start \"\" \"" + this->reportFilePath + "\"";
        system(cmd.c_str());
        } else {
            std::cerr << "Error: " << response.errorMessage << "\n";
        }
    }
}