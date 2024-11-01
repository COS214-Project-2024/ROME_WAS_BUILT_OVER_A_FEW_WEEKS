#ifndef CITY_MAP_H
#define CITY_MAP_H

#include <vector>

class CityHall;
class CityStructure;
class CommercialBuilding;
class IndustrialBuilding;
class ResidentialComplex;
class ResidentialComponent;
class Plant;
class Landmark;
class Road;


class CityMap {
    private: 
        // 2D array of CityStructures using vector
        std::vector<std::vector<CityStructure*> > map;
        CityHall* cityHall;
        int width;
        int height;
    public:
        CityMap();
        CityMap(int width, int height);
        ~CityMap();
        std::vector<std::vector<CityStructure*> > getMap();

        void setCityHall(CityHall* cityHall);

        bool addStructure(int x, int y, CityStructure* structure);
        void addBuilding(CityStructure* originator); // INCREASE TRAFFIC

        void addRoad(Road* originator);  // DECREASE TRAFFIC
        void addResidentialComplex(ResidentialComplex* originator); // INCREASE TRAFFIC AND AFFECTS SATISFACTION
        void addCommercialBuilding(CommercialBuilding* originator); // INCREASE TRAFFIC AND AFFECTS SATISFACTION
        void addIndustrialBuilding(Plant* originator); // INCREASE TRAFFIC AND AFFECTS SATISFACTION
        void addLandmark(Landmark* originator); // INCREASE TRAFFIC AND AFFECTS SATISFACTION
        // void addPlant(Plant* originator); // INCREASE TRAFFIC AND AFFECTS SATISFACTION

        void removeStructure(int x, int y);
        void removeBuilding(CityStructure* originator); // DECREASE TRAFFIC

        void removeRoad(Road* originator); // DECREASE TRAFFIC
        void removeResidentialComplex(ResidentialComplex* originator); // DECREASE TRAFFIC AND AFFECTS SATISFACTION
        void removeCommercialBuilding(CommercialBuilding* originator); // DECREASE TRAFFIC AND AFFECTS SATISFACTION
        void removeIndustrialBuilding(Plant* originator); // DECREASE TRAFFIC AND AFFECTS SATISFACTION
        void removeLandmark(Landmark* originator); // DECREASE TRAFFIC AND AFFECTS SATISFACTION
        // void removePlant(Plant* originator); // DECREASE TRAFFIC AND AFFECTS SATISFACTION

        void addResidentialComponent(ResidentialComponent* residential);
        void removeResidentialComponent(ResidentialComponent* residential);
        void aResidentialComponentChangedItsSatifaction(int oldSatisfaction, int newSatisfaction);

};

#endif