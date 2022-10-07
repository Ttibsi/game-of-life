# https://stackoverflow.com/a/8304850

cmake_minimum_required(VERSION 3.14.0)
project(game-of-life CXX)
OPTION(RUN_TESTS "Run unit tests" OFF)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall)
add_compile_options(-Wextra)

add_subdirectory(src)

if(RUN_TESTS)
    execute_process(COMMAND bash -c "echo UNIT TESTS ENABLED" )
    add_subdirectory(tests)
endif()
