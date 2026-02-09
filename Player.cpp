#include <Player.h>
#include <raymath.h>

const int ROTATION_SPEED = 50;

Player::Player(Vector2 position, float width, float height, Color color, float rotation)
    : Entity(position, width, height, color, rotation) {

}

void Player::Tick(float deltaTime) {
    if (IsKeyDown(KEY_A)) velocity.x -= 1.0;
    if (IsKeyDown(KEY_D)) velocity.x += 1.0;
    if (IsKeyDown(KEY_S)) velocity.y += 1.0;
    if (IsKeyDown(KEY_W)) velocity.y -= 1.0;
    if (IsKeyDown(KEY_R)) {
        rotation += ROTATION_SPEED * deltaTime;
    }
    if (IsKeyDown(KEY_F)) {
        rotation -= ROTATION_SPEED * deltaTime;
    }

    if (Vector2Length(velocity) != 0) {
        position = Vector2Add(position, Vector2Scale(Vector2Normalize(velocity), moveSpeed * deltaTime));
    }
    velocity = {};

    Rectangle rect{this->position.x, this->position.y, this->width, this->height};
    DrawRectanglePro(rect, {this->width / 2, this->height / 2}, this->rotation, this->color);
}