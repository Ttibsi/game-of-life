# https://stackoverflow.com/a/8304850

cmake_minimum_required(VERSION 3.10.0)
project(game-of-life CXX)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-Wall)
add_definitions(-Wextra)

add_subdirectory(src)

