#include <iostream>
#include <vector>

#include "../../CityMap.h"
#include "ResidentialComponent.h"
#include "ResidentialComplex.h"
#include "../Road/Road.h"

ResidentialComplex::ResidentialComplex(ResidentialComponent* residential)  {
    residentialComponents.push_back(residential);
    trafficSatisfaction = 0;
    EmploymentSatisfaction = 0;
    PowerSatisfaction = 0;
    WaterSatisfaction = 0;
    WasteSatisfaction = 0;
    SewageSatisfaction = 0;
    HealthSatisfaction = 5;
    EducationSatisfaction = 5;
    safetySatisfaction = 5;
    bonusSatisfaction = 0;

    satisfaction = 15;
    capacity = residential->getCapacity();
    std::cout << "Residential Complex created" << std::endl;
}

ResidentialComplex::~ResidentialComplex() {
    std::vector<ResidentialComponent*>::iterator it;
    for (it = residentialComponents.begin(); it != residentialComponents.end(); it++) {
        delete *it;
    }
}

std::string ResidentialComplex::getStructureType() {
    return "Residential";
}

void ResidentialComplex::placeStructure(int x, int y, CityMap* cityMap) {
    CityStructure::placeStructure(x, y, cityMap);
    cityMap->addResidentialComplex(this);
}

void ResidentialComplex::newRoadWasAdded() {
    std::cout << "New road was added" << std::endl;
    calculateTrafficSatisfaction(); // sets the traffic satisfaction
    std::cout << "Traffic satisfaction: " << std::endl;
    calculateSatisfaction();
}

void ResidentialComplex::newCommercialBuildingWasAdded() {
    EmploymentSatisfaction = 14;
    calculateSatisfaction();
}

void ResidentialComplex::newIndustrialBuildingWasAdded() {  // FIX
    EmploymentSatisfaction = 14;
    calculateSatisfaction();
}

void ResidentialComplex::newLandmarkWasAdded() {
    bonusSatisfaction = bonusSatisfaction + 2;
    calculateSatisfaction();
}

// REMOVAL CODE

void ResidentialComplex::removeStructure() {
    CityStructure::removeStructure();
    cityMap->removeResidentialComplex(this);
}

void ResidentialComplex::roadWasRemoved() {
    calculateTrafficSatisfaction();
    calculateSatisfaction();
}

void ResidentialComplex::commercialBuildingWasRemoved() {
    EmploymentSatisfaction = 0;
    calculateSatisfaction();
}

void ResidentialComplex::industrialBuildingWasRemoved() {
    EmploymentSatisfaction -= 1;
    calculateSatisfaction();
}

void ResidentialComplex::landmarkWasRemoved() {
    bonusSatisfaction = bonusSatisfaction - 2;
    calculateSatisfaction();
}




int ResidentialComplex::getCapacity() {
    std::cout << "Getting capacity" << capacity << std::endl;
    return capacity;
}

void ResidentialComplex::addResidentialComponent(ResidentialComponent* residential) {
    std::cout << "Adding Residential Component" << std::endl;
    residentialComponents.push_back(residential);
    std::cout << "Informing the city map" << std::endl;
    calculateCapacity(); // Recalculate the capacity of the complex and set the member variable
    cityMap->addResidentialComponent(residential); // INFORM THE CITYMAP OF THE NEW CAPACITY
    
}

void ResidentialComplex::removeResidentialComponent(ResidentialComponent* residential) {
    std::vector<ResidentialComponent*>::iterator it;
    for (it = residentialComponents.begin(); it != residentialComponents.end(); it++) {
        if (*it == residential) {
            residentialComponents.erase(it);
            break;
        }
    }
    cityMap->removeResidentialComponent(this); // INFORM THE CITYMAP OF THE NEW CAPACITY
    calculateCapacity(); // Recalculate the capacity of the complex and set the member variable
}

int ResidentialComplex::calculateCapacity(){
    std::cout << "IN capacity" << std::endl;
    // Calculate the capacity of the complex based on the capacity of the components
    std::vector<ResidentialComponent*>::iterator it;
    int totalCapacity = 0;
    for (it = residentialComponents.begin(); it != residentialComponents.end(); it++) {
        totalCapacity += (*it)->calculateCapacity();
    }
    this->capacity = totalCapacity;
    return totalCapacity;
}

int ResidentialComplex::calculateTrafficSatisfaction() {
    // Traffic satisfaction depends on the traffic of the roads around the complex
    // Get the map
    std::vector< std::vector<CityStructure*> > map = this->cityMap->getMap();
    int newTrafficSatisfaction = 15;
    // Check the squares around the complex
    // CHeck if it is road
    // If it is road, check the traffic state

    // USE TEMPLATE METHOD PATTERN
    std::cout << "Calculating traffic satisfaction" << std::endl;
    std::vector<Road*> roads;
    int maxY = map.size();
    if (maxY == 0) {  return 0; } // Empty map
    int maxX = map.at(0).size();  // Assume all rows are the same size
    

    if (y - 1 >= 0 && y - 1 < maxY && x >= 0 && x < maxX && map.at(y - 1).at(x) != nullptr && map.at(y - 1).at(x)->getStructureType() == "Road") {
        std::cout << "A" << std::endl;
        roads.push_back((Road*)map.at(y-1).at(x));
    }
    if (y >= 0 && y < maxY && x - 1 >= 0 && x - 1 < maxX && map.at(y).at(x-1) != nullptr &&  map.at(y).at(x-1)->getStructureType() == "Road") {
        std::cout << "B" << std::endl;
        roads.push_back((Road*)map.at(y).at(x-1));
    }
    if (y + 1 >= 0 && y + 1 < maxY && x >= 0 && x < maxX && map.at(y + 1).at(x) != nullptr && map.at(y + 1).at(x)->getStructureType() == "Road") {
        std::cout << "C" << std::endl;
        roads.push_back((Road*)map.at(y+1).at(x));
    }
    if (y >= 0 && y < maxY && x + 1 >= 0 && x + 1 < maxX && map.at(y).at(x+1) != nullptr && map.at(y).at(x+1)->getStructureType() == "Road") {
        std::cout << "D" << std::endl;
        roads.push_back((Road*)map.at(y).at(x+1));
    }
    //print out roads
    for (int i = 0; i < roads.size(); i++) {
        std::cout << "Road: " << roads[i]->getStructureType() << std::endl;
    }

    std::cout << "Number of roads: " <<  std::endl;
    std::vector<Road*>::iterator it;
    for (it = roads.begin(); it != roads.end(); it++) {
        int trafficLevel = (*it)->getTrafficLevel();
        std::cout << "Traffic level: " << trafficLevel << std::endl;
        if (trafficLevel == 1) { // LOW TRAFFIC
            newTrafficSatisfaction = newTrafficSatisfaction - 0;
        }
        else if (trafficLevel == 2) { // MEDIUM TRAFFIC
            newTrafficSatisfaction -= 2;
        }
        else if (trafficLevel == 3) { // HIGH TRAFFIC
            newTrafficSatisfaction -= 3.75;
        }
    }
    
    trafficSatisfaction = newTrafficSatisfaction; 
    
    return trafficSatisfaction;
}

int ResidentialComplex::calculateSatisfaction() {
    // Satisfaction depends on:
    // 1. Traffic
    // 2. Railway level
    // 3. Airport level
    // 4. Employment (commercial buildings)
    // 5. Power, Water, Waste, Sewage in radius
    // 6. Landmarks
    // 7. Facilities (Healthcare, education, security and entertainment) // entartainment can just be landmarks

    int oldSatisfaction = satisfaction;
    satisfaction = trafficSatisfaction + EmploymentSatisfaction + PowerSatisfaction + WaterSatisfaction + WasteSatisfaction + SewageSatisfaction + HealthSatisfaction + EducationSatisfaction + safetySatisfaction;
    // Additonal bonus for landmarks, railway level, airport level
    if (satisfaction + bonusSatisfaction > 100) {
        satisfaction = 100;
    }
    cityMap->aResidentialComponentChangedItsSatifaction(oldSatisfaction, satisfaction);
    return satisfaction;

}

int ResidentialComplex::getCost() {
    std::vector <ResidentialComponent*>::iterator it;
    int totalCost = 0;
    for (it = residentialComponents.begin(); it != residentialComponents.end(); it++) {
        if ((*it) != nullptr) {
            totalCost += (*it)->getCost();
        }
    }
    return totalCost;
}

void ResidentialComplex::printResidentialComplexState() {
    std::cout << "Residential Complex State" << std::endl;
    std::cout << "Traffic Satisfaction: " << trafficSatisfaction << std::endl;
    std::cout << "Employment Satisfaction: " << EmploymentSatisfaction << std::endl;
    std::cout << "Power Satisfaction: " << PowerSatisfaction << std::endl;
    std::cout << "Water Satisfaction: " << WaterSatisfaction << std::endl;
    std::cout << "Waste Satisfaction: " << WasteSatisfaction << std::endl;
    std::cout << "Sewage Satisfaction: " << SewageSatisfaction << std::endl;
    std::cout << "Health Satisfaction: " << HealthSatisfaction << std::endl;
    std::cout << "Education Satisfaction: " << EducationSatisfaction << std::endl;
    std::cout << "Safety Satisfaction: " << safetySatisfaction << std::endl;
    std::cout << "Bonus Satisfaction: " << bonusSatisfaction << std::endl;
    std::cout << "Total Satisfaction: " << satisfaction << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
}

