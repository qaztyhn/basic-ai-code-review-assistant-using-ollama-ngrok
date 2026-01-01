#ifndef _TYPES_H
#define _TYPES_H
/**
 * @enum ReviewMode
 * @brief Enumeration of different code review modes.
 *
 * This enum defines the various modes in which a code review can be performed.
 * Each mode corresponds to a specific type of analysis or transformation
 * that the AI model should apply to the provided source code.
 */

enum class ReviewMode {
    ReviewOnly,
    Improve,
    Solution,
    Security,
    Performance,
    UnitTest,
    Comments
};


#endif