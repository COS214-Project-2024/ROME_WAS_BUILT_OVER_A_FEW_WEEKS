#include <iostream>

#include "../../CityMap.h"
#include "ResidentialBuilding.h"

#include "../../GameSimulation.h"

ResidentialBuilding::ResidentialBuilding(int capacity) : capacity(capacity) {
    // EMPTY
}

ResidentialBuilding::~ResidentialBuilding() {
    // EMPTY
}

std::string ResidentialBuilding::getStructureType() {
    return "Residential";
}

void ResidentialBuilding::placeStructure(int x, int y, CityMap* cityMap) {
    // You cannot place a residential building on its own 
    //(because then you cant add more residential components to make a complex)
    std::cout << "You cannot place a residential building on its own" << std::endl;
}

void ResidentialBuilding::removeStructure() {
    // You cannot remove a residential building on its own
    std::cout << "You cannot remove a residential building on its own" << std::endl;
}

int ResidentialBuilding::getCapacity() {
    std::cout << "Getting capacity BUILDING" << capacity << std::endl;
    return capacity;
}

int ResidentialBuilding::calculateCapacity() {
    return capacity;
}

int ResidentialBuilding::getCost() {
    return cost;
}
