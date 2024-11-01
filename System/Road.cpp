#include <iostream>
#include <vector>

#include "Road.h"
#include "CityMap.h"
#include "LowTraffic.h"
#include "MediumTraffic.h"
#include "HighTraffic.h"

#include "CheckAdjacent.h" 


Road::Road() : trafficState(new LowTraffic()) {
    cityMap = nullptr;
    cost = 100;
}

Road::~Road() {
    cityMap = nullptr;
}

std::string Road::getStructureType() {
    return "Road";
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
    std::cout << "calculating traffic" << std::endl;
    // Check the squares around
    int numStructuresAroundRoad = 0;
    
    // Check the square around and check if there are any structures
    CheckAdjacent checkAdjacent;
    numStructuresAroundRoad = checkAdjacent.checkAdjacent(cityMap->getMap(), x, y);
    

    std:: cout << "setting traffic state" << std::endl;
    // Change the traffic state based on the number of structures around the road
    if (numStructuresAroundRoad <= 1) {          // if 0 or 1 then low
        setTrafficState(new LowTraffic());
    } else if (numStructuresAroundRoad == 2) {   // if 2 then medium
        setTrafficState(new MediumTraffic());
    } else { // if 3 or 4 then high
        setTrafficState(new HighTraffic());
    }
    std:: cout << "done calculating traffic" << std::endl;
    std:: cout << "new traffic level: " << getTrafficLevel() << std::endl;
}

void Road::setTrafficState(TrafficState* state) {
    if(trafficState) 
    {
        delete trafficState;  // Clean up old state
    }
    
    trafficState = state;
}

int Road::getTrafficLevel() {
    return trafficState->getTrafficLevel();
}