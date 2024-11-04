#ifndef AIRPORT_H
#define AIRPORT_H

#include "BoosterStructures.h"

/**
 * @class Airport
 * @brief Represents an Airport structure that boosts surrounding areas in the simulation.
 *
 * The Airport class is a specialized type of BoosterStructure that, when placed on the map, 
 * provides unique effects or benefits to surrounding structures.
 */
class Airport : public BoosterStructures {
public:
    /**
     * @brief Constructs an Airport object.
     *
     * Initializes an instance of the Airport class, setting any necessary default values.
     */
    Airport();
};

#endif // AIRPORT_H
