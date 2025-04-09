#ifndef MAZE_SOLVER_CELL_H
#define MAZE_SOLVER_CELL_H

struct Cell {
    int _index{}; // index inside the 1d vector of MazeSolver
    char _value{}; // chars that represent the maze ('+', '|', '-', ' ')
    char _direction{' '}; // (N, E, S, W) direction of the queue's path through the maze
};

#endif //MAZE_SOLVER_CELL_H