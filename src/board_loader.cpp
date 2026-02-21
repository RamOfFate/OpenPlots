//
// Created by ram on 21/02/2026.
//

#include <format>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "space.h"

namespace BoardLoader
{
    Color ParseColor(const std::string& colorStr)
    {
        std::stringstream ss(colorStr);
        std::string segment;
        unsigned char rgba[4] = {255, 255, 255, 255};
        int i = 0;

        while (std::getline(ss, segment, '-') && i < 4)
        {
            rgba[i++] = static_cast<unsigned char>(std::stoi(segment));
        }
        return Color{rgba[0], rgba[1], rgba[2], rgba[3]};
    }

    std::vector<Space> Load(const std::string& path)
    {
        std::vector<Space> spaces;
        std::ifstream file(path);

        if (!file.is_open())
        {
            std::cerr << "Could not open file " << path << std::endl;
            return spaces;
        }

        std::string line;
        bool isHeader = true;

        while (std::getline(file, line))
        {
            if (isHeader)
            {
                isHeader = false;
                continue;
            }

            std::stringstream ss(line);
            std::string cell;
            std::vector<std::string> row;

            while (std::getline(ss, cell, ','))
            {
                row.push_back(cell);
            }

            if (row.size() >= 7)
            {
                Space space;
                space.name = row[0];
                space.price = std::stof(row[1]);
                space.house_price = std::stof(row[2]);
                space.rent = std::stof(row[3]);
                space.house_rent = std::stof(row[4]);
                space.color = ParseColor(row[5]);
                space.type = row[6];

                spaces.push_back(space);
            }
        }
        return spaces;
    }
};


