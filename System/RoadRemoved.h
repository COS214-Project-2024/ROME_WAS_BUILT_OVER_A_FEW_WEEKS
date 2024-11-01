#ifndef ROAD_REMOVED_H
#define ROAD_REMOVED_H

#include "CheckAdjacent.h"
#include "CityStructure.h"


class RoadRemoved : public CheckAdjacent {
    public:
        void performAction(std::vector<std::vector<CityStructure*> > map, int x, int y) {
                map.at(y-1).at(x)->roadWasRemoved();
        }
};

#endif