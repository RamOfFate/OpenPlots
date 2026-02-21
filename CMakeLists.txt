cmake_minimum_required(VERSION 4.1)
project(OpenPlots)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

find_package(raylib REQUIRED)

add_executable(OpenPlots main.cpp
        include/constants.h
        include/board.h
        include/renderer.h
        src/board.cpp
        src/renderer.cpp
        include/ui.h
        src/ui.cpp
        src/game.cpp
        include/game.h
        include/player.h
        include/input.h
        src/input.cpp
        include/space.h
        include/board_loader.h
        src/board_loader.cpp
)

target_link_libraries(OpenPlots raylib m dl pthread)