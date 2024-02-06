#include "include/maze.hpp"
#include <iostream>
#include "include/cell.hpp"

Maze::Maze(int rows, int cols, bool isWall) : rows(rows), cols(cols), isWall(isWall) {
    initializeMaze();
}

void Maze::generateMaze() {

}

void Maze::printMaze() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (maze[r][c].isWall()) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }
    }
}

void Maze::unsetWall() {
    isWall = false;
}

void Maze::initializeMaze() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            maze[r][c] = Cell(r, c);
        }
    }
}
