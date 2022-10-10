enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  # This currently has the last commit on release 1.2.1
  URL https://github.com/google/googletest/archive/15460959cbbfa20e66ef0b5ab497367e47fc0a04.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_executable(test
    game_test.cpp
)

target_link_libraries(test
    GTest::gmock
    GTest::gtest
    GTest::gtest_main
    GTest::gmock_main
    src_lib
)

gtest_discover_tests(test)
