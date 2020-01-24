// ALWAYS include the header file in the associated body
// Include other files as needed.

#include "22_grid.h"

// Implementations are stand-alone (no "class" in a body).
// Use the scope resolution operator (or membership operator) ::
//   to specify the class to which this constructor belongs.

Grid::Grid() {
  for(int x=0; x<CELL_WIDTH; ++x) 
    for(int y=0; y<CELL_HEIGHT; ++y) 
      _grid[x][y] = (bool)(rand()%2);
}

// Each method is also defined. If you miss one that is used anywhere,
//   the linker will give you an "undefined reference" error.
// If you forget the Grid:: prefix to a member, you'll probably get
//   a "cannot access private variable" error - your definition will
//   be treated as a stand-alone function rather than as a method.

std::string Grid::to_string() {
    std::string result;
    for (int y=0; y < CELL_HEIGHT; ++y) {
        for(int x=0; x < CELL_WIDTH; ++x) {
            result += (_grid[x][y]) ? 'X' : '.';
        }
        result += '\n';
    }
    return result;
}

// Compile just the Grid class using the bash / gcc command:
//    g++ --std=c++17 -c 22_grid.cpp
// This will produce a new file, 22_grid.o. YOU CAN'T RUN GRID.O!
// Check 22_main.cpp for the next compilation step...
//    and a trivial shortcut!

