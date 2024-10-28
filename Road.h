#ifndef ROAD_H
#define ROAD_H

#include "CityStructure.h"
#include "TrafficState.h"

class Road : public CityStructure {
    private:
        TrafficState* trafficState; // USE STATE DP in future
    public:
        Road();
        void placeStructure(int x, int y, CityMap* cityMap);
        void removeStructure();
        void calculateTraffic();
        ~Road();
        void newBuildingWasAdded();
        void setTrafficState(TrafficState* state);
        
};

#endif