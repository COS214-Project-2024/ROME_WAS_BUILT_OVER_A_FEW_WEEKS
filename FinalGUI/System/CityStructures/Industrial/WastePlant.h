#ifndef WastePlant_h
#define WastePlant_h

#include "PlantDecorator.h"
class PlantDecorator;
class ResidentialComplex;

class WastePlant : public PlantDecorator {
    public:
        WastePlant(Plant* plant);
        virtual ~WastePlant();
        bool placeStructure(int x, int y, CityMap* cityMap);
        bool removeStructure();
        void newResidentialComplexWasAdded(ResidentialComplex* complex);
        int getRadiusOfEffect();
        string getPlantType();
        string setWastePlant();
};

#endif

