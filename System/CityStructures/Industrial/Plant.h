#ifndef PLANT_H
#define PLANT_H
#include <string>
using namespace std;

#include "IndustrialBuilding.h"
class IndustrialBuilding;

class Plant : public IndustrialBuilding {
    protected:
        static const int DEFAULT_RADIUS_OF_EFFECT = 5;
        int radiusOfEffect;
        string plantType;
    public:
        Plant();
        virtual ~Plant();
        virtual int getRadiusOfEffect();
        virtual bool placeStructure(int x, int y, CityMap* cityMap);
        virtual bool removeStructure();
        virtual string getPlantType() ;

        std::string getStructureType();
        
};

#endif