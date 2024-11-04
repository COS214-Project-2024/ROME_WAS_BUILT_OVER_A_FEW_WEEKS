#include "WoodGenerator.h"

WoodGenerator::WoodGenerator(Factory* factory) : GeneratorDecorator(factory){
    this->factory = factory;
}

WoodGenerator::~WoodGenerator(){
    delete factory;
}

int WoodGenerator::generate(){
    return generateWood();
}

int WoodGenerator::generateWood(){
    return 100;
}

string WoodGenerator::getFactoryType(){
    return setWoodGenerator();
}


string WoodGenerator::setWoodGenerator(){
    factoryType = "|Wood Factory|" + factory->getFactoryType();
    return this->factoryType;
}

bool WoodGenerator::placeStructure(int x, int y, CityMap *cityMap){
    bool placed = CityStructure::placeStructure(x, y, cityMap);
    if (placed) {
        cityMap->addFactory(this);
        return true;
    }
    else {
        return false;
    }
}

bool WoodGenerator::removeStructure(){
    bool removed = cityMap->removeStructure(x, y);
    if (removed) {
        cityMap->removeFactory(this);
        return true;
    }
    else {
        return false;
    }
}