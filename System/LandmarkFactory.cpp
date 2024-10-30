#include "LandmarkFactory.h"

// NEED TO DO RADIOUS

Landmark* ParkFactory::createLandmark() {
    return new Park(8); 
}

Landmark* MonumentFactory::createLandmark() {
    return new Monument(6); 
}

Landmark* CulturalCenterFactory::createLandmark() {
    return new CulturalCenter(9); 
}