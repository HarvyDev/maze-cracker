#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <tuple>
#include <vector>

class Cell {

    public:
        Cell(int row, int col);

        std::tuple<int, int> getPosition() const;
        void setVisited();

        std::vector<Cell> getUnvisitedNeighbors(
            std::vector<std::vector<Cell>> &maze);

    private:
        int row;
        int col;
        bool visited;

};

#endif
