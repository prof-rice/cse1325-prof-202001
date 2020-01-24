// This is the GUARD. It ensures that a header file is included
// exactly ONCE during each compile.

#ifndef __GRID_H
#define __GRID_H

// ONLY include files you need in the header itself.
// You can include more files in the body as needed.

#include <string>

// Our type definitions and constants certainly go in the header,
// because files using our Grid class need to know what a Cell is,
// and how big the grid is.

typedef bool Cell;
const int CELL_WIDTH  = 40;
const int CELL_HEIGHT = 20;

// Include ONLY the declarations (the interface) in the header,
// NOT the definitions (how it works).
// The definitions will go in the body (.cpp file).

class Grid {
    Cell _grid[CELL_WIDTH][CELL_HEIGHT];
  public:
    Grid();
    std::string to_string();
};

#endif
