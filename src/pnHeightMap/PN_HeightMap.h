#ifndef APPLICATION
#define APPLICATION

#include <vector>
#include <SFML/Graphics.hpp>

#include "HeightMap.h"
#include "HeightMapRenderer.h"

#define DT_MULTIPLIER 3

class PN_HeightMap
{
public:
    PN_HeightMap(int windowWidth, int windowHeight, std::string windowTitle, int resolution, int numOctaves, float lacunarity, float persistance);

    void run();
    void handleEvents(float dt);

private:
    void update();
    void render();

    bool isRunning = true;

    sf::RenderWindow window;
    sf::Clock clock;

    HeightMap hmap;
    HeightMapRenderer hmapRenderer;
};

#endif
