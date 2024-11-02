#include <iostream>
#include <vector>

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

#include "CityMap.h"
#include "CityHall.h"

// BUILDING TYPES
#include "CityStructure.h"  
#include "Road.h"
#include "ResidentialComplex.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "IndustrialBuilding.h"
#include "Landmark.h"

// RESIDENTIAL BUILDING TYPES
#include "House.h"
#include "Apartment.h"
#include "Townhouse.h"
#include "Estate.h"

// COMMERCIAL BUILDING TYPES
#include "Shop.h"
#include "Mall.h"
#include "Office.h"

// INDUSTRIAL BUILDING TYPES
#include "Plant.h"
#include "Factory.h"
#include "Warehouse.h"

// LANDMARK TYPES
#include "Colosseum.h"
#include "Pantheon.h"
#include "Park.h"

// GRAPHICS
#include <SFML/Graphics.hpp>




using namespace std;
// SET-UP REQUIREMENTS SO FAR:
// Create CityMap and CityHall.
// CityHall needs reference to political system

// void testDecorator(){
//     cout << "Testing Plants" << endl;
//     Plant* plant = new Plant();
//     Plant* powerPlant = new PowerPlant(plant);
//     Plant* waterPlant = new WaterPlant(powerPlant);
//     Plant* powerPlant2 = new PowerPlant(waterPlant);
//     Plant* wastePlant = new WastePlant(powerPlant2);
//     Plant* sewagePlant = new SewagePlant(wastePlant);

//     std::cout << sewagePlant->getPlantType() << std::endl;

//     cout << "\nTesting Generators" << endl;
//     Factory* factory = new Factory();
//     Factory* concreteFactory = new ConcreteGenerator(factory);
//     Factory* steelFactory = new SteelGenerator(concreteFactory);
//     Factory* woodFactory = new WoodGenerator(steelFactory);


//     std::cout << woodFactory->getFactoryType() << std::endl;
// }

int main(){

    cout << "Hello, World!" << endl;

    // CREATE CITY MAP
    cout << "\nCREATE CITY MAP" << endl;
    CityMap* cityMap = new CityMap();

    // CREATE AND PLACE CITY HALL
    cout << "\nCREATE AND PLACE CITY HALL" << endl;
    CityHall* cityHall = CityHall::getInstance();
    cityHall->placeStructure(0, 0, cityMap);

    // CREATE AND PLACE ROADS
    cout << "\nCREATE AND PLACE ROADS" << endl;
    Road* road1 = new Road();
    road1->placeStructure(0, 1, cityMap);
    Road* road2 = new Road();
    road2->placeStructure(1, 1, cityMap);
    Road* road3 = new Road();
    road3->placeStructure(2, 1, cityMap);


    // CREATE AND PLACE RESIDENTIAL COMPLEXES 
    cout << "\nCREATE AND PLACE RESIDENTIAL COMPLEXES" << endl;
    ResidentialBuilding* house1 = new House();
    ResidentialComplex* residentialComplex1 = new ResidentialComplex(house1);
    residentialComplex1->placeStructure(1, 2, cityMap);

    //print states
    cout << "\nPRINT STATES" << endl;
    cityHall->printCityHallState();
    cout << endl;
    residentialComplex1->printResidentialComplexState();

    // CREATE AND PLACE COMMERCIAL BUILDINGS
    cout << "\nCREATE AND PLACE COMMERCIAL BUILDINGS" << endl;
    CommercialBuilding* shop1 = new Shop();
    shop1->placeStructure(2, 2, cityMap);

    //print states
    cout << "\nPRINT STATES" << endl;
    cityHall->printCityHallState();
    cout << endl;
    residentialComplex1->printResidentialComplexState();

    // // CREATE AND PLACE INDUSTRIAL BUILDINGS
    // cout << "\nCREATE AND PLACE INDUSTRIAL BUILDINGS" << endl;
    // Plant* factory1 = new Factory();
    // factory1->placeStructure(3, 2, cityMap);

    // CREATE AND PLACE LANDMARKS
    cout << "\nCREATE AND PLACE LANDMARKS" << endl;
    Landmark* colosseum = new Colosseum();
    colosseum->placeStructure(0, 2, cityMap);

    // PLACE RESIDENTIAL COMPLEX AFTER HAVING COMMERCIAL BUILDING AND LANDMARK
    cout << "\nPLACE RESIDENTIAL COMPLEX AFTER HAVING COMMERCIAL BUILDING AND LANDMARK" << endl;
    ResidentialBuilding* house2 = new House();
    ResidentialComplex* residentialComplex2 = new ResidentialComplex(house2);
    residentialComplex2->placeStructure(3, 1, cityMap);

    //print states
    cout << "\nPRINT STATES" << endl;
    cityHall->printCityHallState();
    cout << endl;
    residentialComplex1->printResidentialComplexState();
    cout << endl;
    residentialComplex2->printResidentialComplexState();




    std::vector<std::vector<CityStructure*> > map = cityMap->getMap();
    cout << "City Map: " << map.size() << endl;
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] != nullptr){
                cout << map[i][j]->getStructureType() << " ";
            }else{
                cout << "NULL ";
            }
        }
        cout << endl;
    }



    cout << "Bye!" << endl; 

    // // =====================
    // // === GRAPHICS PART ===
    // // =====================
    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }
    // // =====================

    
  

    return 0;
}