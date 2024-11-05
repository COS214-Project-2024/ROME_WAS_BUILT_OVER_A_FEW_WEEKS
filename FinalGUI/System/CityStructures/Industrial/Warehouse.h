#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include <string>
using namespace std;

#include "IndustrialBuilding.h"
class IndustrialBuilding;

class Warehouse : public IndustrialBuilding {
   public:
        Warehouse() { cost = 1000; woodCost = 0; steelCost = 0; concreteCost = 0; };
        virtual ~Warehouse(){};
        bool placeStructure(int x, int y, CityMap* cityMap);

        std::string getStructureType();
};

#endif