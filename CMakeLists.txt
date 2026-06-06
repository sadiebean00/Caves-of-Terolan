cmake_minimum_required(VERSION 3.20)

project(adventure)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(adventure
    src/game.cpp
    src/inventory.cpp
    src/main.cpp
    src/player.cpp
)