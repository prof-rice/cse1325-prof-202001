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

    // To implement grid generations, we _could_ modify the current grid.
    // But a better approach is to construct a NEW generation grid while
    //    referencing the PREVIOUS generation grid.
    // Sounds like we need another (overloaded) constructor!
    Grid(Grid& grid);

    int num_adjacent(int x, int y);

    std::string to_string();
};

#endif
