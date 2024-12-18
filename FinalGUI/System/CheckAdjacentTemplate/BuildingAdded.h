#ifndef BUILDING_ADDED_H
#define BUILDING_ADDED_H

#include "CheckAdjacent.h"
#include "../CityStructures/CityStructure.h"


class BuildingAdded : public CheckAdjacent {
    public:
        void performAction(std::vector<std::vector<CityStructure*> > map, int x, int y) {
                map.at(y).at(x)->buildingWasRemoved();
        }
};

#endif