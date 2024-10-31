#include <iostream>
#include "Factory.h"
#include "GeneratorDecorator.h"
#include "ConcreteGenerator.h"
#include "SteelGenerator.h"
#include "WoodGenerator.h"
#include "Material.h"
#include "Concrete.h"
#include "Steel.h"
#include "Wood.h"
#include "Plant.h"
#include "PlantDecorator.h"
#include "PowerPlant.h"
#include "WaterPlant.h"
#include "WastePlant.h"
#include "SewagePlant.h"


using namespace std;

// SET-UP REQUIREMENTS SO FAR:
// Create CityMap and CityHall.
// CityHall needs reference to political system


void testDecorator(){
    cout << "Testing Plants" << endl;
    Plant* plant = new Plant();
    Plant* powerPlant = new PowerPlant(plant);
    Plant* waterPlant = new WaterPlant(powerPlant);
    Plant* powerPlant2 = new PowerPlant(waterPlant);
    Plant* wastePlant = new WastePlant(powerPlant2);
    Plant* sewagePlant = new SewagePlant(wastePlant);

    std::cout << sewagePlant->getPlantType() << std::endl;

    cout << "\nTesting Generators" << endl;
    Factory* factory = new Factory();
    Factory* concreteFactory = new ConcreteGenerator(factory);
    Factory* steelFactory = new SteelGenerator(concreteFactory);
    Factory* woodFactory = new WoodGenerator(steelFactory);


    std::cout << woodFactory->getFactoryType() << std::endl;
}

int main(){

    /*int x = 0;
    int y = 0;
    int z = 0;

    while (true) {
        if (x == 1000000000){
            cout << "Hello" << endl;
            x = 0;
        }
        
        x++;
    }

    while (true){
        x += 1;
        
        if (x % 100000000 == 0){
            y += 1;
        }

        if (y % 1000000 == 0){
            z += 1;
            x = 0;
        }

        if (z % 100000 == 0){
            cout << "x: " << x << " y: " << y << " z: " << z << endl;
            y = 0;
        }
    }*/
    testDecorator();

    return 0;
}