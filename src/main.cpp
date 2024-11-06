#include "common.hpp"
#include "fastapi/fastapi.hpp"
#include "home/home.hpp"

int main()
{
    // Initialization
    fastapi::FormData form;
    const int initialScreenWidth = 800;
    const int initialScreenHeight = 600;
    InitWindow(initialScreenWidth, initialScreenHeight, "Fc-templates");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    // Load default style to ensure visibility
    GuiLoadStyleDefault();
    GuiSetStyle(DEFAULT, TEXT_SIZE, 18);

    SetTargetFPS(60);

    // Sidebar menu items
    const char *sideMenuItems = "FastApi";
    int selectedItem = -1; // Initial selection
    int scrollIndex = 0;   // Scroll position for ListView

    // Define a container rectangle, this can be positioned dynamically

    // Main loop
    while (!WindowShouldClose())
    {
        // Update screen size dynamically
        float screenWidth = GetScreenWidth();
        float screenHeight = GetScreenHeight();

        Rectangle sideMenu = {10, 20, 100, screenHeight - 40};
        Rectangle mainPanel = {140, 20, screenWidth - 170, screenHeight - 40};
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw Sidebar with ListView and pass &selectedItem as required by your setup
        GuiListView((Rectangle){10, 20, 100, screenHeight - 40}, sideMenuItems, &scrollIndex, &selectedItem);

        // Draw the container outline (optional for visualization)
        DrawRectangleLinesEx(mainPanel, 1, GRAY);

        // Display different content based on the selected sidebar item, drawn inside the container
        switch (selectedItem)
        {
        case 0:
        {

            fastapi::Draw(mainPanel, form);
            break;
        }

        default:
            home::Draw(mainPanel);
            break;
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
