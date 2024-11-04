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
        int woodCost;
        int steelCost;
        int concreteCost;
    public:
        CityStructure();
        virtual ~CityStructure();
        virtual std::string getStructureType() = 0;

        virtual bool placeStructure(int x, int y, CityMap* cityMap);
        virtual bool removeStructure();

        virtual void newRoadWasAdded(){} ; // only affects residential complexes
        virtual void newBuildingWasAdded(){}; // only affects roads
        virtual void newResidentialComplexWasAdded(ResidentialComplex* complex){}; // only affects roads
        virtual void newCommercialBuildingWasAdded(){}; // only affects residential complexes
         // virtual void newIndustrialBuildingWasAdded(){}; // only affects residential complexes
        virtual void newPowerPlantWasAdded(){}; // only affects residential complexes
        virtual void newWaterPlantWasAdded(){}; // only affects residential complexes
        virtual void newWastePlantWasAdded(){}; // only affects residential complexes
        virtual void newSewagePlantWasAdded(){}; // only affects residential complexes
        virtual void newLandmarkWasAdded(){}; // only affects residential complexes

        virtual void roadWasRemoved(){}; // only affects residential complexes
        virtual void buildingWasRemoved(){}; // only affects roads
        virtual void commercialBuildingWasRemoved(){}; // only affects residential complexes
        // virtual void industrialBuildingWasRemoved(){}; // only affects residential complexes
        virtual void powerPlantWasRemoved(){}; // only affects residential complexes
        virtual void waterPlantWasRemoved(){}; // only affects residential complexes
        virtual void wastePlantWasRemoved(){}; // only affects residential complexes
        virtual void sewagePlantWasRemoved(){}; // only affects residential complexes
        virtual void landmarkWasRemoved(){}; // only affects residential complexes

        int getX();
        int getY();
        virtual int getCost();
        int getWoodCost();
        int getSteelCost();
        int getConcreteCost();
        

};

#endif