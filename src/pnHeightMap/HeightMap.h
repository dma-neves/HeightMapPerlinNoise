#ifndef HEIGHT_MAP
#define HEIGHT_MAP

#include <vector>

#include "Vector2D.h"
#include "Octave.h"

class HeightMap
{
public:

    HeightMap(Vector2D dim, int numOctaves, float lacunarity, float persistance);
    ~HeightMap();

    float value(Vector2D pos) { return values[(int)pos.y][(int)pos.x]; }
    float value(int x, int y) { return values[y][x]; }

    void applyRandom();
    void applyPerlinNoise();

    Vector2D getDim() { return dim; }

private:

    void reset();

    Vector2D dim;
    float** values;

    int numOctaves;
    float lacunarity;
    float persistance;
    std::vector<Octave*> octaves;
};

#endif