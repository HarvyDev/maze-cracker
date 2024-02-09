#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "cell.hpp"

class Maze {
public:
    int rows;
    int cols;
    std::vector<std::vector<Cell>> maze;

    Maze(int rows, int cols);

    void generateMaze();
    void printMaze();
    void unsetWall();

private:
    void initializeMaze();
    void dfsMazeGenerator(Cell &cell);
};

#endif
