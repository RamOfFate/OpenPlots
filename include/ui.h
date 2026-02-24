//
// Created by ram on 20/02/2026.
//

#ifndef OPENPLOTS_UI_H
#define OPENPLOTS_UI_H
#include <raylib.h>
#include <vector>

// TODO: Create a structure to track what the user is interacting with (hovered vs selected)
// TODO: Implement the logic to detect which tile the mouse is over
// TODO: Implement the logic to handle clicking on the "Roll" area/button

namespace UI
{
    std::vector<Rectangle> getButtons();
    void UpdateCursor(std::vector<Rectangle>& rectangles);
}
#endif //OPENPLOTS_UI_H
