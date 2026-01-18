#include <raylib.h>
#include <raymath.h>

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
    //Rect Collision
    int lRectX{rectX};
    int rRectX{rectX + rectWidth};
    int uRectY{rectY};
    int bRectY{rectY + rectHeight};


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(rectX, rectY, rectWidth, rectHeight, BLUE);
        EndDrawing();
    }
     CloseWindow();
}