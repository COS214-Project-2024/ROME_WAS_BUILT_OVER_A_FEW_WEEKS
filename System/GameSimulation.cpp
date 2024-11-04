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

    shopMenuOpen = false;

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

            case sf::Event::KeyPressed:
                if (curEvent.key.code == sf::Keyboard::Num1){

                    // CREATE AND PLACE ROADS
                    cout << "\nCREATE AND PLACE ROADS" << endl;
                    Road* road1 = new Road();
                    road1->placeStructure(0, 1, cityMap);
                    cout << "Road 1 placed" << endl;
                    Road* road2 = new Road();
                    road2->placeStructure(1, 1, cityMap);
                    cout << "Road 2 placed" << endl;
                    Road* road3 = new Road();
                    road3->placeStructure(0, 2, cityMap);
                    cout << "Road 3 placed" << endl;

                    Road* road4 = new Road();
                    road4->placeStructure(0, 3, cityMap);
                    Road* road5 = new Road();
                    road5->placeStructure(2, 1, cityMap);
                    Road* road6 = new Road();
                    road6->placeStructure(3, 1, cityMap);

                    cout << "\nCREATE AND PLACE RESIDENTIAL COMPLEXES" << endl;
                    ResidentialBuilding* house1 = new House();
                    ResidentialComplex* residentialComplex1 = new ResidentialComplex(house1);
                    residentialComplex1->placeStructure(1, 2, cityMap);

                    ResidentialBuilding* estate = new Estate();
                    ResidentialBuilding* apartment = new Apartment();
                    ResidentialBuilding* townhouse = new Townhouse();

                    residentialComplex1->addResidentialComponent(estate, cityMap);
                    residentialComplex1->addResidentialComponent(apartment, cityMap);
                    residentialComplex1->addResidentialComponent(townhouse, cityMap);
                    

                    IndustrialBuilding* plant = new Plant();
                    IndustrialBuilding* warehouse = new Warehouse();
                    IndustrialBuilding* factory = new Factory();

                    plant->placeStructure(2, 2, cityMap);
                    warehouse->placeStructure(3, 2, cityMap);
                    factory->placeStructure(1, 3, cityMap);

                    CommercialBuilding* shop1 = new Shop();
                    CommercialBuilding* office1 = new Office();

                    shop1->placeStructure(1, 0, cityMap);
                    office1->placeStructure(2, 0, cityMap);

                    Landmark* colosseum = new Colosseum();
                    Landmark* park = new Park();

                    colosseum->placeStructure(4, 1, cityMap);
                    park->placeStructure(0, 4, cityMap);


                }
                break;

            case sf::Event::MouseButtonPressed:
                if (curEvent.mouseButton.button == sf::Mouse::Left) {
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

                        std::cout << "Clicked on map cell at row: " << mapY << ", column: " << mapX << std::endl;
                        // Process the click event on the map tile (mapX, mapY)
                        // Example: retrieve or modify map data at myMap[mapY][mapX]
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
                // Check if the type has changed
                if (structure->getStructureType() != cityItem.type) {
                    // Update CityItem with the new structure type and texture
                    cityItem.type = structure->getStructureType();
                    cityItem.sprite.setTexture(textures[cityItem.type]);

                    // Optionally adjust the sprite position based on row/col
                    cityItem.sprite.setPosition(col * 128 + 128, row * 128 + 128);
                }

                // Additional logic for road texture changes based on neighbors
                if (cityItem.type == "Road") {
                    std::string roadTexture = determineTexture(structure, map);
                    cityItem.sprite.setTexture(textures[roadTexture]);
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
                }
            } else {
                // Handle landscape tiles if there’s no structure
                if (cityItem.type != "Landscape") {
                    // Assign a random landscape texture
                    cityItem.type = "Landscape";
                    int landscapeTexture = randomLandscapeTexture();
                    cityItem.sprite.setTexture(textures["Landscape" + std::to_string(landscapeTexture)]);
                    cityItem.sprite.setPosition(col * 128 + 128, row * 128 + 128);
                }
            }

            // Draw the sprite for each CityItem in myMap
            window.draw(cityItem.sprite);
        }
    }

    // Now switch to the UI view for fixed elements
    sf::View uiView = window.getDefaultView();
    window.setView(uiView);

    // Draw the stats
    drawStats();

    // Switch back to the main game view
    window.setView(cameraView);
    // Display the frame
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