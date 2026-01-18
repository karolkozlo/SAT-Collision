#include <raylib.h>
#include <raymath.h>

int main() {
    int windowWidth = 800;
    int windowHeight = 600;
    InitWindow(windowWidth, windowHeight, "SAT Collision");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }
     CloseWindow();
}