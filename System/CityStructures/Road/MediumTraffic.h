#ifndef MEDIUMTRAFFIC_H
#define MEDIUMTRAFFIC_H

#include "TrafficState.h"
#include "Road.h"
#include <iostream>
using namespace std;

/**
 * @class MediumTraffic
 * @brief Represents a medium traffic state for a road.
 *
 * The `MediumTraffic` class implements the behavior of medium traffic conditions,
 * adjusting traffic impact on a road and providing the current traffic level.
 */
class MediumTraffic : public TrafficState
{
public:
    /**
     * @brief Adjusts the traffic impact on the given road.
     * @param road Pointer to the `Road` object to adjust.
     */
    void adjustTrafficImpact(Road* road) override;

    /**
     * @brief Gets the current traffic level.
     * @return An integer representing the traffic level.
     */
    int getTrafficLevel() const override;
};

#endif // MEDIUMTRAFFIC_H
