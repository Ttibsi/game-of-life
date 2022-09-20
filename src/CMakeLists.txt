include_directories(${game-of-life_SOURCE_DIR}/src)
add_executable (gol
    main.cpp
    game.cpp
)
add_library( src_lib
    game.cpp
)

target_include_directories(src_lib PUBLIC .)
