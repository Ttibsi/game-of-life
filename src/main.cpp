#include <iostream>
#include <string>

#include "../include/argparse/argparse.hpp"
#include "game.hpp"

std::string version = "v0.1.0";

int main(int argc, char *argv[]) {
    argparse::ArgumentParser program("game-of-life", version);

    program.add_argument("-s", "--size")
        .default_value(12)
        .scan<'i', int>()
        .help("Size of the board to calculate");
    program.add_argument("-i", "--iteration")
        .default_value(0)
        .scan<'i', int>()
        .help("Iteration of the board state to output");

    program.parse_args(argc, argv);
    int size = program.get<int>("--size");
    int iter = program.get<int>("--iteration");

    std::cout << main_game(size, iter);
}
