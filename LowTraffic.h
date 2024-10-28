#ifndef LOWTRAFFIC_H
#define LOWTRAFFIC_H

#include "TrafficState.h"
#include <iostream>
using namespace std;

class LowTraffic : public TrafficState
{
    public:
    void handleNewlyAddedBuilding(Road* road) override;
    void calculateTraffic(Road* road) override;
};

#endif