#include "maze.hpp"
#include <iostream>
#include <ctime>
#include <stack>
#include "cell.hpp"

Maze::Maze(int rows, int cols) : rows(rows), cols(cols), maze(rows, std::vector<Cell>(cols)) {
    initializeMaze();
}

void Maze::generateMaze() {
    std::srand(std::time(0));           // Generate random seed
    std::stack<Cell*> cellStack;        // Create a stack to hold the cells
    Cell *currentCell = &maze[0][0];    // Start at the first cell of the grid
    currentCell->visited = true;        // Mark the cell as visited

    while (true) {
        std::vector<Cell*> unvisitedNeighbors = currentCell->getUnvisitedNeighbors(maze);

        if (!unvisitedNeighbors.empty()) {
            // Chose random unvisited neighbor
            Cell* chosen = unvisitedNeighbors[std::rand() % unvisitedNeighbors.size()];
            chosen->visited = true;

            if (chosen->row == currentCell->row) {
                if (chosen->col > currentCell->col) {
                    maze[currentCell->row][currentCell->col + 1].isWall = false;
                } else {
                    maze[currentCell->row][currentCell->col - 1].isWall = false;
                }
            } else {
                if (chosen->row > currentCell->row) {
                    maze[currentCell->row + 1][currentCell->col].isWall = false;
                } else {
                    maze[currentCell->row - 1][currentCell->col].isWall = false;
                }
            }

            // Push the current cell to the stack
            cellStack.push(currentCell);
            currentCell = chosen;
        } else if (!cellStack.empty()) {
            // If there are no unvisited neighbors, go back to the previous cell
            currentCell = cellStack.top();
            cellStack.pop();
        } else {
            // If the stack is empty and there are no unvisited neighbors, the maze is complete
            break;
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
