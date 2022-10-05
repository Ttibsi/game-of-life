#ifndef GAME_H
#define GAME_H

#include "board.hpp"

int check_neighbors(board_t board, Point cell); 
board_t increment_board_state(board_t board); 
board_t populate_board(board_t b); 
void print_board(board_t b, int size); 
board_t construct_board(int size); 
void main_game(int size, int iter); 

#endif
