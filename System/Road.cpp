#include <iostream>
#include <vector>

#include "Road.h"
#include "CityMap.h"


Road::Road() : trafficState(0) {

}

Road::~Road() {
    cityMap = nullptr;
}

void Road::placeStructure(int x, int y, CityMap* cityMap) {
    // call base class function which assigns it to the map
    CityStructure::placeStructure(x, y, cityMap); 
    calculateTraffic();
    cityMap->addRoad(this);
}

void Road::newBuildingWasAdded() {
    calculateTraffic();
    cityMap->addRoad(this); //logically doesnt make sense to call this function addRoad
}


void Road::removeStructure() {
    CityStructure::removeStructure();
    cityMap->removeRoad(this);

}

void Road::buildingWasRemoved() {
    calculateTraffic();
    cityMap->addRoad(this); //logically doesnt make sense to call this function addRoad
}



void Road::calculateTraffic() {
    // Check the squares around
    int numStructuresAroundRoad = 0;
    if ((cityMap->getMap()).at(y).at(x+1) != nullptr) {
        numStructuresAroundRoad++;
    }
    if ((cityMap->getMap()).at(y).at(x-1) != nullptr) {
        numStructuresAroundRoad++;
    }
    if ((cityMap->getMap()).at(y+1).at(x) != nullptr) {
        numStructuresAroundRoad++;
    }
    if ((cityMap->getMap()).at(y-1).at(x) != nullptr) {
        numStructuresAroundRoad++;
    }

    // Change the traffic state based on the number of structures around the road
    if (numStructuresAroundRoad <= 1) {          // if 0 or 1 then low
        trafficState = 1; // LOW
    } else if (numStructuresAroundRoad == 2) {   // if 2 then medium
        trafficState = 2; // MEDIUM
    } else { // if 3 or 4 then high
        trafficState = 3; // HIGH
    }
}