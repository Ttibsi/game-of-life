#include <fstream>
#include <iostream>
#include <string>
#include <utility>

#include "../include/argparse/argparse.hpp"
#include "../include/nlohmann/json.hpp"
#include "game.hpp"

using json = nlohmann::json;

std::string version = "v0.1.0";

int main(int argc, char *argv[]) {
    argparse::ArgumentParser program("game-of-life", version);

    program.add_argument("-s", "--size")
        .default_value(12)
        .scan<'i', int>()
        .help("Size of the board to calculate");
    program.add_argument("-i", "--iteration")
        .default_value(1)
        .scan<'i', int>()
        .help("Iteration of the board state to output");
    program.add_argument("-j", "--json")
        .default_value("")
        // .scan<'i', std::string>()
        .help("Pass in a JSON config file");

    program.parse_args(argc, argv);
    std::ifstream jsonstream(program.get<std::string>("--json").c_str());
    json config = json::parse(jsonstream);
    std::cout << "json size: " << config.size() << "\n";

    // if (config.size() == 0 ) {
    //     int size = program.get<int>("--size");
    //     int iter = program.get<int>("--iteration");
    // } else {
    //     int size = config[size];
    //     int iter = config[iter];
    // }
    //
    // main_game(size, iter, config);
}
