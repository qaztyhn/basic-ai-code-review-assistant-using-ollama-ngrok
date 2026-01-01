#include "usecase/ReviewCodeUseCase.h"
#include "infra/CurlClient.h"
#include "service/PromptBuilder.h"
#include "service/AIService.h"
#include "service/FileService.h"
#include "service/ChatSession.h"
#include "ui/ConsoleMenu.h"
#include "ui/ConfigProvider.h"
#include "common/InputValidator.h" 

#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdlib>
#include <filesystem>

const std::string MODEL_NAME = "gpt-oss:20b"; 

void ReviewCodeUseCase::execute() {
    std::string ngrokUrl = ConfigProvider::getURL();
    std::unique_ptr<IHttpClient> httpClient = std::make_unique<CurlClient>();
    
    AIService reviewer(std::move(httpClient), ngrokUrl, MODEL_NAME);

    while (true) {
        ConsoleMenu::showMainMenu();
        int choice = ConsoleMenu::getChoice();
        
        if (choice == 0) {
            std::cout << "Goodbye! See you again.\n";
            break;
        }

        try {
            ReviewMode mode = ConsoleMenu::choiceParser(choice);
            std::string rawPath = ConfigProvider::getFilePath();
            std::filesystem::path sourcePath(rawPath);
            std::string code = FileService::readContent(rawPath);
            
            if (code.empty()) {
                throw std::runtime_error("The specified file is empty or could not be read.");
            }
            std::cout <<"Processing...\n";
            ReviewRequest request;
            request.modelName = MODEL_NAME;
            request.promptRaw = PromptBuilder::buildReviewPrompt(mode);
            request.mode = mode;
            request.sourceCode = code;

            ReviewResponse result = reviewer.reviewCode(request);
            
            if (result.success) {
                std::filesystem::path outPath = sourcePath.parent_path() / (sourcePath.stem().string() + "_review.txt");
                std::string outFileName = outPath.string();
                
                FileService::writeContent(outFileName, result.content);
                std::cout << "Success" << "\n";
                std::cout << "Report saved to: " << outFileName << "\n";
                std::string cmd = "start \"\" \"" + outFileName + "\"";
                system(cmd.c_str());
            
                std::string initialContext = request.promptRaw + "\n\nCode:\n" + code;
                initialContext += "\n\nAI Analysis:\n" + result.content;

                ChatSession session(reviewer, initialContext, outFileName);
                
                session.start();

            } else {
                throw std::runtime_error("AI Review operation failed.");
            }

        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << "\n";
        }
        std::cout << "\nPress Enter to return to main menu...";
        std::cin.get();
    }
}