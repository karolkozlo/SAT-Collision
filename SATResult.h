#ifndef SATRESULT_H
#define SATRESULT_H
#include <raylib.h>

struct SATResult {
    bool intersect = false;
    float penetration = 0.0f;
    Vector2 axis = {0, 0};
    // Minimum Translation Vector
    Vector2 mtv  = {0, 0};
};

#endif