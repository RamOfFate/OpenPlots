//
// Created by ram on 20/02/2026.
//

#ifndef OPENPLOTS_UI_H
#define OPENPLOTS_UI_H

#include "raylib.h"
#include "board.h"
#include <vector>

namespace UI {
    struct SidebarState {
        int hoveredIndex;
        int selectedIndex;
        bool showDetails;
        const Space* activeSpace;
    };

    SidebarState CalculateSidebarState(Vector2 virtualMouse, const std::vector<Space> &board, int currentSelected);


}

#endif //OPENPLOTS_UI_H