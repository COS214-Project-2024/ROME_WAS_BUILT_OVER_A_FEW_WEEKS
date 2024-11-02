#ifndef PLANT_H
#define PLANT_H
#include <string>
using namespace std;

#include "IndustrialBuilding.h"
class IndustrialBuilding;

class Plant : public IndustrialBuilding {
    protected:
        int radiusOfEffect;
        string plantType;
    public:
        Plant() {cost = 1000; woodCost = 100; steelCost = 100; concreteCost = 100;};
        Plant(int radiusOfEffect) : radiusOfEffect(radiusOfEffect) {};
        virtual ~Plant(){};
        int getRadiusOfEffect() { return radiusOfEffect; };
        bool placeStructure(int x, int y, CityMap* cityMap) {};
        virtual string getPlantType(){ return plantType;};
        
};

#endif