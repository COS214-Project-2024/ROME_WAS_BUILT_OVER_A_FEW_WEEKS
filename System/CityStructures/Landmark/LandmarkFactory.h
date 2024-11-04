#ifndef LANDMARK_FACTORY_H
#define LANDMARK_FACTORY_H

#include "../BuildingFactory.h"
#include "Park.h"
#include "Colosseum.h"
#include "Pantheon.h"

/**
 * @class LandmarkFactory
 * @brief Abstract factory class for creating Landmark structures.
 *
 * `LandmarkFactory` serves as a base class for specific factories that create landmark types like parks, colosseums, and pantheons.
 */
class LandmarkFactory : public BuildingFactory {
public:
    /**
     * @brief Creates a landmark.
     * @return A pointer to a newly created Landmark object.
     */
    virtual Landmark* createLandmark() = 0;

    /**
     * @brief Virtual destructor for `LandmarkFactory`.
     */
    virtual ~LandmarkFactory() {};
};

/**
 * @class ParkFactory
 * @brief Factory class for creating Park landmarks.
 */
class ParkFactory : public LandmarkFactory {
public:
    /**
     * @brief Creates a Park landmark.
     * @return A pointer to a newly created Park object.
     */
    virtual Landmark* createLandmark() override;
};

/**
 * @class ColosseumFactory
 * @brief Factory class for creating Colosseum landmarks.
 */
class ColosseumFactory : public LandmarkFactory {
public:
    /**
     * @brief Creates a Colosseum landmark.
     * @return A pointer to a newly created Colosseum object.
     */
    virtual Landmark* createLandmark() override;
};

/**
 * @class PantheonFactory
 * @brief Factory class for creating Pantheon landmarks.
 */
class PantheonFactory : public LandmarkFactory {
public:
    /**
     * @brief Creates a Pantheon landmark.
     * @return A pointer to a newly created Pantheon object.
     */
    virtual Landmark* createLandmark() override;
};

#endif // LANDMARK_FACTORY_H
