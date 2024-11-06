#ifndef HOME_HPP
#define HOME_HPP

#include "raylib/raylib.h"

namespace home
{
    // Draw accepts a Rectangle representing the container's position and size
    inline void Draw(const Rectangle &container)
    {
        DrawText("Home", container.x + 10, container.y + 10, 20, BLACK);
        DrawText("Please select a initial template to start", container.x + 10, container.y + 40, 20, DARKGRAY);
    }

}

#endif // HOME_HPP
