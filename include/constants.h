//
// Created by ram on 20/02/2026.
//

#ifndef OPENPLOTS_CONSTANTS_H
#define OPENPLOTS_CONSTANTS_H


#include "raylib.h"

namespace Config
{
    // TODO: Define the screen dimensions (1280x720)
    constexpr float SCREEN_WIDTH = 1280.0f;
    constexpr float SCREEN_HEIGHT = 720.0f;
    // TODO: Define the board size and UI layout constants (Sidebar width, etc.)
    constexpr float UI_MARGIN = 80.0f;
    constexpr float UI_SEPARATOR = 20.0f;

    constexpr float BOARD_START_X = UI_MARGIN;
    constexpr float BOARD_START_Y = UI_MARGIN;
    constexpr float BOARD_SIZE = SCREEN_HEIGHT - UI_MARGIN * 2;

    constexpr float BOARD_PADDING = 80;
    constexpr float INNER_BOARD_START_X = BOARD_START_X + BOARD_PADDING;
    constexpr float INNER_BOARD_START_Y = BOARD_START_Y + BOARD_PADDING;
    constexpr float INNER_BOARD_WIDTH = BOARD_SIZE - BOARD_PADDING * 2;
    constexpr float INNER_BOARD_HEIGHT = BOARD_SIZE - BOARD_PADDING * 2;

    constexpr float SIDEBAR_START_X = UI_MARGIN + BOARD_SIZE + UI_SEPARATOR;
    constexpr float SIDEBAR_START_Y = UI_MARGIN;
    constexpr float SIDEBAR_WIDTH = SCREEN_WIDTH - UI_MARGIN * 2 - UI_SEPARATOR - BOARD_SIZE;
    constexpr float SIDEBAR_HEIGHT = SCREEN_HEIGHT - UI_MARGIN * 2;

    constexpr float DICE_SIZE = 50.0f;
    constexpr float DICE_PADDING = 10.0f;
    constexpr float PIP_RADIUS = 5.0f;
    constexpr float DICE_SEPARATOR = 10.0f;
    constexpr float FIRST_DICE_START_X = UI_MARGIN + BOARD_SIZE / 2.0f - DICE_SIZE - DICE_SEPARATOR;
    constexpr float SECOND_DICE_START_X = FIRST_DICE_START_X + DICE_SIZE + DICE_SEPARATOR;
    constexpr float DICE_START_Y = UI_MARGIN + BOARD_PADDING + 50.0f;

    constexpr float SPACE_DETAILS_START_X = SIDEBAR_START_X + UI_SEPARATOR;
    constexpr float SPACE_DETAILS_START_Y = SIDEBAR_START_Y + UI_SEPARATOR;
    constexpr float SPACE_DETAILS_WIDTH = 180.0f;
    constexpr float SPACE_DETAILS_HEIGHT = 240.0f;


    // TODO: Define a way to store colors for the different property groups
    constexpr auto BOARD_BACKGROUND_COLOR = Color(191, 219, 174, 255);
    constexpr auto BACKGROUND_COLOR = Color(15, 15, 15, 255);
    constexpr auto UI_BACKGROUND_COLOR = Color(25, 25, 25, 255);
    constexpr auto BOARD_BORDER_COLOR = BLACK;

    // TODO: Define buttons boundaries
    constexpr Rectangle DICE_BUTTON = {
        FIRST_DICE_START_X, DICE_START_Y,
        DICE_SIZE * 2 + DICE_SEPARATOR,
        DICE_SIZE
    };
}

#endif //OPENPLOTS_CONSTANTS_H
