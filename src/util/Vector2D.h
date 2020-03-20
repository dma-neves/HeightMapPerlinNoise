#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

class Vector2D
{
public:
    Vector2D(float x = 0, float y = 0);

    float x, y;

    Vector2D operator+(Vector2D vec);
    Vector2D operator-(Vector2D vec);
    Vector2D operator*(float scaler);
    Vector2D operator/(float scaler);

    void operator+=(Vector2D vec);
    void operator-=(Vector2D vec);
    void operator*=(float scaler);
    void operator/=(float scaler);
    void operator=(float num);

    bool operator==(Vector2D vec) { return (x == vec.x && y == vec.y); }
    bool operator!=(Vector2D vec) { return !(*this==vec); }

    void setMagnitude(float mag) { *this *= (mag / magnitude()); }
    float magnitude();
    bool null();
    
    float angle(Vector2D vec);
    void rotate(float angle);

    sf::Vector2f sfVector() { return sf::Vector2f(x, y); }
};

#endif // VECTOR2D_H
