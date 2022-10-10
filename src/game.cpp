#include "board.hpp"

#include <iostream>

board_t populate_board(board_t b) {
    int places_to_fill[5] = {2, 4, 6, 8};
    for (int i : places_to_fill) { b[i].toggle = true; }
    return b;
}

void print_board(board_t b, int size) {
    for (auto &pair : b) {
        if (pair.toggle == true) {
            std::cout << " # ";
        } else {
            std::cout << " . ";
        }

        if (pair.y_cord == (size - 1)) { std::cout << '\n'; }
    }
}

board_t construct_board(int size) {
    board_t board;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Point elem = {i, j, false};
            board.push_back(elem);
        }
    }

    return board;
}

void main_game(int size, int iter) {
    // board_t my_Board = construct_board(size);
    board_t my_Board = populate_board(construct_board(size));
    print_board(my_Board, size);
}
