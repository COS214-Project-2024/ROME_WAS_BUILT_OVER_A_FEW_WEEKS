#ifndef INDUSTRIAL_BUILDING_H
#define INDUSTRIAL_BUILDING_H

#include "../CityStructure.h"
#include "../../CityMap.h"

class CityMap;

/**
 * @class IndustrialBuilding
 * @brief Represents a generic industrial building.
 *
 * The `IndustrialBuilding` class inherits from `CityStructure` and 
 * provides a base for all industrial building types, managing common 
 * properties and behaviors such as structure placement and removal.
 */
class IndustrialBuilding : public CityStructure {
public:
    /**
     * @brief Constructs an IndustrialBuilding object with default properties.
     */
    IndustrialBuilding();

    /**
     * @brief Destroys the IndustrialBuilding object.
     */
    virtual ~IndustrialBuilding();

    /**
     * @brief Gets the type of the structure.
     * @return A string representing the structure type.
     */
    std::string getStructureType();

    /**
     * @brief Places the industrial building structure at the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the industrial building structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    virtual bool removeStructure();
};

#endif // INDUSTRIAL_BUILDING_H
