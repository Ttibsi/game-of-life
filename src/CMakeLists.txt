include_directories(${game-of-life_SOURCE_DIR}/src)
add_executable (gol
    main.cpp
    foo.cpp
)
add_library( src_lib
    foo.cpp
)

target_include_directories(src_lib PUBLIC .)
