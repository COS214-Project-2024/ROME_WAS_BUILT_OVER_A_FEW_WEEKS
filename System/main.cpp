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


using namespace std;

// SET-UP REQUIREMENTS SO FAR:
// Create CityMap and CityHall.
// CityHall needs reference to political system


void testDecorator(){
    cout << "Testing Decorator" << endl;
    Plant* plant = new Plant();
    Plant* powerPlant = new PowerPlant(plant);
    Plant* waterPlant = new WaterPlant(powerPlant);
    Plant* powerPlant2 = new PowerPlant(waterPlant);

    cout << "Hello" << endl;
    std::cout << powerPlant2->getPlantType() << std::endl;

    
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