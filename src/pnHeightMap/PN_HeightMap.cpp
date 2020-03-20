#include "PN_HeightMap.h"

PN_HeightMap::PN_HeightMap(int windowWidth, int windowHeight, std::string windowTitle, int resolution, int numOctaves, float lacunarity, float persistance) :
window(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Close),
hmap(Vector2D(resolution, resolution), numOctaves, lacunarity, persistance),
hmapRenderer(&hmap, 5, &window)
{
    hmap.applyPerlinNoise();
}

void PN_HeightMap::run()
{
    while (isRunning)
    {
        float dt = clock.restart().asSeconds() * DT_MULTIPLIER;;

        update();
        render();
        handleEvents(dt);
    }
}

void PN_HeightMap::update()
{
}

void PN_HeightMap::render()
{
    window.clear();

    hmapRenderer.render();

    window.display();
}

void PN_HeightMap::handleEvents(float dt)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            isRunning = false;
            window.close();
        }
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        isRunning = false;
        window.close();
    }
}