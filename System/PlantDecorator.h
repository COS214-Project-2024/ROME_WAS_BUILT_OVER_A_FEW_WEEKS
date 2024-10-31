#ifndef PLANT_DECORATOR_H
#define PLANT_DECORATOR_H

#include "Plant.h"
class Plant;

class PlantDecorator : public Plant {
    protected:
        Plant* plant;
    public:
        PlantDecorator(){};
        PlantDecorator(Plant* plant) : plant(plant) {this->plant = plant;};
        virtual ~PlantDecorator() {};
        int getRadiusOfEffect() { return plant->getRadiusOfEffect(); };
        void placeStructure(int x, int y, CityMap* cityMap) { plant->placeStructure(x, y, cityMap); };
        virtual string getPlantType(){return plantType;};

};


#endif 