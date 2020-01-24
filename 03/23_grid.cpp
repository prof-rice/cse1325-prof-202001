#include "23_grid.h"

Grid::Grid() {
  for(int x=0; x<CELL_WIDTH; ++x) 
    for(int y=0; y<CELL_HEIGHT; ++y) 
      _grid[x][y] = (bool)(rand()%2);
}

// The implementation for num_adjacent. Remember the Grid:: prefix!
// The std::min and std::max functions ensure we don't count past the grid edges.
// Notice that we can access _grid directly, because we are also a member of the 
//    Grid class!

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

