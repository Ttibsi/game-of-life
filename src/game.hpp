#ifndef GAME_H
#define GAME_H

#include "../include/nlohmann/json.hpp"
#include "board.hpp"
using json = nlohmann::json;

int check_neighbors(board_t board, Point cell);
board_t increment_board_state(board_t board);
board_t populate_board(board_t b);
void print_board(board_t b, int size);
board_t construct_board(int size);
void main_game(int size, int iter, json config);

#endif
