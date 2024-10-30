#ifndef CITY_MAP_H
#define CITY_MAP_H

#include "CityStructure.h"
#include "CommercialBuilding.h"
#include "IndustrialBuilding.h"
#include "Plant.h"
#include "Landmark.h"
#include "Road.h"

#include <vector>

class CityMap {
    private: 
        // 2D array of CityStructures using vector
        std::vector<std::vector<CityStructure*> > map;
        int width;
        int height;
    public:
        CityMap();
        CityMap(int width, int height);
        std::vector<std::vector<CityStructure*> > getMap();

        void addStructure(int x, int y, CityStructure* structure);
        void addRoad(Road* originator);  // DECREASE TRAFFIC
        void addBuilding(CityStructure* originator); // INCREASE TRAFFIC
        void addCommercialBuilding(CommercialBuilding* originator); // INCREASE TRAFFIC AND AFFECTS SATISFACTION
        void addIndustrialBuilding(Plant* originator); // INCREASE TRAFFIC AND AFFECTS SATISFACTION
        void addLandmark(Landmark* originator); // INCREASE TRAFFIC AND AFFECTS SATISFACTION
        virtual void removeStructure(int x, int y) {};
        // void printMap();
        ~CityMap();
};

#endif