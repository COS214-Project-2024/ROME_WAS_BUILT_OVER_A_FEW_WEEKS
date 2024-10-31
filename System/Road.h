#ifndef ROAD_H
#define ROAD_H

#include "CityStructure.h"
#include "TrafficState.h"
#include "ResidentialComplex.h"

class ResidentialComplex;

class CityMap;

class Road : public CityStructure {
    private:
        TrafficState* trafficState; // USE STATE DP in future
    public:
        Road();
        ~Road();
        std::string getStructureType();

        void placeStructure(int x, int y, CityMap* cityMap);
        void newBuildingWasAdded();

        void removeStructure();
        void buildingWasRemoved();

        void calculateTraffic();

        void setTrafficState(TrafficState* trafficState);
        int getTrafficLevel();
        

        
};

#endif