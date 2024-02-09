#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include "cell.hpp"

class Solver {
public:
    std::vector<std::pair<int, int>> solveMazeDFS(std::vector<Cell> &maze);
    std::vector<std::pair<int,int>> auxDFS(Cell &current, std::vector<std::pair<int,int>> &sol);
};

#endif
