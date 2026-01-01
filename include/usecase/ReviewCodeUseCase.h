/**
 * @file ReviewCodeUseCase.h
 * @brief Application logic controller/coordinator.
 * @details This file defines the primary use case for the application. It acts 
 * as the "Controller" in the architecture, orchestrating the flow of data 
 * between the User Interface (ConsoleMenu), Configuration (ConfigProvider), 
 * File System (FileService), and the AI Logic (AIService).
 */

#ifndef _REVIEWCODEUSECASE_H
#define _REVIEWCODEUSECASE_H

/**
 * @class ReviewCodeUseCase
 * @brief Encapsulates the execution logic for the code review process.
 *
 * This class contains the high-level business logic. It does not handle
 * low-level details (like HTTP or file I/O) directly but rather delegates 
 * to the appropriate service classes to perform a complete review cycle:
 * 1. Get configuration.
 * 2. Show menu and get user intent.
 * 3. Read the source file.
 * 4. Send the request to the AI.
 * 5. Display/Save the results.
 */
class ReviewCodeUseCase {
public:
    /**
     * @brief Executes the main workflow of the application.
     *
     * This method runs the entire lifecycle of a single review session.
     * It is typically called from `main()` to start the program's logic.
     */
    void execute();
};

#endif // _REVIEWCODEUSECASE_H