#ifndef ENTITY_H
#define ENTITY_H
#include <raylib.h>

class Entity {
    public:
        Entity(Vector2 position, float width, float height, Color color);
        Rectangle GetCollisionRect();
        virtual Vector2 GetPosition();
        virtual void Tick(float deltaTime);
    protected:
        Vector2 position;
        float width;
        float height;
        Color color;
};

#endif