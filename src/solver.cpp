#include "solver.hpp"
#include <stack>

std::vector<std::pair<int,int>> Solver::solveMazeDFS(std::vector<Cell> &maze) {
    std::vector<std::pair<int,int>> sol;
    return auxDFS(maze[0][0], sol);
}

std::vector<std::pair<int,int>> Solver::auxDFS(Cell &current, std::vector<std::pair<int,int>> sol) {
    current.visited = true;
    Cell *next;

    while (next) {
        next = getRandomUnvisitedNeighbors(maze);
        if(next) {
            if (noWall(current, next)) {
                sol.push({next->row, next->col});
                auxDFS(*next);
            } 
        }

    }
}
