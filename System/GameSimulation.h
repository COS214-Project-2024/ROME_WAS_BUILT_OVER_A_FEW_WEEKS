#ifndef GAME_SIMULATION_H
#define GAME_SIMULATION_H

class CityMap;
class CityHall;
class CityStructure;
class IndustrialBuilding;

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

class GameSimulation {
public:
    GameSimulation(CityHall* cityHall, CityMap* cityMap);
    void gameRun();

    // Textures
    std::map<std::string, sf::Texture> textures;

    // Game values
    float imageScale = 1;

    struct CityItem {
        sf::Sprite sprite;
        std::string type;
    };


    struct ShopItem {
        sf::Sprite sprite;
        int cost;
        std::string type;
    };

    struct PlantItem {
        sf::Sprite sprite;
        int cost;
        //std::string type;
    };


private:
    // Reference to main buildings
    CityHall* cityHall;
    CityMap* cityMap;
    std::vector<std::vector<CityItem>> myMap;
    std::vector<sf::Sprite> borderMap;

    // Graphics (changed from pointers to regular member variables)
    sf::RenderWindow window;
    sf::Time timePerFrame;
    sf::View cameraView;

    // Satisfaction
    sf::Font font;
    sf::Text satisfactionText;
    sf::Sprite satisfactionBackground;
    sf::Sprite satisfactionIcon;

    // Materials
    sf::Sprite steelSprite;
    sf::Sprite steelBackground;
    sf::Text steelText;

    sf::Sprite concreteSprite;
    sf::Sprite concreteBackground;
    sf::Text concreteText;

    sf::Sprite woodSprite;
    sf::Sprite woodBackground;
    sf::Text woodText;

    // Population
    sf::Text populationText;
    sf::Sprite populationBackground;
    sf::Sprite populationIcon;

    // Currency
    sf::Text currencyText;
    sf::Sprite currencyBackground;
    sf::Sprite currencyIcon;

    // Game handling
    void processEvents();
    void update(sf::Time deltaTime);  // User inputs
    void drawFrame();
    void drawSatisfaction();
    void drawPopulation();
    void drawCurrency();
    void drawWood();
    void drawSteel();
    void drawConcrete();

    void gameLoop();
    
    void drawStats();

    void createShopMenu();
    void drawShopMenu();
    

    // Other functions
    void centerTextOnSprite(sf::Text& text, const sf::Sprite& sprite);
    void createMap();
    std::string determineTexture(CityStructure* structure, const std::vector<std::vector<CityStructure*> >& map);
    int randomLandscapeTexture();

    bool shopMenuOpen;
    sf::Sprite shopMenuSprite;
    std::vector<std::vector<ShopItem>> shopButtons;


    // Shop stuff
    int nextPlacementX;
    int nextPlacementY;

    IndustrialBuilding* curPlant;
    std::vector<PlantItem> plantItems;
    void createPlantSprites();
    void drawPlant();
};

#endif
