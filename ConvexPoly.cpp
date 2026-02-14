#include <ConvexPoly.h>

static inline Vector2 Rotate(const Vector2& v, float cos, float sin) {
    return {v.x * cos - v.y * sin,
            v.x * sin + v.y * cos};
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