#ifndef ROAD_ADDED_H
#define ROAD_ADDED_H

#include "CheckAdjacent.h"
#include "CityStructure.h"


class RoadAdded : public CheckAdjacent {
    public:
        void performAction(std::vector<std::vector<CityStructure*> > map, int x, int y) {
                map.at(y-1).at(x)->newRoadWasAdded();
        }
};



#endif