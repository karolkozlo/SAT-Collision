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
    std::vector<Vector2> otherPoints = {
        {0, 0},
        {60, 0},
        {60, 60},
        {0, 60}
    };
    Entity otherThing{{(windowWidth / 50) + 400, (windowHeight / 4) + 100}, otherPoints, RED};

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