#include <iostream>
#include "maze.hpp"

int main() {
    Maze maze(25, 25);
    // maze.generateMaze();
    // maze.printMaze();
    std::cout << " " << maze.maze[0][0].getUnvisitedNeighbors(maze.maze).size() << std::endl;
    return 0;
}
