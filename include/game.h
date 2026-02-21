//
// Created by ram on 20/02/2026.
//

#ifndef OPENPLOTS_GAME_LOGIC_H
#define OPENPLOTS_GAME_LOGIC_H
#include "raylib.h"
#include <string>

struct Player
{
    int id;
    std::string name;
    int position;
    Vector2 visualPos;
    int balance;
    Color color;
    bool isBankrupt;

    Player(int id, std::string name, int pos, int bal, Color col, bool bankrupt)
        : id(id), name(name), position(pos), balance(bal), color(col), isBankrupt(bankrupt) {
        visualPos = { 0, 0 }; // We will set this properly in main
    }
};

struct DiceResult {
    int die1;
    int die2;
    int total;
    bool isDouble;
};

struct GameContext {
    std::vector<Player> players;
    int currentPlayerIndex = 0;
    DiceResult lastRoll = {1, 6, 2, false};
    bool canRoll = true;
};

DiceResult RollDice();

void MovePlayer(Player& player, int steps);



#endif //OPENPLOTS_GAME_LOGIC_H