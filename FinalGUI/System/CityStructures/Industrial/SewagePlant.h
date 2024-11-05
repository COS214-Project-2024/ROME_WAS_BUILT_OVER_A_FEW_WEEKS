#ifndef SewagePlant_h
#define SewagePlant_h

#include "PlantDecorator.h"
class PlantDecorator;
class ResidentialComplex;

class SewagePlant : public PlantDecorator {
    public:
        SewagePlant(Plant* plant);
        virtual ~SewagePlant();
        bool placeStructure(int x, int y, CityMap* cityMap);
        bool removeStructure();
        void newResidentialComplexWasAdded(ResidentialComplex* complex);
        int getRadiusOfEffect();
        string getPlantType();
        string setSewagePlant();
};

#endif