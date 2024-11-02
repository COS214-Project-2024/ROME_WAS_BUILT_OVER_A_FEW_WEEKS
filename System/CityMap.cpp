#include <iostream> 
#include <vector>

#include "CityHall.h"
#include "CityStructures/CityStructure.h"
#include "CityStructures/Commercial/CommercialBuilding.h"
#include "CityStructures/Industrial/IndustrialBuilding.h"
#include "CityStructures/Residential/ResidentialComplex.h"
#include "CityStructures/Residential/ResidentialComponent.h"
#include "CityStructures/Industrial/Plant.h"
#include "CityStructures/Landmark/Landmark.h"
#include "CityStructures/Road/Road.h"

#include "CheckAdjacentTemplate/CheckAdjacent.h"
#include "CheckAdjacentTemplate/BuildingAdded.h"
#include "CheckAdjacentTemplate/BuildingRemoved.h"
#include "CheckAdjacentTemplate/RoadAdded.h"
#include "CheckAdjacentTemplate/RoadRemoved.h"


const int DEFAULT_HEIGHT = 8;
const int DEFAULT_WIDTH = 16;


CityMap::CityMap()  : map(DEFAULT_HEIGHT, std::vector<CityStructure*>(DEFAULT_HEIGHT, nullptr)) {
    // Here, map is initialized as a DEFAULT 2D vector of nullptr pointers.
}


CityMap::CityMap(int width, int height)  : map(height, std::vector<CityStructure*>(width, nullptr)) {
    // Here, map is initialized as a 2D vector of nullptr pointers.
}

std::vector<std::vector<CityStructure*> > CityMap::getMap() {
    return map;
}

void CityMap::setCityHall(CityHall* cityHall) {
    this->cityHall = cityHall;
    // std::cout << "Placing the city hall" << std::endl;
    // std::cout << "cityHall: " << cityHall->getStructureType()<< std::endl;
}

bool CityMap::addStructure(int x, int y, CityStructure* structure) {
    std::cout << "citymap addStructure" << std::endl;

    // VALIDATE IF LOCATION IS IN BOUNDS
    if (y < 0 || y >= map.size() || x < 0 || x >= map[y].size()) {
    std::cout << "Invalid location" << std::endl;
    return false;
    }

    // VALIDATE IF THERE IS ALREADY A STRUCTURE AT THE LOCATION
    if (map.at(y).at(x) != nullptr) {
        std::cout << "There is already a structure at this location" << std::endl;
        return false;
    }
    
    // VALIDATE IF THERE IS AN ADJACENT ROAD (DOESN'T APPLY TO CITY HALL)
    bool hasAdjacentRoad = true;
    std::string currStructure = structure->getStructureType();

    if (currStructure != "CityHall"  && currStructure != "Road") {
        std::cout << "Checking for adjacent road" << std::endl;
        hasAdjacentRoad = false;
        int maxY = map.size();
        if (maxY == 0) {
            return false; // Empty map
        }
        int maxX = map.at(0).size();  // Assume all rows are the same size
        std::string structureType;

        // Check (y - 1, x)
        if (y - 1 >= 0 && y - 1 < maxY && x >= 0 && x < maxX && map.at(y - 1).at(x) != nullptr) {
            structureType = map.at(y - 1).at(x)->getStructureType();
            if (structureType == "Road") {
                hasAdjacentRoad = true;
            }
        }

        // Check (y, x - 1)
        if (y >= 0 && y < maxY && x - 1 >= 0 && x - 1 < maxX && map.at(y).at(x - 1) != nullptr) {
            structureType = map.at(y).at(x - 1)->getStructureType();
            if (structureType == "Road") {
                hasAdjacentRoad = true;
            }
        }

        // Check (y + 1, x)
        if (y + 1 >= 0 && y + 1 < maxY && x >= 0 && x < maxX && map.at(y + 1).at(x) != nullptr) {
            structureType = map.at(y + 1).at(x)->getStructureType();
            if (structureType == "Road") {
                hasAdjacentRoad = true;
            }
        }

        // Check (y, x + 1)
        if (y >= 0 && y < maxY && x + 1 >= 0 && x + 1 < maxX && map.at(y).at(x + 1) != nullptr) {
            structureType = map.at(y).at(x + 1)->getStructureType();
            if (structureType == "Road") {
                hasAdjacentRoad = true;
            }
        }
    }

    if (hasAdjacentRoad == false) {
        std::cout << "Cannot place the structure without an adjacent road" << std::endl;
        return false;
    }
    
    // VALIDATE IF PLAYER HAS ENOUGH POPE COINS
    int deduction = structure->getCost();
    // std::cout << "structure type: " << structure->getStructureType() << std::endl;
    std::cout << "deduction: " << deduction << std::endl;
    if (cityHall->deductPopeCoins(deduction) == false) {
        std::cout << "Not enough pope coins to place the structure" << std::endl;
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
    std::cout << "x: " << x << " y: " << y << std::endl;

    // Calls newBuildingWasAdded on all adjacent roads (with appropriate bounds checking)
    BuildingAdded buildingAdded;
    std::cout << "RR" << std::endl;
    buildingAdded.checkAdjacent(map, x, y);
    std::cout << "RR" << std::endl;
    

}

void CityMap::addResidentialComplex(ResidentialComplex* originator) {
    this->cityHall->increaseNumResidentialComplexes();

    int addedCapacity = originator->getCapacity();                          // I THINK THIS SHOULD WORK
    std::cout << "added capacity: " << addedCapacity << std::endl;
    this->cityHall->increaseCapacity(addedCapacity);

    // call addBuilding to adjust the traffic
    addBuilding(originator);
    std::cout << "RR" << std::endl;
    // notify all city structures in the map that a new residential complex was added
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map.at(i).at(j) != nullptr) {
                map.at(i).at(j)->newResidentialComplexWasAdded(originator); // could notify roads here instead of in addBuilding function
            }
        }
    }

    
}

void CityMap::addCommercialBuilding(CommercialBuilding* originator) {
    // call addBuilding to adjust the traffic
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING
    // RADIUS WILL BE BIGGER IN THIS CASE
    this->cityHall->increaseNumCommercialBuildings();

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

    
    
}

void CityMap::addIndustrialBuilding(Plant* originator) {
    // call addBuilding to adjust the traffic
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING
    // RADIUS WILL BE BIGGER IN THIS CASE

    this->cityHall->increaseNumIndustrialBuildings();

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
            try {
            std::cout << "jjj" << std::endl;
            if (map.at(leftCornerY + i).at(leftCornerX + j) != nullptr) {
                map.at(leftCornerY + i).at(leftCornerX + j)->newLandmarkWasAdded(); 
            }
            } catch (const std::out_of_range& oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
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
    std::cout << "informing city hall" << std::endl;
    int addedCapacity = residential->getCapacity();
    std::cout << "added capacity: " << addedCapacity << std::endl;
    this->cityHall->increaseCapacity(addedCapacity);
    std::cout << "END informing city hall" << std::endl;
}

void CityMap::removeResidentialComponent(ResidentialComponent* residential) {
    this->cityHall->decreaseCapacity(residential->getCapacity());
}

void CityMap::aResidentialComponentChangedItsSatifaction(int oldSatisfaction, int newSatisfaction) {
    std::cout << "CHAIN OF RESPONSIBILITY" << std::endl;
    cityHall->calculateResidentialSatisfaction(oldSatisfaction, newSatisfaction);
}