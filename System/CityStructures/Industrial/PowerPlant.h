#ifndef PowerPlant_h
#define PowerPlant_h

#include "PlantDecorator.h"
class PlantDecorator;

class PowerPlant : public PlantDecorator {
    public:
        PowerPlant(Plant* plant) : PlantDecorator(plant) {this->plant = plant;};
        virtual ~PowerPlant() {};
        int getRadiusOfEffect() { return plant->getRadiusOfEffect() + 1; };
        bool placeStructure(int x, int y, CityMap* cityMap) { plant->placeStructure(x, y, cityMap); };
        string getPlantType();
        string setPowerPlant();
};

#endif