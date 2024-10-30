#ifndef LANDMARK_FACTORY_H
#define LANDMARK_FACTORY_H

#include "BuildingFactory.h"
#include "Park.h"
#include "Monument.h"
#include "CulturalCenter.h"

class LandmarkFactory : public BuildingFactory {
    public: 
        virtual Landmark* createLandmark() = 0;
        virtual ~LandmarkFactory() {};
};

class ParkFactory : public LandmarkFactory {
    public:
        virtual Landmark* createLandmark() override;
};

class MonumentFactory : public LandmarkFactory {
    public:
        virtual Landmark* createLandmark() override;
};

class CulturalCenterFactory : public LandmarkFactory {
    public:
        virtual Landmark* createLandmark() override;
};

#endif
