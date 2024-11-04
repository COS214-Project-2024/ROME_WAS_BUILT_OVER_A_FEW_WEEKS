#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
using namespace std;

#include "IndustrialBuilding.h"

/**
 * @class Warehouse
 * @brief Represents a warehouse as an industrial building.
 *
 * The `Warehouse` class inherits from `IndustrialBuilding` and defines the 
 * specific characteristics and behaviors of a warehouse.
 */
class Warehouse : public IndustrialBuilding {
public:
    /**
     * @brief Constructs a Warehouse with default costs.
     * The default cost is set to 1000, with wood, steel, and concrete costs initialized to 0.
     */
    Warehouse() { cost = 1000; woodCost = 0; steelCost = 0; concreteCost = 0; }

    /**
     * @brief Destroys the Warehouse object.
     */
    virtual ~Warehouse();

    /**
     * @brief Places the warehouse structure at the specified location.
     * @param x The x-coordinate for placement.
     * @param y The y-coordinate for placement.
     * @param cityMap Pointer to the `CityMap` object where the structure will be placed.
     * @return True if the structure is successfully placed, false otherwise.
     */
    bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Removes the warehouse structure from the city map.
     * @return True if the structure is successfully removed, false otherwise.
     */
    bool removeStructure();
};

#include "IndustrialBuilding.h"

#endif // WAREHOUSE_H
