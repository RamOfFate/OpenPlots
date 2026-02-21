//
// Created by ram on 20/02/2026.
//

#ifndef OPENPLOTS_RENDERER_H
#define OPENPLOTS_RENDERER_H

#include "board.h"
#include "ui.h"

struct Player;

namespace Renderer {
    void DrawBoard(const std::vector<Space> &board, int selectedIndex, Font &gameFont);

    void DrawSpace(const Space& space, int index, Font &gameFont);

    void DrawSidebar(const UI::SidebarState& sidebar_state, const Font &gameFont);

    void DrawPlayers(const std::vector<Player>& players);

    void DrawDice(int value, float offset = 0, Color color = BEIGE);
}

#endif //OPENPLOTS_RENDERER_H