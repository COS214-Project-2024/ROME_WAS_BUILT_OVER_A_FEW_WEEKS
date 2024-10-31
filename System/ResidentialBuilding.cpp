#include <iostream>

#include "CityMap.h"
#include "ResidentialBuilding.h"

ResidentialBuilding::ResidentialBuilding(int capacity) : capacity(capacity) {
    // EMPTY
}

ResidentialBuilding::~ResidentialBuilding() {
    // EMPTY
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
    return capacity;
}

int ResidentialBuilding::calculateCapacity() {
    return capacity;
}

// for cloning
ResidentialBuilding* ResidentialBuilding::clone() const{
    return new ResidentialBuilding(*this);
}