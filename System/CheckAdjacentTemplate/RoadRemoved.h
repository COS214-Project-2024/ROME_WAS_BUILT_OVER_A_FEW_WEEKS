#ifndef ROAD_REMOVED_H
#define ROAD_REMOVED_H

#include "CheckAdjacent.h"
#include "../CityStructures/CityStructure.h"
#include "../CityMap.h"

/**
 * @class RoadRemoved
 * @brief Represents an action to be performed when a road is removed from the city map.
 *
 * The `RoadRemoved` class provides functionality to mark a specified location on the map
 * as having a road removed. It inherits from `CheckAdjacent` and overrides the `performAction` method.
 */
class RoadRemoved : public CheckAdjacent {
public:
    /**
     * @brief Executes the action of marking a road as removed at a specific location.
     *
     * This function modifies the specified cell in the map by calling `roadWasRemoved()`
     * on the `CityStructure` located at (x, y), indicating that a road was removed from this position.
     *
     * @param map 2D vector representing the city map with `CityStructure` pointers.
     * @param x The x-coordinate of the road's location.
     * @param y The y-coordinate of the road's location.
     */
    void performAction(std::vector<std::vector<CityStructure*>> map, int x, int y) override {
        map.at(y).at(x)->roadWasRemoved();
    }
};

#endif // ROAD_REMOVED_H
