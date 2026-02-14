#ifndef CONVEX_POLY_H
#define CONVEX_POLY_H
#include <raylib.h>
#include <vector>
#include <cmath>

class ConvexPoly {
    public:
        Vector2 center;
        float angleRadians = 0.f;
        std::vector<Vector2> localVertices;
        std::vector<Vector2> GetWorldPoints();
};

#endif