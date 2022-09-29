#ifndef GAME_H
#define GAME_H

#include "board.hpp"

void print_board(board_t b, int size); 
board_t construct_board(int size); 
void main_game(int size, int iter); 

#endif
