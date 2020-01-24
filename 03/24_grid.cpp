#include "24_grid.h"

Grid::Grid() {
  for(int x=0; x<CELL_WIDTH; ++x) 
    for(int y=0; y<CELL_HEIGHT; ++y) 
      _grid[x][y] = (bool)(rand()%2);
}

// The rules for Conway's Life are:
//   1. A grid cell remains alive if surrounded by 2 or 3 living cells
//   2. A grid cell is born if surround by 3 living cells
// Note that the array "grid" is previous generation pass as a parameter, 
//   and "_grid" is the new generation that we're constructing from it.
// You can play with the rules by modifying this constructor if you like!

Grid::Grid(Grid& grid) {
    for(int x=0; x < CELL_WIDTH; ++x) {
        for(int y=0; y < CELL_HEIGHT; ++y) {
            bool adjacent_2 = (grid.num_adjacent(x,y) == 2);
            bool adjacent_3 = (grid.num_adjacent(x,y) == 3);

            // _grid is private - but only to non-Grid classes!
            if(grid._grid[x][y])
                _grid[x][y] = (adjacent_2 || adjacent_3);
            else
                _grid[x][y] = adjacent_3;
        }
    }
}

int Grid::num_adjacent(int x, int y) {
    int result = 0;
    for(int xx=std::max(x-1,0); xx <= std::min(x+1,CELL_WIDTH-1); ++xx) {
        for(int yy=std::max(y-1,0); yy <= std::min(y+1, CELL_HEIGHT-1); ++yy) {
	    if (!(x==xx && y==yy) && _grid[xx][yy]) ++result;
        }
    }
    return result;
}

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

