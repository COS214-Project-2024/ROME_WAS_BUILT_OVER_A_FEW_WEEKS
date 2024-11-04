#include "SteelGenerator.h"

SteelGenerator::SteelGenerator(Factory* factory) : GeneratorDecorator(factory){
    this->factory = factory;
}

SteelGenerator::~SteelGenerator(){
    delete factory;
}


int SteelGenerator::generate(){
    return generateSteel();
}

int SteelGenerator::generateSteel(){
    return 100;
}

string SteelGenerator::getFactoryType(){
    return setSteelGenerator();
}

string SteelGenerator::setSteelGenerator(){
    factoryType = "|Steel Factory|" + factory->getFactoryType();
    return this->factoryType;
}

bool SteelGenerator::placeStructure(int x, int y, CityMap *cityMap){
    bool placed = CityStructure::placeStructure(x, y, cityMap);
    if (placed) {
        cityMap->addFactory(this);
        return true;
    }
    else {
        return false;
    }
}

bool SteelGenerator::removeStructure(){
    bool removed = cityMap->removeStructure(x, y);
    if (removed) {
        cityMap->removeFactory(this);
        return true;
    }
    else {
        return false;
    }
}