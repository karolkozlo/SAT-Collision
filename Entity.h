#ifndef ENTITY_H
#define ENTITY_H
#include <raylib.h>

class Entity {
    public:
        Entity(Vector2 position, float width, float height);
        Rectangle GetCollisionRect();
        Vector2 GetPosition();
        void Tick(float deltaTime);
    private:
        Vector2 position;
        float width;
        float height;
};

#endif