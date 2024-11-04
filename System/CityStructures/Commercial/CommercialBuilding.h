#ifndef COMMERCIAL_BUILDING_H
#define COMMERCIAL_BUILDING_H

#include "../CityStructure.h"
#include "../../CityMap.h"
#include "../Residential/ResidentialComplex.h"

class ResidentialComplex;
class CityMap;

/**
 * @class CommercialBuilding
 * @brief Represents a commercial building within the city.
 *
 * The `CommercialBuilding` class provides properties and functionality specific to commercial structures,
 * including radius of effect and interaction with `CityMap` and `ResidentialComplex`.
 */
class CommercialBuilding : public CityStructure {
private:
    int radiusOfEffect; /**< Radius of effect of the commercial building on nearby structures. */

public:
    /**
     * @brief Constructs a `CommercialBuilding` with a specified radius of effect.
     * @param radiusOfEffect The radius of effect of the commercial building.
     */
    CommercialBuilding(int radiusOfEffect);

    /**
     * @brief Virtual destructor for `CommercialBuilding`.
     */
    virtual ~CommercialBuilding();

    /**
     * @brief Gets the type of structure as a string.
     * @return A string indicating the type of structure, such as "CommercialBuilding".
     */
    std::string getStructureType();

    /**
     * @brief Gets the radius of effect of the commercial building.
     * @return The radius of effect as an integer.
     */
    int getRadiusOfEffect();

    /**
     * @brief Places the commercial building at a specific location on the city map.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap A pointer to the city map where the structure is to be placed.
     * @return `true` if placement is successful, `false` otherwise.
     */
    bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the commercial building from the city map.
     * @return `true` if removal is successful, `false` otherwise.
     */
    bool removeStructure();

    /**
     * @brief Notifies the commercial building that a new residential complex has been added.
     * @param complex A pointer to the new `ResidentialComplex`.
     */
    void newResidentialComplexWasAdded(ResidentialComplex* complex);
};

#endif // COMMERCIAL_BUILDING_H
