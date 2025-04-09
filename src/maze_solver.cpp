#include <fstream>
#include "../inc/maze_solver.h"
#include "../inc/queue.h"

MazeSolver::MazeSolver(std::string i_filepath, std::string o_filepath) {
    _queue = new Queue();
    this->_i_filepath = std::move(i_filepath);
    this->_o_filepath = std::move(o_filepath);
}

void MazeSolver::run() {
    open_insert();

    _queue->push_back({_maze_start});

    // Loop for the queue to traverse the maze until it reaches the end.
    // When it reaches the end, the queue will be empty and peek() will return -1.
    while (_queue->peek()._index != -1) {
        navigate_adjacent_cells(_queue->peek()._index);
    }

    int index = trace_solution_path(_maze_end);

    // Loop to follow the direction set at each cell until the start is reached.
    // Changes the value of each cell on solution path to '#'.
    while (index != _maze_start) {
        index = trace_solution_path(index);
    }

    // Saves the solution to a separate file (filepath provided by user)
    save_solution();
}

int MazeSolver::open_insert() {
    try {

        int index = 0;
        Cell cell{};

        std::ifstream file { _i_filepath };

        // Open the file for reading if it exists
        if (file) {

            bool maze_width_found {false};

            char c;
            while (file.get(c)) {

                cell._index = index;
                cell._value = c;

                // Finds the width of the maze from the first newline character in the file.
                // Assumes the start of the maze is always at the top left.
                if (c == '\n' && !maze_width_found) {
                    _maze_width = index + 1;
                    _maze_start = index + 1;
                    maze_width_found = true;
                }

                _maze.push_back(cell);
                index++;
            }

            if (file.eof()) {
                _maze_end = index - 1 - _maze_width;

                // If there is trailing whitespace after the maze,
                // this ensures that _maze_end is at the correct index.
                // (because of the last '\n')
                if (_maze.at(_maze.size() - 1)._value == '\n') {
                    _maze_end = index - 2 - _maze_width;
                }
            }
        } else {
            std::cerr << "Unable to open input file '" << _i_filepath << "'." << std::endl;
        }

    } catch (const std::exception& e) {

        std::cerr << "File operation failed: " << e.what() << std::endl;
    }

    return 0;
}

void MazeSolver::navigate_adjacent_cells(int index) {
    const int EAST = index + 1;
    const int SOUTH = index + _maze_width;
    const int WEST = index - 1;
    const int NORTH = index - _maze_width;

    // Sets the starting cell's direction to east.
    // Assumes the start is always at the top left.
    if (index == _maze_start) {
        _maze[index]._direction = 'E';
    }

    // (If the cell is empty and there is no direction set)
    // Pushes that cell onto the queue and sets the direction of travel.
    if (_maze.at(EAST)._value == ' ' && _maze.at(EAST)._direction == ' ') {
        _queue->push_back({EAST});
        _maze[EAST]._direction = 'E';
    }

    if (_maze.at(SOUTH)._value == ' ' && _maze.at(SOUTH)._direction == ' ') {
        _queue->push_back({SOUTH});
        _maze[SOUTH]._direction = 'S';
    }

    if (_maze.at(WEST)._value == ' ' && _maze.at(WEST)._direction == ' ') {
        _queue->push_back({WEST});
        _maze[WEST]._direction = 'W';
    }

    if (_maze.at(NORTH)._value == ' ' && _maze.at(NORTH)._direction == ' ') {
        _queue->push_back({NORTH});
        _maze[NORTH]._direction = 'N';
    }

    _queue->pop_front();
}

int MazeSolver::trace_solution_path(int index) {
    const int EAST = index + 1;
    const int SOUTH = index + _maze_width;
    const int WEST = index - 1;
    const int NORTH = index - _maze_width;

    _maze.at(index)._value = '#';

    // Checks the direction set to the cell,
    // sets the index (to go to next) as the opposite of that direction.
    if (_maze.at(index)._direction == 'E') {
        index = WEST;
    } else if (_maze.at(index)._direction == 'S') {
        index = NORTH;
    } else if (_maze.at(index)._direction == 'W') {
        index = EAST;
    } else if (_maze.at(index)._direction == 'N') {
        index = SOUTH;
    }

    // Marks the last space, otherwise it's empty
    if (index == _maze_start) {
        _maze.at(index)._value = '#';
    }

    return index;
}

int MazeSolver::save_solution() {
    try {

        std::ofstream file{ _o_filepath };

        if (!file) {
            std::cerr << "Unable to open " << _o_filepath << "\n";
            return 1;
        }

        for (auto &&item : _maze) {
            file << item._value;
        }

    } catch (const std::exception& e) {

        std::cerr << "File operation failed: " << e.what() << std::endl;
    }

    return 0;
}