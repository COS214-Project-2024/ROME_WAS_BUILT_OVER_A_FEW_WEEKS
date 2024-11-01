#include "LowTraffic.h"
#include "Road.h"

void LowTraffic::adjustTrafficImpact(Road* road)
{
    cout << "Low traffic in surrounding structures" << endl;
}

int LowTraffic::getTrafficLevel() const
{
    return 1;
}