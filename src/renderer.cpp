//
// Created by ram on 20/02/2026.
//

#include "renderer.h"

#include <sstream>

#include "constants.h"
#include "game.h"

namespace Renderer {
    void DrawSpace(const Space& space, const int index, Font &gameFont) {
        const Rectangle rect = GetSpaceRect(index);

        const bool isCorner = (index % 10 == 0);

        float rotation = 0.0f;

        if (isCorner) {
            DrawRectangleRec(rect, space.color);
        }
        else {
            DrawRectangleRec(rect, RAYWHITE);
            constexpr float hSize = 0.25f;
            if (index < 10) { // BOTTOM: Header at Top
                DrawRectangleRec({rect.x, rect.y, rect.width, rect.height * hSize}, space.color);
                rotation = 0.0f;
            }
            else if (index < 20) { // LEFT: Header at Right
                DrawRectangleRec({rect.x + rect.width * (1 - hSize), rect.y, rect.width * hSize, rect.height}, space.color);
                rotation = 90.0f;
            }
            else if (index < 30) { // TOP: Header at Bottom
                DrawRectangleRec({rect.x, rect.y + rect.height * (1 - hSize), rect.width, rect.height * hSize}, space.color);
                rotation = 180.0f;
            }
            else { // RIGHT: Header at Left
                DrawRectangleRec({rect.x, rect.y, rect.width * hSize, rect.height}, space.color);
                rotation = -90.0f;
            }
        }

        DrawRectangleLinesEx(rect, 1.0f, BLACK);

        constexpr float baseFontSize = 12 ;
        const Font font = gameFont;

        std::vector<std::string> lines;
        std::string currentLine;
        std::stringstream ss(space.name);
        std::string word;

        while (ss >> word) lines.push_back(word);

        float totalHeight = static_cast<float>(lines.size()) * (baseFontSize + 2);
        float currentYOffset = -totalHeight / 2.0f + (baseFontSize / 2.0f);

        for (const auto& line : lines) {
            Vector2 textSize = MeasureTextEx(gameFont, line.c_str(), baseFontSize, 1.0f);

            float lineFontSize = baseFontSize;

            float maxWidth = rect.width * 0.8f;

            if (rotation == 90 || rotation == -90 ) maxWidth = rect.height * 0.8f;

            if (textSize.x > maxWidth) {
                lineFontSize *= (maxWidth / textSize.x);
                textSize = MeasureTextEx(font, line.c_str(), lineFontSize, 1.0f);
            }

            Vector2 lineOrigin = { textSize.x / 2.0f, textSize.y / 2.0f };

            const Vector2 center = {
                rect.x + rect.width / 2.0f,
                rect.y + rect.height / 2.0f
            };
            Vector2 lineCenter = center;
            if (rotation == 0) lineCenter.y += currentYOffset;
            else if (rotation == 180) lineCenter.y -= currentYOffset;
            else if (rotation == 90)  lineCenter.x -= currentYOffset;
            else lineCenter.x += currentYOffset;

            DrawTextPro(gameFont, line.c_str(), lineCenter, lineOrigin, rotation, lineFontSize, 1.0f, BLACK);

            currentYOffset += (baseFontSize + 2);
        }

    };

    void DrawBoard(const std::vector<Space> &board, const int selectedIndex, Font &gameFont) {
        constexpr Rectangle innerBoard = {
            20.0f + Config::INNER_BOARD_PADDING,
            20.0f + Config::INNER_BOARD_PADDING,
            Config::BOARD_SIZE - (Config::INNER_BOARD_PADDING * 2.0f),
            Config::BOARD_SIZE - (Config::INNER_BOARD_PADDING * 2.0f)
        };

        DrawRectangleRec(innerBoard, (Color){ 230, 235, 220, 255 });
        DrawRectangleLinesEx(innerBoard, 1.0f, BLACK);

        constexpr float titleFontSize = 80.0f;
        auto [x, y] = MeasureTextEx(gameFont, Config::GAME_TITLE, titleFontSize , 1.0f);
        const Vector2 titleOrigin = { x / 2.0f, y / 2.0f };

        DrawTextPro(gameFont, Config::GAME_TITLE, {Config::BOARD_SIZE / 2.0f + Config::PADDING, Config::BOARD_SIZE / 2.0f + Config::PADDING}, titleOrigin, 45.0f, titleFontSize, 1.0f, LIGHTGRAY);

        for (int i = 0; i < static_cast<int>(board.size()); i++) {
            const Rectangle rect = GetSpaceRect(i);
            DrawSpace(board[i], i, gameFont);

            if (i == selectedIndex) {
                DrawRectangleLinesEx(rect, 3.0f, MAROON);
            }
        }
    }

    void DrawSidebar(const UI::SidebarState &sidebar_state, const Font &gameFont) {
        DrawRectangle(Config::UI_START_X + Config::PADDING + Config::UI_SEPARATOR , Config::PADDING, Config::SCREEN_WIDTH - Config::UI_START_X - Config::PADDING * 2 - Config::UI_SEPARATOR, Config::SCREEN_HEIGHT - Config::PADDING * 2, (Color){30, 30, 30, 255});
        if (sidebar_state.showDetails && sidebar_state.activeSpace != nullptr) {
            const auto&[name, price, rent, color, buyable] = *sidebar_state.activeSpace;

            constexpr float cardWidth = 180;
            constexpr float cardHeight = 240;
            constexpr float cardX = Config::UI_START_X + 50 + Config::UI_SEPARATOR;
            constexpr float cardY = 50;

            DrawRectangle(cardX + 4, cardY + 4, cardWidth, cardHeight, BLACK);
            DrawRectangle(cardX, cardY, cardWidth, cardHeight, RAYWHITE);

            DrawRectangle(cardX, cardY, cardWidth, 40, color);

            constexpr float nameSize = 18.0f;
            auto [x, y] = MeasureTextEx(gameFont, name.c_str(), nameSize, 1.0f);
            const Vector2 namePos = { cardX + (cardWidth / 2) - (x / 2), cardY + 50 };
            DrawTextEx(gameFont, name.c_str(), namePos, nameSize, 1.0f, BLACK);

            DrawLine(cardX + 10, cardY + 70, cardX + cardWidth - 10, cardY + 70, LIGHTGRAY);

            if (buyable) {
                DrawTextEx(gameFont, TextFormat("RENT $%d", rent), {cardX + 15, cardY + 90}, 15.0f, 1.0f, BLACK);
                DrawTextEx(gameFont, TextFormat("MORTGAGE: $%d", price / 2), {cardX + 15, cardY + 210}, 12.0f, 1.0f, DARKGRAY);
            } else {
                DrawTextEx(gameFont, "Special Interest", {cardX + 15, cardY + 90}, 15.0f, 1.0f, DARKPURPLE);
            }
        }

    }

    void DrawPlayers(const std::vector<Player>& players)
    {
        for (const auto& player : players)
        {
            if (player.isBankrupt) continue;

            auto [x, y, width, height] = GetSpaceRect(player.position);

            DrawCircleV(player.visualPos, 8.0f, player.color);
            DrawCircleLinesV(player.visualPos, 8.0f, BLACK);
        }
    }

    void DrawDice(const int value, const float offset, Color color)
    {
        const float x = Config::BOARD_SIZE / 2 - 65 + Config::PADDING  + offset ;
        constexpr float y = Config::PADDING + Config::INNER_BOARD_PADDING + 50;
        const Rectangle rec = {x, y, 50, 50};
        constexpr float dice_padding = 12.0f;
        DrawRectangleRounded(rec, 0.4f, 0, color);
        if (value > 1)
        {
            DrawCircle(x + dice_padding, y + dice_padding, 5.0f, BLACK);
            DrawCircle(x + 50 - dice_padding, y + 50 - dice_padding, 5.0f, BLACK);
        }
        if (value > 3)
        {
            DrawCircle(x + 50 - dice_padding, y + dice_padding, 5.0f, BLACK);
            DrawCircle(x + dice_padding, y + 50 - dice_padding, 5.0f, BLACK);
        }
        if (value > 5)
        {
            DrawCircle(x + dice_padding, y + 25, 5.0f, BLACK);
            DrawCircle(x + 50 - dice_padding, y + 25, 5.0f, BLACK);
        }
        if (value % 2 != 0)
        {
            DrawCircle(x + 25, y + 25, 5.0f, BLACK);
        }
    }
}
