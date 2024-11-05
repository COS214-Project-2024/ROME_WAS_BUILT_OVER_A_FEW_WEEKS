#ifndef PowerPlant_h
#define PowerPlant_h

#include "PlantDecorator.h"
class PlantDecorator;
class ResidentialComplex;

class PowerPlant : public PlantDecorator {
    public:
        PowerPlant(Plant* plant);
        virtual ~PowerPlant();
        bool placeStructure(int x, int y, CityMap* cityMap);
        bool removeStructure();
        void newResidentialComplexWasAdded(ResidentialComplex* complex);
        int getRadiusOfEffect();
        string getPlantType();
        string setPowerPlant();
};

#endif