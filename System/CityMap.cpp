#include <iostream> 
#include <vector>

#include "CityHall.h"
#include "CityStructure.h"
#include "CommercialBuilding.h"
#include "IndustrialBuilding.h"
#include "ResidentialComplex.h"
#include "ResidentialComponent.h"
#include "Plant.h"
#include "Landmark.h"
#include "Road.h"

#include "CheckAdjacent.h"
#include "BuildingAdded.h"
#include "BuildingRemoved.h"
#include "RoadAdded.h"
#include "RoadRemoved.h"


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
    // std::cout << "Placing the city hall" << std::endl;
    // std::cout << "cityHall: " << cityHall->getStructureType()<< std::endl;
}

bool CityMap::addStructure(int x, int y, CityStructure* structure) {
    std::cout << "citymap addStructure" << std::endl;
    int deduction = structure->getCost();
    std::cout << "deduction: " << deduction << std::endl;
    if (cityHall->deductPopeCoins(deduction) == false) {
        std::cout << "Not enough pope coins to place the structure" << std::endl;
        return false;
    }
    if (y < 0 || y >= map.size() || x < 0 || x >= map[y].size()) {
    std::cout << "Invalid location" << std::endl;
    return false;
    }
    if (map.at(y).at(x) != nullptr) {
        std::cout << "There is already a structure at this location" << std::endl;
        return false;
    }
    

    // DO VALIDATION (is it supposed to be at y then x?)
    map.at(y).at(x) = structure;
    return true;
    
    
}

void CityMap::addRoad(Road* originator) {
    // TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW TRAFFIC
    int x = originator->getX();
    int y = originator->getY();
    
    // Calls newRoadWasAdded on all adjacent residential complexes (with appropriate bounds checking)
    RoadAdded roadAdded;
    roadAdded.checkAdjacent(map, x, y);

}



void CityMap::addBuilding(CityStructure* originator) {
    // TELL ADJACENT ROADS TO ADJUST THEIR TRAFFIC BASED ON NEW BUILDING
    //then the roads will tell the residential complexes to adjust their satisfaction (CAN BE DONE USING MEDIATOR AS WELL)
    int x = originator->getX();
    int y = originator->getY();

    // Calls newBuildingWasAdded on all adjacent roads (with appropriate bounds checking)
    BuildingAdded buildingAdded;
    buildingAdded.checkAdjacent(map, x, y);
    

}

void CityMap::addResidentialComplex(ResidentialComplex* originator) {
    // call addBuilding to adjust the traffic
    addBuilding(originator);

    // notify all city structures in the map that a new residential complex was added
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map.at(i).at(j) != nullptr) {
                map.at(i).at(j)->newResidentialComplexWasAdded(originator); // could notify roads here instead of in addBuilding function
            }
        }
    }

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

    // if (map.at(y).at(x) == cityHall) {
    //     std::cout << "Cannot remove the city hall" << std::endl;
    //     return;
    // }

    int refund = map.at(y).at(x)->getCost();
    cityHall->addPopeCoins(refund);

    map.at(y).at(x) = nullptr;
    
}

void CityMap::removeRoad(Road* originator) {
    // TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW TRAFFIC
    int x = originator->getX();
    int y = originator->getY();

    // Calls roadWasRemoved on all adjacent residential complexes (with appropriate bounds checking)
    RoadRemoved roadRemoved;
    roadRemoved.checkAdjacent(map, x, y);

}

void CityMap::removeBuilding(CityStructure* originator) {
    // TELL ADJACENT ROADS TO ADJUST THEIR TRAFFIC BASED ON NEW BUILDING
    //then the roads will tell the residential complexes to adjust their satisfaction (CAN BE DONE USING MEDIATOR AS WELL)
    int x = originator->getX();
    int y = originator->getY();

    // Calls buildingWasRemoved on all adjacent roads (with appropriate bounds checking)
    BuildingRemoved buildingRemoved;
    buildingRemoved.checkAdjacent(map, x, y);

}   

void CityMap::removeResidentialComplex(ResidentialComplex* originator) {
    // call addBuilding to adjust the traffic
    removeBuilding(originator);

    this->cityHall->decreaseNumResidentialComplexes();
}

void CityMap::removeCommercialBuilding(CommercialBuilding* originator) {
    // call addBuilding to adjust the traffic
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING
    // RADIUS WILL BE BIGGER IN THIS CASE

    removeBuilding(originator);

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
                map.at(leftCornerY + i).at(leftCornerX + j)->commercialBuildingWasRemoved(); 
            }
        }
    }

    this->cityHall->decreaseNumCommercialBuildings();
    
}

void CityMap::removeIndustrialBuilding(Plant* originator) {
    // call addBuilding to adjust the traffic
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING
    // RADIUS WILL BE BIGGER IN THIS CASE

    removeBuilding(originator);

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
                map.at(leftCornerY + i).at(leftCornerX + j)->industrialBuildingWasRemoved(); 
            }
        }
    }

    this->cityHall->decreaseNumIndustrialBuildings();

}

void CityMap::removeLandmark(Landmark* originator) {
    // call addBuilding to adjust the traffic
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING
    // RADIUS WILL BE BIGGER IN THIS CASE

    removeBuilding(originator);

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
                map.at(leftCornerY + i).at(leftCornerX + j)->landmarkWasRemoved(); 
            }
        }
    }
}


void CityMap::addResidentialComponent(ResidentialComponent* residential) {
    this->cityHall->increaseCapacity(residential->getCapacity());
}

void CityMap::removeResidentialComponent(ResidentialComponent* residential) {
    this->cityHall->decreaseCapacity(residential->getCapacity());
}

void CityMap::aResidentialComponentChangedItsSatifaction(int oldSatisfaction, int newSatisfaction) {
    cityHall->calculateResidentialSatisfaction(oldSatisfaction, newSatisfaction);
}