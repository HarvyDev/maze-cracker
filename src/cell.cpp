#include <iostream>
#include "cell.hpp"
#include <algorithm>
#include <random>

Cell::Cell() : row(0), col(0), visited(false), walls({true, true, true, true}) {}

Cell::Cell(int row, int col) : row(row), col(col), visited(false), walls({ true, true, true, true }) {}

std::tuple<int, int> Cell::getPosition() const {
    return std::make_tuple(row, col);
}

Cell* Cell::getRandomUnvisitedNeighbors(std::vector<std::vector<Cell>> &maze) {
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

    // In case there are no more unvisited neighbors
    if (neighbours.empty()) {
        return nullptr;
    }

    // Get a random neighbor
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(neighbours.begin(), neighbours.end(), g);

    return neighbours[0];
}

void Cell::removeWalls(Cell &next, std::vector<std::vector<Cell>> &maze) {
    int x = col - next.col;

    // Next cell is to the right
    if (x == -1) {
        walls[1] = false;       // Remove right wall
        next.walls[0] = false;  // Remove left wall from next cell
    }

    // Next cell is to the left
    else if (x == 1) {
        walls[0] = false;       // Remove left wall
        next.walls[1] = false;  // Remove right wall from next cell
    }

    int y = row - next.row;

    // Next cell is below
    if (y == -1) {
        walls[3] = false;       // Remove bottom wall
        next.walls[2] = false;  // Remove top wall from next cell
    }

    // Next cell is above
    else if (y == 1) {
        walls[2] = false;       // Remove top wall
        next.walls[3] = false;  // Remove bottom wall from next cell
    }
}
