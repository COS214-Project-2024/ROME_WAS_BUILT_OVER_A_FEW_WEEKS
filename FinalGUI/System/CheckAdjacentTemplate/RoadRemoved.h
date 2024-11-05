#ifndef ROAD_REMOVED_H
#define ROAD_REMOVED_H

#include "CheckAdjacent.h"
#include "../CityStructures/CityStructure.h"
#include "../CityMap.h"


class RoadRemoved : public CheckAdjacent {
    public:
        void performAction(std::vector<std::vector<CityStructure*> > map, int x, int y) {
                map.at(y).at(x)->roadWasRemoved();
        }
};

#endif