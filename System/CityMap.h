#ifndef CITY_MAP_H
#define CITY_MAP_H

#include <vector>


class CityHall;
class CityStructure;
class CommercialBuilding;
class IndustrialBuilding;
class ResidentialComplex;
class ResidentialComponent;
class Warehouse;
class Plant;
class Landmark;
class Road;
class Factory;


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
        void addPlant(Plant* originator); // INCREASE TRAFFIC AND AFFECTS SATISFACTION
        void addIndustrialBuilding(IndustrialBuilding* originator); // INCREASE TRAFFIC AND AFFECTS SATISFACTION
        void addWarehouse(Warehouse* originator); // INCREASE TRAFFIC AND INCREASE STORAGE CAPACITY
        void addLandmark(Landmark* originator); // INCREASE TRAFFIC AND AFFECTS SATISFACTION
        void addFactory(Factory* originator); // INCREASE TRAFFIC AND INCREASE NUMBER OF FACTORIES
        
        bool checkResidentialComponent(ResidentialComponent* residential, CityMap* citcheckCityMapyMap);
        
        bool removeStructure(int x, int y);
        void removeBuilding(CityStructure* originator); // DECREASE TRAFFIC

        void removeRoad(Road* originator); // DECREASE TRAFFIC
        void removeResidentialComplex(ResidentialComplex* originator); // DECREASE TRAFFIC AND AFFECTS SATISFACTION
        void removeCommercialBuilding(CommercialBuilding* originator); // DECREASE TRAFFIC AND AFFECTS SATISFACTION
        void removeIndustrialBuilding(IndustrialBuilding* originator); // DECREASE TRAFFIC AND AFFECTS SATISFACTION
        void removeLandmark(Landmark* originator); // DECREASE TRAFFIC AND AFFECTS SATISFACTION
        void removePlant(Plant* originator); // DECREASE TRAFFIC AND AFFECTS SATISFACTION
        void removeWarehouse(Warehouse* originator); // DECREASE TRAFFIC AND DECREASE STORAGE CAPACITY
        void removeFactory(Factory* originator); // DECREASE TRAFFIC AND DECREASE NUMBER OF FACTORIES

        void addResidentialComponent(ResidentialComponent* residential);
        void removeResidentialComponent(ResidentialComponent* residential);
        void aResidentialComponentChangedItsSatifaction(int oldSatisfaction, int newSatisfaction);

        void generateResources(Factory* factory);

};

#endif