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
        Plant() {};
        Plant(int radiusOfEffect) : radiusOfEffect(radiusOfEffect) {};
        virtual ~Plant(){};
        int getRadiusOfEffect();
        void placeStructure(int x, int y, CityMap* cityMap);
        virtual string getPlantType();
        
};

#endif