#include "HeightMap.h"

#include<ctime>

HeightMap::HeightMap(Vector2D dim, int numOctaves, float lacunarity, float persistance) : dim(dim), numOctaves(numOctaves), lacunarity(lacunarity), persistance(persistance)
{
    values = new float*[(int)dim.y];

    for(int i = 0; i < dim.y; i++) values[i] = new float[(int)dim.x];
}

HeightMap::~HeightMap()
{
    for(int i = 0; i < dim.y; i++) delete(values[i]);

    delete(values);
}

void HeightMap::applyRandom()
{
    srand(time(0));

    for(int y = 0; y < dim.y; y++)
    {
        for(int x = 0;x < dim.x; x++)
        {
            values[y][x] = (float)(rand() % 255) / 255.0f;
        }
    }
}

void HeightMap::reset()
{
    for(int y = 0; y < dim.y; y++)
    {
        for(int x = 0;x < dim.x; x++)
        {
            values[y][x] = 0;
        }
    }
}

void HeightMap::applyPerlinNoise()
{
    srand(time(0));

    reset();
    float totalAmp = 0;

    for(int i = 0; i < numOctaves; i++)
    {
        Octave* octave = new Octave(dim, pow(lacunarity, i+1), pow(persistance, i+1), i);
        octaves.push_back(octave);

        totalAmp += octave->getAmp();

        for(int y = 0; y < dim.y; y++)
        {
            for(int x = 0;x < dim.x; x++)
            {
                values[y][x] += octave->value(x, y);
            }
        }
    }

    for(int y = 0; y < dim.y; y++)
    {
        for(int x = 0;x < dim.x; x++)
        {
            values[y][x] /= totalAmp;
        }
    }

    for(int i = 0; i < numOctaves; i++)
    {
        delete( octaves.at(i) );
    }
    octaves.clear();
}