#include <Player.h>
#include <raymath.h>

Player::Player(Vector2 position, float width, float height, Color color)
    : Entity(position, width, height, color) {

}

void Player::Tick(float deltaTime) {
    if (IsKeyDown(KEY_A)) velocity.x -= 1.0;
    if (IsKeyDown(KEY_D)) velocity.x += 1.0;
    if (IsKeyDown(KEY_S)) velocity.y += 1.0;
    if (IsKeyDown(KEY_W)) velocity.y -= 1.0;

    if (Vector2Length(velocity) != 0) {
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(velocity), moveSpeed * deltaTime));
    }
    velocity = {};

    DrawRectangle(this->position.x, this->position.y, this->width, this->height, this->color);
}