#include "board.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

board_t construct_board(int size);
void print_board(board_t b, int size);
board_t populate_board(board_t b);

int check_neighbors(board_t board, Point cell) {
    int living_neighbors = 0;

    // clang-format off
    std::vector<std::pair<int, int>> relative_cords = {
        std::make_pair(-1, -1),
        std::make_pair(-1, 0),
        std::make_pair(-1, 1),
        std::make_pair(0, -1),
        std::make_pair(0, +1),
        std::make_pair(+1, -1),
        std::make_pair(+1, 0),
        std::make_pair(+1, +1),
    };
    // clang-format on

    for (std::pair<int, int> i : relative_cords) {
        int x_val = i.first + cell.x_cord;
        int y_val = i.second + cell.y_cord;

        Point temp = {x_val, y_val, false};

        auto found = std::find_if(board.begin(), board.end(),
                                  [&](auto const &e) { return e == temp; });

        if (found != board.end()) {
            if (found->live == true) {
                living_neighbors++;
            }
        }
    }

    return living_neighbors;
}

board_t increment_board_state(board_t board) {
    board_t new_board = construct_board(std::sqrt(board.size()));

    for (long unsigned int i = 0; i < board.size(); i++) {
        int live_adj = check_neighbors(board, board[i]);
        // std::cout << std::boolalpha;
        // std::cout << "{ (" << board[i].x_cord << ", " << board[i].y_cord <<
        // ") " << board[i].live << " " << live_adj << "}\n";

        if (board[i].live == true) {
            // Any live cell with two or three live neighbours survives
            // All other live in_state[i]s die in the next generation.
            // Similarly, all other dead in_state[i]s stay dead.
            if (!(live_adj == 2 || live_adj == 3)) {
                new_board[i].live = false;
            } else {
                new_board[i].live = true;
            }
        } else {
            // Any dead cell with three live neighbours becomes a live cell
            if (live_adj == 3) {
                new_board[i].live = true;
            } else {
                new_board[i].live = false;
            }
        }
    }

    return new_board;
}

board_t populate_board(board_t b, std::vector<int> places_to_fill) {
    for (int i : places_to_fill) {
        b[i].live = true;
    }
    return b;
}

void print_board(board_t b, int size) {
    for (auto &pair : b) {
        if (pair.live == true) {
            std::cout << " # ";
        } else {
            std::cout << " . ";
        }

        if (pair.y_cord == (size - 1)) {
            std::cout << '\n';
        }
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
    board_t my_Board =
        populate_board(construct_board(size), {2, 8, 11, 12, 13}); // len 5

    // board_t my_Board = populate_board(
    //         construct_board(size),
    //         {2, 15, 25, 26, 27}
    //     ); // len 12

    print_board(my_Board, size);

    for (int i = 0; i < iter; i++) {
        std::cout << "iter = " << iter << "\n";
        my_Board = increment_board_state(my_Board);
        print_board(my_Board, size);
    }
}
