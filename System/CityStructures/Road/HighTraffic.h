#ifndef HIGHTRAFFIC_H
#define HIGHTRAFFIC_H

#include "TrafficState.h"
#include "Road.h"
#include <iostream>
using namespace std;

/**
 * @class HighTraffic
 * @brief Represents a high traffic state for a road.
 *
 * The `HighTraffic` class implements the behavior of high traffic conditions,
 * adjusting traffic impact on a road and providing the current traffic level.
 */
class HighTraffic : public TrafficState
{
public:
    /**
     * @brief Constructs a `HighTraffic` object.
     */
    HighTraffic();

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

#endif // HIGHTRAFFIC_H
