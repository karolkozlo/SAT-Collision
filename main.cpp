#include <raylib.h>
#include <raymath.h>
#include <Entity.h>

int main() {
    int windowWidth = 800;
    int windowHeight = 600;
    InitWindow(windowWidth, windowHeight, "SAT Collision");
    SetTargetFPS(60);

    // Rect
    int rectX = windowWidth / 4;
    int rectY = windowHeight / 4;
    int rectWidth = 60;
    int rectHeight = 60;
    int rectMoveSpeed = 8;
    int rectYDirection = 1;
    Entity player{{windowWidth / 4, windowHeight / 4}, 60, 60};
    Entity otherThing{{(windowWidth / 50) + 400, (windowHeight / 4) + 100}, 60, 60};
    //Rect Collision
    int lRectX{rectX};
    int rRectX{rectX + rectWidth};
    int uRectY{rectY};
    int bRectY{rectY + rectHeight};


    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        BeginDrawing();
        ClearBackground(WHITE);
        player.Tick(deltaTime);
        otherThing.Tick(deltaTime);
        EndDrawing();
    }
     CloseWindow();
}