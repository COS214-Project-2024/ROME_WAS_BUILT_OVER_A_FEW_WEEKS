#ifndef CITY_STRUCTURE_H
#define CITY_STRUCTURE_H

class CityMap;

class CityStructure {
    protected: 
        int x;
        int y;
        CityMap* cityMap; // MEDIATOR
    public:
        CityStructure();
        virtual void placeStructure(int x, int y, CityMap* cityMap);
        virtual void removeStructure();
        virtual ~CityStructure();
        virtual void newRoadWasAdded(){} ; // only affects residential complexes
        virtual void newBuildingWasAdded(){}; // only affects roads
        virtual void newCommercialBuildingWasAdded(){}; // only affects residential complexes
        virtual void newIndustrialBuildingWasAdded(){}; // only affects residential complexes
        virtual void newLandmarkWasAdded(){}; // only affects residential complexes

        int getX();
        int getY();
};

#endif