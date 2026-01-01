// service/PromptBuilder.cpp
#include "service/PromptBuilder.h"

std::string PromptBuilder::buildReviewPrompt(ReviewMode mode) {
    std::string prompt;
    switch (mode) {
    case ReviewMode::ReviewOnly:
        prompt = "Act like a Senior Software Engineer. Review the following code. Identify bugs, logic errors, and bad practices. Be concise.";
        break;
    case ReviewMode::Improve:
        prompt = "Act like a Senior Software Engineer. Review the code and suggest improvements for readability, maintainability, and clean code principles (SOLID, DRY).";
        break;
    case ReviewMode::Solution:
        prompt = "Act like a Senior Software Engineer. The code below has issues. Rewrite it completely with a better, more optimized solution. Explain your changes.";
        break;
    case ReviewMode::Security:
        prompt = "Act as a Cyber Security Expert. Audit the following code for security vulnerabilities (e.g., Buffer Overflow, SQL Injection, XSS, Memory Leaks). Report ONLY security risks.";
        break;
    case ReviewMode::Performance:
        prompt = "Act as a Performance Engineer. Analyze the time and space complexity (Big-O). Identify bottlenecks and suggest specific optimizations to make it faster.";
        break;
    case ReviewMode::UnitTest:
        prompt = "Act as a QA Engineer. Generate comprehensive C++ Unit Tests (using Google Test framework) for the provided code. Cover edge cases and happy paths.";
        break;
    case ReviewMode::Comments:
        prompt = "Act as a Documentation Expert. Rewrite the code adding Doxygen-style comments for classes/methods and inline comments for complex logic. Do not change the logic.";
        break;
    }
    prompt += "\n\n"
              "IMPORTANT OUTPUT FORMAT INSTRUCTIONS:\n"
              "- The output must be strictly PLAIN TEXT.\n"
              "- Do NOT use Markdown formatting (NO bold **, NO italics *, NO headers #).\n"
              "- Do NOT use code blocks with backticks (```).\n"
              "- Use UPPERCASE for section headings (e.g., '=== SECTION NAME ===').\n"
              "- Use simple indentation or dashes (-) for lists.\n"
              "- Keep the layout clean and readable for Windows Notepad.\n";
    return prompt;
}