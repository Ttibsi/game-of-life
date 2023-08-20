include_directories(${game-of-life_SOURCE_DIR}/src)
include_directories(${game-of-life_SOURCE_DIR}/include)
add_library( src_lib
    game.cpp
    game.hpp
    board.hpp
)

add_executable (gol
    main.cpp
)


target_link_libraries(gol tinfo src_lib)

target_include_directories(src_lib PUBLIC .)
