//
// Created by ram on 20/02/2026.
//
#include <random>
#include "game.h"


DiceResult RollDice() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);

    const int d1 = dis(gen);
    const int d2 = dis(gen);

    return { d1, d2, d1 + d2, d1 == d2 };
}

void MovePlayer(Player& player, const int steps)
{
    player.position = (player.position + steps) % 40;

    if (player.position < (player.position - steps))
    {
        player.balance += 200;
    }
}