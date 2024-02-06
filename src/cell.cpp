#include <iostream>
#include "include/cell.hpp"

Cell::Cell(int row, int col) : row(row), col(col), visited(false) {}

std::tuple<int, int> Cell::getPosition() const {
    return std::make_tuple(row, col);
}

std::vector<Cell> Cell::getUnvisitedNeighbors(std::vector<std::vector<Cell>> &maze) {
    std::vector<Cell> neighbors;
    if (row > 0 && !maze[row - 1][col].visited) {
        neighbors.push_back(maze[row - 1][col]);
    }
    if (col > 0 && !maze[row][col - 1].visited) {
        neighbors.push_back(maze[row][col - 1]);
    }
    if (row < maze.size() - 1 && !maze[row + 1][col].visited) {
        neighbors.push_back(maze[row + 1][col]);
    }
    if (col < maze[0].size() - 1 && !maze[row][col + 1].visited) {
        neighbors.push_back(maze[row][col + 1]);
    }
    return neighbors;
}

void Cell::setVisited() {
    visited = true;
}
