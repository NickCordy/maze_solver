# Maze Solver

A C++ program that solves mazes using a **breadth-first search (BFS)** algorithm. The program reads a maze from a text file, navigates through it using a **queue-based approach**, and outputs the solution to another file.

## Features

- **Maze Input**: Reads maze structures from text files.
- **Breadth-First Search**: Uses a queue to explore paths in the maze.
- **Solution Output**: Outputs the solved maze with the path marked.

## How It Works

1. **Input**: The maze is represented as a grid in a text file, where:
   - `+` represents walls.
   - Spaces represent paths.
   - The start is at the top-left corner.
   - The end is at the bottom-right corner.

2. **Algorithm**:
   - The program uses a queue to keep track of the cells to explore.
   - It explores all possible paths level by level (BFS) until it reaches the end of the maze.
   - Each cell stores the direction from which it was reached (N, E, S, W).
   - Once the end is reached, the program traces back the solution path using the stored directions.

3. **Output**: The solved maze is saved to a file with the solution path marked as `#`.

## Getting Started

### Prerequisites

- C++ compiler (e.g., GCC, Clang, or MSVC)
- CMake (minimum version 3.17)

### Building the Project

1. Clone the repository:

   ```bash
   git clone <repository-url>
   cd maze-solver
   ```

2. Configure the project using CMake:

   ```bash
   cmake -S . -B build
   ```

3. Build the project:

   ```bash
   cmake --build build
   ```

4. Example of running the program

   ```bash
   ./build/maze_solver.exe ../tests/maze.txt ../solved/solution.txt
   ```

   - Replace `../tests/maze.txt` with the path to your input maze file.
   - Replace `../solved/solution.txt` with the desired path for the output file.