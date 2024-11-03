#ifndef LANDMARK_FACTORY_H
#define LANDMARK_FACTORY_H

#include "BuildingFactory.h"
#include "Park.h"
#include "Colosseum.h"
#include "Pantheon.h"

class LandmarkFactory : public BuildingFactory {
    public: 
        virtual Landmark* createLandmark() = 0;
        virtual ~LandmarkFactory() {};
};

class ParkFactory : public LandmarkFactory {
    public:
        virtual Landmark* createLandmark() override;
};

class ColosseumFactory : public LandmarkFactory {
    public:
        virtual Landmark* createLandmark() override;
};

class PantheonFactory : public LandmarkFactory {
    public:
        virtual Landmark* createLandmark() override;
};

#endif
