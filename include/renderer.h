//
// Created by ram on 20/02/2026.
//

#ifndef OPENPLOTS_RENDERER_H
#define OPENPLOTS_RENDERER_H

namespace Renderer
{
    // TODO: Create functionality to draw the background and the board grid
    void DrawBoard();
    // TODO: Create functionality to draw the property cards in the sidebar when selected
    void DrawSidebar();
    // TODO: Create functionality to draw the player tokens using their visual coordinates
    // TODO: Create functionality to draw the dice faces based on the last roll

    void DrawDice(Color dice_color, int dice1, int dice2);
}

#endif //OPENPLOTS_RENDERER_H
