#include <iostream>
#include <vector>

#include "../src/board.hpp"
#include "../src/game.cpp"
#include "gtest/gtest.h"

int check_neighbors(board_t board, Point cell);
board_t increment_board_state(board_t board);
board_t populate_board(board_t b);
board_t construct_board(int size);
void print_board(board_t b, int size);

TEST(gameDisplay, populateBoard) {
    board_t b = populate_board(construct_board(3));
    EXPECT_EQ(b[2].live, true);
    EXPECT_EQ(b[6].live, true);
    EXPECT_EQ(b[5].live, false);
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

    test_board[4].live = true;
    test_board[0].live = true;
    EXPECT_EQ(check_neighbors(test_board, test_board[4]), 1);
    test_board[1].live = true;
    test_board[3].live = true;
    EXPECT_EQ(check_neighbors(test_board, test_board[4]), 3);
}

TEST(gameLogic, incrementBoard) {
    board_t b = construct_board(3);
    b[2].live = true;
    b[4].live = true;
    b[8].live = true;
    print_board(b, 3);
    board_t c = increment_board_state(b);
    print_board(b, 3);

    EXPECT_EQ(c[0].live, false);
    EXPECT_EQ(c[1].live, false);
    EXPECT_EQ(c[2].live, false);
    EXPECT_EQ(c[3].live, false);
    EXPECT_EQ(c[4].live, true);
    EXPECT_EQ(c[5].live, true);
    EXPECT_EQ(c[6].live, false);
    EXPECT_EQ(c[7].live, false);
    EXPECT_EQ(c[8].live, false);
}
