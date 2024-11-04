#ifndef ROAD_H
#define ROAD_H

#include "../CityStructure.h"

class TrafficState;
class ResidentialComplex;
class CityMap;

/**
 * @class Road
 * @brief Represents a road structure in the city.
 *
 * The `Road` class inherits from `CityStructure` and includes functionality
 * for managing traffic states, placing and removing structures, and calculating traffic impact.
 */
class Road : public CityStructure {
private:
    TrafficState* trafficState; /**< Pointer to the current traffic state of the road. */

public:
    /**
     * @brief Constructs a `Road` object with a default traffic state.
     */
    Road();

    /**
     * @brief Destroys the `Road` object and cleans up resources.
     */
    ~Road();

    /**
     * @brief Gets the type of the structure as a string.
     * @return A string representing the type of the structure.
     */
    std::string getStructureType();

    /**
     * @brief Places the road structure at specified coordinates on the city map.
     * @param x The x-coordinate where the road is placed.
     * @param y The y-coordinate where the road is placed.
     * @param cityMap Pointer to the `CityMap` in which the structure is being placed.
     * @return `true` if the structure was successfully placed; otherwise `false`.
     */
    bool placeStructure(int x, int y, CityMap* cityMap);

    /**
     * @brief Notifies the road that a new building was added.
     */
    void newBuildingWasAdded();

    /**
     * @brief Removes the road structure from the city map.
     * @return `true` if the structure was successfully removed; otherwise `false`.
     */
    bool removeStructure();

    /**
     * @brief Notifies the road that a building was removed.
     */
    void buildingWasRemoved();

    /**
     * @brief Calculates the traffic impact based on the current traffic state.
     */
    void calculateTraffic();

    /**
     * @brief Sets the current traffic state for the road.
     * @param trafficState Pointer to the `TrafficState` to set.
     */
    void setTrafficState(TrafficState* trafficState);

    /**
     * @brief Gets the current traffic level.
     * @return An integer representing the traffic level.
     */
    int getTrafficLevel();
};

#endif // ROAD_H
