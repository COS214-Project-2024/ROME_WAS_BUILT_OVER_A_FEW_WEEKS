#ifndef CITY_STRUCTURE_H
#define CITY_STRUCTURE_H

#include <string>

class ResidentialComplex;
class CityMap;

class CityStructure {
    protected: 
        int x;
        int y;
        CityMap* cityMap; // MEDIATOR
        int cost;
    public:
        CityStructure();
        virtual ~CityStructure();
        virtual std::string getStructureType() = 0;

        virtual void placeStructure(int x, int y, CityMap* cityMap);
        virtual void removeStructure();

        virtual void newRoadWasAdded(){} ; // only affects residential complexes
        virtual void newBuildingWasAdded(){}; // only affects roads
        virtual void newResidentialComplexWasAdded(ResidentialComplex* complex){}; // only affects roads
        virtual void newCommercialBuildingWasAdded(){}; // only affects residential complexes
        virtual void newIndustrialBuildingWasAdded(){}; // only affects residential complexes
        virtual void newLandmarkWasAdded(){}; // only affects residential complexes

        virtual void roadWasRemoved(){}; // only affects residential complexes
        virtual void buildingWasRemoved(){}; // only affects roads
        virtual void commercialBuildingWasRemoved(){}; // only affects residential complexes
        virtual void industrialBuildingWasRemoved(){}; // only affects residential complexes
        virtual void landmarkWasRemoved(){}; // only affects residential complexes

        int getX();
        int getY();
        virtual int getCost();

};

#endif