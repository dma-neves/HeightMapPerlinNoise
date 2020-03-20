#ifndef HEIGHT_MAP_RENDERER
#define HEIGHT_MAP_RENDERER

#include <SFML/Graphics.hpp>

#include "HeightMap.h"

class HeightMapRenderer
{
public:

    HeightMapRenderer(HeightMap* hmap, int res, sf::RenderWindow* window);

    void render();

private:

    HeightMap* hmap;
    int res;

    sf::RenderWindow* window;
};

#endif