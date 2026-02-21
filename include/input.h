//
// Created by ram on 21/02/2026.
//

#ifndef OPENPLOTS_INPUT_H
#define OPENPLOTS_INPUT_H

#include "raylib.h"

namespace Input
{
    // TODO: Define a structure to store the "Virtual Mouse State"
    //       This should hold the translated X/Y coordinates
    //       It should also track button states (is the button down, was it just pressed?)
    // TODO: Define a way to store the Window/Scale data needed for translation
    //       (Current scale, X offset, Y offset)
    Vector2 GetVirtualMousePosition();

    bool isClicked(Rectangle bounds);


    bool isHovered(Rectangle bounds);
}

#endif //OPENPLOTS_INPUT_H
