#include <iostream>
#include <vector>

#include "../src/game.cpp"
#include "../src/board.hpp"
#include "gtest/gtest.h"

int check_neighbors(board_t board, Point cell); 
board_t increment_board_state(board_t board); 
board_t populate_board(board_t b); 
board_t construct_board(int size); 

TEST(gameDisplay, populateBoard) { 
    board_t b = populate_board(construct_board(3));
    EXPECT_EQ(b[2].toggle, true);
    EXPECT_EQ(b[6].toggle, true);
    EXPECT_EQ(b[5].toggle, false);
}

TEST(gameDisplay, constructBoard) { 
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

TEST(gameLogic, checkNeighbors) {
    board_t test_board = construct_board(3);

    test_board[4].toggle = true;
    test_board[0].toggle = true;
    EXPECT_EQ(check_neighbors(test_board, test_board[4]), 1);
    test_board[3].toggle = true;
    test_board[1].toggle = true;
    EXPECT_EQ(check_neighbors(test_board, test_board[4]), 3);
}

TEST(gameLogic, incrementBoard) {
    board_t b = construct_board(3);
    b[2].toggle = true;
    b[4].toggle = true;
    b[8].toggle = true;
    board_t c = increment_board_state(b);
    EXPECT_EQ(c[0].toggle, false);
    EXPECT_EQ(c[1].toggle, false);
    EXPECT_EQ(c[2].toggle, false);
    EXPECT_EQ(c[3].toggle, false);
    EXPECT_EQ(c[4].toggle, true);
    EXPECT_EQ(c[5].toggle, true);
    EXPECT_EQ(c[6].toggle, false);
    EXPECT_EQ(c[7].toggle, false);
    EXPECT_EQ(c[8].toggle, false);
}
