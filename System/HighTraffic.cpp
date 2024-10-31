#include "HighTraffic.h"
#include "Road.h"

void HighTraffic::adjustTrafficImpact(Road* road)
{
    cout << "High traffic in surrounding structures" << endl;
}

int HighTraffic::getTrafficLevel() const
{
    return 3;
}