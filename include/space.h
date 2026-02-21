//
// Created by ram on 21/02/2026.
//

#ifndef OPENPLOTS_SPACE_H
#define OPENPLOTS_SPACE_H
#include <raylib.h>
#include <string>

struct Space
{
    std::string name;
    float price;
    float house_price;
    float rent;
    float house_rent;
    Color color;
    std::string type;
};

#endif //OPENPLOTS_SPACE_H
