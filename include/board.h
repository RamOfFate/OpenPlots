//
// Created by ram on 20/02/2026.
//

#ifndef OPENPLOTS_BOARD_H
#define OPENPLOTS_BOARD_H

#include <string>
#include <vector>

#include "raylib.h"

struct Space {
    std::string name;
    int price;
    int rent;
    Color color;
    bool buyable;
};

std::vector<Space> InitializeBoard();
Rectangle GetSpaceRect(int index);

#endif //OPENPLOTS_BOARD_H