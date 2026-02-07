#include <Entity.h>
#include <raymath.h>

Entity::Entity(Vector2 position, float width, float height, Color color) {
    this->position = position;
    this->width = width;
    this->height = height;
    this->color = color;
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

void Entity::Tick(float deltaTime) {
    DrawRectangle(this->position.x, this->position.y, this->width, this->height, this->color);
}