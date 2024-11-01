#ifndef CHECK_ADJACENT_H
#define CHECK_ADJACENT_H

#include <vector>

class CityStructure;

class CheckAdjacent {
    public:
        int checkAdjacent(std::vector<std::vector<CityStructure*> > map, int x, int y);
        virtual void performAction(std::vector<std::vector<CityStructure*> > map, int x, int y);
};


#endif