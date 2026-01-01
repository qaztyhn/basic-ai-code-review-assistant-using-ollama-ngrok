/**
 * @file ConsoleMenu.h
 * @brief User interface definition for the console application.
 * @details This file defines the static methods responsible for rendering the
 * command-line menu, capturing user input, and mapping choices to application logic.
 */

#ifndef _CONSOLEMENU_H
#define _CONSOLEMENU_H

#include "common/Types.h"

/**
 * @class ConsoleMenu
 * @brief Static utility class for Console UI interactions.
 *
 * This class handles all direct interaction with the standard output and input.
 * It presents options to the user and converts raw input into domain-specific types.
 */
class ConsoleMenu {
public:
    /**
     * @brief Displays the main application menu to standard output.
     *
     * Prints the available review modes (e.g., Security, Performance, Clean Code)
     * and instructions on how to select them.
     */
    static void showMainMenu();

    /**
     * @brief Captures the user's menu selection.
     *
     * Reads an integer value from standard input. It may include basic validation
     * to ensure the input is a number.
     *
     * @return int The raw integer choice entered by the user.
     */
    static int getChoice();

    /**
     * @brief Converts a raw integer input into a specific ReviewMode.
     *
     * Maps the user's integer selection (e.g., 1, 2, 3) to the corresponding
     * `ReviewMode` enum value used by the internal logic.
     *
     * @param choice The integer input received from `getChoice()`.
     * @return ReviewMode The corresponding enum value. Defaults to a standard mode if the input is invalid.
     */
    static ReviewMode choiceParser(int choice);
};

#endif // _CONSOLEMENU_H