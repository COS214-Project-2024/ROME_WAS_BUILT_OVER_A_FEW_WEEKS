#ifndef HIGHTRAFFIC_H
#define HIGHTRAFFIC_H

#include "TrafficState.h"
#include "Road.h"
#include <iostream>
using namespace std;

class HighTraffic : public TrafficState
{
    public:
    HighTraffic();
    void adjustTrafficImpact(Road* road) override;
    int getTrafficLevel() const override;
};

#endif