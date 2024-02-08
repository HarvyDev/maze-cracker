# Maze Generator and Solver

This is a simple maze generator and solver using C++.

## Table of Contents
- [Maze Generator and Solver](#maze-generator-and-solver)
  - [Table of Contents](#table-of-contents)
  - [Building the project](#building-the-project)
  - [Running the project](#running-the-project)
  - [Structure of the maze](#structure-of-the-maze)
  - [Generating the maze](#generating-the-maze)
    - [Depth First Search Algorithm](#depth-first-search-algorithm)

## Building the project

To build the project, run the following commands in the root directory of the project, after cloning the repository:

``` bash
mkdir build
cd build
cmake ..
make
```
## Running the project

In order to run the project, run the following command in the build directory, after building the project:

``` bash
./maze
```

It will then print out a maze of the size defined in main.cpp. The maze is printed to the console, with the following characters representing the different parts of the maze:

| Character | Description       |
|-----------|-------------------|
| ` `       | Empty cell        |
| `\|`      | Wall              |
| `---`     | Ceiling and floor |
| `+`       | Intersection      |

## Structure of the maze

The maze is represented as a 2D array of cells. Each cell has four walls: top, right, bottom, and left. The walls are represented by an array of booleans. If a wall is present, the value is true, otherwise it is false.

## Generating the maze

### Depth First Search Algorithm
The maze is generated using the recursive backtracking algorithm. The algorithm is a randomized version of the depth-first search algorithm. The algorithm starts at a random cell and chooses a random neighbouring cell that has not been visited. If the algorithm reaches a dead end, it backtracks to the last cell that has unvisited neighbours. The algorithm continues until all cells have been visited.
