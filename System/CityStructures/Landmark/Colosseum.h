#ifndef COLLOSSEUM_H
#define COLLOSSEUM_H

#include "Landmark.h"
#include <string>

/**
 * @class Colosseum
 * @brief Represents a Colosseum, a specific type of landmark.
 *
 * The `Colosseum` class provides functionality specific to a colosseum, with a default cost and radius.
 */
class Colosseum : public Landmark {
private:
    static const int DEFAULT_COLOSSEUM_COST = 100000; /**< Default construction cost for a colosseum. */
    static const int DEFAULT_COLOSSEUM_RADIUS = 5;    /**< Default radius of effect for a colosseum. */

public:
    /**
     * @brief Constructs a `Colosseum` object with default properties.
     */
    Colosseum();

    /**
     * @brief Destroys the `Colosseum` object.
     */
    ~Colosseum();

    /**
     * @brief Gets the type of this landmark as a string.
     * @return A string representing the type of the landmark.
     */
    std::string getLandmarkType();
};

#endif // COLLOSSEUM_H
