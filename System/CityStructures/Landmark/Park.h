#ifndef PARK_H
#define PARK_H

#include "Landmark.h"
#include <string>

/**
 * @class Park
 * @brief Represents a Park, which is a type of Landmark.
 *
 * The Park class provides functionality specific to parks, including a default cost and radius.
 */
class Park : public Landmark {
private:
    static const int DEFAULT_PARK_COST = 10000;    /**< Default cost for constructing a park. */
    static const int DEFAULT_PARK_RADIUS = 3;      /**< Default radius of effect for a park. */

public:
    /**
     * @brief Constructs a Park object.
     */
    Park();

    /**
     * @brief Destroys the Park object.
     */
    ~Park();

    /**
     * @brief Gets the type of this landmark as a string.
     * @return A string representing the type of the landmark.
     */
    std::string getLandmarkType();
};

#endif // PARK_H
