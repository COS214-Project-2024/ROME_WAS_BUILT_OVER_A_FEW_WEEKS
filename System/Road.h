#ifndef ROAD_H
#define ROAD_H

#include "CityStructure.h"

class Road : public CityStructure {
    private:
        int trafficState; // USE STATE DP in future
    public:
        Road();
        void placeStructure(int x, int y, CityMap* cityMap);
        void removeStructure();
        void calculateTraffic();
        ~Road();
        void newBuildingWasAdded();

        
};

#endif