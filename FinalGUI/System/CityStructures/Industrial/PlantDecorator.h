#ifndef PLANT_DECORATOR_H
#define PLANT_DECORATOR_H

#include <iostream>

#include "Plant.h"
class Plant;

class PlantDecorator : public Plant {
    protected:
        Plant* plant;
    public:
        PlantDecorator();
        PlantDecorator(Plant* plant);
        virtual ~PlantDecorator();
        int getRadiusOfEffect();
        virtual bool placeStructure(int x, int y, CityMap* cityMap) = 0;
        virtual bool removeStructure() = 0;
        virtual string getPlantType();

};


#endif 