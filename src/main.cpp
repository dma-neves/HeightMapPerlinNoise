#include "PN_HeightMap.h"

#include <iostream>

int main()
{
    std::cout << "Example: Resolution = 100 Number of octaves = 3 Lacunariry = 4.1 Persistance = 3.5" << std::endl << std::endl;
    
    int resolution, numOctaves;
    float lacunarity, persistance;
    std::cout << "Resolution: ";
    std::cin >> resolution;
    std::cout << "Number of octaves: ";
    std::cin >> numOctaves;
    std::cout << "Lacunarity: ";
    std::cin >> lacunarity;
    std::cout << "Persistance: ";
    std::cin >> persistance;

    PN_HeightMap pnHeightMap(500, 500, "Perlin noise height map", resolution, numOctaves, lacunarity, persistance);
    pnHeightMap.run();
}