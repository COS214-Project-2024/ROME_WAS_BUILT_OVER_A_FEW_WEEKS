//JARED TESTING

// Booster Structures
#include "./BoosterStructures/Airport.h"
#include "./BoosterStructures/BoosterStructures.h"
#include "./BoosterStructures/Railway.h"
#include "./BoosterStructures/Hospital.h"
#include "./BoosterStructures/PoliceStation.h"
#include "./BoosterStructures/School.h"

// Check Adjacent Template
#include "./CheckAdjacentTemplate/CheckAdjacent.h"

// City Structures - Residential
#include "./CityStructures/Residential/Apartment.h"
#include "./CityStructures/Residential/Estate.h"
#include "./CityStructures/Residential/House.h"
#include "./CityStructures/Residential/ResidentialBuilding.h"
#include "./CityStructures/Residential/ResidentialComplex.h"
#include "./CityStructures/Residential/Townhouse.h"

// City Structures - Commercial
#include "./CityStructures/Commercial/CommercialBuilding.h"
#include "./CityStructures/Commercial/Mall.h"
#include "./CityStructures/Commercial/Office.h"
#include "./CityStructures/Commercial/Shop.h"

// City Structures - Industrial
#include "./CityStructures/Industrial/Concrete.h"
#include "./CityStructures/Industrial/ConcreteGenerator.h"
#include "./CityStructures/Industrial/Factory.h"
#include "./CityStructures/Industrial/IndustrialBuilding.h"
#include "./CityStructures/Industrial/Plant.h"
#include "./CityStructures/Industrial/PowerPlant.h"
#include "./CityStructures/Industrial/SewagePlant.h"
#include "./CityStructures/Industrial/Steel.h"
#include "./CityStructures/Industrial/SteelGenerator.h"
#include "./CityStructures/Industrial/Warehouse.h"
#include "./CityStructures/Industrial/WastePlant.h"
#include "./CityStructures/Industrial/WaterPlant.h"
#include "./CityStructures/Industrial/Wood.h"
#include "./CityStructures/Industrial/WoodGenerator.h"

// City Structures - Landmark
#include "./CityStructures/Landmark/Colosseum.h"
#include "./CityStructures/Landmark/Landmark.h"
#include "./CityStructures/Landmark/Pantheon.h"
#include "./CityStructures/Landmark/Park.h"

// City Structures - Road
#include "./CityStructures/Road/HighTraffic.h"
#include "./CityStructures/Road/LowTraffic.h"
#include "./CityStructures/Road/MediumTraffic.h"
#include "./CityStructures/Road/Road.h"

// Political System
#include "./PoliticalSystem/Authoritarianism.h"
#include "./PoliticalSystem/Communism.h"
#include "./PoliticalSystem/Democracy.h"
#include "./PoliticalSystem/PoliticalSystem.h"

// Satisfaction Handlers
#include "./SatisfactionHandler/HighSatisfactionHandler.h"
#include "./SatisfactionHandler/LowSatisfactionHandler.h"
#include "./SatisfactionHandler/MediumSatisfactionHandler.h"
#include "./SatisfactionHandler/SatisfactionHandler.h"

// Factory Methods
#include "./CityStructures/BuildingFactory.h"
#include "./CityStructures/Commercial/CommercialFactory.h"
#include "./CityStructures/Industrial/IndustrialFactory.h"
#include "./CityStructures/Landmark/LandmarkFactory.h"
#include "./CityStructures/Residential/ResidentialFactory.h"

// Iterators

#include "LinearBuildingIterator.cpp"
#include "BuildingIterator.h"

// Core City Classes
#include "CityHall.h"
#include "CityMap.h"
#include "./CityStructures/CityStructure.h"

using namespace std;

#include <iostream>

int main() {
    
    cout << "=========================================================================================================================================" << endl;

    cout << "\t\t\t⠀⠀⠀⠀⠀⢀⣠⣤⣤⣶⣶⣶⣶⣶⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "\t\t\t⠀⠀⢀⣴⣾⣿⣿⠿⢿⣿⣿⠏⠉⠉⠹⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "\t\t\t⠀⣴⣿⠟⢻⣿⠁⠀⠀⣿⣿⠀⠀⠀⠀⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "\t\t\t⢰⣿⡇⠀⢸⣿⣀⣤⣤⣿⣿⣶⣶⣶⣶⣿⣿⣿⣷⣄⡀⠀⠀⠀⠀⠀" << endl;
    cout << "\t\t\t⢸⣿⣧⣴⣿⣿⣿⡿⣿⣿⣿⡟⠉⠉⢻⣿⣿⣿⢿⣿⣿⣷⣦⣄⠀⠀" << endl;
    cout << "\t\t\t⢸⣿⣿⠟⢻⣿⠃⠀⠀⣿⣿⠀⠀⠀⠀⣿⣿⠀⠀⠘⣿⡟⠙⣿⣷⡀" << endl;
    cout << "\t\t\t⢸⣿⡇⠀⢸⣿⠀⠀⠀⣿⣿⣀⣀⣀⣀⣿⣿⠀⠀⠀⣿⡇⠀⢸⣿⡇" << endl;
    cout << "\t\t\t⢸⣿⣧⣴⣾⣿⣿⣿⣿⣿⣿⣿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣼⣿⡇" << endl;
    cout << "\t\t\t⢸⣿⡿⠋⢹⣿⠋⠀⠈⣿⣿⠃⠀⠀⠘⣿⣿⠁⠀⠙⣿⡏⠙⢿⣿⡇" << endl;
    cout << "\t\t\t⢸⣿⣧⣤⣼⣿⣤⣤⣤⣿⣿⣤⣤⣤⣤⣿⣿⣤⣤⣤⣿⣧⣤⣼⣿⡇" << endl;
    cout << "\t\t\t⠈⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠁" << endl;

    std::cout << "  ____                                               _           _ _ _   \n";
    std::cout << " |  _ \\ ___  _ __ ___   ___   __      ____ _ ___    | |__  _   _(_) | |_ \n";
    std::cout << " | |_) / _ \\| '_ ` _ \\ / _ \\  \\ \\ /\\ / / _` / __|   | '_ \\| | | | | | __|\n";
    std::cout << " |  _ < (_) | | | | | |  __/   \\ V  V / (_| \\__ \\   | |_) | |_| | | | |_ \n";
    std::cout << " |_| \\_\\___/|_| |_| |_|\\___|    \\_/\\_/ \\__,_|___/   |_.__/ \\__,_|_|_|\\__|\n";
    std::cout << "         / _ \\__   _____ _ __      __ _     / _| _____      __           \n";
    std::cout << "        | | | \\ \\ / / _ \\ '__|    / _` |   | |_ / _ \\ \\ /\\ / /           \n";
    std::cout << "        | |_| |\\ V /  __/ |      | (_| |   |  _|  __/\\ V  V /            \n";
    std::cout << "         \\___/  \\_/ \\___|_|       \\__,_|   |_|  \\___| \\_/\\_/             \n";
    std::cout << "                 __      _____  ___| | _____                             \n";
    std::cout << "                 \\ \\ /\\ / / _ \\/ _ \\ |/ / __|                            \n";
    std::cout << "                  \\ V  V /  __/  __/   <\\__ \\                            \n";
    std::cout << "                   \\_/\\_/ \\___|\\___|_|\\_\\___/                            \n";

    cout << "\n" << endl;
    cout << "\t\t\t⠀⠀⠀⠀⠀⢀⣠⣤⣤⣶⣶⣶⣶⣶⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "\t\t\t⠀⠀⢀⣴⣾⣿⣿⠿⢿⣿⣿⠏⠉⠉⠹⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "\t\t\t⠀⣴⣿⠟⢻⣿⠁⠀⠀⣿⣿⠀⠀⠀⠀⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "\t\t\t⢰⣿⡇⠀⢸⣿⣀⣤⣤⣿⣿⣶⣶⣶⣶⣿⣿⣿⣷⣄⡀⠀⠀⠀⠀⠀" << endl;
    cout << "\t\t\t⢸⣿⣧⣴⣿⣿⣿⡿⣿⣿⣿⡟⠉⠉⢻⣿⣿⣿⢿⣿⣿⣷⣦⣄⠀⠀" << endl;
    cout << "\t\t\t⢸⣿⣿⠟⢻⣿⠃⠀⠀⣿⣿⠀⠀⠀⠀⣿⣿⠀⠀⠘⣿⡟⠙⣿⣷⡀" << endl;
    cout << "\t\t\t⢸⣿⡇⠀⢸⣿⠀⠀⠀⣿⣿⣀⣀⣀⣀⣿⣿⠀⠀⠀⣿⡇⠀⢸⣿⡇" << endl;
    cout << "\t\t\t⢸⣿⣧⣴⣾⣿⣿⣿⣿⣿⣿⣿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣼⣿⡇" << endl;
    cout << "\t\t\t⢸⣿⡿⠋⢹⣿⠋⠀⠈⣿⣿⠃⠀⠀⠘⣿⣿⠁⠀⠙⣿⡏⠙⢿⣿⡇" << endl;
    cout << "\t\t\t⢸⣿⣧⣤⣼⣿⣤⣤⣤⣿⣿⣤⣤⣤⣤⣿⣿⣤⣤⣤⣿⣧⣤⣼⣿⡇" << endl;
    cout << "\t\t\t⠈⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠁" << endl;
    cout << "=========================================================================================================================================" << endl;

    //Test Residential Factories
    std::cout << "\033[1mCREATING RESIDENTIAL BUILDINGS USING FACTORY METHOD\033[0m" << std::endl;
    HouseFactory houseFactory;
    ResidentialBuilding* house = houseFactory.createResidentialBuilding();
    std::cout << "Created house with capacity: " << house->getCapacity() << std::endl;

    ApartmentFactory apartmentFactory;
    ResidentialBuilding* apartment = apartmentFactory.createResidentialBuilding();
    std::cout << "Created apartment with capacity: " << apartment->getCapacity() << std::endl;

    EstateFactory estateFactory;
    ResidentialBuilding* estate = estateFactory.createResidentialBuilding();
    std::cout << "Created estate with capacity: " << estate->getCapacity() << std::endl;

    TownhouseFactory townhouseFactory;
    ResidentialBuilding* townhouse = townhouseFactory.createResidentialBuilding();
    std::cout << "Created townhouse with capacity: " << townhouse->getCapacity() << std::endl;

    // Test Commercial Factories
    std::cout << "\n\033[1mCREATING COMMERCIAL BUILDINGS USING FACTORY METHOD\033[0m" << std::endl;
    ShopFactory shopFactory;
    CommercialBuilding* shop = shopFactory.createCommercialBuilding();
    std::cout << "Created shop with radius of effect: " << static_cast<Shop*>(shop)->getRadiusOfEffect() << std::endl;

    OfficeFactory officeFactory;
    CommercialBuilding* office = officeFactory.createCommercialBuilding();
    std::cout << "Created office with radius of effect: " << static_cast<Office*>(office)->getRadiusOfEffect() << std::endl;

    MallFactory mallFactory;
    CommercialBuilding* mall = mallFactory.createCommercialBuilding();
    std::cout << "Created mall with radius of effect: " << static_cast<Mall*>(mall)->getRadiusOfEffect() << std::endl;

    // Test Landmark Factories
    std::cout << "\n\033[1mCREATING LANDMARKS USING FACTORY METHOD\033[0m" << std::endl;
    ParkFactory parkFactory;
    Landmark* park = parkFactory.createLandmark();
    std::cout << "Created park with radius of effect: " << static_cast<Park*>(park)->getRadiusOfEffect() << std::endl;

    ColosseumFactory colosseumFactory;
    Landmark* colosseum = colosseumFactory.createLandmark();
    std::cout << "Created colosseum with radius of effect: " << static_cast<Colosseum*>(colosseum)->getRadiusOfEffect() << std::endl;

    PantheonFactory pantheonFactory;
    Landmark* pantheon = pantheonFactory.createLandmark();
    std::cout << "Created cultural center with radius of effect: " << static_cast<Pantheon*>(pantheon)->getRadiusOfEffect() << std::endl;
    

    // Test Industrial Factories
    std::cout << "\n\033[1mCREATING INDUSTRIAL BUILDINGS USING FACTORY METHOD\033[0m" << std::endl;
    PlantFactory plantFactory;
    IndustrialBuilding* plant = plantFactory.createIndustrialBuilding();
    std::cout << "Created plant" << std::endl;

    FactoryFactory factoryFactory;
    IndustrialBuilding* factory = factoryFactory.createIndustrialBuilding();
    std::cout << "Created factory" << std::endl;

    WarehouseFactory warehouseFactory;
    IndustrialBuilding* warehouse = warehouseFactory.createIndustrialBuilding();
    std::cout << "Created warehouse" << std::endl;

    //Create factories and generators
    std::cout << "\n\033[1mCREATING GENERATORS USING DECORATOR PATTERN\033[0m" << std::endl;
    ConcreteGenerator* concreteGenerator = new ConcreteGenerator(static_cast<Factory*>(factory));
    SteelGenerator* steelGenerator = new SteelGenerator(concreteGenerator);
    WoodGenerator* woodGenerator = new WoodGenerator(steelGenerator);
    std::cout << "Factory type of all three: " << woodGenerator->getFactoryType() << std::endl;

    std::cout << "\n\033[1mCREATING PLANTS USING DECORATOR PATTERN\033[0m" << std::endl;
    Plant* powerPlant = new PowerPlant(static_cast<Plant*>(plant));
    Plant* sewagePlant = new SewagePlant(powerPlant);
    std::cout << "Plant type of power and sewage: " << sewagePlant->getPlantType() << std::endl;
    Plant* waterPlant = new WaterPlant(new Plant());
    Plant* wastePlant = new WastePlant(waterPlant);
    std::cout << "Plant type of water and waste: " << wastePlant->getPlantType() << std::endl;

    //Creating city map
    std::cout << "\n\033[1mCREATING CITY MAP\033[0m" << std::endl;
    CityMap* cityMap = new CityMap();
    std::cout << "City map created" << std::endl;

    //Creating city hall
    std::cout << "\n\033[1mCREATING CITY HALL\033[0m" << std::endl;
    CityHall* cityHall = CityHall::getInstance();


    //Creating political system
    std::cout << "\n\033[1mCREATING POLITICAL SYSTEM\033[0m" << std::endl;
    PoliticalSystem* democracy = new Democracy();
    PoliticalSystem* communsim = new Communism();
    PoliticalSystem* authoritarianism = new Authoritarianism();
    std::cout << "Poloitical systems created" << std::endl;

    //Setting political system
    std::cout << "\n\033[1mCHOOSE YOUR POLITICAL SYSTEM\033[0m" << std::endl;
    std::cout << "\n\033[1m1: DEMOCRACY\033[0m" << std::endl;
    std::cout << "\n\033[1m2: COMMUNISM\033[0m" << std::endl;
    std::cout << "\n\033[1m3: AUTHORITARIANISM\033[0m" << std::endl;
    std::cout << "\n\033[1mENTER YOUR CHOICE: \033[0m" << std::endl;
    int choice;
    std::cin >> choice;
    
    //check if choice is a valid number
    if(std::cin.fail()){
        std::cout << "Invalid choice" << std::endl;
        return 0;
    }
    if(choice < 1 || choice > 3){
        std::cout << "Invalid choice" << std::endl;
        return 0;
    }
    if (choice == 1) {
        cityHall->setPoliticalSystem(democracy);
        std::cout << "\n\033[1mDEMOCRACY CHOSEN\033[0m" << std::endl;
    }
    else if (choice == 2) {
        cityHall->setPoliticalSystem(communsim);
        std::cout << "\n\033[1mCOMMUNISM CHOSEN\033[0m" << std::endl;
    }
    else if (choice == 3) {
        cityHall->setPoliticalSystem(authoritarianism);
        std::cout << "\n\033[1mAUTHORITARIANISM CHOSEN\033[0m" << std::endl;
    }

    cityHall->placeStructure(0, 0, cityMap);
    std::cout << "City hall created and placed at position 0,0 on map" << std::endl;

    //Print out map after placing city hall
    std::cout << "\n\033[1mPRINTING CITY MAP AFTER PLACING CITY HALL\033[0m" << std::endl;
    cout << "=========================================================================================================================================" << endl;

    std::vector<std::vector<CityStructure*> > map = cityMap->getMap();
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] != nullptr) {
                std::cout << map[i][j]->getStructureType() << " ";
            }
            else {
                std::cout << "NULL ";
            }
        }
        std::cout << std::endl;
    }
    cout << "=========================================================================================================================================" << endl;

    //Create and place roads at edges of map
    std::cout << "\n\033[1mCREATING AND PLACING ROADS\033[0m" << std::endl;
    std::cout << "\n\033[1mROAD 1 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road1 = new Road();
    road1->placeStructure(0, 1, cityMap);
    std::cout << "\n\033[1mROAD 2 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road2 = new Road();
    road2->placeStructure(0, 2, cityMap);
    std::cout << "\n\033[1mROAD 3 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road3 = new Road();
    road3->placeStructure(0, 3, cityMap);
    std::cout << "\n\033[1mROAD 4 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road4 = new Road();
    road4->placeStructure(0, 4, cityMap);
    std::cout << "\n\033[1mROAD 5 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road5 = new Road();
    road5->placeStructure(0, 5, cityMap);
    std::cout << "\n\033[1mROAD 6 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road6 = new Road();
    road6->placeStructure(0, 6, cityMap);
    std::cout << "\n\033[1mROAD 7 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road7 = new Road();
    road7->placeStructure(0, 7, cityMap);
    std::cout << "\n\033[1mROAD 8 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road8 = new Road();
    road8->placeStructure(0, 8, cityMap);
    std::cout << "\n\033[1mROAD 9 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road9 = new Road();
    road9->placeStructure(0, 9, cityMap);
    std::cout << "\n\033[1mROAD 10 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road10 = new Road();
    road10->placeStructure(0, 10, cityMap);
    std::cout << "\n\033[1mROAD 11 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road11 = new Road();
    road11->placeStructure(0, 11, cityMap);
    std::cout << "\n\033[1mROAD 12 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road12 = new Road();
    road12->placeStructure(0, 12, cityMap);
    std::cout << "\n\033[1mROAD 13 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road13 = new Road();
    road13->placeStructure(0, 13, cityMap);
    std::cout << "\n\033[1mROAD 14 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road14 = new Road();
    road14->placeStructure(0, 14, cityMap);
    std::cout << "\n\033[1mROAD 15 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road15 = new Road();
    road15->placeStructure(0, 15, cityMap);
    std::cout << "\n\033[1mROAD 16 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road16 = new Road();
    road16->placeStructure(0, 16, cityMap);
    std::cout << "\n\033[1mROAD 17 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road17 = new Road();
    road17->placeStructure(0, 17, cityMap);
    std::cout << "\n\033[1mROAD 18 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road18 = new Road();
    road18->placeStructure(0, 18, cityMap);
    std::cout << "\n\033[1mROAD 19 AND ITS AFFECTS\033[0m" << std::endl;
    Road* road19 = new Road();
    road19->placeStructure(0, 19, cityMap);

    std::cout << "\n\033[1mCREATED AND PLACED ROADS AT LEFT EDGE OF THE MAP\033[0m" << std::endl;



    //Print out map after placing roads
    std::cout << "\n\033[1mPRINTING CITY MAP AFTER PLACING ROADS\033[0m" << std::endl;
    cout << "=========================================================================================================================================" << endl;

    map = cityMap->getMap();
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] != nullptr) {
                std::cout << map[i][j]->getStructureType() << " ";
            }
            else {
                std::cout << "NULL ";
            }
        }
        std::cout << std::endl;
    }
    cout << "=========================================================================================================================================" << endl;

    //Print city hall state
    std::cout << "\n\033[1mPRINTING CITY HALL STATE\033[0m" << std::endl;
    cityHall->printCityHallState();

    //Create and place residential complex 
    std::cout << "\n\033[1mCREATING AND PLACING RESIDENTIAL COMPLEX\033[0m" << std::endl;
    ResidentialComplex* residentialComplex1 = new ResidentialComplex(house);
    residentialComplex1->placeStructure(1, 1, cityMap);
    std::cout << "Residential complex created and placed at position 1,1 on map" << std::endl;

    //Print out map after placing residential complex
    std::cout << "\n\033[1mPRINTING CITY MAP AFTER PLACING RESIDENTIAL COMPLEX\033[0m" << std::endl;
    cout << "=========================================================================================================================================" << endl;

    map = cityMap->getMap();
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] != nullptr) {
                std::cout << map[i][j]->getStructureType() << " ";
            }
            else {
                std::cout << "NULL ";
            }
        }
        std::cout << std::endl;
    }
    cout << "=========================================================================================================================================" << endl;

    //Print residential complex state
    std::cout << "\n\033[1mPRINTING RESIDENTIAL COMPLEX STATE\033[0m" << std::endl;
    residentialComplex1->printResidentialComplexState();

    //Create and place commercial building
    std::cout << "\n\033[1mPLACING COMMERCIAL BUILDING THATS NOT NEXT TO A ROAD\033[0m" << std::endl;
    shop->placeStructure(2, 2, cityMap);

    std::cout << "\n\033[1mPLACING COMMERCIAL BUILDING NEXT TO ROAD\033[0m" << std::endl;
    office->placeStructure(1, 2, cityMap);

    //Place plant
    std::cout << "\n\033[1mPLACING PLANT BUILDING\033[0m" << std::endl;
    sewagePlant->placeStructure(1, 3, cityMap);

    //Place landmark
    std::cout << "\n\033[1mPLACING LANDMARK BUILDING\033[0m" << std::endl;
    park->placeStructure(1, 4, cityMap);

    //Place warehouse
    std::cout << "\n\033[1mPLACING WAREHOUSE BUILDING\033[0m" << std::endl;
    int storageCapacity = cityHall->getStorageCapacity();
    warehouse->placeStructure(1, 5, cityMap);
    std::cout << "\n\033[1mSTORAGE CAPACITY BEFORE PLACING WAREHOUSE: \033[0m" << storageCapacity << std::endl;
    std::cout << "\033[1mSTORAGE CAPACITY AFTER PLACING WAREHOUSE: \033[0m" << cityHall->getStorageCapacity() << std::endl;

    //Place generator
    std::cout << "\n\033[1mPLACING GENERATOR BUILDING\033[0m" << std::endl;
    steelGenerator->placeStructure(1, 6, cityMap);
    std::cout << "\n\033[1mGENERATOR TYPE PLACED: \033[0m" << steelGenerator->getFactoryType() << std::endl;
    std::cout << "\033[1mNumber of factories: \033[0m" << cityHall->getNumFactories() << std::endl;
    std::cout << "\033[1mGENERATE RESOURCES\033[0m" << std::endl;
    cityMap->generateResources(steelGenerator);
    std::cout << "\n" << std::endl;
    woodGenerator->placeStructure(1, 7, cityMap);
    std::cout << "\n\033[1mGENERATOR TYPE PLACED: \033[0m" << woodGenerator->getFactoryType() << std::endl;
    std::cout << "\033[1mNumber of factories: \033[0m" << cityHall->getNumFactories() << std::endl;
    std::cout << "\033[1mGENERATE RESOURCES\033[0m" << std::endl;
    cityMap->generateResources(woodGenerator);

    //Add component to complex
    std::cout << "\n\033[1mADDING COMPONENT TO RESIDENTIAL COMPLEX\033[0m" << std::endl;
    residentialComplex1->addResidentialComponent(apartment, cityMap);

    //Clone residential complex
    std::cout << "\n\033[1mCLONING RESIDENTIAL COMPLEX\033[0m" << std::endl;
    ResidentialComponent* residentialComplex2 = residentialComplex1->clone();
    std::cout << "Residential complex cloned" << std::endl;
    residentialComplex2->placeStructure(1, 8, cityMap);

    //Iterate through residential complex
    std::cout << "\n\033[1mITERATING THROUGH RESIDENTIAL COMPLEX\033[0m" << std::endl;
    std::vector<ResidentialComponent*> residentialComponents = residentialComplex1->getResidentialComponents();
    LinearBuildingIterator* linearBuildingIterator = new LinearBuildingIterator(residentialComponents);
    while (linearBuildingIterator->hasNext()) {
        std::cout << "Structure type: ";
        std::cout << linearBuildingIterator->next()->getStructureType() << std::endl;
    }

    //Print out map after placing buildings
    std::cout << "\n\033[1mPRINTING CITY MAP AFTER PLACING BUILDINGS\033[0m" << std::endl;
    cout << "=========================================================================================================================================" << endl;

    map = cityMap->getMap();
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] != nullptr) {
                std::cout << map[i][j]->getStructureType() << " ";
            }
            else {
                std::cout << "NULL ";
            }
        }
        std::cout << std::endl;
    }
    cout << "=========================================================================================================================================" << endl;

    //Print city hall state
    std::cout << "\n\033[1mPRINTING CITY HALL STATE\033[0m" << std::endl;
    cityHall->printCityHallState();

    //Remove residential complex
    std::cout << "\n\033[1mREMOVING RESIDENTIAL COMPLEX\033[0m" << std::endl;
    residentialComplex1->removeStructure();
    std::cout << "Residential complex removed" << std::endl;

    std::cout << "\n\033[1mREMOVE WAREHOUSE\033[0m" << std::endl;
    storageCapacity = cityHall->getStorageCapacity();
    warehouse->removeStructure();
    std::cout << "\n\033[1mSTORAGE CAPACITY BEFORE REMOVING WAREHOUSE: \033[0m" << storageCapacity << std::endl;
    std::cout << "\033[1mSTORAGE CAPACITY AFTER REMOVING WAREHOUSE: \033[0m" << cityHall->getStorageCapacity() << std::endl;

    //Print out map after removing buildings
    std::cout << "\n\033[1mPRINTING CITY MAP AFTER REMOVING BUILDINGS\033[0m" << std::endl;
    std::cout << "=========================================================================================================================================" << std::endl;

    map = cityMap->getMap();
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] != nullptr) {
                std::cout << map[i][j]->getStructureType() << " ";
            }
            else {
                std::cout << "NULL ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "=========================================================================================================================================" << std::endl;

    //Print city hall state
    std::cout << "\n\033[1mPRINTING CITY HALL STATE\033[0m" << std::endl;
    cityHall->printCityHallState();
    


    return 0;
}
