#include <Entity.h>
#include <raymath.h>

Entity::Entity(Vector2 position, float width, float height, Color color, float rotation) {
    this->position = position;
    this->width = width;
    this->height = height;
    this->color = color;
    this->rotation = rotation;
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
    Rectangle rect{this->position.x, this->position.y, this->width, this->height};
    DrawRectanglePro(rect, {this->width / 2, this->height / 2}, this->rotation, this->color);
}