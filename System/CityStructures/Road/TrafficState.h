#ifndef TRAFFICSTATE_H
#define TRAFFICSTATE_H

#include <iostream>
#include <string>

class Road;

/**
 * @class TrafficState
 * @brief Abstract base class for different traffic states.
 *
 * The `TrafficState` class provides an interface for implementing various traffic states,
 * such as low, medium, and high traffic conditions.
 */
class TrafficState
{
public:
    /**
     * @brief Default constructor for `TrafficState`.
     */
    TrafficState() = default;

    /**
     * @brief Virtual destructor for `TrafficState`.
     */
    virtual ~TrafficState() = default;

    /**
     * @brief Adjusts the traffic impact on a given road.
     * @param road Pointer to the `Road` object to adjust.
     */
    virtual void adjustTrafficImpact(Road* road) = 0;

    /**
     * @brief Gets the current traffic level.
     * @return An integer representing the traffic level.
     */
    virtual int getTrafficLevel() const = 0;
};

#endif // TRAFFICSTATE_H
