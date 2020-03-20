#include "HeightMapRenderer.h"

HeightMapRenderer::HeightMapRenderer(HeightMap* hmap, int res, sf::RenderWindow* window) : hmap(hmap), res(res), window(window)
{
}

void HeightMapRenderer::render()
{
    Vector2D pixelSize = Vector2D( window->getSize().x / hmap->getDim().x, window->getSize().y / hmap->getDim().y );

    sf::RectangleShape pixel;
    pixel.setSize(pixelSize.sfVector());

    for(int y = 0; y < hmap->getDim().y; y++)
    {
        for(int x = 0; x < hmap->getDim().x; x++)
        {
            pixel.setPosition(x*pixelSize.x, y*pixelSize.y);
            int val = hmap->value(x,y) * 255;
            pixel.setFillColor(sf::Color(val, val, val, 255));

            window->draw(pixel);
        }
    }
}