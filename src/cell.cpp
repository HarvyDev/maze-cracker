#include <iostream>
#include "cell.hpp"

Cell::Cell() : row(0), col(0), visited(false) {}

Cell::Cell(int row, int col) : row(row), col(col), visited(false) {}

std::tuple<int, int> Cell::getPosition() const {
    return std::make_tuple(row, col);
}

std::vector<Cell*> Cell::getUnvisitedNeighbors(std::vector<std::vector<Cell>> &maze) {
    std::vector<Cell*> neighbours;

    // Right neighbor
    if (col >= 0 && col + 1 < maze[0].size() && !maze[row][col + 1].visited) {
        neighbours.push_back(&maze[row][col + 1]);
    }
    // Left neighbor
    if (col > 0 && col < maze[0].size() && !maze[row][col - 1].visited) {
        neighbours.push_back(&maze[row][col - 1]);
    }
    // Upper neighbor
    if (row > 0 && row < maze.size() && !maze[row - 1][col].visited) {
        neighbours.push_back(&maze[row - 1][col]);
    }
    // Lower neighbor
    if (row >= 0 && row + 1 < maze.size() && !maze[row + 1][col].visited) {
        neighbours.push_back(&maze[row + 1][col]);
    }
    return neighbours;
}

bool hasUnvisitedCells(std::vector<std::vector<Cell>> &maze) {
    for (int r = 0; r < maze.size(); r++) {
        for (int c = 0; c < maze[0].size(); c++) {
            if (!maze[r][c].visited) {
                return true;
            }
        }
    }
    return false;
}
