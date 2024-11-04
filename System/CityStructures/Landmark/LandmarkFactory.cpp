#include "LandmarkFactory.h"

// NEED TO DO RADIOUS

Landmark* ParkFactory::createLandmark() {
    return new Park(); 
}

Landmark* ColosseumFactory::createLandmark() {
    return new Colosseum(); 
}

Landmark* PantheonFactory::createLandmark() {
    return new Pantheon(); 
}