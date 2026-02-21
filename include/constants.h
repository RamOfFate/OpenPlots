//
// Created by ram on 20/02/2026.
//

#ifndef OPENPLOTS_CONSTANTS_H
#define OPENPLOTS_CONSTANTS_H
#include <string>

namespace Config {
    constexpr float SCREEN_WIDTH = 1280.0f;
    constexpr float SCREEN_HEIGHT = 720.0f;

    constexpr float PADDING = 20.0f;
    constexpr float UI_SEPARATOR = 20.0f;

    constexpr int TOTAL_SPACES = 40;
    constexpr float BOARD_SIZE = SCREEN_HEIGHT - PADDING * 2;
    constexpr float INNER_BOARD_PADDING = (BOARD_SIZE / 12.0f) * 1.5f;

    constexpr Color COLOR_BACKGROUND = {21, 21, 21, 255};
    constexpr auto COLOR_FOREGROUND = LIGHTGRAY;

    constexpr float UI_START_X = BOARD_SIZE ;

    constexpr auto GAME_TITLE = "Open Plots";
}

#endif //OPENPLOTS_CONSTANTS_H