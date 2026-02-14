#include <Entity.h>
#include <raymath.h>

Entity::Entity(Vector2 position, float width, float height, Color color, float rotation) {
    this->position = position;
    this->width = width;
    this->height = height;
    this->color = color;
    this->rotation = rotation;
}

Entity::Entity(Vector2 position, std::vector<Vector2> points, Color color, float rotation) {
    this->position = position;
    this->color = color;
    this->rotation = rotation;

    this->shape.angleRadians = rotation;
    this->shape.center = position;
    this->shape.localVertices = points;
}

Rectangle Entity::GetCollisionRect() {
    return Rectangle{
        GetPosition().x,
        GetPosition().y,
        width,
        height
    };
};

Vector2 Entity::GetPosition() {
    return position;
}

void Entity::DrawOutline() {
    size_t pointsNumber = this->shape.localVertices.size();
    std::vector<Vector2> points = this->shape.GetWorldPoints();
    if (pointsNumber < 2) return;
    for (size_t i = 0; i < pointsNumber; ++i) {
        DrawLineEx(points[i], points[(i+1) % pointsNumber], 1, this->color);
    }
}

void Entity::DrawShape() {
    DrawOutline();
}

void Entity::Tick(float deltaTime) {
    this->DrawShape();
}