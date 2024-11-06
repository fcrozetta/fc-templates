#include "raylib/raylib.h"

int main()
{
    // Initialize window
    int screenWidth = 800;
    int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Hello, raylib!");

    SetTargetFPS(60); // Set frame rate

    // Main game loop
    while (!WindowShouldClose())
    { // Detect window close button
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, world!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    // Close window and deinitialize raylib
    CloseWindow();
    return 0;
}
