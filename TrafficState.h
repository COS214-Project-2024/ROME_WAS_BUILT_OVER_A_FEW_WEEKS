#ifndef TRAFFICSTATE_H
#define TRAFFICSTATE_H

#include <iostream>
#include <string>

class Road;

class TrafficState
{
    public:
    virtual ~TrafficState() = default;
    virtual void adjustTrafficImpact(Road* road) = 0;
    virtual int getTrafficLevel() const = 0;
};

#endif
