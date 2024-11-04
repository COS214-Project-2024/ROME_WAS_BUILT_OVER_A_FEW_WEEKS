#ifndef APARTMENT_H
#define APARTMENT_H

#include "ResidentialBuilding.h"

/**
 * @class Apartment
 * @brief Represents an apartment as a type of residential building.
 *
 * The `Apartment` class inherits from `ResidentialBuilding` and defines the properties 
 * specific to apartments, including capacity and cost.
 */
class Apartment : public ResidentialBuilding {
private:
    static const int DEFAULT_APARTMENT_CAPACITY = 100; ///< Default capacity for an apartment.
    static const int DEFAULT_APARTMENT_COST = 10000;   ///< Default cost for an apartment.
public:
    /**
     * @brief Constructs an Apartment object.
     */
    Apartment();

    /**
     * @brief Destroys the Apartment object.
     */
    ~Apartment();

    /**
     * @brief Gets the type of the residential building.
     * @return A string representing the residential building type.
     */
    std::string getResidentialBuildingType() override;
};

#endif // APARTMENT_H
