#include "raylib.h"
#include <vector>
#include <algorithm>

#include "constants.h"
#include "input.h"

namespace UI
{
    std::vector<Rectangle> getButtons()
    {
        return {Config::DICE_BUTTON};
    }


    void UpdateCursor(std::vector<Rectangle>& rectangles)
    {
        bool hovered = false;
        for (Rectangle rectangle : rectangles)
        {
            if (Input::isHovered(rectangle) && !IsMouseButtonDown(0))
            {
                SetMouseCursor(4);
                hovered = true;
                break;
            }
        }
        if (!hovered) SetMouseCursor(0);
    }
}
