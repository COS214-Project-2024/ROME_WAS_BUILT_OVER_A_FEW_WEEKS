#ifndef BUILDING_ADDED_H
#define BUILDING_ADDED_H

#include "CheckAdjacent.h"
#include "../CityStructures/CityStructure.h"

/**
 * @class BuildingAdded
 * @brief Represents an action that occurs when a building is added to the map.
 *
 * BuildingAdded performs an action on a 2D map by notifying the city structure
 * at a specified location that a building has been removed from that position.
 * This class inherits from CheckAdjacent.
 */
class BuildingAdded : public CheckAdjacent {
public:
    /**
     * @brief Executes the action of marking a building as removed at a specific location.
     *
     * This function modifies the specified cell in the map by calling `buildingWasRemoved()`
     * on the `CityStructure` located at (x, y), indicating that a building was removed
     * at this position.
     *
     * @param map 2D vector representing the city map with `CityStructure` pointers.
     * @param x The x-coordinate of the building's location.
     * @param y The y-coordinate of the building's location.
     */
    void performAction(std::vector<std::vector<CityStructure*>> map, int x, int y) {
        map.at(y).at(x)->buildingWasRemoved();
    }
};

#endif // BUILDING_ADDED_H