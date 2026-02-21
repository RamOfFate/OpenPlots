#include "raylib.h"
#include <algorithm>
#include <cmath>

#include "constants.h"
#include "board.h"
#include "renderer.h"
#include "ui.h"
#include "game.h"

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, "Open Plots");

    Font mainFont = LoadFontEx("resources/Poppins-SemiBold.ttf", 64, nullptr, 0);

    const std::vector<Space> gameBoard = InitializeBoard();

    std::vector<Player> players = {
        {0, "Player 1", 0, 1500, RED, false},
        {1, "Player 2", 0, 1500, BLUE, false},
        {2, "Player 3", 0, 1500, GREEN, false}
    };

    for (auto& player : players) {
        Rectangle rect = GetSpaceRect(player.position);
        float offX = (player.id % 2 == 0) ? -10.0f : 10.0f;
        float offY = (player.id < 2) ? -10.0f : 10.0f;
        player.visualPos = {
            rect.x + rect.width / 2.0f + offX,
            rect.y + rect.height / 2.0f + offY
        };
    }

    GameContext gameContext;
    int persistentSelection = -1;

    const RenderTexture2D target = LoadRenderTexture(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);

    while (!WindowShouldClose()) {
        const auto currentWidth = static_cast<float>(GetScreenWidth());
        const auto currentHeight = static_cast<float>(GetScreenHeight());

        const float scale = std::min(currentWidth / Config::SCREEN_WIDTH, currentHeight / Config::SCREEN_HEIGHT);
        const float renderWidth = Config::SCREEN_WIDTH * scale;
        const float renderHeight = Config::SCREEN_HEIGHT * scale;
        const float offsetX = (currentWidth - renderWidth) / 2.0f;
        const float offsetY = (currentHeight - renderHeight) / 2.0f;

        Vector2 mouse = GetMousePosition();
        const Vector2 virtualMouse = {
            (mouse.x - offsetX) / scale,
            (mouse.y - offsetY) / scale
        };

        UI::SidebarState uiState = UI::CalculateSidebarState(virtualMouse, gameBoard, persistentSelection);
        persistentSelection = uiState.selectedIndex;

        Rectangle rollButton = {
            Config::BOARD_SIZE / 2 - 65 + Config::PADDING,
            Config::PADDING + Config::INNER_BOARD_PADDING + 50,
            145, 55
        };

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(virtualMouse, rollButton)) {
            gameContext.lastRoll = RollDice();

            Player& currentPlayer = players[gameContext.currentPlayerIndex];
            currentPlayer.position = (currentPlayer.position + gameContext.lastRoll.total) % 40;

            gameContext.currentPlayerIndex = (gameContext.currentPlayerIndex + 1) % players.size();
        }

        bool hoveringDice = CheckCollisionPointRec(virtualMouse, rollButton);
        if (uiState.hoveredIndex != -1 || hoveringDice) {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        } else {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }

        float dt = GetFrameTime();
        float lerpSpeed = 8.0f;

        for (auto& player : players) {
            Rectangle targetRect = GetSpaceRect(player.position);
            float pOffX = (player.id % 2 == 0) ? -10.0f : 10.0f;
            float pOffY = (player.id < 2) ? -10.0f : 10.0f;

            Vector2 targetPos = {
                targetRect.x + targetRect.width / 2.0f + pOffX,
                targetRect.y + targetRect.height / 2.0f + pOffY
            };

            player.visualPos.x += (targetPos.x - player.visualPos.x) * lerpSpeed * dt;
            player.visualPos.y += (targetPos.y - player.visualPos.y) * lerpSpeed * dt;
        }

        BeginTextureMode(target);
            ClearBackground(BLACK);

            Renderer::DrawBoard(gameBoard, persistentSelection, mainFont);
            Renderer::DrawSidebar(uiState, mainFont);
            Renderer::DrawPlayers(players);

            Color turnColor = players[gameContext.currentPlayerIndex].color;
            DrawCircle(rollButton.x - 20, rollButton.y + 25, 8, turnColor);
            DrawCircleLines(rollButton.x - 20, rollButton.y + 25, 8, BLACK);

            Renderer::DrawDice(gameContext.lastRoll.die1, 0.0f, turnColor);
            Renderer::DrawDice(gameContext.lastRoll.die2, 80.0f, turnColor);
        EndTextureMode();

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexturePro(target.texture,
                { 0.0f, 0.0f, static_cast<float>(target.texture.width), static_cast<float>(-target.texture.height) },
                { offsetX, offsetY, renderWidth, renderHeight },
                { 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    }
    
    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}