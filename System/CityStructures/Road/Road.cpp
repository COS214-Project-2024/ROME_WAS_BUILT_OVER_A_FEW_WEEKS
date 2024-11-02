#include <iostream>
#include <vector>

#include "Road.h"
#include "../../CityMap.h"
#include "LowTraffic.h"
#include "MediumTraffic.h"
#include "HighTraffic.h"

#include "../../CheckAdjacentTemplate/CheckAdjacent.h" 

#include "../../GameSimulation.h"

sf::Texture* Road::texture1 = new sf::Texture();
sf::Texture* Road::texture2 = new sf::Texture();
sf::Texture* Road::texture3 = new sf::Texture();
sf::Texture* Road::texture4 = new sf::Texture();


Road::Road() : trafficState(new LowTraffic()) {
    cityMap = nullptr;
    cost = 100;

    static bool isLoaded = false;

    if (!isLoaded){
        texture1->loadFromFile("../../../images/spr_Road1.png");
        texture2->loadFromFile("../../../images/spr_Road2.png");
        texture3->loadFromFile("../../../images/spr_Road3.png");
        texture4->loadFromFile("../../../images/spr_Road4.png");
        isLoaded = true;
    }

    sprite->setTexture(*texture1);
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
    std::vector<std::vector<CityStructure*> > map = cityMap->getMap();
    int maxY = map.size();
    if (maxY == 0) { return; }  // Empty map
    int maxX = map.at(0).size();  // Assume all rows are the same size
    // Check (y - 1, x)
    if (y - 1 >= 0 && y - 1 < maxY && x >= 0 && x < maxX && map.at(y - 1).at(x) != nullptr && map.at(y - 1).at(x)->getStructureType() != "Road") {
        numStructuresAroundRoad++;
    }
    // Check (y, x - 1)
    if (y >= 0 && y < maxY && x - 1 >= 0 && x - 1 < maxX && map.at(y).at(x - 1) != nullptr && map.at(y).at(x - 1)->getStructureType() != "Road") {
        numStructuresAroundRoad++;
    }
    // Check (y + 1, x)
    if (y + 1 >= 0 && y + 1 < maxY && x >= 0 && x < maxX && map.at(y + 1).at(x) != nullptr && map.at(y + 1).at(x)->getStructureType() != "Road") {
        numStructuresAroundRoad++;
    }
    // Check (y, x + 1)
    if (y >= 0 && y < maxY && x + 1 >= 0 && x + 1 < maxX && map.at(y).at(x + 1) != nullptr && map.at(y).at(x + 1)->getStructureType() != "Road") {
        numStructuresAroundRoad++;
    }

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