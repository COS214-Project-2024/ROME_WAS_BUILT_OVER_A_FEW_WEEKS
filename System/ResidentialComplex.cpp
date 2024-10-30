#include <iostream>
#include <vector>

#include "CityMap.h"
#include "ResidentialComponent.h"
#include "ResidentialComplex.h"

ResidentialComplex::ResidentialComplex(ResidentialComponent* residential)  {
    addResidentialComponent(residential);
    satisfaction = 100;
    capacity = residential->calculateCapacity();
}

void ResidentialComplex::placeStructure(int x, int y, CityMap* cityMap) {
    CityStructure::placeStructure(x, y, cityMap);
    cityMap->addBuilding(this);
}

void ResidentialComplex::removeStructure() {
    cityMap->removeStructure(x, y);
}

ResidentialComplex::~ResidentialComplex() {
    std::vector<ResidentialComponent*>::iterator it;
    for (it = residentialComponents.begin(); it != residentialComponents.end(); it++) {
        delete *it;
    }
}

void ResidentialComplex::newRoadWasAdded() {
    calculateTrafficSatisfaction(); // sets the traffic satisfaction
    calculateSatisfaction();
}

void ResidentialComplex::newCommercialBuildingWasAdded() {
    EmploymentSatisfaction += 1;
    calculateSatisfaction();
}

void ResidentialComplex::newIndustrialBuildingWasAdded() {  // FIX
    EmploymentSatisfaction += 1;
    calculateSatisfaction();
}

void ResidentialComplex::newLandmarkWasAdded() {
    satisfaction += 1;
}



int ResidentialComplex::getCapacity() {
    return capacity;
}

void ResidentialComplex::addResidentialComponent(ResidentialComponent* residential) {
    residentialComponents.push_back(residential);
    calculateCapacity(); // Recalculate the capacity of the complex and set the member variable
}

int ResidentialComplex::calculateCapacity(){
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
    std::vector<std::vector<CityStructure*> > cityMap = this->cityMap->getMap();
    int newTrafficSatisfaction = 0;
    // Check the squares around the complex
    // CHeck if it is road
    // If it is road, check the traffic state

    // USE TEMPLATE METHOD PATTERN

    // if (cityMap.at(y).at(x+1) != nullptr) {
    //     newTrafficSatisfaction += 1;
    // }
    // if (cityMap.at(y).at(x-1) != nullptr) {
    //     newTrafficSatisfaction += 1;
    // }
    // if (cityMap.at(y+1).at(x) != nullptr) {
    //     newTrafficSatisfaction += 1;
    // }
    // if (cityMap.at(y-1).at(x) != nullptr) {
    //     newTrafficSatisfaction += 1;
    // }

    trafficSatisfaction = newTrafficSatisfaction; 
    
    //return trafficSatisfaction;
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

    satisfaction = trafficSatisfaction + EmploymentSatisfaction + PowerSatisfaction + WaterSatisfaction + WasteSatisfaction + SewageSatisfaction + HealthSatisfaction + EducationSatisfaction + safetySatisfaction;
    // Additonal bonus for landmarks, railway level, airport level
    return satisfaction;

}



