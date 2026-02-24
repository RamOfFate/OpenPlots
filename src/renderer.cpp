
#include "constants.h"
#include "input.h"
#include "raylib.h"
#include "ui.h"

namespace Renderer
{
    void DrawBoard()
    {
        constexpr Rectangle main_board = {Config::UI_MARGIN, Config::UI_MARGIN, Config::BOARD_SIZE, Config::BOARD_SIZE};
        // main board bg
        DrawRectangle(main_board.x, main_board.y, main_board.width, main_board.height,
                      Config::BOARD_BACKGROUND_COLOR);

        constexpr Rectangle inner_board = {
            Config::INNER_BOARD_START_X, Config::INNER_BOARD_START_Y, Config::INNER_BOARD_WIDTH,
            Config::INNER_BOARD_HEIGHT
        };
        // inner board bg
        DrawRectangle(inner_board.x, inner_board.y, inner_board.width, inner_board.height, LIGHTGRAY);

        DrawRectangleLinesEx(inner_board, 2, Config::BOARD_BORDER_COLOR);
    }

    void DrawSidebar()
    {
        // main sidebar bg
        DrawRectangle(Config::SIDEBAR_START_X, Config::SIDEBAR_START_Y, Config::SIDEBAR_WIDTH, Config::SIDEBAR_HEIGHT,
                      Config::UI_BACKGROUND_COLOR);

        // card view bg
        DrawRectangle(Config::SPACE_DETAILS_START_X, Config::SPACE_DETAILS_START_Y, Config::SPACE_DETAILS_WIDTH,
                      Config::SPACE_DETAILS_HEIGHT, RAYWHITE);
    }

    void DrawPips(const Rectangle dice_rec, const int dice)
    {
        const float x = dice_rec.x;
        const float y = dice_rec.y;
        const float width = dice_rec.width;
        const float height = dice_rec.height;
        if (dice > 1)
        {
            DrawCircleV({x + Config::DICE_PADDING, y + Config::DICE_PADDING}, Config::PIP_RADIUS, BLACK);
            DrawCircleV({
                            x + width - Config::DICE_PADDING,
                            y + height - Config::DICE_PADDING
                        }, Config::PIP_RADIUS,
                        BLACK);
        }
        if (dice > 3)
        {
            DrawCircleV({x + width - Config::DICE_PADDING, y + Config::DICE_PADDING},
                        Config::PIP_RADIUS, BLACK);
            DrawCircleV({x + Config::DICE_PADDING, y + height - Config::DICE_PADDING},
                        Config::PIP_RADIUS, BLACK);
        }
        if (dice > 5)
        {
            DrawCircleV({x + Config::DICE_PADDING, y + height / 2}, Config::PIP_RADIUS, BLACK);
            DrawCircleV({x + width - Config::DICE_PADDING, y + height / 2},
                        Config::PIP_RADIUS, BLACK);
        }
        if (dice % 2 != 0)
            DrawCircleV({
                            x + width / 2,
                            y + height / 2
                        }, Config::PIP_RADIUS, BLACK);
    }

    void DrawDice(const Color dice_color, int dice1, int dice2)
    {
        constexpr Rectangle dice1_rec = {
            Config::FIRST_DICE_START_X, Config::DICE_START_Y, Config::DICE_SIZE, Config::DICE_SIZE
        };
        DrawRectangleRounded(dice1_rec, 0.4, 1, dice_color);

        constexpr Rectangle dice2_rec = {
            Config::SECOND_DICE_START_X, Config::DICE_START_Y, Config::DICE_SIZE,
            Config::DICE_SIZE
        };
        DrawRectangleRounded(dice2_rec, 0.4, 1, dice_color);

        DrawPips(dice1_rec, dice1);
        DrawPips(dice2_rec, dice2);
    };
}
