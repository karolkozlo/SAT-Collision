#ifndef ENTITY_H
#define ENTITY_H
#include <raylib.h>
#include <ConvexPoly.h>

class Entity {
    public:
        Entity(Vector2 position, float width, float height, Color color, float rotation = 0);
        Entity(Vector2 position, std::vector<Vector2> points, Color color, float rotation = 0);
        Rectangle GetCollisionRect();
        virtual Vector2 GetPosition();
        virtual void Tick(float deltaTime);
        void DrawShape();
        void DrawOutline();
        // void DrawFill();
    protected:
        Vector2 position;
        ConvexPoly shape;
        float width;
        float height;
        Color color;
        float rotation;
};

#endif