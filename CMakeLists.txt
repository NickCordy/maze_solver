cmake_minimum_required(VERSION 3.17)
project(maze_solver)

set(CMAKE_CXX_STANDARD 14)

add_executable(maze_solver
        src/main.cpp
        src/maze_solver.cpp
        src/queue.cpp
)
