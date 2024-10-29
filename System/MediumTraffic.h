
#ifndef MEDIUMTRAFFIC_H
#define MEDIUMTRAFFIC_H

#include "TrafficState.h"
#include "Road.h"
#include <iostream>
using namespace std;

class MediumTraffic : public TrafficState
{
    public:
    void adjustTrafficImpact(Road* road) override;
    int getTrafficLevel() const override;
};

#endif
