#include <Player.h>
#include <raymath.h>

const int ROTATION_SPEED = 5;

Player::Player(Vector2 position, std::vector<Vector2> points, Color color, float rotation)
    : Entity(position, points, color, rotation) {
        lastPosition = position;
        lastRotation = this->shape.angleRadians;
}

void Player::Tick(float deltaTime, const std::vector<ConvexPoly*>& obstacles) {
    lastPosition = this->position;
    lastRotation = this->shape.angleRadians;

    if (IsKeyDown(KEY_A)) velocity.x -= 1.0;
    if (IsKeyDown(KEY_D)) velocity.x += 1.0;
    if (IsKeyDown(KEY_S)) velocity.y += 1.0;
    if (IsKeyDown(KEY_W)) velocity.y -= 1.0;
    float deltaAngle = 0.0f;
    if (IsKeyDown(KEY_E)) {
        deltaAngle += ROTATION_SPEED * deltaTime;
    }
    if (IsKeyDown(KEY_R)) {
        deltaAngle -= ROTATION_SPEED * deltaTime;
    }

    this->TryMove(obstacles, velocity, deltaAngle, deltaTime);

    velocity = {};
    Entity::Tick(deltaTime);
}

bool Player::TryMove(const std::vector<ConvexPoly*>& obstacles, Vector2 inputDelta, float deltaAngle, float deltaTime) {
    Vector2 move = {0,0};
    if (Vector2Length(inputDelta) > 0.0f) {
        move = Vector2Scale(Vector2Normalize(inputDelta), moveSpeed * deltaTime);
    }
    // Try to move
    this->position = Vector2Add(this->position, move);
    this->shape.center = this->position;
    // Check collision
    bool collided = false;
    Vector2 lastAxis = {0,0};
    for (int i = 0; i < 4; ++i) {
        bool any = false;
        for (ConvexPoly* ob : obstacles) {
            SATResult result = ConvexPoly::SATCollision(this->shape, *ob);
            if (result.intersect) {
                this->position = Vector2Subtract(this->position, result.mtv);
                this->shape.center = this->position;
                lastAxis = result.axis;
                any = true;
                collided = true;
            }
        }
        if (!any) break;
    }
    // Slide
    if (collided) {
        Vector2 tangent = { -lastAxis.y, lastAxis.x };
        float alongT = Vector2DotProduct(move ,tangent);
        Vector2 slideMove = Vector2Scale(tangent, alongT);


        Vector2 beforeSlide = this->position;
        this->position = Vector2Add(this->position, slideMove);
        this->shape.center = this->position;

        bool stillColliding = false;
        for (ConvexPoly* ob : obstacles) {
            SATResult result = ConvexPoly::SATCollision(this->shape, *ob);
            if (result.intersect) {
                stillColliding = true;
                break;
            }
        }
        if (stillColliding) {
            this->position = beforeSlide;
            this->shape.center = this->position;
        }
    }
    // Try to rotate
    float oldAngle = this->shape.angleRadians;
    this->shape.angleRadians += deltaAngle;
    bool rotationCollision = false;
    for (ConvexPoly* ob : obstacles) {
        SATResult result = ConvexPoly::SATCollision(this->shape, *ob);
        if (result.intersect) { rotationCollision = true; break; }
    }
    if (rotationCollision) {
        this->shape.angleRadians = oldAngle;
    }


    for (ConvexPoly* ob : obstacles) {
        SATResult s = ConvexPoly::SATCollision(this->shape, *ob);
        if (s.intersect) return false;
    }
    return true;
}
