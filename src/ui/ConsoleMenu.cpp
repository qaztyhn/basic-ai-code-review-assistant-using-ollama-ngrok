// ui/ConsoleMenu.cpp
#include "ui/ConsoleMenu.h"
#include "common/InputValidator.h" // Nhớ include InputValidator
#include <iostream>

void ConsoleMenu::showMainMenu() {
    std::cout << "\n================ AI CODE REVIEWER ================\n";
    std::cout << "--- General ---\n";
    std::cout << "1. Review Code (General Feedback)\n";
    std::cout << "2. Improve Code (Refactor & Clean Code)\n";
    std::cout << "3. Propose Solution (Rewrite logic)\n";
    
    std::cout << "\n--- Specialist Mode ---\n";
    std::cout << "4. Security Audit (Find vulnerabilities)\n";
    std::cout << "5. Performance Analysis (Optimize speed/memory)\n";
    std::cout << "6. Generate Unit Tests (Google Test)\n";
    std::cout << "7. Auto-Comment (Add Doxygen/Explain code)\n";
    
    std::cout << "\n--- System ---\n";
    std::cout << "0. Exit\n";
    std::cout << "==================================================\n";
}

int ConsoleMenu::getChoice() {
    std::string choice;
    std::cout << "Enter your choice: " << std::endl;
    getline(std::cin, choice);
    while (!InputValidator::isValidInteger(choice) || !InputValidator::isValidChoice(std::stoi(choice))) {
        std::cerr << "Invalid choice. Please enter a valid choice (0-7): " << std::endl;
        getline(std::cin, choice);
    }
    return std::stoi(choice);
}
ReviewMode ConsoleMenu::choiceParser(int choice) {
    switch(choice) {
        case 1: return ReviewMode::ReviewOnly;
        case 2: return ReviewMode::Improve;
        case 3: return ReviewMode::Solution;
        case 4: return ReviewMode::Security;
        case 5: return ReviewMode::Performance;
        case 6: return ReviewMode::UnitTest;
        case 7: return ReviewMode::Comments;
        default: return ReviewMode::ReviewOnly;
    }
}