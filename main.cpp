#include <raylib.h>
#include <raymath.h>
#include <Entity.h>
#include <Player.h>

int main() {
    float windowWidth = 800;
    float windowHeight = 600;
    InitWindow(windowWidth, windowHeight, "SAT Collision");
    SetTargetFPS(60);

    std::vector<Vector2> playerPoints = {
        {0, 0},
        {60, 0},
        {60, 60},
        {0, 60}
    };
    Player player{{windowWidth / 4, windowHeight / 4}, playerPoints, BLUE};
    std::vector<Vector2> otherPoints = {
        {0, 0},
        {60, 0},
        {60, 60},
        {0, 60}
    };
    Entity otherThing{{(windowWidth / 50.f) + 400.f, (windowHeight / 4.f) + 100.f}, otherPoints, RED};

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