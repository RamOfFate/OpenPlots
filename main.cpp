#include "raylib.h"
#include <algorithm>

#include "constants.h"
#include "board.h"
#include "renderer.h"
#include "ui.h"
#include "player.h"

int main() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, "Open Plots");

    Font mainFont = LoadFontEx("resources/Poppins-SemiBold.ttf", 64, nullptr, 0);


    const std::vector<Space> gameBoard = InitializeBoard();

    const RenderTexture2D target = LoadRenderTexture(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);

    int persistentSelection = -1;

    const std::vector<Player> players = {
        {0, "Player 1", 0, 1500, RED, false},
        {1, "Player 2", 0, 1500, BLUE, false},
        {2, "Player 3", 0, 1500, GREEN, false}
    };

    while (!WindowShouldClose()) {

        const auto currentWidth = static_cast<float>(GetScreenWidth());
        const auto currentHeight = static_cast<float>(GetScreenHeight());

        const float scale = std::min( currentWidth / Config::SCREEN_WIDTH, currentHeight / Config::SCREEN_HEIGHT );

        const float renderWidth = Config::SCREEN_WIDTH * scale;
        const float renderHeight = Config::SCREEN_HEIGHT * scale;
        const float offsetX = (currentWidth - renderWidth) / 2.0f;
        const float offsetY = (currentHeight - renderHeight) / 2.0f;

        auto [x, y] = GetMousePosition();

        const Vector2 virtualMouse = {
            (x - offsetX ) / scale,
            (y - offsetY ) / scale
        };

        UI::SidebarState uiState = UI::CalculateSidebarState(virtualMouse, gameBoard, persistentSelection);
        persistentSelection = uiState.selectedIndex;

        if (uiState.hoveredIndex != -1) {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        } else {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }

        BeginTextureMode(target);

            ClearBackground(BLACK);
            Renderer::DrawBoard(gameBoard, persistentSelection, mainFont);
            Renderer::DrawSidebar(uiState, mainFont);
            Renderer::DrawPlayers(players);

        EndTextureMode();

        BeginDrawing();

            ClearBackground(BLACK);
            DrawTexturePro(target.texture, { 0.0f, 0.0f, static_cast<float>(target.texture.width), static_cast<float>(-target.texture.height)},
            {offsetX, offsetY, renderWidth,renderHeight},
            {0, 0}, 0.0f, WHITE);

        EndDrawing();
    }

    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}