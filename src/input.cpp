//
// Created by ram on 21/02/2026.
//

#include "raylib.h"
#include <algorithm>

#include "constants.h"


namespace Input
{
    Vector2 GetVirtualMousePosition()
    {
        const float scale = std::min(static_cast<float>(GetScreenWidth()) / Config::SCREEN_WIDTH,
                                     static_cast<float>(GetScreenHeight()) / Config::SCREEN_HEIGHT);

        const float render_width = Config::SCREEN_WIDTH * scale;
        const float render_height = Config::SCREEN_HEIGHT * scale;

        const float offset_x = (static_cast<float>(GetScreenWidth()) - render_width) / 2;
        const float offset_y = (static_cast<float>(GetScreenHeight()) - render_height) / 2;

        const auto [x, y] = GetMousePosition();

        const float adjusted_x = x - offset_x;
        const float adjusted_y = y - offset_y;

        const float virtual_x = adjusted_x / scale;
        const float virtual_y = adjusted_y / scale;

        return {virtual_x, virtual_y};
    }

    bool isHovered(const Rectangle bounds)
    {
        return CheckCollisionPointRec(GetMousePosition(), bounds);
    }

    bool isClicked(const Rectangle bounds)
    {
        return (isHovered(bounds) && IsMouseButtonPressed(1));
    }
}
