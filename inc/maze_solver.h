#ifndef MAZE_SOLVER_MAZE_SOLVER_H
#define MAZE_SOLVER_MAZE_SOLVER_H

#include <vector>
#include "queue.h"
#include "cell.h"

class MazeSolver {
    std::string _i_filepath{};
    std::string _o_filepath{};
    Queue* _queue;
    std::vector<Cell> _maze;
    int _maze_width{};
    int _maze_start{};
    int _maze_end{};

public:
    explicit MazeSolver(std::string i_filepath, std::string o_filepath);

    void run();

    // Attempts to open the input file specified by the user.
    // Inserts the files contents into a 1d vector of maze 'Cells' with an index and value for each char.
    int open_insert();

    // Checks for empty neighbouring cells and pushes each to the queue.
    // Sets the direction of travel for each cell traversed (N, E, S, W).
    // Pops the front node off the queue.
    void navigate_adjacent_cells(int index);

    // Sets the cell value of an index to '#', indicating it is on the solution path.
    // Returns the next cell on the solution path based on the cells direction variable.
    int trace_solution_path(int index);

    // Saves the contents of the _maze vector to the output file specified by the user.
    int save_solution();
};

#endif //MAZE_SOLVER_MAZE_SOLVER_H