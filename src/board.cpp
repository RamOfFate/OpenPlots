//
// Created by ram on 20/02/2026.
//

#include "board.h"
#include "constants.h"

const std::vector<Space> MASTER_BOARD_DATA = {
    {"GO", 0, 0, GOLD, false},

    {"Mediterranean Avenue", 60, 2, BROWN, true},
    {"Community Chest", 0, 0, RAYWHITE, false},
    {"Baltic Avenue", 60, 4, BROWN, true},
    {"Income Tax", 0, 0, RAYWHITE, false},

    {"Reading Railroad", 200, 25, LIGHTGRAY, true},
    {"Oriental Avenue", 100, 6, SKYBLUE, true},
    {"Chance", 0, 0, RAYWHITE, false},
    {"Vermont Avenue", 100, 6, SKYBLUE, true},
    {"Connecticut Avenue", 120, 8, SKYBLUE, true},

    {"Jail / Just Visiting", 0, 0, PURPLE, false},
    {"St. Charles Place", 140, 10, PINK, true},
    {"Electric Company", 150, 0, DARKGRAY, true},
    {"States Avenue", 140, 10, PINK, true},
    {"Virginia Avenue", 160, 12, PINK, true},

    {"Pennsylvania Railroad", 200, 25, LIGHTGRAY, true},
    {"St. James Place", 180, 14, ORANGE, true},
    {"Community Chest", 0, 0, RAYWHITE, false},
    {"Tennessee Avenue", 180, 14, ORANGE, true},
    {"New York Avenue", 200, 16, ORANGE, true},

    {"Free Parking", 0, 0, RAYWHITE, false},
    {"Kentucky Avenue", 220, 18, RED, true},
    {"Chance", 0, 0, RAYWHITE, false},
    {"Indiana Avenue", 220, 18, RED, true},
    {"Illinois Avenue", 240, 20, RED, true},

    {"B.&O. Railroad", 200, 25, LIGHTGRAY, true},
    {"Atlantic Avenue", 260, 22, YELLOW, true},
    {"Vent nor Avenue", 260, 22, YELLOW, true},
    {"Water Works", 150, 0, DARKGRAY, true},
    {"Marvin Gardens", 280, 24, YELLOW, true},

    {"Go To Jail", 0, 0, RAYWHITE, false},
    {"Pacific Avenue", 300, 26, GREEN, true},
    {"North Carolina Avenue", 300, 26, GREEN, true},
    {"Community Chest", 0, 0, RAYWHITE, false},
    {"Pennsylvania Avenue", 320, 28, GREEN, true},

    {"Short Line Railroad", 200, 25, LIGHTGRAY, true},
    {"Chance", 0, 0, RAYWHITE, false},
    {"Park Place", 350, 35, DARKBLUE, true},
    {"Luxury Tax", 0, 0, RAYWHITE, false},
    {"Boardwalk", 400, 50, DARKBLUE, true}
};

std::vector<Space> InitializeBoard() {
    std::vector<Space> board;
    for (int i = 0; i < Config::TOTAL_SPACES; i++) {
        if (i < MASTER_BOARD_DATA.size()) {
            board.push_back(MASTER_BOARD_DATA.at(i));
        }
        else {
            board.push_back({"PLOT" + std::to_string(i), 100, 10, DARKGREEN, true});
        }
    }
    return board;
}

Rectangle GetSpaceRect(const int index) {
    constexpr float unit = Config::BOARD_SIZE / 12.0f;
    constexpr float startX = Config::PADDING;
    constexpr float startY = Config::PADDING;
    constexpr float cornerSize = unit * 1.5f;
    constexpr float propLong = unit * 1.5f;
    constexpr float propShort = unit;

    float x = 0.0f, y = 0.0f, w = 0.0f, h = 0.0f;
    const bool isCorner = (index % 10 == 0);

    if (index < 10) { // BOTTOM
        y = startY + Config::BOARD_SIZE - cornerSize;
        if (isCorner) {
            w = cornerSize; h = cornerSize;
            x = (index == 0) ? (startX + Config::BOARD_SIZE - cornerSize) : startX;
        } else {
            w = propShort; h = propLong;
            x = startX + Config::BOARD_SIZE - cornerSize - (static_cast<float>(index) * propShort);
        }
    }
    else if (index < 20) { // LEFT
        x = startX;
        if (isCorner) {
            w = cornerSize; h = cornerSize;
            y = (index == 10) ? (startY + Config::BOARD_SIZE - cornerSize) : startY;
        } else {
            w = propLong; h = propShort;
            y = startY + Config::BOARD_SIZE - cornerSize - (static_cast<float>(index - 10) * propShort);
        }
    }
    else if (index < 30) { // TOP
        y = startY;
        if (isCorner) {
            w = cornerSize; h = cornerSize;
            x = (index == 20) ? startX : (startX + Config::BOARD_SIZE - cornerSize);
        } else {
            w = propShort; h = propLong;
            x = startX + cornerSize + (static_cast<float>(index - 21) * propShort);
        }
    }
    else { // RIGHT
        x = startX + Config::BOARD_SIZE - cornerSize;
        if (isCorner) {
            w = cornerSize; h = cornerSize;
            y = (index == 30) ? startY : (startY + Config::BOARD_SIZE - cornerSize);
        } else {
            w = propLong; h = propShort;
            y = startY + cornerSize + (static_cast<float>(index - 31) * propShort);
        }
    }

    return {x, y, w, h};
}