#ifndef GAME_SIMULATION_H
#define GAME_SIMULATION_H

class CityMap;
class CityHall;
class CityStructure;

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

    // Game handling
    void processEvents();
    void update(sf::Time deltaTime);  // User inputs
    void drawFrame();

    // Other functions
    void createMap();
    std::string determineTexture(CityStructure* structure, const std::vector<std::vector<CityStructure*>>& map);
    int randomLandscapeTexture();

    bool shopMenuOpen;
    sf::Sprite shopMenuSprite;
    std::vector<sf::Sprite> shopButtons;
};

#endif
