include_directories(${game-of-life_SOURCE_DIR}/src)
add_executable (gol
    main.cpp
    game.cpp
    game.hpp
    board.hpp
)
add_library( src_lib
    game.cpp
    game.hpp
    board.hpp
)

target_link_libraries(gol tinfo)

target_include_directories(src_lib PUBLIC .)
