#ifndef LOWTRAFFIC_H
#define LOWTRAFFIC_H

#include "TrafficState.h"
#include <iostream>
using namespace std;

/**
 * @class LowTraffic
 * @brief Represents a low traffic state for a road.
 *
 * The `LowTraffic` class implements the behavior of low traffic conditions,
 * adjusting traffic impact on a road and providing the current traffic level.
 */
class LowTraffic : public TrafficState
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

#endif // LOWTRAFFIC_H
