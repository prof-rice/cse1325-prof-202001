#ifndef __GRID_H
#define __GRID_H

#include <string>

typedef bool Cell;
const int CELL_WIDTH  = 80;
const int CELL_HEIGHT = 40;

class Grid {
    Cell _grid[CELL_WIDTH][CELL_HEIGHT];
  public:
    Grid();
    Grid(Grid& grid);

    int num_adjacent(int x, int y);

    std::string to_string();
};

#endif
