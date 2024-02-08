#include "maze.hpp"
#include <iostream>
#include <ctime>
#include <stack>
#include "cell.hpp"

Maze::Maze(int rows, int cols) : rows(rows), cols(cols), maze(rows, std::vector<Cell>(cols)) {
    initializeMaze();
}

void Maze::generateMaze() {
    maze[0][0].unsetWall();         // Unset the wall of the starting cell
    dfsMazeGenerator(maze[0][0]);   // Call DFS with the starting cell
}

void Maze::dfsMazeGenerator(Cell &cell) {
    // Set the current cell as visited
    cell.visited = true;

    if (!hasUnvisitedCells(maze)) {
        return; // Maze is complete
    }

    std::vector<Cell*> neighbours = cell.getUnvisitedNeighbors(maze);

    for (Cell* neighbor : neighbours) {
        if (!neighbor->visited) {
            neighbor->unsetWall();
            dfsMazeGenerator(*neighbor);
        }
    }
}

void Maze::printMaze() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (maze[r][c].isWall) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Maze::initializeMaze() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            maze[r][c] = Cell(r, c);
        }
    }
}
