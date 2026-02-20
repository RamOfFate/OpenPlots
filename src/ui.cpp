//
// Created by ram on 20/02/2026.
//
#include "ui.h"

namespace UI {
    SidebarState CalculateSidebarState(const Vector2 virtualMouse, const std::vector<Space> &board, const int currentSelected) {
        SidebarState sidebarStates = { -1, currentSelected, false, nullptr};

        for (int i = 0; i < static_cast<int>(board.size()); i++) {
                if (CheckCollisionPointRec(virtualMouse, GetSpaceRect(i))) {
                    sidebarStates.hoveredIndex = i;
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                        sidebarStates.selectedIndex = sidebarStates.selectedIndex != i ? i : -1;
                    }
                    break;
                }
        }

        if (const int displayIndex (sidebarStates.hoveredIndex != -1 ? sidebarStates.hoveredIndex : sidebarStates.selectedIndex); displayIndex != -1) {
            sidebarStates.showDetails = true;
            sidebarStates.activeSpace = &board[displayIndex];
        }
        return sidebarStates;
    }
}