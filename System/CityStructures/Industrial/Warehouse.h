#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include <string>
using namespace std;

#include "IndustrialBuilding.h"
class IndustrialBuilding;

class Warehouse : public CityStructure {
   public:
        Warehouse() {};
        virtual ~Warehouse(){};
        bool placeStructure(int x, int y, CityMap* cityMap);
        
};

#endif