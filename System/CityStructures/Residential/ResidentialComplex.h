#ifndef RESIDENTIAL_COMPLEX_H
#define RESIDENTIAL_COMPLEX_H

#include <vector>

#include "ResidentialComponent.h"

class CityMap;
class ResidentialComponent;

class ResidentialComplex : public ResidentialComponent {
    private:
        std::vector<ResidentialComponent*> residentialComponents;

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
    public:
        ResidentialComplex(ResidentialComponent* residential);
        ~ResidentialComplex();
        std::string getStructureType();

        bool placeStructure(int x, int y, CityMap* cityMap);
        void newRoadWasAdded();
        void newCommercialBuildingWasAdded();
        void newIndustrialBuildingWasAdded();
        void newLandmarkWasAdded();

        void removeStructure();
        void roadWasRemoved();
        void commercialBuildingWasRemoved();
        void industrialBuildingWasRemoved();
        void landmarkWasRemoved();

        int getCapacity(); // Retrieves the member variable capacity instead of recalculating it

        void addResidentialComponent(ResidentialComponent* residential);
        void removeResidentialComponent(ResidentialComponent* residential);
        int calculateCapacity();
        int getCost();

        int calculateTrafficSatisfaction();
        int calculateSatisfaction();

        void printResidentialComplexState();
};

#endif