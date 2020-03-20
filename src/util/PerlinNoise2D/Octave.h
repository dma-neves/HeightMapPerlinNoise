#ifndef OCTAVE
#define OCTAVE

#include "Vector2D.h"

class Octave
{
public:

    Octave(Vector2D dim, int freq, float amp);
    ~Octave();

    float value(int x, int y) { return values[y][x]; }
    float getAmp() { return amp; }

private:

    void reset();
    void generateOctave();
    float getHeight();

    float linearInterpolationHeight(float pos_a, float height_a, float pos_b, float height_b, float pos_new);

    float** values;
    Vector2D dim;

    int period;
    float amp;
    int variance = 100;
};

#endif