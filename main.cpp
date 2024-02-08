#include <iostream>
#include "maze.hpp"

int main() {
    Maze maze(10,10);
    maze.generateMaze();
    maze.printMaze();
    return 0;
}
