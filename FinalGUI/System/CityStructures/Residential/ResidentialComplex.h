#ifndef RESIDENTIAL_COMPLEX_H
#define RESIDENTIAL_COMPLEX_H

#include <vector>

#include "ResidentialComponent.h"

class CityMap;
class ResidentialComponent;

class ResidentialComplex : public ResidentialComponent {
    private:

        float trafficSatisfaction; // 15
        float EmploymentSatisfaction; //14
        float PowerSatisfaction; //14
        float WaterSatisfaction; //14
        float WasteSatisfaction; // 14
        float SewageSatisfaction; //14
        float HealthSatisfaction; //5
        float EducationSatisfaction; //5
        float safetySatisfaction; //5
        float bonusSatisfaction;

        float satisfaction; //total satisfaction of the complex
        int capacity; 
        int realCapacity;
    public:

        std::vector<ResidentialComponent*> residentialComponents;

        ResidentialComplex(ResidentialComponent* residential);
        ~ResidentialComplex();
        std::string getStructureType();

        bool placeStructure(int x, int y, CityMap* cityMap);
        void newRoadWasAdded();
        void newCommercialBuildingWasAdded();
        // void newIndustrialBuildingWasAdded();
        void newPowerPlantWasAdded();
        void newWaterPlantWasAdded();
        void newWastePlantWasAdded();
        void newSewagePlantWasAdded();
        void newLandmarkWasAdded();

        bool removeStructure();
        void roadWasRemoved();
        void commercialBuildingWasRemoved();
        // void industrialBuildingWasRemoved();
        void powerPlantWasRemoved();
        void waterPlantWasRemoved();
        void wastePlantWasRemoved();
        void sewagePlantWasRemoved();
        void landmarkWasRemoved();

        int getCapacity(); // Retrieves the member variable capacity instead of recalculating it

        void addResidentialComponent(ResidentialComponent* residential, CityMap* cityMap);
        void removeResidentialComponent(ResidentialComponent* residential);
        int calculateCapacity();
        int getCost();

        int calculateTrafficSatisfaction();
        int calculateSatisfaction();

        void printResidentialComplexState();

};

#endif