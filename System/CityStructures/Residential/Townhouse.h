#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "ResidentialBuilding.h"

/**
 * @class Townhouse
 * @brief Represents a townhouse as a type of residential building.
 *
 * The `Townhouse` class inherits from `ResidentialBuilding` and defines the properties 
 * specific to townhouses, including capacity and cost.
 */
class Townhouse : public ResidentialBuilding {
private:
    static const int DEFAULT_TOWNHOUSE_CAPACITY = 15; ///< Default capacity for a townhouse.
    static const int DEFAULT_TOWNHOUSE_COST = 5000;   ///< Default cost for a townhouse.
public:
    /**
     * @brief Constructs a Townhouse object.
     */
    Townhouse();

    /**
     * @brief Destroys the Townhouse object.
     */
    ~Townhouse();

    /**
     * @brief Gets the type of the residential building.
     * @return A string representing the residential building type.
     */
    std::string getResidentialBuildingType();
};

#endif // TOWNHOUSE_H
