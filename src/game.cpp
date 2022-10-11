#include "board.hpp"

#include <iostream>

void print_board(board_t b, int size); 

int check_neighbors(board_t board, Point cell) {
    int living_neighbors = 0;

    // 8 neighbors
    // TODO: Could this logic be handled better? Switch case seems wrong here
    for (Point i : board) {
        if (i == cell) { continue; }

        if (i.x_cord == cell.x_cord - 1 &&
            i.y_cord == cell.y_cord - 1 && 
            i.toggle == true) {
            living_neighbors++;
        }

        if (i.x_cord == cell.x_cord &&
            i.y_cord == cell.y_cord - 1 && 
            i.toggle == true) {
            living_neighbors++;
        }

        if (i.x_cord == cell.x_cord + 1 &&
            i.y_cord == cell.y_cord - 1 &&
            i.toggle == true ) {
            living_neighbors++;
        }

        if (i.x_cord == cell.x_cord - 1 &&
            i.y_cord == cell.y_cord &&
            i.toggle == true) {
            living_neighbors++;
        }

        if (i.x_cord == cell.x_cord + 1 &&
            i.y_cord == cell.y_cord &&
            i.toggle == true) {
            living_neighbors++;
        }

        if (i.x_cord == cell.x_cord + 1 &&
            i.y_cord == cell.y_cord - 1 &&
            i.toggle == true) {
            living_neighbors++;
        }

        if (i.x_cord == cell.x_cord + 1 &&
            i.y_cord == cell.y_cord &&
            i.toggle == true) {
            living_neighbors++;
        }

        if (i.x_cord == cell.x_cord + 1 &&
            i.y_cord == cell.y_cord + 1 &&
            i.toggle == true) {
            living_neighbors++;
        }
    }

    return living_neighbors;
}

board_t increment_board_state(board_t board) {
    for (Point &cell : board) {
        int live_adj = check_neighbors(board, cell);

        if (cell.toggle == true) {
            // Any live cell with two or three live neighbours survives
            // All other live cells die in the next generation. 
            // Similarly, all other dead cells stay dead.
            if (!(live_adj == 2 || live_adj == 3)) {
                cell.toggle = false;
            } else { cell.toggle = true; }
        } else if (cell.toggle == false) {
            //Any dead cell with three live neighbours becomes a live cell
            if (live_adj == 3) { cell.toggle = true; }
        }
    }

    return board;
}

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
