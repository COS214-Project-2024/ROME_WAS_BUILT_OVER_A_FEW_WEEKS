#ifndef WaterPlant_h
#define WaterPlant_h

#include "PlantDecorator.h"
class PlantDecorator;
class ResidentialComplex;

class WaterPlant : public PlantDecorator {
    public:
        WaterPlant(Plant* plant);
        virtual ~WaterPlant();
        int getRadiusOfEffect() ;
        bool placeStructure(int x, int y, CityMap* cityMap);
        bool removeStructure();
        void newResidentialComplexWasAdded(ResidentialComplex* complex);
        string getPlantType();
        string setWaterPlant();
};

#endif