
#include <vector>
#include "BuildingIterator.h"


class LinearBuildingIterator : public BuildingIterator {
private:
    const std::vector<ResidentialComplex*>& buildings;  // Reference to buildings in a ResidentialComplex
    size_t currentIndex;                      // Current index in the iteration

public:
    // Constructor: initialize with a vector of Building pointers
    LinearBuildingIterator(const std::vector<ResidentialComplex*>& buildings)
        : buildings(buildings), currentIndex(0) {}

    // Check if there is another building to iterate over
    bool hasNext() const override {
        return currentIndex < buildings.size();
    }

    // Return the next building in the list and advance the index
    ResidentialComplex* next() override {
        if (!hasNext()) {
            return nullptr;  // Return nullptr if there are no more buildings
        }
        return buildings[currentIndex++];
    }

    // Destructor: nothing to clean up
    ~LinearBuildingIterator() override = default;
};
