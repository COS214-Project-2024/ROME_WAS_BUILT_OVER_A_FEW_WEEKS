#ifndef LINEARBUILDINGITERATOR_H
#define LINEARBUILDINGITERATOR_H

#include <vector>
#include "BuildingIterator.h"

/**
 * @class LinearBuildingIterator
 * @brief A concrete iterator that provides linear traversal over a collection of `ResidentialComplex` buildings.
 *
 * The `LinearBuildingIterator` iterates over a vector of `ResidentialComplex` pointers in a linear fashion,
 * starting from the beginning of the collection and moving sequentially to the end.
 */
class LinearBuildingIterator : public BuildingIterator {
private:
    const std::vector<ResidentialComplex*>& buildings;  ///< Reference to buildings in a ResidentialComplex.
    size_t currentIndex;                                ///< Current index in the iteration.

public:
    /**
     * @brief Constructor for `LinearBuildingIterator`.
     * @param buildings A reference to a vector of `ResidentialComplex` pointers to iterate over.
     *
     * Initializes the iterator with the given vector and sets the starting index to 0.
     */
    LinearBuildingIterator(const std::vector<ResidentialComplex*>& buildings);

    /**
     * @brief Checks if there is another building to iterate over.
     * @return `true` if there are more buildings to iterate over, otherwise `false`.
     */
    bool hasNext() const override;

    /**
     * @brief Retrieves the next `ResidentialComplex` in the iteration and advances the index.
     * @return A pointer to the next `ResidentialComplex` object, or `nullptr` if there are no more buildings.
     */
    ResidentialComplex* next() override;
};

#endif  // LINEARBUILDINGITERATOR_H
