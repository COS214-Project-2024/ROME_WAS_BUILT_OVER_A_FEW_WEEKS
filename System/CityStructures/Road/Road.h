#ifndef ROAD_H
#define ROAD_H

#include "../CityStructure.h"

class TrafficState;
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
        

        static sf::Texture* texture1;
        static sf::Texture* texture2;
        static sf::Texture* texture3;
        static sf::Texture* texture4;

        
};

#endif