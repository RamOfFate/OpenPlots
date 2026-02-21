//
// Created by ram on 21/02/2026.
//

#ifndef OPENPLOTS_BOARD_LOADER_H
#define OPENPLOTS_BOARD_LOADER_H
#include <vector>

#include "space.h"

namespace BoardLoader
{
    std::vector<Space> Load(std::string path);
}

#endif //OPENPLOTS_BOARD_LOADER_H
