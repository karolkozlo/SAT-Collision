#include <ConvexPoly.h>
#include <raymath.h>

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