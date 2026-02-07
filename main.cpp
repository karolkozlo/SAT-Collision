#include <raylib.h>
#include <raymath.h>
#include <Entity.h>
#include <Player.h>

int main() {
    int windowWidth = 800;
    int windowHeight = 600;
    InitWindow(windowWidth, windowHeight, "SAT Collision");
    SetTargetFPS(60);

    Player player{{windowWidth / 4, windowHeight / 4}, 60, 60, BLUE};
    Entity otherThing{{(windowWidth / 50) + 400, (windowHeight / 4) + 100}, 60, 60, RED};

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