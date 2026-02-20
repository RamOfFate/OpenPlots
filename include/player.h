//
// Created by ram on 20/02/2026.
//

#ifndef OPENPLOTS_PLAYER_H
#define OPENPLOTS_PLAYER_H
#include "raylib.h"
#include <string>

struct Player
{
    int id;
    std::string name;
    int position;
    int balance;
    Color color;
    bool isBankrupt;
};

#endif //OPENPLOTS_PLAYER_H