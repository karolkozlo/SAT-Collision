#include <Entity.h>
#include <raymath.h>

Entity::Entity(Vector2 position, std::vector<Vector2> points, Color color, float rotation) {
    this->position = position;
    this->color = color;

    this->shape.angleRadians = rotation;
    this->shape.center = position;
    this->shape.localVertices = points;
}

Vector2 Entity::GetPosition() {
    return position;
}

void Entity::DrawOutline(std::vector<Vector2>& points) {
    size_t pointsNumber = this->shape.localVertices.size();
    if (pointsNumber < 2) return;
    for (size_t i = 0; i < pointsNumber; ++i) {
        DrawLineEx(points[i], points[(i+1) % pointsNumber], 1, this->color);
    }
}

void Entity::DrawFill(std::vector<Vector2>& points) {
    if (points.size() < 3) return;
    Vector2 origin = points[0];

    for (size_t i = 1; i + 1 < points.size(); ++i) {
        DrawTriangle(origin, points[i+1], points[i], this->color);
    }
}

void Entity::DrawShape() {
    std::vector<Vector2> points = this->shape.GetWorldPoints();
    DrawFill(points);
    DrawOutline(points);
}

void Entity::Tick(float deltaTime) {
    DrawShape();
}