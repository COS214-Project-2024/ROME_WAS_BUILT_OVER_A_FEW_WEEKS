#ifndef BUILDING_REMOVED_H
#define BUILDING_REMOVED_H

#include "CheckAdjacent.h"
#include "../CityStructures/CityStructure.h"

/**
 * @class BuildingRemoved
 * @brief Represents an action that occurs when a building is removed from the map.
 *
 * BuildingRemoved performs an action on a 2D map by notifying the city structure
 * at a specified location that a new building has been added at that position.
 * This class inherits from CheckAdjacent.
 */
class BuildingRemoved : public CheckAdjacent {
public:
    /**
     * @brief Executes the action of marking a new building as added at a specific location.
     *
     * This function modifies the specified cell in the map by calling `newBuildingWasAdded()`
     * on the `CityStructure` located at (x, y), indicating that a building was added
     * at this position.
     *
     * @param map 2D vector representing the city map with `CityStructure` pointers.
     * @param x The x-coordinate of the building's location.
     * @param y The y-coordinate of the building's location.
     */
    void performAction(std::vector<std::vector<CityStructure*>> map, int x, int y) {
        map.at(y).at(x)->newBuildingWasAdded();
    }
};

#endif // BUILDING_REMOVED_H