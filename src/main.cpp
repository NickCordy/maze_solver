#include <iostream>
#include "../inc/maze_solver.h"

int main(int argc, char** argv) {
    try {
        if (argc != 3) {
            std::cerr << "Error: Incorrect usage.\nUsage: .\\solve.exe <input filepath> <output filepath>" << std::endl;
            return 1;
        }

        std::string i_filepath = argv[1];
        std::string o_filepath = argv[2];

        MazeSolver maze_solver(i_filepath, o_filepath);
        maze_solver.run();

    } catch (const std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}