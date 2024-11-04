#ifndef PANTHEON_H
#define PANTHEON_H

#include "Landmark.h"
#include <string>

/**
 * @class Pantheon
 * @brief Represents a Pantheon, which is a type of Landmark.
 *
 * The Pantheon class provides functionality specific to a pantheon, with a high construction cost and large radius.
 */
class Pantheon : public Landmark {
private:
    static const int DEFAULT_PANTHEON_COST = 1000000; /**< Default cost for constructing a pantheon. */
    static const int DEFAULT_PANTHEON_RADIUS = 10;    /**< Default radius of effect for a pantheon. */

public:
    /**
     * @brief Constructs a Pantheon object.
     */
    Pantheon();

    /**
     * @brief Destroys the Pantheon object.
     */
    ~Pantheon();

    /**
     * @brief Gets the type of this landmark as a string.
     * @return A string representing the type of the landmark.
     */
    std::string getLandmarkType();
};

#endif // PANTHEON_H
