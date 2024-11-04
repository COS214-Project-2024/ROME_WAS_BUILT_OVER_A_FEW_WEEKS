#ifndef ROAD_ADDED_H
#define ROAD_ADDED_H

#include "CheckAdjacent.h"
#include "../CityStructures/CityStructure.h"

/**
 * @class RoadAdded
 * @brief Represents an action to be performed when a new road is added to the city map.
 *
 * The `RoadAdded` class provides functionality to mark a specified location on the map
 * as having a new road. It inherits from `CheckAdjacent` and overrides `performAction`.
 */
class RoadAdded : public CheckAdjacent {
public:
    /**
     * @brief Executes the action of marking a new road at a specific location.
     *
     * This function modifies the specified cell in the map by calling `newRoadWasAdded()`
     * on the `CityStructure` located at (x, y), indicating that a road was added at this position.
     *
     * @param map 2D vector representing the city map with `CityStructure` pointers.
     * @param x The x-coordinate of the road's location.
     * @param y The y-coordinate of the road's location.
     */
    void performAction(std::vector<std::vector<CityStructure*>> map, int x, int y) override {
        map.at(y).at(x)->newRoadWasAdded();
    }
};

#endif // ROAD_ADDED_H