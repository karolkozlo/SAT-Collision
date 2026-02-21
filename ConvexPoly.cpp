#include <ConvexPoly.h>
#include <raymath.h>
#include <limits>

static inline Vector2 Rotate(const Vector2& v, float cos, float sin) {
    return {v.x * cos - v.y * sin,
            v.x * sin + v.y * cos};
}

static void ComputeAxes(const std::vector<Vector2>& verts, std::vector<Vector2>& axes) {
    size_t vertCount = verts.size();
    for (size_t i = 0; i < vertCount; i++) {
        Vector2 edge = Vector2Subtract(verts[(i+1) % vertCount], verts[i]);
        if (Vector2Length(edge) <= 1e-8f ) {
            continue;
        }
        Vector2 axis = {-edge.y, edge.x};
        axis = Vector2Normalize(axis);
        axes.push_back(axis);
    }
}

static void ProjectOntoAxis(std::vector<Vector2>& verts, Vector2& axis, float& outMin, float& outMax) {
    float dot = Vector2DotProduct(verts[0], axis);
    outMin = dot;
    outMax = dot;
    for (size_t i = 1; i < verts.size(); i++) {
        dot = Vector2DotProduct(verts[i], axis);
        if (dot < outMin) {
            outMin = dot;
        }
        if (dot > outMax) {
            outMax = dot;
        }
    }
}


struct SATResult {
    bool intersect = false;
    float penetration = 0.0f;
    Vector2 axis = {0, 0};
    // Minimum Translation Vector
    Vector2 mtv  = {0, 0};
};

SATResult SATCollision(ConvexPoly& a, ConvexPoly& b) {
    SATResult result;
    std::vector<Vector2> aVerts = a.GetWorldPoints();
    std::vector<Vector2> bVerts = b.GetWorldPoints();

    if (aVerts.size() < 3 || bVerts.size() < 3) {
        return result;
    }

    std::vector<Vector2> axes;
    axes.reserve(aVerts.size() + bVerts.size());
    ComputeAxes(aVerts, axes);
    ComputeAxes(bVerts, axes);


    Vector2 bestAxis = {0, 0};
    Vector2 centersDelta = Vector2Subtract(b.center, a.center);
    float minOverlap = std::numeric_limits<float>::infinity();

    for (Vector2& axis : axes) {
        float aMin, aMax, bMin, bMax;
        ProjectOntoAxis(aVerts, axis, aMin, aMax);
        ProjectOntoAxis(bVerts, axis, bMin, bMax);
        float max = aMax < bMax ? aMax : bMax;
        float min = aMin > bMin ? aMin : bMin;
        float overlap = max - min;
        if (overlap <= 0) {
            result.intersect = false;
            return result;
        }

        if (overlap < minOverlap) {
            minOverlap = overlap;
            bestAxis = axis;
        }
    }

    if (Vector2DotProduct(bestAxis, centersDelta) < 0) {
        bestAxis = Vector2Negate(bestAxis);
    }

    result.intersect = true;
    result.axis = bestAxis;
    result.penetration = minOverlap;
    result.mtv = Vector2Scale(bestAxis, minOverlap);
    return result;
}

std::vector<Vector2> ConvexPoly::GetWorldPoints() {
    const float cos = cosf(this->angleRadians);
    const float sin = sinf(this->angleRadians);
    std::vector<Vector2> result;
    result.reserve(this->localVertices.size());
    for (Vector2& v : this->localVertices) {
        Vector2 rotated = Rotate(v, cos, sin);
        result.push_back({this->center.x + rotated.x, this->center.y + rotated.y});
    }
    return result;
}