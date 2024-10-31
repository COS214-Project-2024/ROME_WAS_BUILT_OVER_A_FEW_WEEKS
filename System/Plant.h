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
        Plant() {radiusOfEffect = 2;};
        virtual ~Plant(){};
        int getRadiusOfEffect() { return radiusOfEffect; };
        void placeStructure(int x, int y, CityMap* cityMap) {};
        virtual string getPlantType(){ return plantType;};
        
};

#endif