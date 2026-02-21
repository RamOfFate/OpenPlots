// TODO: Initialize the Raylib window and audio/fonts
// TODO: Setup the Game, Board, and RenderTarget
// TODO: Create the Main Loop:
//    1. Calculate the mouse position relative to the virtual resolution
//    2. Update the UI state (hover/selection)
//    3. Update the Game logic (lerping, turn handling)
//    4. Draw everything to the RenderTarget
//    5. Draw the RenderTarget to the screen with letterboxing/scaling
// TODO: Unload resources and close the window

#include <algorithm>
#include <chrono>
#include <random>
#include <string>

#include "constants.h"
#include "game.h"
#include "input.h"
#include "raylib.h"
#include "renderer.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, "Open Plots");

    const RenderTexture2D target = LoadRenderTexture(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);


    while (!WindowShouldClose())
    {
        const auto currentWidth = static_cast<float>(GetScreenWidth());
        const auto currentHeight = static_cast<float>(GetScreenHeight());

        const float scale = std::min(currentWidth / Config::SCREEN_WIDTH, currentHeight / Config::SCREEN_HEIGHT);
        const float renderWidth = Config::SCREEN_WIDTH * scale;
        const float renderHeight = Config::SCREEN_HEIGHT * scale;
        const float offsetX = (currentWidth - renderWidth) / 2.0f;
        const float offsetY = (currentHeight - renderHeight) / 2.0f;

        BeginTextureMode(target);
        ClearBackground(Config::BACKGROUND_COLOR);
        Renderer::DrawBoard();
        Renderer::DrawSidebar();

        Renderer::DrawDice(BEIGE, 5, 6);

        DrawText(
            (std::to_string(Input::GetVirtualMousePosition().x) + " " + std::to_string(
                Input::GetVirtualMousePosition().y)).c_str(), 4, 4, 20, RED);
        EndTextureMode();

        BeginDrawing();
        ClearBackground(Config::BACKGROUND_COLOR);
        DrawTexturePro(target.texture,
                       {
                           0.0f, 0.0f, static_cast<float>(target.texture.width),
                           static_cast<float>(-target.texture.height)
                       },
                       {offsetX, offsetY, renderWidth, renderHeight},
                       {0, 0},
                       0.0f,
                       WHITE
        );
        EndDrawing();
    }
    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}
