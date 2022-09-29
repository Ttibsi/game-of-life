#include <vector>

#include "../src/game.cpp"
#include "../src/board.hpp"
#include "gtest/gtest.h"

board_t construct_board(int size); 
TEST(game, constructBoard) { 
    board_t b = construct_board(3);
    board_t test_val;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Point k = {i, j, false};
            test_val.push_back(k);
        }
    }

    EXPECT_EQ(b, test_val);
}
