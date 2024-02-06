#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include "include/cell.hpp"

class Maze {
    public:
        Maze(int rows, int cols, bool isWall);

        void generateMaze();
        void printMaze();
        void unsetWall();

    private:
        int rows;
        int cols;
        bool isWall;

        std::vector<std::vector<Cell>> maze;

        void initializeMaze();
};
#endif
