#ifndef WaterPlant_h
#define WaterPlant_h

#include "PlantDecorator.h"
class PlantDecorator;

class WaterPlant : public PlantDecorator {
    public:
        WaterPlant(Plant* plant) : PlantDecorator(plant) {this->plant = plant;};
        virtual ~WaterPlant() {};
        int getRadiusOfEffect() { return plant->getRadiusOfEffect() + 1; };
        void placeStructure(int x, int y, CityMap* cityMap) { plant->placeStructure(x, y, cityMap); };
        string getPlantType();
        string setWaterPlant();
};

#endif