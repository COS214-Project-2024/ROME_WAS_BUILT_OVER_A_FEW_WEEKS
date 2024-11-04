#ifndef ESTATE_H
#define ESTATE_H

#include "ResidentialBuilding.h"

/**
 * @class Estate
 * @brief Represents an estate as a type of residential building.
 *
 * The `Estate` class inherits from `ResidentialBuilding` and defines the properties 
 * specific to estates, including capacity and cost.
 */
class Estate : public ResidentialBuilding {
private:
    static const int DEFAULT_ESTATE_CAPACITY = 120; ///< Default capacity for an estate.
    static const int DEFAULT_ESTATE_COST = 10000;   ///< Default cost for an estate.
public:
    /**
     * @brief Constructs an Estate object.
     */
    Estate();

    /**
     * @brief Destroys the Estate object.
     */
    ~Estate();

    /**
     * @brief Gets the type of the residential building.
     * @return A string representing the residential building type.
     */
    std::string getResidentialBuildingType() override;
};

#endif // ESTATE_H
