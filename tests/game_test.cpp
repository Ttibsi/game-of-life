#include <utility>

#include "../src/game.cpp"
#include "gtest/gtest.h"

std::pair<int, int> main_game(int size, int iter); 

TEST(game, return_size_iter) { 
    std::pair<int, int> test_value = {5, 12};
    EXPECT_EQ(main_game(5, 12), test_value);
}
