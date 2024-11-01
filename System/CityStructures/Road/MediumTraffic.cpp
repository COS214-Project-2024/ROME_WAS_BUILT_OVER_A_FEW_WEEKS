#include "MediumTraffic.h"
#include "Road.h"

void MediumTraffic::adjustTrafficImpact(Road* road)
{
    cout << "Medium traffic in surrounding structures" << endl;
}

int MediumTraffic::getTrafficLevel() const
{
    return 2;
}