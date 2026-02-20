#include <Player.h>
#include <raymath.h>

const int ROTATION_SPEED = 5;

Player::Player(Vector2 position, std::vector<Vector2> points, Color color, float rotation)
    : Entity(position, points, color, rotation) {
}

void Player::Tick(float deltaTime) {
    if (IsKeyDown(KEY_A)) velocity.x -= 1.0;
    if (IsKeyDown(KEY_D)) velocity.x += 1.0;
    if (IsKeyDown(KEY_S)) velocity.y += 1.0;
    if (IsKeyDown(KEY_W)) velocity.y -= 1.0;
    if (IsKeyDown(KEY_E)) {
        this->shape.angleRadians += ROTATION_SPEED * deltaTime;
    }
    if (IsKeyDown(KEY_R)) {
        this->shape.angleRadians -= ROTATION_SPEED * deltaTime;
    }

    if (Vector2Length(velocity) != 0) {
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(velocity), moveSpeed * deltaTime));
        this->shape.center = position;
    }
    velocity = {};

    Entity::Tick(deltaTime);
}