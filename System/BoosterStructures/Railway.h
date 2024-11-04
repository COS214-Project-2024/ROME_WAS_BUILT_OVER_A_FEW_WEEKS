#ifndef RAILWAY_H
#define RAILWAY_H

#include "BoosterStructures.h"

/**
 * @class Railway
 * @brief Represents a Railway structure that provides satisfaction boosts to the surrounding areas.
 *
 * Railway is a derived class of BoosterStructures and represents a railway system in the simulation,
 * which can provide specific enhancements to nearby structures or areas.
 */
class Railway : public BoosterStructures {
public:
    /**
     * @brief Constructs a Railway object.
     *
     * Initializes a new instance of the Railway class with default values.
     */
    Railway();
};

#endif // RAILWAY_H