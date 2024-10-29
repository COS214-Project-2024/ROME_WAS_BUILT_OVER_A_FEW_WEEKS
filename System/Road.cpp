#include <iostream>
#include <vector>

#include "Road.h"
#include "CityMap.h"
#include "LowTraffic.h"
#include "MediumTraffic.h"
#include "HighTraffic.h"


Road::Road() : trafficState(new LowTraffic) {

}

Road::~Road() {
    delete trafficState;  // Clean up
}

void Road::placeStructure(int x, int y, CityMap* cityMap) {
    // call base class function which assigns it to the map
    CityStructure::placeStructure(x, y, cityMap); 
    calculateTraffic();
    cityMap->addRoad(this);
}

void Road::removeStructure() {
    cityMap->removeStructure(x, y);
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
        trafficState = new LowTraffic; // LOW
    } else if (numStructuresAroundRoad == 2) {   // if 2 then medium
        trafficState = new MediumTraffic; // MEDIUM
    } else { // if 3 or 4 then high
        trafficState = new HighTraffic; // HIGH
    }
}

void Road::newBuildingWasAdded() {
    calculateTraffic();
    cityMap->addRoad(this); //logically doesnt make sense to call this function addRoad
}

//newly added
void Road::setTrafficState(TrafficState* state)
{
    if(trafficState) 
    {
        delete trafficState;  // Clean up old state
    }
    
    trafficState = state;
}
