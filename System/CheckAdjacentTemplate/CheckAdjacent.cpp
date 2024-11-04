#include "CheckAdjacent.h"
#include "../CityStructures/CityStructure.h"
#include <iostream>

int CheckAdjacent::checkAdjacent(std::vector<std::vector<CityStructure*> > map, int x, int y) {

    int maxY = map.size();


    if (maxY == 0) {
        return 0; // Empty map
    }

    int maxX = map.at(0).size();  // Assume all rows are the same size

    int numNonNullAdjacents = 0;

    // Check (y - 1, x)
    if (y - 1 >= 0 && y - 1 < maxY && x >= 0 && x < maxX && map.at(y - 1).at(x) != nullptr) {
        std::cout << "Checking adjacent structure: y - 1, x " << map.at(y - 1).at(x)->getStructureType() << std::endl;
        numNonNullAdjacents++;
        performAction(map, x, y - 1);
        
    }

    // Check (y, x - 1)
    if (y >= 0 && y < maxY && x - 1 >= 0 && x - 1 < maxX && map.at(y).at(x - 1) != nullptr) {
        std::cout << "Checking adjacent structure: y, x - 1 " << map.at(y).at(x - 1)->getStructureType() << std::endl;
        numNonNullAdjacents++;
        performAction(map, x - 1, y);
        
    }

    // Check (y + 1, x)
    if (y + 1 >= 0 && y + 1 < maxY && x >= 0 && x < maxX && map.at(y + 1).at(x) != nullptr) {
        std::cout << "Checking adjacent structure: y + 1, x " << map.at(y + 1).at(x)->getStructureType() << std::endl;
        numNonNullAdjacents++;
        performAction(map, x, y + 1);
    }

    // Check (y, x + 1)
    if (y >= 0 && y < maxY && x + 1 >= 0 && x + 1 < maxX && map.at(y).at(x + 1) != nullptr) {
        std::cout << "Checking adjacent structure: y, x + 1 " << map.at(y).at(x + 1)->getStructureType() << std::endl;
        numNonNullAdjacents++;
        performAction(map, x + 1, y);
        
    }

    return numNonNullAdjacents;

}

void CheckAdjacent::performAction(std::vector<std::vector<CityStructure*> > map, int x, int y) {
    // Do nothing
}