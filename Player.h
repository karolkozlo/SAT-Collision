#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>
#include <Entity.h>

class Player : public Entity {
    public:
        Player(Vector2 position, float width, float height, Color color, float rotation = 0);
        virtual void Tick(float deltaTime) override;
    private:
        float moveSpeed = 400;
        Vector2 velocity{};
};

#endif