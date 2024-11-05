#include "GameSimulation.h"
#include "CityStructure.h"
#include "CityMap.h"
#include "CityHall.h"

#include <iostream>
#include <random>

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

#include <iostream>
#include <random>

#include <thread>
#include <chrono>


GameSimulation::GameSimulation(CityHall *cityHall, CityMap *cityMap) {
    // Set references to game objects
    this->cityHall = cityHall;
    this->cityMap = cityMap;

    // Create window (no need to use new)
    window.create(sf::VideoMode(1120, 630), "Rome Was Built In a Day", sf::Style::Close );
    timePerFrame = sf::seconds(1.f / 60.f);

    // Sleep
    //std::this_thread::sleep_for(std::chrono::seconds(8));

    // Viewport (cameraView as a regular member)
    cameraView.setSize(1120, 630);
    cameraView.setCenter(1120 / 2, 630 / 2);
    window.setView(cameraView);

    // Load textures
    textures["Apartment"].loadFromFile("../images/spr_Apartment.png");
    textures["CityHall"].loadFromFile("../images/spr_CityHall.png");
    textures["Estate"].loadFromFile("../images/spr_Estate.png");
    textures["Factory"].loadFromFile("../images/spr_Factory.png");
    textures["House"].loadFromFile("../images/spr_House.png");
    textures["Landscape1"].loadFromFile("../images/spr_Landscape1.png");
    textures["Landscape2"].loadFromFile("../images/spr_Landscape2.png");
    textures["Landscape3"].loadFromFile("../images/spr_Landscape3.png");
    textures["Colosseum"].loadFromFile("../images/spr_Monument.png");
    textures["Office"].loadFromFile("../images/spr_Office.png");
    textures["Park"].loadFromFile("../images/spr_Park.png");
    textures["Plant"].loadFromFile("../images/spr_Plant.png");
    textures["Road1"].loadFromFile("../images/spr_Road1.png");
    textures["Road2"].loadFromFile("../images/spr_Road2.png");
    textures["Road3"].loadFromFile("../images/spr_Road3.png");
    textures["Road4"].loadFromFile("../images/spr_Road4.png");
    textures["Shop"].loadFromFile("../images/spr_Shop.png");
    textures["Townhouse"].loadFromFile("../images/spr_TownHouse.png");
    textures["Warehouse"].loadFromFile("../images/spr_Warehouse.png");
    textures["Border1"].loadFromFile("../images/spr_Border1.png");
    textures["Border2"].loadFromFile("../images/spr_Border2.png");
    textures["satisfactionBackground"].loadFromFile("../images/spr_IconBorder.png");
    textures["highSatisfactionIcon"].loadFromFile("../images/spr_HighSatisfaction.png");
    textures["mediumSatisfactionIcon"].loadFromFile("../images/spr_MediumSatisfaction.png");
    textures["lowSatisfactionIcon"].loadFromFile("../images/spr_LowSatisfaction.png");
    textures["Steel"].loadFromFile("../images/spr_Steel.png");
    textures["Concrete"].loadFromFile("../images/spr_Concrete.png");
    textures["Wood"].loadFromFile("../images/spr_Wood.png");
    textures["Population"].loadFromFile("../images/spr_Population.png");
    textures["PopeCoins"].loadFromFile("../images/spr_PopeCoins.png");
    textures["WindowBorder"].loadFromFile("../images/spr_WindowBorder.png");
    textures["Water"].loadFromFile("../images/spr_Water.png");
    textures["Sewage"].loadFromFile("../images/spr_Sewage.png");
    textures["Electricity"].loadFromFile("../images/spr_Electricity.png");
    textures["Waste"].loadFromFile("../images/spr_Waste.png");

    //std::this_thread::sleep_for(std::chrono::seconds(2));

    // Create the map
    createMap();

    // Create world border
    float worldWidth = myMap[0].size() * 128.f + 256.f;
    float worldHeight = myMap.size() * 128.f + 256.f;

    // Top and bottom borders
    for (int i = 0; i < myMap[0].size(); i++) {
        sf::Sprite borderTop;
        sf::Sprite borderBottom;

        borderTop.setTexture(textures["Border1"]);
        borderBottom.setTexture(textures["Border1"]);
        borderBottom.setRotation(180);

        borderTop.setScale(2, 2);
        borderBottom.setScale(2, 2);

        borderTop.setPosition(128.f + i * 128, 0);
        borderBottom.setPosition(256.f + i * 128, worldHeight);

        borderMap.push_back(borderTop);
        borderMap.push_back(borderBottom);
    }

    // Left and right borders
    for (int i = 0; i < myMap.size(); i++) {
        sf::Sprite borderLeft;
        sf::Sprite borderRight;

        borderLeft.setTexture(textures["Border1"]);
        borderLeft.setRotation(-90);
        borderRight.setTexture(textures["Border1"]);
        borderRight.setRotation(90);

        borderLeft.setScale(2, 2);
        borderRight.setScale(2, 2);

        borderLeft.setPosition(0, 256.f + i * 128);
        borderRight.setPosition(worldWidth, i * 128 + 128);

        borderMap.push_back(borderLeft);
        borderMap.push_back(borderRight);
    }

    // Corners
    sf::Sprite topLeft;
    sf::Sprite topRight;
    sf::Sprite bottomLeft;
    sf::Sprite bottomRight;

    topLeft.setTexture(textures["Border2"]);
    topRight.setTexture(textures["Border2"]);
    bottomLeft.setTexture(textures["Border2"]);
    bottomRight.setTexture(textures["Border2"]);

    topLeft.setRotation(-90);
    topRight.setRotation(0);
    bottomLeft.setRotation(180);
    bottomRight.setRotation(90);

    topLeft.setScale(2, 2);
    topRight.setScale(2, 2);
    bottomLeft.setScale(2, 2);
    bottomRight.setScale(2, 2);

    topLeft.setPosition(0, 128.f);
    topRight.setPosition(worldWidth - 128, 0);
    bottomLeft.setPosition(128, worldHeight);
    bottomRight.setPosition(worldWidth, worldHeight - 128);

    borderMap.push_back(topLeft);
    borderMap.push_back(topRight);
    borderMap.push_back(bottomLeft);
    borderMap.push_back(bottomRight);


    // Satisfaction text
    if(!font.loadFromFile("../fonts/PixelFJVerdana12pt.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    satisfactionText.setFont(font);
    satisfactionText.setCharacterSize(16);
    satisfactionText.setFillColor(sf::Color::White);
    satisfactionText.setPosition(45, 55);
    // Create background sprite for satisfaction text
    satisfactionBackground.setTexture(textures["satisfactionBackground"]);
    satisfactionBackground.setPosition(15, 25);
    satisfactionBackground.setScale(2, 2);
    satisfactionBackground.setColor(sf::Color(0, 0, 0, 150));
    // Create satisfaction icons
    satisfactionIcon.setTexture(textures["highSatisfactionIcon"]);
    satisfactionIcon.setPosition(10, 15);
    satisfactionIcon.setScale(0.25, 0.25);



    // Materials

    // Steel
    steelSprite.setTexture(textures["Steel"]);
    steelSprite.setPosition(680, 15);
    steelSprite.setScale(0.3, 0.3);

    // Create background sprite for satisfaction text
    steelBackground.setTexture(textures["satisfactionBackground"]);
    steelBackground.setPosition(680, 25);
    steelBackground.setScale(2, 2);
    steelBackground.setColor(sf::Color(0, 0, 0, 150));

    // Text
    steelText.setFont(font);
    steelText.setCharacterSize(14);
    steelText.setFillColor(sf::Color::White);
    steelText.setPosition(710, 55);


    //Concrete
    concreteSprite.setTexture(textures["Concrete"]);
    concreteSprite.setPosition(830, 15);
    concreteSprite.setScale(0.3, 0.3);

    // Create background sprite for satisfaction text
    concreteBackground.setTexture(textures["satisfactionBackground"]);
    concreteBackground.setPosition(830, 25);
    concreteBackground.setScale(2, 2);
    concreteBackground.setColor(sf::Color(0, 0, 0, 150));

    // Text
    concreteText.setFont(font);
    concreteText.setCharacterSize(14);
    concreteText.setFillColor(sf::Color::White);
    concreteText.setPosition(860, 55);


    //Wood
    woodSprite.setTexture(textures["Wood"]);
    woodSprite.setPosition(980, 15);
    woodSprite.setScale(0.2, 0.2);

    // Create background sprite for satisfaction text
    woodBackground.setTexture(textures["satisfactionBackground"]);
    woodBackground.setPosition(980, 25);
    woodBackground.setScale(2, 2);
    woodBackground.setColor(sf::Color(0, 0, 0, 150));

    // Text
    woodText.setFont(font);
    woodText.setCharacterSize(14);
    woodText.setFillColor(sf::Color::White);
    woodText.setPosition(1010, 55);



    // Population
    populationText.setFont(font);
    populationText.setCharacterSize(16);
    populationText.setFillColor(sf::Color::White);
    populationText.setPosition(205, 55);
    // Create background sprite for satisfaction text
    populationBackground.setTexture(textures["satisfactionBackground"]);
    populationBackground.setPosition(150, 25);
    populationBackground.setScale(2, 2);
    populationBackground.setColor(sf::Color(0, 0, 0, 150));
    // Create satisfaction icons
    populationIcon.setTexture(textures["Population"]);
    populationIcon.setPosition(150, 15);
    populationIcon.setScale(0.25, 0.25);


    // Currency
    currencyText.setFont(font);
    currencyText.setCharacterSize(16);
    currencyText.setFillColor(sf::Color::White);
    currencyText.setPosition(355, 55);
    // Create background sprite for currency text
    currencyBackground.setTexture(textures["satisfactionBackground"]);
    currencyBackground.setPosition(300, 25);
    currencyBackground.setScale(2, 2);
    currencyBackground.setColor(sf::Color(0, 0, 0, 150));
    // Create currency icons
    currencyIcon.setTexture(textures["PopeCoins"]);
    currencyIcon.setPosition(300, 15);
    currencyIcon.setScale(0.25, 0.25);
    centerTextOnSprite(currencyText, currencyIcon);

    createShopMenu();
    shopMenuOpen = false;
    plantMenuOpen = false;
}


void GameSimulation::centerTextOnSprite(sf::Text& text, const sf::Sprite& sprite) {
    // Step 1: Get the center of the sprite
    sf::FloatRect spriteBounds = sprite.getGlobalBounds();
    float spriteCenterX = spriteBounds.left + spriteBounds.width / 2.f;
    float spriteCenterY = spriteBounds.top + spriteBounds.height / 1.f;

    // Step 2: Get the bounds of the text
    sf::FloatRect textBounds = text.getLocalBounds();

    // Step 3: Set the origin of the text to its center
    text.setOrigin(textBounds.left + textBounds.width / 2.f, 
                   textBounds.top + textBounds.height / 2.f);

    // Step 4: Position the text at the center of the sprite
    text.setPosition(spriteCenterX, spriteCenterY);
}


void GameSimulation::createMap() {
    std::vector<std::vector<CityStructure*>> map = cityMap->getMap();
    int numRows = map.size();
    int numCols = map[0].size();
    myMap = std::vector<std::vector<CityItem>>(numRows, std::vector<CityItem>(numCols));

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            CityStructure* structure = map[row][col];
            if (structure != nullptr) {
                myMap[row][col].type = structure->getStructureType();
                std::string textureKey = determineTexture(structure, map);
                myMap[row][col].sprite.setTexture(textures[textureKey]);
                myMap[row][col].sprite.setPosition(col * 128 + 128, row * 128 + 128);
                myMap[row][col].sprite.setScale(2.0f, 2.0f);
            } else {
                myMap[row][col].type = "Landscape";
                int landscapeTexture = randomLandscapeTexture();
                myMap[row][col].sprite.setTexture(textures["Landscape" + std::to_string(landscapeTexture)]);
                myMap[row][col].sprite.setPosition(col * 128 + 128, row * 128 + 128);
                myMap[row][col].sprite.setScale(2.0f, 2.0f);
            }
        }
    }
}


std::string GameSimulation::determineTexture(CityStructure* structure, const std::vector<std::vector<CityStructure*> >& map) {
    if (structure->getStructureType() == "Road") {
        std::string roadTexture = "Road1";
        int x = structure->getX();
        int y = structure->getY();

        // Check neighbors to determine road type
        if (x > 0 && map[y][x - 1] != nullptr && map[y][x - 1]->getStructureType() == "Road") {
            roadTexture = "Road2";
            
        } else if (y > 0 && map[y - 1][x] != nullptr && map[y - 1][x]->getStructureType() == "Road") {
            roadTexture = "Road3";
        } else if (x < map[0].size() - 1 && map[y][x + 1] != nullptr && map[y][x + 1]->getStructureType() == "Road") {
            roadTexture = "Road4";
        }
        return roadTexture;
    }else if (structure->getStructureType() == "Residential"){
        // DO STUFF BASED ON RESIDENTIAL COMPLEX IDK
        return "Apartment";
    }

    // Otherwise, return texture based on structure type
    return structure->getStructureType();
}


int GameSimulation::randomLandscapeTexture() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3);
    return dis(gen);
}


void GameSimulation::gameRun(){
    sf::Clock clock;
    sf::Time elapsed = sf::Time::Zero;
    sf::Time eventTimer = sf::Time::Zero;
    const sf::Time eventInterval = sf::seconds(5.0f); // Event every 10 seconds

    while (window.isOpen()){
        processEvents();

        sf::Time deltaTime = clock.restart();
        elapsed += deltaTime;
        eventTimer += deltaTime;

        // Handle fixed time step updates
        while (elapsed >= timePerFrame){
            elapsed -= timePerFrame;
            update(timePerFrame);
        }

        if (eventTimer >= eventInterval){
            eventTimer -= eventInterval;
            gameLoop();
        }

        drawFrame();
    }
}


void GameSimulation::gameLoop(){

    float satisfactionTemp = cityHall->calculateSatisfaction();

    cityHall->addSteel(100);
    cityHall->addWood(100);
    cityHall->addConcrete(100);


    std::cout << " ========== Satisfaction: " << satisfactionTemp << " ===========" << std::endl;

    satisfactionTemp = cityHall->getCitizenSatisfactionImpact(satisfactionTemp);

    std::cout << " ========== Satisfaction: " << satisfactionTemp << " ===========" << std::endl;
    
    cityHall->populationChange(satisfactionTemp);
    float taxesCollected = cityHall->collectTaxes(satisfactionTemp);

    cityHall->getBudgetSplit(taxesCollected);
}


void GameSimulation::processEvents(){
    sf::Event curEvent;

    while (window.pollEvent(curEvent)){
        switch (curEvent.type){
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                if (curEvent.mouseButton.button == sf::Mouse::Left) {

                    if (shopMenuOpen){
                        // Get mouse coordinates with viewport offset
                        // Get mouse coordinates relative to the window
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // Convert to world coordinates using the default view
                        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos, window.getDefaultView());

                        // Check if any sprite in the shop got clicked
                        for (int i = 0; i < shopButtons.size(); i++) {
                            for (int j = 0; j < shopButtons[i].size(); j++) {
                                if (shopButtons[i][j].sprite.getGlobalBounds().contains(worldPos)) {
                                    // Get the structure type based on the button clicked
                                    std::string structureType = shopButtons[i][j].type;

                                    bool structurePlaced = false;

                                    if (structureType == "House") {
                                        ResidentialBuilding* house = new House();
                                        // Check if x and y is landscape
                                        if(myMap[nextPlacementY][nextPlacementX].type == "Landscape"){
                                            ResidentialComplex* residentialComplex = new ResidentialComplex(house);
                                            structurePlaced = residentialComplex->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                        }else{
                                            if (ResidentialComplex* complex = dynamic_cast<ResidentialComplex*>(cityMap->getMap()[nextPlacementY][nextPlacementX])) {
                                                complex->addResidentialComponent(house, cityMap);
                                            }
                                        }
                                    } else if (structureType == "Apartment") {
                                        ResidentialBuilding* apartment = new Apartment();
                                        
                                        if(myMap[nextPlacementY][nextPlacementX].type == "Landscape"){
                                            ResidentialComplex* residentialComplex = new ResidentialComplex(apartment);
                                            structurePlaced = residentialComplex->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                        }else{
                                            if (ResidentialComplex* complex = dynamic_cast<ResidentialComplex*>(cityMap->getMap()[nextPlacementY][nextPlacementX])) {
                                                complex->addResidentialComponent(apartment, cityMap);
                                            }
                                        }

                                    } else if (structureType == "Townhouse") {
                                        ResidentialBuilding* townhouse = new Townhouse();
                                        
                                        if(myMap[nextPlacementY][nextPlacementX].type == "Landscape"){
                                            ResidentialComplex* residentialComplex = new ResidentialComplex(townhouse);
                                            structurePlaced = residentialComplex->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                        }else{
                                            if (ResidentialComplex* complex = dynamic_cast<ResidentialComplex*>(cityMap->getMap()[nextPlacementY][nextPlacementX])) {
                                                complex->addResidentialComponent(townhouse, cityMap);
                                            }
                                        }
                                    } else if (structureType == "Estate") {
                                        ResidentialBuilding* estate = new Estate();
                                        
                                        if(myMap[nextPlacementY][nextPlacementX].type == "Landscape"){
                                            ResidentialComplex* residentialComplex = new ResidentialComplex(estate);
                                            structurePlaced = residentialComplex->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                        }else{
                                            if (ResidentialComplex* complex = dynamic_cast<ResidentialComplex*>(cityMap->getMap()[nextPlacementY][nextPlacementX])) {
                                                complex->addResidentialComponent(estate, cityMap);
                                            }
                                        }
                                    } else if (structureType == "Road") {
                                        Road* road = new Road();
                                        structurePlaced = road->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                    } else if (structureType == "Shop") {
                                        CommercialBuilding* shop = new Shop();
                                        structurePlaced = shop->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                    } else if (structureType == "Mall") {
                                        CommercialBuilding* mall = new Mall();
                                        structurePlaced = mall->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                    } else if (structureType == "Office") {
                                        CommercialBuilding* office = new Office();
                                        structurePlaced = office->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                    } else if (structureType == "Plant") {
                                           // CREATE AND PLACE PLANTS
                                        Plant* basePlant = new Plant();
                                        Plant* powerPlant = new PowerPlant(basePlant);
                                        Plant* powerWaterPlant = new WaterPlant(powerPlant);
                                        Plant* powerWaterWastePlant = new WastePlant(powerWaterPlant);
                                        Plant* powerWaterWasteSewagePlant = new SewagePlant(powerWaterWastePlant);
                                        structurePlaced = powerWaterWasteSewagePlant->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                    } else if (structureType == "Factory") {
                                        IndustrialBuilding* factory = new Factory();
                                        structurePlaced = factory->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                    } else if (structureType == "Warehouse") {
                                        IndustrialBuilding* warehouse = new Warehouse();
                                        structurePlaced = warehouse->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                    } else if (structureType == "Colosseum") {
                                        Landmark* colosseum = new Colosseum();
                                        structurePlaced = colosseum->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                    } else if (structureType == "Pantheon") {
                                        Landmark* pantheon = new Pantheon();
                                        structurePlaced = pantheon->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                    } else if (structureType == "Park") {
                                        Landmark* park = new Park();
                                        structurePlaced = park->placeStructure(nextPlacementX, nextPlacementY, cityMap);
                                    }
                                }
                            }
                        }
                        // Close the shop menu
                        shopMenuOpen = false;
                    }else if (plantMenuOpen) {
                        // Handle clicks on plant menu items

                        // Get mouse coordinates relative to the window
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // Convert to world coordinates using the default view
                        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos, window.getDefaultView());

                        // Loop over plant items to check for clicks
                        for (int i = 0; i < plantItems.size(); ++i) {
                            PlantItem& item = plantItems[i];

                            // Check if the sprite contains the mouse position and if the item can be bought
                            if (item.sprite.getGlobalBounds().contains(worldPos) && item.canBuy) {

                                // Check if the player has enough coins
                                if (cityHall->getPopeCoins() >= item.cost) {

                                    // Check if the plant already has this decorator
                                    std::string plantTypes = curPlant->getPlantType();
                                    if (plantTypes.find(item.type) == std::string::npos) {

                                        // Store previous x and y positions
                                        int x = curPlant->getX();
                                        int y = curPlant->getY();

                                        Plant* newPlant = nullptr;

                                        // Create the corresponding decorator and assign it back to curPlant
                                        if (item.type == "Water") {
                                            newPlant = new WaterPlant(curPlant);
                                        } else if (item.type == "Electricity") {
                                            newPlant = new PowerPlant(curPlant);
                                        } else if (item.type == "Waste") {
                                            newPlant = new WastePlant(curPlant);
                                        } else if (item.type == "Sewage") {
                                            newPlant = new SewagePlant(curPlant);
                                        }

                                        curPlantX = nextPlacementX;
                                        curPlantY = nextPlacementY;
                                        curPlant = new Plant();
                                        curPlant->placeStructure(curPlantX, curPlantY, cityMap);


                                        cityMap->map[curPlantY][curPlantX] = curPlant;
                                        
                                        // Output for debugging
                                        std::cout << "Decorator applied. New plant type: " << curPlant->getPlantType() << std::endl;

                                    }
                                }

                                // Break out of the loop after handling the click
                                break;
                            }
                        }

                        plantMenuOpen = false;

                    }else{ 
                        // Get the mouse position in the window
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // Convert to world coordinates by taking into account the camera's view
                        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos, cameraView);

                        // Offset for borders
                        float xOffset = 128.f;
                        float yOffset = 128.f;

                        // Subtract offsets to ignore borders
                        float worldX = worldPos.x - xOffset;
                        float worldY = worldPos.y - yOffset;

                        // Check if the world coordinates are within the map bounds
                        if (worldX >= 0 && worldY >= 0 &&
                            worldX < (myMap[0].size() * 128.f) &&
                            worldY < (myMap.size() * 128.f)) {
                            
                            // Calculate the indices in the map array
                            int mapX = static_cast<int>(worldX) / 128;
                            int mapY = static_cast<int>(worldY) / 128;

                            std::string structureType = myMap[mapY][mapX].type;

                            if (structureType == "Landscape") {
                                nextPlacementX = mapX;
                                nextPlacementY = mapY;
                                shopMenuOpen = true;
                            } else if (structureType == "Road") {
                                std::cout << "Road CLICKED" << std::endl;
                            } else if (structureType == "Residential") {
                                nextPlacementX = mapX;
                                nextPlacementY = mapY;
                                shopMenuOpen = true;
                            } else if (structureType == "Plant") {
                                std::cout << "Plant CLICKED" << std::endl;
                                // nextPlacementX = mapX;
                                // nextPlacementY = mapY;
                                // curPlant = dynamic_cast<Plant*>(cityMap->getMap()[mapY][mapX]);
                                // createPlantSprites();
                                // plantMenuOpen = true;
                            } else if (structureType == "Factory") {
                                std::cout << "Factory CLICKED" << std::endl;
                            } else if (structureType == "Colosseum" || structureType == "Park" || structureType == "Office" || structureType == "Shop") {
                                std::cout << "Radius-display CLICKED" << std::endl;
                            }
                        }
                    }
                    
                }
                break;
        }
    }
}


void GameSimulation::update(sf::Time deltaTime) {
    const float cameraSpeed = 200.0f;
    sf::Vector2f cameraMove(0.f, 0.f);

    // World boundaries
    float worldWidth = myMap[0].size() * 128.f + 256.f;
    float worldHeight = myMap.size() * 128.f + 256.f;

    // Check keyboard input for camera movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        cameraMove.x -= cameraSpeed * deltaTime.asSeconds() * (!shopMenuOpen); // Move left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        cameraMove.x += cameraSpeed * deltaTime.asSeconds() * (!shopMenuOpen); // Move right
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        cameraMove.y -= cameraSpeed * deltaTime.asSeconds() * (!shopMenuOpen); // Move up
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        cameraMove.y += cameraSpeed * deltaTime.asSeconds() * (!shopMenuOpen); // Move down
    }

    // Move the camera view
    cameraView.move(cameraMove);

    // Get the camera's new center position after movement
    sf::Vector2f cameraCenter = cameraView.getCenter();

    // Calculate the camera boundaries
    float halfWidth = cameraView.getSize().x / 2.f;
    float halfHeight = cameraView.getSize().y / 2.f;

    // Clamp the camera's position within the game world bounds
    cameraCenter.x = std::clamp(cameraCenter.x, halfWidth, worldWidth - halfWidth);
    cameraCenter.y = std::clamp(cameraCenter.y, halfHeight, worldHeight - halfHeight);

    // Apply the clamped center to the camera view
    cameraView.setCenter(cameraCenter);

    // Apply the updated camera view to the window
    window.setView(cameraView);

}


void GameSimulation::drawFrame() {
    // Clear the window for the new frame
    window.clear();

    // Draw Border
    for (int i = 0; i < borderMap.size(); i++){
        window.draw(borderMap[i]);
    }

    // Get the current city map data
    std::vector<std::vector<CityStructure*> > map = cityMap->getMap();

    // Iterate through each cell in the map
    for (int row = 0; row < map.size(); ++row) {
        for (int col = 0; col < map[row].size(); ++col) {
            CityStructure* structure = map[row][col];
            CityItem& cityItem = myMap[row][col];

            // Check if there's a structure in the cell
            if (structure != nullptr) {
                // Update CityItem with the new structure type if it has changed
                if (structure->getStructureType() != cityItem.type) {
                    // Update CityItem with the new structure type and texture
                    cityItem.type = structure->getStructureType();
                    cityItem.sprite.setTexture(textures[cityItem.type]);

                    cityItem.sprite.setPosition(col * 128 + 128, row * 128 + 128);
                }

                // Additional logic for road texture changes based on neighbors
                if (cityItem.type == "Road") {
                    // Determine road texture and rotation
                    std::string roadTexture;
                    int rotation = 0;

                    int x = structure->getX();
                    int y = structure->getY();

                    bool connectedUp = false;
                    bool connectedDown = false;
                    bool connectedLeft = false;
                    bool connectedRight = false;

                    int numConnections = 0;

                    // Check up
                    if (y > 0 && map[y - 1][x] != nullptr && map[y - 1][x]->getStructureType() == "Road") {
                        connectedUp = true;
                        numConnections++;
                    }
                    // Check down
                    if (y < map.size() - 1 && map[y + 1][x] != nullptr && map[y + 1][x]->getStructureType() == "Road") {
                        connectedDown = true;
                        numConnections++;
                    }
                    // Check left
                    if (x > 0 && map[y][x - 1] != nullptr && map[y][x - 1]->getStructureType() == "Road") {
                        connectedLeft = true;
                        numConnections++;
                    }
                    // Check right
                    if (x < map[0].size() - 1 && map[y][x + 1] != nullptr && map[y][x + 1]->getStructureType() == "Road") {
                        connectedRight = true;
                        numConnections++;
                    }

                    // Determine the road texture and rotation based on connections

                    if (numConnections == 1) {
                        // Dead-end or isolated road, use Road1
                        roadTexture = "Road1";
                        if (connectedUp) {
                            rotation = 90;
                        } else if (connectedRight) {
                            rotation = 0;
                        } else if (connectedDown) {
                            rotation = 270;
                        } else if (connectedLeft) {
                            rotation = 180;
                        }
                    } else if (numConnections == 2) {
                        if (connectedLeft && connectedRight) {
                            // Horizontal road
                            roadTexture = "Road1";
                            rotation = 0;
                        } else if (connectedUp && connectedDown) {
                            // Vertical road
                            roadTexture = "Road1";
                            rotation = 90;
                        } else if (connectedUp && connectedRight) {
                            roadTexture = "Road2";
                            rotation = 0;
                        } else if (connectedRight && connectedDown) {
                            roadTexture = "Road2";
                            rotation = 90;
                        } else if (connectedDown && connectedLeft) {
                            roadTexture = "Road2";
                            rotation = 180;
                        } else if (connectedLeft && connectedUp) {
                            roadTexture = "Road2";
                            rotation = 270;
                        }
                    } else if (numConnections == 3) {
                        roadTexture = "Road3";
                        if (!connectedLeft) {
                            // Connected up, right, down
                            rotation = 0;
                        } else if (!connectedUp) {
                            // Connected right, down, left
                            rotation = 90;
                        } else if (!connectedRight) {
                            // Connected down, left, up
                            rotation = 180;
                        } else if (!connectedDown) {
                            // Connected left, up, right
                            rotation = 270;
                        }
                    } else if (numConnections == 4) {
                        roadTexture = "Road4";
                        rotation = 0;
                    } else {
                        // No connections, use default Road1
                        roadTexture = "Road1";
                        rotation = 0;
                    }

                    // Update the texture and rotation
                    cityItem.sprite.setTexture(textures[roadTexture]);

                    // Set origin to center (32,32 is half of 64x64 sprite size)
                    cityItem.sprite.setOrigin(32, 32);

                    // Set scale
                    cityItem.sprite.setScale(2.0f, 2.0f);

                    // Apply rotation
                    cityItem.sprite.setRotation(rotation);

                    // Update position (since origin changed, adjust position accordingly)
                    cityItem.sprite.setPosition(col * 128 + 128 + 64, row * 128 + 128 + 64);

                }else if (cityItem.type == "Residential"){
                    // DO STUFF BASED ON RESIDENTIAL COMPLEX IDK
                    cityItem.sprite.setTexture(textures["Apartment"]);

                    // Load all 4 residence buildings inside of the residential complex
                    if (ResidentialComplex* residentialComplex = dynamic_cast<ResidentialComplex*>(structure)) {

                        cityItem.sprite.setTexture(textures[residentialComplex->residentialComponents[0]->getStructureType()]);

                        if (residentialComplex->residentialComponents.size() >= 2) {
                            cityItem.sprite.setScale(1, 1);

                            sf::Sprite tempLandscape;
                            tempLandscape.setTexture(textures["Landscape1"]);
                            tempLandscape.setPosition(col * 128 + 128, row * 128 + 128);
                            tempLandscape.setScale(2, 2);
                            window.draw(tempLandscape);
                            
                            for (int i = 1; i < residentialComplex->residentialComponents.size(); i++) {
                                sf::Sprite residentialSprite;
                                residentialSprite.setTexture(textures[residentialComplex->residentialComponents[i]->getStructureType()]);



                                int xOffset = 0;
                                int yOffset = 0;

                                if (i == 1) {
                                    xOffset = 64;
                                } else if (i == 2) {
                                    yOffset = 64;
                                } else if (i == 3) {
                                    xOffset = 64;
                                    yOffset = 64;
                                }

                                residentialSprite.setPosition(col * 128 + 128 + xOffset, row * 128 + 128 + yOffset);
                                window.draw(residentialSprite);
                            }


                        }
                    }
                }else {
                    // For other structures, update texture and position if type has changed
                    if (structure->getStructureType() != cityItem.type) {
                        cityItem.sprite.setTexture(textures[cityItem.type]);
                        cityItem.sprite.setPosition(col * 128 + 128, row * 128 + 128);
                        cityItem.sprite.setScale(2.0f, 2.0f);
                        cityItem.sprite.setOrigin(0, 0); // reset origin
                        cityItem.sprite.setRotation(0);  // reset rotation
                    }
                }
            } else {
                // Handle landscape tiles if there’s no structure
                if (cityItem.type != "Landscape") {
                    // Assign a random landscape texture
                    cityItem.type = "Landscape";
                    int landscapeTexture = randomLandscapeTexture();
                    cityItem.sprite.setTexture(textures["Landscape" + std::to_string(landscapeTexture)]);
                    cityItem.sprite.setPosition(col * 128 + 128, row * 128 + 128);
                    cityItem.sprite.setScale(2.0f, 2.0f);
                    cityItem.sprite.setOrigin(0, 0); // reset origin
                    cityItem.sprite.setRotation(0);  // reset rotation
                }
            }

            // Draw the sprite for each CityItem in myMap
            window.draw(cityItem.sprite);
        }
    }

    if (shopMenuOpen){
        drawShopMenu();
    } else if(plantMenuOpen){
        drawPlantMenu();
    } else {
        sf::View uiView = window.getDefaultView();
        window.setView(uiView);

        // Draw the stats
        drawStats();

        // Switch back to the main game view
        window.setView(cameraView);
    }

    window.display();
}


void GameSimulation::drawSatisfaction() {
    // Draw the satisfaction text
    int satisfaction = cityHall->getCurrSatisfaction();
    satisfactionText.setString(std::to_string(satisfaction) + "%");

    if (satisfaction >= 70) {
        satisfactionIcon.setTexture(textures["highSatisfactionIcon"]);
    } else if (satisfaction >= 40) {
        satisfactionIcon.setTexture(textures["mediumSatisfactionIcon"]);
    } else {
        satisfactionIcon.setTexture(textures["lowSatisfactionIcon"]);
    }


    // Draw the background for the satisfaction text
    window.draw(satisfactionBackground);
    window.draw(satisfactionText);
    window.draw(satisfactionIcon);
}


void GameSimulation:: drawWood() {
    window.draw(woodBackground);
    // woodText.setString(std::to_string(cityHall->getWood()) + " \n/ " + std::to_string(cityHall->getMaxWood()));
    woodText.setString(std::to_string(cityHall->getWood()));
    window.draw(woodText);
    window.draw(woodSprite);
}


void GameSimulation::drawSteel() {
    window.draw(steelBackground);
    // steelText.setString(std::to_string(cityHall->getSteel()) + " \n/ " + std::to_string(cityHall->getMaxSteel()));
    steelText.setString(std::to_string(cityHall->getSteel()));
    window.draw(steelText);
    window.draw(steelSprite);
}


void GameSimulation::drawConcrete() {
    window.draw(concreteBackground);
    // concreteText.setString(std::to_string(cityHall->getConcrete()) + " \n/ " + std::to_string(cityHall->getMaxConcrete()));
    concreteText.setString(std::to_string(cityHall->getConcrete()));
    window.draw(concreteText);
    window.draw(concreteSprite);
}


void GameSimulation::drawPopulation() {
    window.draw(populationBackground);
    populationText.setString(std::to_string(cityHall->getNumCitizens()));
    window.draw(populationText);
    window.draw(populationIcon);
}


void GameSimulation::drawCurrency() {
    window.draw(currencyBackground);
    currencyText.setString(std::to_string(cityHall->getPopeCoins()));
    window.draw(currencyText);
    window.draw(currencyIcon);
}


void GameSimulation::drawStats() {
    drawSatisfaction();
    drawPopulation();
    drawCurrency();
    drawSteel();
    drawConcrete();
    drawWood();
}


void GameSimulation::createShopMenu(){
    // Populate each row with shop items
    // Type is gonna be stored in texture name of sprite
    // Cost is gonna be stored in the shop item
    // Sprite is gonna be stored in the shop item

    // RESIDENTIAL
    sf::Sprite house;
    house.setTexture(textures["House"]);
    house.setScale(1.5, 1.5);
    ResidentialComponent* houseComponent = new House();
    int costHouse = houseComponent->getCost();
    ShopItem houseItem;
    houseItem.sprite = house;
    houseItem.cost = costHouse;
    houseItem.type = "House";

    sf::Sprite apartment;
    apartment.setTexture(textures["Apartment"]);
    apartment.setScale(1.5, 1.5);
    ResidentialComponent* apartmentComponent = new Apartment();
    int costApartment = apartmentComponent->getCost();
    ShopItem apartmentItem;
    apartmentItem.sprite = apartment;
    apartmentItem.cost = costApartment;
    apartmentItem.type = "Apartment";

    sf::Sprite estate;
    estate.setTexture(textures["Estate"]);
    estate.setScale(1.5, 1.5);
    ResidentialComponent* estateComponent = new Estate();
    int costEstate = estateComponent->getCost();
    ShopItem estateItem;
    estateItem.sprite = estate;
    estateItem.cost = costEstate;
    estateItem.type = "Estate";

    sf::Sprite townhouse;
    townhouse.setTexture(textures["Townhouse"]);
    townhouse.setScale(1.5, 1.5);
    ResidentialComponent* townhouseComponent = new Townhouse();
    int costTownhouse = townhouseComponent->getCost();
    ShopItem townhouseItem;
    townhouseItem.sprite = townhouse;
    townhouseItem.cost = costTownhouse;
    townhouseItem.type = "Townhouse";

    std::vector<ShopItem> residentialItems;
    residentialItems.push_back(houseItem);
    residentialItems.push_back(apartmentItem);
    residentialItems.push_back(estateItem);
    residentialItems.push_back(townhouseItem);


    // COMMERCIAL
    sf::Sprite shop;
    shop.setTexture(textures["Shop"]);
    shop.setScale(1.5, 1.5);
    CommercialBuilding* shopBuilding = new Shop();
    int costShop = shopBuilding->getCost();
    ShopItem shopItem;
    shopItem.sprite = shop;
    shopItem.cost = costShop;
    shopItem.type = "Shop";

    sf::Sprite office;
    office.setTexture(textures["Office"]);
    office.setScale(1.5, 1.5);
    CommercialBuilding* officeBuilding = new Office();
    int costOffice = officeBuilding->getCost();
    ShopItem officeItem;
    officeItem.sprite = office;
    officeItem.cost = costOffice;
    officeItem.type = "Office";

    std::vector<ShopItem> commercialItems;
    commercialItems.push_back(shopItem);
    commercialItems.push_back(officeItem);


    // INDUSTRIAL
    sf::Sprite plant;
    plant.setTexture(textures["Plant"]);
    plant.setScale(1.5, 1.5);
    Plant* basePlant = new Plant();
    int costPlant = basePlant->getCost();
    ShopItem plantItem;
    plantItem.sprite = plant;
    plantItem.cost = costPlant;
    plantItem.type = "Plant";

    sf::Sprite warehouse;
    warehouse.setTexture(textures["Warehouse"]);
    warehouse.setScale(1.5, 1.5);
    Warehouse* warehouseBuilding = new Warehouse();
    int costWarehouse = warehouseBuilding->getCost();
    ShopItem warehouseItem;
    warehouseItem.sprite = warehouse;
    warehouseItem.cost = costWarehouse;
    warehouseItem.type = "Warehouse";

    sf::Sprite factory;
    factory.setTexture(textures["Factory"]);
    factory.setScale(1.5, 1.5);
    Factory* factoryBuilding = new Factory();
    int costFactory = factoryBuilding->getCost();
    ShopItem factoryItem;
    factoryItem.sprite = factory;
    factoryItem.cost = costFactory;
    factoryItem.type = "Factory";

    std::vector<ShopItem> industrialItems;
    industrialItems.push_back(plantItem);
    industrialItems.push_back(warehouseItem);
    industrialItems.push_back(factoryItem);


    // LANDMARK
    sf::Sprite colosseum;
    colosseum.setTexture(textures["Colosseum"]);
    colosseum.setScale(1.5, 1.5);
    Landmark* colosseumBuilding = new Colosseum();
    int costColosseum = colosseumBuilding->getCost();
    ShopItem colosseumItem;
    colosseumItem.sprite = colosseum;
    colosseumItem.cost = costColosseum;
    colosseumItem.type = "Colosseum";

    sf::Sprite park;
    park.setTexture(textures["Park"]);
    park.setScale(1.5, 1.5);
    Landmark* parkBuilding = new Park();
    int costPark = parkBuilding->getCost();
    ShopItem parkItem;
    parkItem.sprite = park;
    parkItem.cost = costPark;
    parkItem.type = "Park";

    std::vector<ShopItem> landmarkItems;
    landmarkItems.push_back(colosseumItem);
    landmarkItems.push_back(parkItem);

    // Add road to the shop menu
    sf::Sprite road;
    road.setTexture(textures["Road1"]);
    road.setScale(1.5, 1.5);
    Road* roadBuilding = new Road();
    int costRoad = roadBuilding->getCost();
    ShopItem roadItem;
    roadItem.sprite = road;
    roadItem.cost = costRoad;
    roadItem.type = "Road";

    std::vector<ShopItem> roadItems;
    roadItems.push_back(roadItem);

    // Add all vectors to the shop menu vector array
    shopButtons.push_back(residentialItems);
    shopButtons.push_back(commercialItems);
    shopButtons.push_back(industrialItems);
    shopButtons.push_back(landmarkItems);
    shopButtons.push_back(roadItems);

    delete houseComponent;
    delete apartmentComponent;
    delete estateComponent;
    delete townhouseComponent;
    delete shopBuilding;
    delete officeBuilding;
    delete basePlant;
    delete warehouseBuilding;
    delete factoryBuilding;
    delete colosseumBuilding;
    delete parkBuilding;
    delete roadBuilding;
}


void GameSimulation::drawShopMenu(){
    // Draw background
    // Dark rectangle
    window.setView(window.getDefaultView());
    sf::RectangleShape backgroundColour(sf::Vector2f(1120, 630));
    backgroundColour.setPosition(0, 0);

    backgroundColour.setFillColor(sf::Color(0, 0, 0, 200));
    window.draw(backgroundColour);

    // Draw the shop menu
    // "Shop" text
    sf::Text shopText;
    shopText.setFont(font);
    shopText.setString("Shop");
    shopText.setCharacterSize(32);
    shopText.setFillColor(sf::Color::White);
    shopText.setOrigin(shopText.getLocalBounds().width / 2, shopText.getLocalBounds().height / 2);
    shopText.setPosition(1120 / 2, 64);
    window.draw(shopText);

    // Draw underline for shop
    sf::RectangleShape underline(sf::Vector2f(1120 / 4, 2));
    underline.setOrigin(1120 / 4 / 2, 2 / 2);
    underline.setPosition(1120 / 2, 70);
    underline.setFillColor(sf::Color::White);
    window.draw(underline);

    // ============ RESIDENTIAL DISPLAY ============
    // Residential text
    sf::Text residentialText;
    residentialText.setFont(font);
    residentialText.setString("Residential");
    residentialText.setCharacterSize(20);
    residentialText.setFillColor(sf::Color::White);
    residentialText.setPosition((1120 / 4)/2  - 100, 112);
    window.draw(residentialText);

    // Draw residential buttons
    for (int i = 0; i < shopButtons[0].size(); i++){
        shopButtons[0][i].sprite.setPosition((1120 / 4)/2 - 100, 140 + i * 124);
        window.draw(shopButtons[0][i].sprite);

        // Draw coin icon to the left of text
        sf::Sprite coinIcon;
        coinIcon.setTexture(textures["PopeCoins"]);
        coinIcon.setScale(0.2, 0.2);
        coinIcon.setPosition((1120 / 4)/2, 160 + i * 124 + 50);
        window.draw(coinIcon);

        // Display texture name
        sf::Text buildingName;
        buildingName.setFont(font);
        buildingName.setString(shopButtons[0][i].type);
        buildingName.setCharacterSize(14);
        buildingName.setFillColor(sf::Color::White);
        buildingName.setPosition((1120 / 4)/2 + 8, 180 + i * 124);
        window.draw(buildingName);

        sf::Text residentialCost;
        residentialCost.setFont(font);
        residentialCost.setString(std::to_string(shopButtons[0][i].cost));
        residentialCost.setCharacterSize(10);
        residentialCost.setFillColor(sf::Color::White);
        residentialCost.setPosition((1120 / 4)/2 + 26, 160 + i * 124 + 60);
        window.draw(residentialCost);
    }


    sf::Text commercialText;
    commercialText.setFont(font);
    commercialText.setString("Commercial");
    commercialText.setCharacterSize(20);
    commercialText.setFillColor(sf::Color::White);
    commercialText.setPosition((1120 / 3) - 86, 112);
    window.draw(commercialText);

    // Draw commercial buttons
    for (int i = 0; i < shopButtons[1].size(); i++){
        shopButtons[1][i].sprite.setPosition((1120 / 3) - 70, 140 + i * 124);
        window.draw(shopButtons[1][i].sprite);

        // Draw coin icon to the left of text
        sf::Sprite coinIcon;
        coinIcon.setTexture(textures["PopeCoins"]);
        coinIcon.setScale(0.2, 0.2);
        coinIcon.setPosition((1120 / 3) + 30, 160 + i * 124 + 50);
        window.draw(coinIcon);

        // Display texture name
        sf::Text buildingName;
        buildingName.setFont(font);
        buildingName.setString(shopButtons[1][i].type);
        buildingName.setCharacterSize(14);
        buildingName.setFillColor(sf::Color::White);
        buildingName.setPosition((1120 / 3) + 38, 180 + i * 124);
        window.draw(buildingName);

        sf::Text commercialCost;
        commercialCost.setFont(font);
        commercialCost.setString(std::to_string(shopButtons[1][i].cost));
        commercialCost.setCharacterSize(10);
        commercialCost.setFillColor(sf::Color::White);
        commercialCost.setPosition((1120 / 3) + 54, 160 + i * 124 + 60);
        window.draw(commercialCost);
    }


    sf::Text industrialText;
    industrialText.setFont(font);
    industrialText.setString("Industrial");
    industrialText.setCharacterSize(20);
    industrialText.setFillColor(sf::Color::White);
    industrialText.setPosition((1120 / 3) * 1.54 - 40, 112);
    window.draw(industrialText);

    // Draw industrial buttons
    for (int i = 0; i < shopButtons[2].size(); i++){
        shopButtons[2][i].sprite.setPosition((1120 / 3) * 1.54 - 40, 140 + i * 124);
        window.draw(shopButtons[2][i].sprite);

        // Draw coin icon to the left of text
        sf::Sprite coinIcon;
        coinIcon.setTexture(textures["PopeCoins"]);
        coinIcon.setScale(0.2, 0.2);
        coinIcon.setPosition((1120 / 3) * 1.54 + 60, 160 + i * 124 + 50);
        window.draw(coinIcon);

        // Display texture name
        sf::Text buildingName;
        buildingName.setFont(font);
        buildingName.setString(shopButtons[2][i].type);
        buildingName.setCharacterSize(14);
        buildingName.setFillColor(sf::Color::White);
        buildingName.setPosition((1120 / 3) * 1.54 + 68, 180 + i * 124);
        window.draw(buildingName);

        sf::Text industrialCost;
        industrialCost.setFont(font);
        industrialCost.setString(std::to_string(shopButtons[2][i].cost));
        industrialCost.setCharacterSize(10);
        industrialCost.setFillColor(sf::Color::White);
        industrialCost.setPosition((1120 / 3) * 1.54 + 86, 160 + i * 124 + 60);
        window.draw(industrialCost);
    }


    sf::Text landmarkText;
    landmarkText.setFont(font);
    landmarkText.setString("Landmark");
    landmarkText.setCharacterSize(20);
    landmarkText.setFillColor(sf::Color::White);
    landmarkText.setPosition((1120 / 3) * 2.3 - 40, 112);
    window.draw(landmarkText);

    // Draw landmark buttons
    for (int i = 0; i < shopButtons[3].size(); i++){
        shopButtons[3][i].sprite.setPosition((1120 / 3) * 2.3 - 40, 140 + i * 124);
        window.draw(shopButtons[3][i].sprite);

        // Draw coin icon to the left of text
        sf::Sprite coinIcon;
        coinIcon.setTexture(textures["PopeCoins"]);
        coinIcon.setScale(0.2, 0.2);
        coinIcon.setPosition((1120 / 3) * 2.3 + 60, 160 + i * 124 + 50);
        window.draw(coinIcon);

        // Display texture name
        sf::Text buildingName;
        buildingName.setFont(font);
        buildingName.setString(shopButtons[3][i].type);
        buildingName.setCharacterSize(14);
        buildingName.setFillColor(sf::Color::White);
        buildingName.setPosition((1120 / 3) * 2.3 + 68, 180 + i * 124);
        window.draw(buildingName);

        sf::Text landmarkCost;
        landmarkCost.setFont(font);
        landmarkCost.setString(std::to_string(shopButtons[3][i].cost));
        landmarkCost.setCharacterSize(10);
        landmarkCost.setFillColor(sf::Color::White);
        landmarkCost.setPosition((1120 / 3) * 2.3 + 86, 160 + i * 124 + 60);
        window.draw(landmarkCost);
    }


    // Draw road at the bottom right corner
    shopButtons[4][0].sprite.setPosition((1120 / 3) * 2.3 - 40, 140 + 124 * 2);
    window.draw(shopButtons[4][0].sprite);

    // Draw coin icon to the left of text
    sf::Sprite coinIcon;
    coinIcon.setTexture(textures["PopeCoins"]);
    coinIcon.setScale(0.2, 0.2);
    coinIcon.setPosition((1120 / 3) * 2.3 + 60, 160 + 124 * 2 + 50);
    window.draw(coinIcon);

    // Display texture name
    sf::Text buildingName;
    buildingName.setFont(font);
    buildingName.setString(shopButtons[4][0].type);
    buildingName.setCharacterSize(14);
    buildingName.setFillColor(sf::Color::White);
    buildingName.setPosition((1120 / 3) * 2.3 + 68, 180 + 124 * 2);
    window.draw(buildingName);

    sf::Text roadCost;
    roadCost.setFont(font);
    roadCost.setString(std::to_string(shopButtons[4][0].cost));
    roadCost.setCharacterSize(10);
    roadCost.setFillColor(sf::Color::White);
    roadCost.setPosition((1120 / 3) * 2.3 + 86, 160 + 124 * 2 + 60);
    window.draw(roadCost);

}


void GameSimulation::createPlantSprites() {
    // Clear any existing plant items
    plantItems.clear();

    // Load coin icon texture
    sf::Texture& coinTexture = textures["PopeCoins"];

    // WATER PLANT
    PlantItem waterItem;
    waterItem.sprite.setTexture(textures["Water"]);
    waterItem.sprite.setScale(8, 8);
    waterItem.cost = 1000;
    waterItem.type = "Water";
    waterItem.coinIcon.setTexture(coinTexture);
    waterItem.coinIcon.setScale(0.2f, 0.2f);

    // ELECTRICITY PLANT
    PlantItem electricityItem;
    electricityItem.sprite.setTexture(textures["Electricity"]);
    electricityItem.sprite.setScale(8, 8);
    electricityItem.cost = 1000;
    electricityItem.type = "Electricity";
    electricityItem.coinIcon.setTexture(coinTexture);
    electricityItem.coinIcon.setScale(0.2f, 0.2f);

    // WASTE PLANT
    PlantItem wasteItem;
    wasteItem.sprite.setTexture(textures["Waste"]);
    wasteItem.sprite.setScale(8, 8);
    wasteItem.cost = 1000;
    wasteItem.type = "Waste";
    wasteItem.coinIcon.setTexture(coinTexture);
    wasteItem.coinIcon.setScale(0.2f, 0.2f);

    // SEWAGE PLANT
    PlantItem sewageItem;
    sewageItem.sprite.setTexture(textures["Sewage"]);
    sewageItem.sprite.setScale(8, 8);
    sewageItem.cost = 1000;
    sewageItem.type = "Sewage";
    sewageItem.coinIcon.setTexture(coinTexture);
    sewageItem.coinIcon.setScale(0.2f, 0.2f);

    // Determine which plants have already been bought
    std::string plantTypes = curPlant->getPlantType();

    waterItem.canBuy = (plantTypes.find("Water") == std::string::npos);
    electricityItem.canBuy = (plantTypes.find("Power") == std::string::npos);
    wasteItem.canBuy = (plantTypes.find("Waste") == std::string::npos);
    sewageItem.canBuy = (plantTypes.find("Sewage") == std::string::npos);

    // Add items to the plantItems vector
    plantItems.push_back(waterItem);
    plantItems.push_back(electricityItem);
    plantItems.push_back(wasteItem);
    plantItems.push_back(sewageItem);
}



void GameSimulation::drawPlantMenu() {
    // Draw background
    window.setView(window.getDefaultView());
    sf::RectangleShape backgroundColour(sf::Vector2f(1120, 630));
    backgroundColour.setPosition(0, 0);
    backgroundColour.setFillColor(sf::Color(0, 0, 0, 200));
    window.draw(backgroundColour);

    // Number of plant items (should be 4)
    int numItems = plantItems.size();
    float sectionWidth = 1120.0f / numItems;

    for (int i = 0; i < numItems; ++i) {
        PlantItem& item = plantItems[i];

        // Calculate positions
        float xPosition = i * sectionWidth;
        float centerX = xPosition + sectionWidth / 2.0f;

        // Draw the plant name
        sf::Text itemText;
        itemText.setFont(font);
        itemText.setString(item.type);
        itemText.setCharacterSize(20);
        itemText.setFillColor(sf::Color::White);
        sf::FloatRect textRect = itemText.getLocalBounds();
        itemText.setOrigin(textRect.left + textRect.width / 2.0f, 0);
        itemText.setPosition(centerX, 200);
        window.draw(itemText);

        // Set the sprite's position
        sf::Sprite& sprite = item.sprite;
        sf::FloatRect spriteBounds = sprite.getLocalBounds();
        sprite.setOrigin(spriteBounds.width / 2.0f, 0);
        sprite.setPosition(centerX, 260);

        // Save original color
        sf::Color originalColor = sprite.getColor();

        // Grey out the sprite if it can't be bought
        if (!item.canBuy) {
            sprite.setColor(sf::Color(100, 100, 100, 255)); // Greyed out
        }

        // Draw the sprite
        window.draw(sprite);

        // Restore original color
        sprite.setColor(originalColor);

        // Set the coin icon's position
        sf::Sprite& coinIcon = item.coinIcon;
        coinIcon.setPosition(centerX - coinIcon.getGlobalBounds().width / 2.0f, sprite.getPosition().y + sprite.getGlobalBounds().height + 10);

        // Save original color
        sf::Color originalCoinColor = coinIcon.getColor();

        // Grey out the coin icon if it can't be bought
        if (!item.canBuy) {
            coinIcon.setColor(sf::Color(100, 100, 100, 255)); // Greyed out
        }

        // Draw the coin icon
        window.draw(coinIcon);

        // Restore original color
        coinIcon.setColor(originalCoinColor);

        // Draw the price text
        sf::Text priceText;
        priceText.setFont(font);
        priceText.setString(std::to_string(item.cost));
        priceText.setCharacterSize(14);
        priceText.setFillColor(sf::Color::White);
        sf::FloatRect priceRect = priceText.getLocalBounds();
        priceText.setOrigin(priceRect.left + priceRect.width / 2.0f, 0);
        float priceY = coinIcon.getPosition().y + coinIcon.getGlobalBounds().height + 5;
        priceText.setPosition(centerX, priceY);
        window.draw(priceText);
    }
}

