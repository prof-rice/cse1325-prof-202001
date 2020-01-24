#ifndef __GRID_H
#define __GRID_H

#include <string>

typedef bool Cell;
const int CELL_WIDTH  = 40;
const int CELL_HEIGHT = 20;

class Grid {
    Cell _grid[CELL_WIDTH][CELL_HEIGHT];
  public:
    Grid();

    // Calculate the number of adjacent living cells
    // to the cell at (x,y) in this grid
    int num_adjacent(int x, int y);

    std::string to_string();
};

#endif
