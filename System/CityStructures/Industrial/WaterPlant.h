#ifndef WaterPlant_h
#define WaterPlant_h

#include "PlantDecorator.h"
class PlantDecorator;

class WaterPlant : public PlantDecorator {
    public:
        WaterPlant(Plant* plant) : PlantDecorator(plant) {this->plant = plant;};
        virtual ~WaterPlant() {};
        int getRadiusOfEffect() { return plant->getRadiusOfEffect() + 1; };
        string getPlantType();
        string setWaterPlant();
};

#endif