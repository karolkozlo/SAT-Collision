#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>
#include <Entity.h>

class Player : public Entity {
    public:
        Player(Vector2 position, std::vector<Vector2> points, Color color, float rotation = 0);
        void Tick(float deltaTime, const std::vector<ConvexPoly*>& obstacles);
    private:
        float moveSpeed = 400;
        Vector2 velocity{};
        Vector2 lastPosition{};
        float lastRotation = 0.0f;
        bool TryMove(const std::vector<ConvexPoly*>& obstacles, Vector2 inputDelta, float deltaAngle, float deltaTime);
};

#endif