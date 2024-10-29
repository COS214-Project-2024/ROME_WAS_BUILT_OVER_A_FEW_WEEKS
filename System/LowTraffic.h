#ifndef LOWTRAFFIC_H
#define LOWTRAFFIC_H

#include "TrafficState.h"
#include <iostream>
using namespace std;

class LowTraffic : public TrafficState
{
    public:
    void adjustTrafficImpact(Road* road) override;
    int getTrafficLevel() const override;
};

#endif