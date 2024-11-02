#ifndef SewagePlant_h
#define SewagePlant_h

#include "PlantDecorator.h"
class PlantDecorator;

class SewagePlant : public PlantDecorator {
    public:
        SewagePlant(Plant* plant) : PlantDecorator(plant) {this->plant = plant;};
        virtual ~SewagePlant() {};
        int getRadiusOfEffect() { return plant->getRadiusOfEffect() + 1; };
<<<<<<< HEAD
        bool placeStructure(int x, int y, CityMap* cityMap) { plant->placeStructure(x, y, cityMap); };
=======
>>>>>>> origin/JM-PlantMediator
        string getPlantType();
        string setSewagePlant();
};

#endif