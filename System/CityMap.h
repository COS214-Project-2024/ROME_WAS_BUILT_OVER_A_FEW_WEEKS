#ifndef CITY_MAP_H
#define CITY_MAP_H

#include <vector>

class CityHall;
class CityStructure;
class CommercialBuilding;
class IndustrialBuilding;
class ResidentialComplex;
class ResidentialComponent;
class Warehouse;
class Plant;
class Landmark;
class Road;
class Factory;

/**
 * @class CityMap
 * @brief Class representing a map of the city composed of various structures.
 */
class CityMap {
private:
    std::vector<std::vector<CityStructure*>> map; ///< 2D array representing the city map.
    CityHall* cityHall; ///< Pointer to the CityHall structure.
    int width; ///< Width of the city map.
    int height; ///< Height of the city map.

public:
    /**
     * @brief Default constructor for CityMap.
     */
    CityMap();

    /**
     * @brief Parameterized constructor for CityMap.
     * @param width Width of the city map.
     * @param height Height of the city map.
     */
    CityMap(int width, int height);

    /**
     * @brief Destructor for CityMap.
     */
    ~CityMap();

    /**
     * @brief Retrieves the current map.
     * @return 2D vector of CityStructure pointers representing the map.
     */
    std::vector<std::vector<CityStructure*>> getMap();

    void setCityHall(CityHall* cityHall);

    // Structure addition methods with respective traffic and satisfaction adjustments:
    bool addStructure(int x, int y, CityStructure* structure);
    void addBuilding(CityStructure* originator);
    void addRoad(Road* originator);
    void addResidentialComplex(ResidentialComplex* originator);
    void addCommercialBuilding(CommercialBuilding* originator);
    void addPlant(Plant* originator);
    void addIndustrialBuilding(IndustrialBuilding* originator);
    void addWarehouse(Warehouse* originator);
    void addLandmark(Landmark* originator);
    void addFactory(Factory* originator);

    // Residential component checking:
    bool checkResidentialComponent(ResidentialComponent* residential, CityMap* cityMap);

    // Structure removal methods:
    bool removeStructure(int x, int y);
    void removeBuilding(CityStructure* originator);
    void removeRoad(Road* originator);
    void removeResidentialComplex(ResidentialComplex* originator);
    void removeCommercialBuilding(CommercialBuilding* originator);
    void removeIndustrialBuilding(IndustrialBuilding* originator);
    void removeLandmark(Landmark* originator);
    void removePlant(Plant* originator);
    void removeWarehouse(Warehouse* originator);
    void removeFactory(Factory* originator);

    // Residential component management:
    void addResidentialComponent(ResidentialComponent* residential);
    void removeResidentialComponent(ResidentialComponent* residential);
    void aResidentialComponentChangedItsSatifaction(int oldSatisfaction, int newSatisfaction);

    // Resource generation:
    void generateResources(Factory* factory);
};

#endif
