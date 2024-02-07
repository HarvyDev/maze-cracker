#ifndef CELL_H
#define CELL_H

#include <tuple>
#include <vector>

class Cell {

    public:
        int row;
        int col;
        bool visited;
        bool isWall = true;

        Cell();
        Cell(int row, int col);

        std::tuple<int, int> getPosition() const;

        void setVisited();

        bool isVisited() const;

        int getRow() const { return row; }

        int getCol() const { return col; }

        void unsetWall() { isWall = false; }

        std::vector<Cell*> getUnvisitedNeighbors(
            std::vector<std::vector<Cell>> &maze);
};

#endif
