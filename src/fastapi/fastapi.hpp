#ifndef FASTAPI_HPP
#define FASTAPI_HPP

#include "../common.hpp"
#include <iostream>

namespace fastapi
{
    struct FormData
    {
        bool checkbox = false;      // State for the CheckBox
        bool buttonPressed = false; // Track button press
    };

    inline void Draw(const Rectangle &container, FormData &formData)
    {
        // Title
        DrawText("Simple Form", container.x + 10, container.y + 10, 20, BLACK);

        // Checkbox
        GuiCheckBox(Rectangle{container.x + 10, container.y + 50, 20, 20}, "Accept Terms", &formData.checkbox);

        // Button with adjusted position and size
        if (GuiButton(Rectangle{container.x + 10, container.y + 90, 120, 40}, "Submit"))
        {
            formData.buttonPressed = !formData.buttonPressed; // Toggle button state
            std::cout << "Button Pressed: " << (formData.buttonPressed ? "ON" : "OFF") << std::endl;
        }

        // Display button state
        DrawText(formData.buttonPressed ? "Button is ON" : "Button is OFF", container.x + 140, container.y + 100, 16, DARKGRAY);
    }

} // namespace fastapi

#endif // FASTAPI_HPP
