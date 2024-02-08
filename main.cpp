#include <iostream>
#include "maze.hpp"

int main() {
    Maze maze(25,25);
    maze.generateMaze();
    maze.printMaze();
    return 0;
}
