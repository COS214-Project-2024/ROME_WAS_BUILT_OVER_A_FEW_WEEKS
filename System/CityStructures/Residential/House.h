#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuilding.h"

/**
 * @class House
 * @brief Represents a house as a type of residential building.
 *
 * The `House` class inherits from `ResidentialBuilding` and defines the properties 
 * specific to houses, including capacity and cost.
 */
class House : public ResidentialBuilding {
private:
    static const int DEFAULT_HOUSE_CAPACITY = 5; ///< Default capacity for a house.
    static const int DEFAULT_HOUSE_COST = 1000;   ///< Default cost for a house.
public:
    /**
     * @brief Constructs a House object.
     */
    House();

    /**
     * @brief Destroys the House object.
     */
    ~House();

    /**
     * @brief Gets the type of the residential building.
     * @return A string representing the residential building type.
     */
    std::string getResidentialBuildingType() override;
};

#endif // HOUSE_H
