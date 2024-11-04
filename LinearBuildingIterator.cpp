#include "LinearBuildingIterator.h"

/**
 * @brief Constructor for `LinearBuildingIterator`.
 * @param buildings A reference to a vector of `ResidentialComplex` pointers to iterate over.
 *
 * Initializes the iterator with the given vector and sets the starting index to 0.
 */
LinearBuildingIterator::LinearBuildingIterator(const std::vector<ResidentialComplex*>& buildings)
    : buildings(buildings), currentIndex(0) {}

/**
 * @brief Checks if there is another building to iterate over.
 * @return `true` if there are more buildings to iterate over, otherwise `false`.
 */
bool LinearBuildingIterator::hasNext() const {
    return currentIndex < buildings.size();
}

/**
 * @brief Retrieves the next `ResidentialComplex` in the iteration and advances the index.
 * @return A pointer to the next `ResidentialComplex` object, or `nullptr` if there are no more buildings.
 */
ResidentialComplex* LinearBuildingIterator::next() {
    if (!hasNext()) {
        return nullptr;  // Return nullptr if there are no more buildings
    }
    return buildings[currentIndex++];
}
