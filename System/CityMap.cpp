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
#include "CityStructures/Industrial/Warehouse.h"

#include "CheckAdjacentTemplate/CheckAdjacent.h"
#include "CheckAdjacentTemplate/BuildingAdded.h"
#include "CheckAdjacentTemplate/BuildingRemoved.h"
#include "CheckAdjacentTemplate/RoadAdded.h"
#include "CheckAdjacentTemplate/RoadRemoved.h"
#include "CityMap.h"


const int DEFAULT_HEIGHT = 20;
const int DEFAULT_WIDTH = 20;


CityMap::CityMap()  : map(DEFAULT_HEIGHT, std::vector<CityStructure*>(DEFAULT_HEIGHT, nullptr)) {
    // Here, map is initialized as a DEFAULT 2D vector of nullptr pointers.
    for (int i = 0; i < DEFAULT_HEIGHT; i++) {
        for (int j = 0; j < DEFAULT_WIDTH; j++) {
            map.at(i).at(j) = nullptr;
        }
    }
}


CityMap::CityMap(int width, int height)  : map(height, std::vector<CityStructure*>(width, nullptr)) {
    // Here, map is initialized as a 2D vector of nullptr pointers.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map.at(i).at(j) = nullptr;
        }
    }
}

std::vector<std::vector<CityStructure*> > CityMap::getMap() {
    return map;
}

void CityMap::setCityHall(CityHall* cityHall) {
    this->cityHall = cityHall;
}

bool CityMap::addStructure(int x, int y, CityStructure* structure) {
    // VALIDATE IF LOCATION IS IN BOUNDS
    if (y < 0 || y >= map.size() || x < 0 || x >= map[y].size()) {
        std::cout << "Invalid location" << std::endl;
        return false;
    }

    // VALIDATE IF THERE IS ALREADY A STRUCTURE AT THE LOCATION
    if (map.at(y).at(x) != nullptr) {
        std::cout << "There is already a structure at the location " << x << ", " << y << std::endl;
        return false;
    }
    
    // VALIDATE IF THERE IS AN ADJACENT ROAD (DOESN'T APPLY TO CITY HALL)
    bool hasAdjacentRoad = true;
    std::string currStructure = structure->getStructureType();

    if (currStructure != "CityHall"  && currStructure != "Road") {
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
    std::cout << "deduction: " << deduction << std::endl;
    if (cityHall->deductPopeCoins(deduction) == false) {
        std::cout << "Not enough pope coins to place the structure" << std::endl;
        return false;
    }

    //VALIDATE IF PLAYER HAS ENOUGH RESOURCES
    int woodCost = structure->getWoodCost();
    int steelCost = structure->getSteelCost();
    int concreteCost = structure->getConcreteCost();
    if (cityHall->deductWood(woodCost) == false) {
        std::cout << "Not enough wood to place the structure" << std::endl;
        return false;
    }
    if (cityHall->deductSteel(steelCost) == false) {
        std::cout << "Not enough steel to place the structure" << std::endl;
        return false;
    }
    if (cityHall->deductConcrete(concreteCost) == false) {
        std::cout << "Not enough concrete to place the structure" << std::endl;
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
    // TELL ADJACENT ROADS TO ADJUST THEIR TRAFFIC BASED ON NEW BUILDING (roads then tell adjacent residential complexes to adjust their satisfaction)
    int x = originator->getX();
    int y = originator->getY();;

    // Calls newBuildingWasAdded on all adjacent roads (with appropriate bounds checking)
    BuildingAdded buildingAdded;
    buildingAdded.checkAdjacent(map, x, y);
}

void CityMap::addResidentialComplex(ResidentialComplex* originator) {
    // Increase the number of residential complexes in the city hall
    this->cityHall->increaseNumResidentialComplexes();

    // Increase the capacity of the city hall
    int addedCapacity = originator->getCapacity();                          
    this->cityHall->increaseCapacity(addedCapacity);

    // call addBuilding to adjust the traffic as above
    addBuilding(originator);

    // notify all city structures in the map that a new residential complex was added
    // done to inform radius buildings so that res building can set an initial satisfaction
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map.at(i).at(j) != nullptr) {
                map.at(i).at(j)->newResidentialComplexWasAdded(originator); // could notify roads here instead of in addBuilding function
            }
        }
    }

    
}

void CityMap::addCommercialBuilding(CommercialBuilding* originator) {
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIIUS BUILDING

    // Increase the number of commercial buildings in the city hall
    this->cityHall->increaseNumCommercialBuildings();

    // call addBuilding to adjust the traffic
    addBuilding(originator);

    int x = originator->getX();
    int y = originator->getY();
    int radiusOfEffect = originator->getRadiusOfEffect();

    // radius for radius buildings works as concentric squares
    int minX = std::max(0, x - radiusOfEffect);
    int maxX = std::min(static_cast<int>(map[0].size()) - 1, x + radiusOfEffect);
    int minY = std::max(0, y - radiusOfEffect);
    int maxY = std::min(static_cast<int>(map.size()) - 1, y + radiusOfEffect);

    for (int i = minY; i <= maxY; ++i) {
        for (int j = minX; j <= maxX; ++j) {
            if (map[i][j] != nullptr) {
                map[i][j]->newCommercialBuildingWasAdded();
            }
        }
    }
    
}

void CityMap::addIndustrialBuilding(IndustrialBuilding* originator) {
    // call addBuilding to adjust the traffic
    this->cityHall->increaseNumIndustrialBuildings();
    addBuilding(originator);
}

void CityMap::addPlant(Plant* originator) {
    // call addBuilding to adjust the traffic
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING

    // Increase the number of industrial buildings in the city hall
    this->cityHall->increaseNumIndustrialBuildings();

    // call addBuilding to adjust the traffic
    addBuilding(originator);

    int x = originator->getX();
    int y = originator->getY();
    int radiusOfEffect = originator->getRadiusOfEffect();

    int minX = std::max(0, x - radiusOfEffect);
    int maxX = std::min(static_cast<int>(map[0].size()) - 1, x + radiusOfEffect);
    int minY = std::max(0, y - radiusOfEffect);
    int maxY = std::min(static_cast<int>(map.size()) - 1, y + radiusOfEffect);

    for (int i = minY; i <= maxY; ++i) {
        for (int j = minX; j <= maxX; ++j) {
            if (map[i][j] != nullptr) {
                map[i][j]->newIndustrialBuildingWasAdded();
            }
        }
    }


}

void CityMap::addWarehouse(Warehouse* originator) {
    // call addBuilding to adjust the traffic
    this->cityHall->increaseNumIndustrialBuildings();
    addBuilding(originator);
    this->cityHall->increaseStorageCapacity();
}


void CityMap::addLandmark(Landmark* originator) {
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING

    // ADD increaseNumLandmark functionality later (no real reason, just to keep uniformity)

    // call addBuilding to adjust the traffic
    addBuilding(originator);

    int x = originator->getX();
    int y = originator->getY();
    int radiusOfEffect = originator->getRadiusOfEffect();

    int minX = std::max(0, x - radiusOfEffect);
    int maxX = std::min(static_cast<int>(map[0].size()) - 1, x + radiusOfEffect);
    int minY = std::max(0, y - radiusOfEffect);
    int maxY = std::min(static_cast<int>(map.size()) - 1, y + radiusOfEffect);

    for (int i = minY; i <= maxY; ++i) {
        for (int j = minX; j <= maxX; ++j) {
            if (map[i][j] != nullptr) {
                map[i][j]->newLandmarkWasAdded();
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
   
   // VALIDATE IF LOCATION IS IN BOUNDS
    if (y < 0 || y >= map.size() || x < 0 || x >= map[y].size()) {
        std::cout << "Invalid location" << std::endl;
        return;
    }
   
   // VALIDATE IF LOCATION HAS A STRUCTURE
    if (map.at(y).at(x) == nullptr) {
        return;
    }

    // CANNOT REMOVE CITY HALL
    if (map.at(y).at(x) == cityHall) {
        std::cout << "Cannot remove the city hall" << std::endl;
        return;
    }

    // VALIDATE IF STRUCTURE IS ROAD IF IT HAS ADJACENT BUILDINGS
    bool hasAdjacentBuildings = false;
    std::string currStructure = map.at(y).at(x)->getStructureType();

    if (currStructure == "Road") {
        hasAdjacentBuildings = false;
        int maxY = map.size();
        if (maxY == 0) {
            return; // Empty map
        }
        int maxX = map.at(0).size();  // Assume all rows are the same size
        std::string structureType;

        // Check (y - 1, x)
        if (y - 1 >= 0 && y - 1 < maxY && x >= 0 && x < maxX && map.at(y - 1).at(x) != nullptr) {
            structureType = map.at(y - 1).at(x)->getStructureType();
            if (structureType != "Road") {
                hasAdjacentBuildings = true;
            }
        }

        // Check (y, x - 1)
        if (y >= 0 && y < maxY && x - 1 >= 0 && x - 1 < maxX && map.at(y).at(x - 1) != nullptr) {
            structureType = map.at(y).at(x - 1)->getStructureType();
            if (structureType != "Road") {
                hasAdjacentBuildings = true;
            }
        }

        // Check (y + 1, x)
        if (y + 1 >= 0 && y + 1 < maxY && x >= 0 && x < maxX && map.at(y + 1).at(x) != nullptr) {
            structureType = map.at(y + 1).at(x)->getStructureType();
            if (structureType != "Road") {
                hasAdjacentBuildings = true;
            }
        }

        // Check (y, x + 1)
        if (y >= 0 && y < maxY && x + 1 >= 0 && x + 1 < maxX && map.at(y).at(x + 1) != nullptr) {
            structureType = map.at(y).at(x + 1)->getStructureType();
            if (structureType != "Road") {
                hasAdjacentBuildings = true;
            }
        }
    }

    if (hasAdjacentBuildings == true) {
        std::cout << "Cannot remove the road without removing adjacent buildings" << std::endl;
        return;
    }

    int refund = map.at(y).at(x)->getCost();
    cityHall->addPopeCoins(refund);

    map.at(y).at(x) = nullptr;

    return;
    
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
    // TELL ADJACENT ROADS TO ADJUST THEIR TRAFFIC BASED ON NEW BUILDING (roads then tell adjacent residential complexes to adjust their satisfaction)
    int x = originator->getX();
    int y = originator->getY();

    // Calls buildingWasRemoved on all adjacent roads (with appropriate bounds checking)
    BuildingRemoved buildingRemoved;
    buildingRemoved.checkAdjacent(map, x, y);

}   

void CityMap::removeResidentialComplex(ResidentialComplex* originator) {
    // Decreae the number of residential complexes in the city hall
    this->cityHall->decreaseNumResidentialComplexes();

    // Decrease the capacity of the city hall
    int removedCapacity = originator->getCapacity();
    this->cityHall->decreaseCapacity(removedCapacity);

    // call removeBuilding to adjust the traffic
    removeBuilding(originator);

    // DONT need to notify all city structures in the map that a new residential complex was added
    // I THINK


}

void CityMap::removeCommercialBuilding(CommercialBuilding* originator) {
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING
    
    // Decrease the number of commercial buildings in the city hall
    this->cityHall->decreaseNumCommercialBuildings();

    // call removeBuilding to adjust the traffic
    removeBuilding(originator);

    int x = originator->getX();
    int y = originator->getY();
    int radiusOfEffect = originator->getRadiusOfEffect();

    // radius for radius buildings works as concentric squares
    int minX = std::max(0, x - radiusOfEffect);
    int maxX = std::min(static_cast<int>(map[0].size()) - 1, x + radiusOfEffect);
    int minY = std::max(0, y - radiusOfEffect);
    int maxY = std::min(static_cast<int>(map.size()) - 1, y + radiusOfEffect);

    for (int i = minY; i <= maxY; ++i) {
        for (int j = minX; j <= maxX; ++j) {
            if (map[i][j] != nullptr) {
                map[i][j]->commercialBuildingWasRemoved();
            }
        }
    }
    
}

void CityMap::removeIndustrialBuilding(Plant* originator) {
    // TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING

    // Decrease the number of industrial buildings in the city hall
    this->cityHall->decreaseNumIndustrialBuildings();

    // call removeBuilding to adjust the traffic
    removeBuilding(originator);

    // radius for radius buildings works as concentric squares
    int x = originator->getX();
    int y = originator->getY();
    int radiusOfEffect = originator->getRadiusOfEffect();

    int minX = std::max(0, x - radiusOfEffect);
    int maxX = std::min(static_cast<int>(map[0].size()) - 1, x + radiusOfEffect);
    int minY = std::max(0, y - radiusOfEffect);
    int maxY = std::min(static_cast<int>(map.size()) - 1, y + radiusOfEffect);

    for (int i = minY; i <= maxY; ++i) {
        for (int j = minX; j <= maxX; ++j) {
            if (map[i][j] != nullptr) {
                map[i][j]->industrialBuildingWasRemoved();
            }
        }
    }

}

void CityMap::removeLandmark(Landmark* originator) {
    //TELL ADJACENT RESIDENTIAL COMPLEXES TO ADJUST THEIR SATISFACTIONS BASED ON NEW RADIAL BUILDING

    // ADD decreaseNumLandmark functionality later (no real reason, just to keep uniformity)

    // call removeBuilding to adjust the traffic
    removeBuilding(originator);

    int x = originator->getX();
    int y = originator->getY();
    int radiusOfEffect = originator->getRadiusOfEffect();

    // radius for radius buildings works as concentric squares
    int minX = std::max(0, x - radiusOfEffect);
    int maxX = std::min(static_cast<int>(map[0].size()) - 1, x + radiusOfEffect);
    int minY = std::max(0, y - radiusOfEffect);
    int maxY = std::min(static_cast<int>(map.size()) - 1, y + radiusOfEffect);

    for (int i = minY; i <= maxY; ++i) {
        for (int j = minX; j <= maxX; ++j) {
            if (map[i][j] != nullptr) {
                map[i][j]->landmarkWasRemoved();
            }
        }
    }
}


void CityMap::addResidentialComponent(ResidentialComponent* residential) {
    int addedCapacity = residential->getCapacity();
    this->cityHall->increaseCapacity(addedCapacity);
}

void CityMap::removeResidentialComponent(ResidentialComponent* residential) {
    this->cityHall->decreaseCapacity(residential->getCapacity());
}

void CityMap::aResidentialComponentChangedItsSatifaction(int oldSatisfaction, int newSatisfaction) {
    cityHall->calculateResidentialSatisfaction(oldSatisfaction, newSatisfaction);
}