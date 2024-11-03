#ifndef WastePlant_h
#define WastePlant_h

#include "PlantDecorator.h"
class PlantDecorator;

class WastePlant : public PlantDecorator {
    public:
        WastePlant(Plant* plant) : PlantDecorator(plant) {this->plant = plant;};
        virtual ~WastePlant() {};
        int getRadiusOfEffect() { return plant->getRadiusOfEffect() + 1; };
        string getPlantType();
        string setWastePlant();
};

#endif