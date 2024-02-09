#ifndef CELL_H
#define CELL_H

#include <tuple>
#include <vector>

class Cell {
public:
    int row;
    int col;
    bool visited;
    std::vector<bool> walls;

    Cell();
    Cell(int row, int col);

    std::tuple<int, int> getPosition() const;

    int getRow() const { return row; }

    int getCol() const { return col; }

    Cell * getRandomUnvisitedNeighbors(
        std::vector<std::vector<Cell>> &maze);

    void removeWalls(Cell &next, std::vector<std::vector<Cell>> &maze);
};

bool hasUnvisitedCells(std::vector<std::vector<Cell>> &maze);

#endif
