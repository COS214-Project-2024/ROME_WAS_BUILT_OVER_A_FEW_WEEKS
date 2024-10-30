#include <iostream> 
#include <vector>

#include "CityStructure.h"
#include "CityMap.h"

const int DEFAULT_HEIGHT = 20;
const int DEFAULT_WIDTH = 20;


CityMap::CityMap()  : map(DEFAULT_HEIGHT, std::vector<CityStructure*>(DEFAULT_HEIGHT, nullptr)) {
    // Here, map is initialized as a DEFAULT 2D vector of nullptr pointers.
}


CityMap::CityMap(int width, int height)  : map(height, std::vector<CityStructure*>(width, nullptr)) {
    // Here, map is initialized as a 2D vector of nullptr pointers.
}

std::vector<std::vector<CityStructure*>> CityMap::getMap() {
    return map;
}

void CityMap::setCityHall(CityHall* cityHall) {
    this->cityHall = cityHall;
}

void CityMap::addStructure(int x, int y, CityStructure* structure) {

    int deduction = structure->getCost();
    if (cityHall->deductPopeCoins(deduction) == false) {
        std::cout << "Not enough pope coins to place the structure" << std::endl;
        return;
    }

    // DO VALIDATION (is it supposed to be at y then x?)
    map.at(y).at(x) = structure;
    
    
}

void CityMap::addRoad(Road* originator) {
    // TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW TRAFFIC
    int x = originator->getX();
    int y = originator->getY();

    if (map.at(y).at(x+1) != nullptr) {
        map.at(y).at(x+1)->newRoadWasAdded();
    }
    if (map.at(y).at(x-1) != nullptr) {
        map.at(y).at(x-1)->newRoadWasAdded();
    }
    if (map.at(y+1).at(x) != nullptr) {
        map.at(y+1).at(x)->newRoadWasAdded();
    }
    if (map.at(y-1).at(x) != nullptr) {
        map.at(y-1).at(x)->newRoadWasAdded();
    }

}



void CityMap::addBuilding(CityStructure* originator) {
    // TELL ADJACENT ROADS TO ADJUST THEIR TRAFFIC BASED ON NEW BUILDING
    //then the roads will tell the residential complexes to adjust their satisfaction (CAN BE DONE USING MEDIATOR AS WELL)
    int x = originator->getX();
    int y = originator->getY();

    if (map.at(y).at(x+1) != nullptr) {
        map.at(y).at(x+1)->newBuildingWasAdded();
    }
    if (map.at(y).at(x-1) != nullptr) {
        map.at(y).at(x-1)->newBuildingWasAdded();
    }
    if (map.at(y+1).at(x) != nullptr) {
        map.at(y+1).at(x)->newBuildingWasAdded();
    }
    if (map.at(y-1).at(x) != nullptr) {
        map.at(y-1).at(x)->newBuildingWasAdded();
    }

}

void CityMap::addResidentialComplex(ResidentialComplex* originator) {
    // call addBuilding to adjust the traffic
    addBuilding(originator);

    this->cityHall->increaseNumResidentialComplexes();
}

void CityMap::addCommercialBuilding(CommercialBuilding* originator) {
    // call addBuilding to adjust the traffic
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING
    // RADIUS WILL BE BIGGER IN THIS CASE

    addBuilding(originator);

    int x = originator->getX();
    int y = originator->getY();
    int radiusOfEffect = originator->getRadiusOfEffect();

    // radius for radius buildings works as concentric squares
    int leftCornerX , leftCornerY;
    for (int i = 0; i < radiusOfEffect; i++) {
        leftCornerX = x - i;
        leftCornerY = y - i;
    }

    int heightWidthOfSquareOfEffect = 2*radiusOfEffect + 1;

    for (int i = 0; i < heightWidthOfSquareOfEffect; i++) {
        for (int j = 0; j < heightWidthOfSquareOfEffect; j++) {
            if (map.at(leftCornerY + i).at(leftCornerX + j) != nullptr) {
                map.at(leftCornerY + i).at(leftCornerX + j)->newCommercialBuildingWasAdded(); 
            }
        }
    }

    this->cityHall->increaseNumCommercialBuildings();
    
}

void CityMap::addIndustrialBuilding(Plant* originator) {
    // call addBuilding to adjust the traffic
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING
    // RADIUS WILL BE BIGGER IN THIS CASE

    addBuilding(originator);

    int x = originator->getX();
    int y = originator->getY();
    int radiusOfEffect = originator->getRadiusOfEffect();

    // radius for radius buildings works as concentric squares
    int leftCornerX , leftCornerY;
    for (int i = 0; i < radiusOfEffect; i++) {
        leftCornerX = x - i;
        leftCornerY = y - i;
    }

    int heightWidthOfSquareOfEffect = 2*radiusOfEffect + 1;

    for (int i = 0; i < heightWidthOfSquareOfEffect; i++) {
        for (int j = 0; j < heightWidthOfSquareOfEffect; j++) {
            if (map.at(leftCornerY + i).at(leftCornerX + j) != nullptr) {
                map.at(leftCornerY + i).at(leftCornerX + j)->newIndustrialBuildingWasAdded(); 
            }
        }
    }

    this->cityHall->increaseNumIndustrialBuildings();

}

void CityMap::addLandmark(Landmark* originator) {
    // call addBuilding to adjust the traffic
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING
    // RADIUS WILL BE BIGGER IN THIS CASE

    addBuilding(originator);

    int x = originator->getX();
    int y = originator->getY();
    int radiusOfEffect = originator->getRadiusOfEffect();

    // radius for radius buildings works as concentric squares
    int leftCornerX , leftCornerY;
    for (int i = 0; i < radiusOfEffect; i++) {
        leftCornerX = x - i;
        leftCornerY = y - i;
    }

    int heightWidthOfSquareOfEffect = 2*radiusOfEffect + 1;

    for (int i = 0; i < heightWidthOfSquareOfEffect; i++) {
        for (int j = 0; j < heightWidthOfSquareOfEffect; j++) {
            if (map.at(leftCornerY + i).at(leftCornerX + j) != nullptr) {
                map.at(leftCornerY + i).at(leftCornerX + j)->newLandmarkWasAdded(); 
            }
        }
    }
}

CityMap::~CityMap() {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            delete map[i][j];
        }
    }
    map.clear();
}

void CityMap::removeStructure(int x, int y) {
    // DO VALIDATION
    if (map.at(y).at(x) == nullptr) {
        std::cout << "No structure to remove" << std::endl;
        return;
    }

    if (map.at(y).at(x) == cityHall) {
        std::cout << "Cannot remove the city hall" << std::endl;
        return;
    }

    int refund = map.at(y).at(x)->getCost();
    cityHall->addPopeCoins(refund);

    map.at(y).at(x) = nullptr;
    
}

void CityMap::removeRoad(Road* originator) {
    // TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW TRAFFIC
    int x = originator->getX();
    int y = originator->getY();

    if (map.at(y).at(x+1) != nullptr) {
        map.at(y).at(x+1)->roadWasRemoved();
    }
    if (map.at(y).at(x-1) != nullptr) {
        map.at(y).at(x-1)->roadWasRemoved();
    }
    if (map.at(y+1).at(x) != nullptr) {
        map.at(y+1).at(x)->roadWasRemoved();
    }
    if (map.at(y-1).at(x) != nullptr) {
        map.at(y-1).at(x)->roadWasRemoved();
    }

}