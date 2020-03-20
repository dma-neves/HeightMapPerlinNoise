#include "Octave.h"

Octave::Octave(Vector2D dim, int period, float amp, int temp) : dim(dim), period(period), amp(amp)
{
    values = new float*[(int)dim.y];

    for(int i = 0; i < dim.y; i++) values[i] = new float[(int)dim.x];
    reset();

    generateOctave();
}

void Octave::reset()
{
    for(int y = 0; y < dim.y; y += 1)
    {
        for(int x = 0; x < dim.x; x += 1)
        {
            values[y][x] = 0;
        }
    }
}

Octave::~Octave()
{
    for(int i = 0; i < dim.y; i++) delete(values[i]);

    delete(values);
}

float Octave::getHeight()
{
    return (float) (rand() % variance*amp) / (float)variance;
}

float Octave::linearInterpolationHeight(float pos_a, float height_a, float pos_b, float height_b, float pos_new)
{
    // height(pos) = alpha * pos + beta
    float alpha;
    float beta;

    Vector2D slope = Vector2D(pos_b, height_b) - Vector2D(pos_a, height_a);
    alpha = slope.y / slope.x;
    beta = height_a - alpha*pos_a;

    return alpha * pos_new + beta;
}

void Octave::generateOctave()
{
    for(int y = 0; y < dim.y; y += 1)
    {
        for(int x = 0; x < dim.x; x += 1)
        {
            values[y][x] = 0;//getHeight();
        }
    }

    for(int y = 0; y != dim.y+period-1; y += period)
    {
        if(y >= dim.y) y = dim.y - 1;
        values[y][0] = getHeight();

        for(int x = 0; x < dim.x; x += period)
        {
            int next_x = x + period >= dim.x ? dim.x - 1 : x + period;
            float this_h = values[y][x];
            float next_h = getHeight();
            values[y][next_x] = next_h;

            for(int sx = x+1; sx < next_x; sx++)
            {
                values[y][sx] = linearInterpolationHeight(x, this_h, next_x, next_h, sx);
            }
        }
    }

    for(int x = 0; x < dim.x; x ++)
    {
        for(int y = 0; y < dim.y; y += period)
        {
            int next_y = y + period >= dim.y ? dim.y - 1 : y + period;
            float this_h = values[y][x];
            float next_h = values[next_y][x];

            for(int sy = y+1; sy < next_y; sy++)
            {
                values[sy][x] = linearInterpolationHeight(y, this_h, next_y, next_h, sy);
            }
        }
    }
}