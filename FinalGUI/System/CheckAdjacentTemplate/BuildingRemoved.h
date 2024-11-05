#ifndef BUILDING_REMOVED_H
#define BUILDING_REMOVED_H

#include "CheckAdjacent.h"
#include "../CityStructures/CityStructure.h"


class BuildingRemoved : public CheckAdjacent {
    public:
        void performAction(std::vector<std::vector<CityStructure*> > map, int x, int y) {
                map.at(y).at(x)->newBuildingWasAdded();
        }
};

#endif