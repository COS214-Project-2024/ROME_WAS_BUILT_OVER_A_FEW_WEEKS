#ifndef RESIDENTIAL_COMPLEX_H
#define RESIDENTIAL_COMPLEX_H

#include <vector>

#include "ResidentialComponent.h"

class ResidentialComplex : public ResidentialComponent {
    private:
        std::vector<ResidentialComponent*> residentialComponents;

        int trafficSatisfaction; // 15
        int EmploymentSatisfaction; //14
        int PowerSatisfaction; //14
        int WaterSatisfaction; //14
        int WasteSatisfaction; // 14
        int SewageSatisfaction; //14
        int HealthSatisfaction; //5
        int EducationSatisfaction; //5
        int safetySatisfaction; //5

        int satisfaction; //total satisfaction of the complex
        int capacity;
    public:
        ResidentialComplex(ResidentialComponent* residential);
        ~ResidentialComplex();

        void placeStructure(int x, int y, CityMap* cityMap);
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
        int calculateCapacity();

        int calculateTrafficSatisfaction();
        int calculateSatisfaction();
};

#endif