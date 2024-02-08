#include "maze.hpp"
#include <iostream>
#include <ctime>
#include <stack>
#include <algorithm>
#include <random>
#include "cell.hpp"

Maze::Maze(int rows, int cols) : rows(rows), cols(cols), maze(rows, std::vector<Cell>(cols)) {
    initializeMaze();
}

void Maze::generateMaze() {
    Cell *initial = &maze[0][0];                // Starting cell
    Cell *final = &maze[rows - 1][cols - 1];    // Ending cell
    final->walls[3] = false;
    initial->walls[2] = false;
    dfsMazeGenerator(*initial);
}

void Maze::dfsMazeGenerator(Cell &current) {
    current.visited = true;
    Cell *next;
    while (next) {
        next = current.getRandomUnvisitedNeighbors(maze);
        if (next) {
            current.removeWalls(*next, maze);
            dfsMazeGenerator(*next);
        }
        else
            break;
    }
}

void Maze::printMaze() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            std::cout << "+";
            if (maze[r][c].walls[2]) {
                std::cout << "---";
            } else {
                std::cout << "   ";
            }
        }
        std::cout << "+" << std::endl;

        for (int c = 0; c < cols; c++) {
            if (maze[r][c].walls[0]) {
                std::cout << "|   ";
            } else {
                std::cout << "    ";
            }
        }
        if (maze[r][cols - 1].walls[1]) {
            std::cout << "|";
        }
        std::cout << std::endl;
    }

    for (int c = 0; c < cols; c++) {
        std::cout << "+";
        if (maze[rows - 1][c].walls[3]) {
            std::cout << "---";
        } else {
            std::cout << "   ";
        }
    }
    std::cout << "+" << std::endl;
}

void Maze::initializeMaze() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            maze[r][c] = Cell(r, c);
        }
    }
}
