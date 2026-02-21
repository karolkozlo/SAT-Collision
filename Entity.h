#ifndef ENTITY_H
#define ENTITY_H
#include <raylib.h>
#include <ConvexPoly.h>

class Entity {
    public:
        Entity(Vector2 position, std::vector<Vector2> points, Color color, float rotation = 0);
        virtual Vector2 GetPosition();
        virtual void Tick(float deltaTime);
        void DrawShape();
        void DrawOutline(std::vector<Vector2>& points);
        void DrawFill(std::vector<Vector2>& points);
        ConvexPoly shape;
    protected:
        Vector2 position;
        Color color;
};

#endif