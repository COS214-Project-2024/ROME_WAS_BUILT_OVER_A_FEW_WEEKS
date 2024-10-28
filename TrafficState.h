#ifndef TRAFFICSTATE_H
#define TRAFFICSTATE_H

#include <iostream>
#include <string>

class Road;

class TrafficState
{
    public:
    virtual ~TrafficState() = default;
    virtual void calculateTraffic(Road* road) = 0;
    virtual void handleNewlyAddedBuilding(Road* road) = 0;
};

#endif