#include <iostream>

typedef bool Cell;
const int CELL_WIDTH  = 40;
const int CELL_HEIGHT = 20;

class Grid {
  // PRIVATE MEMBERS: Unlike a struct, class memberss are PRIVATE by default.
  //    Thus, _grid CANNOT be accessed outside of our class methods
    Cell _grid[CELL_WIDTH][CELL_HEIGHT];

  // PUBLIC MEMBERS: We now declare the remaining members to be PUBLIC, like a struct
  //    Usually, data is private and our methods, constructors, and destructor public
  public:
    // CONSTRUCTOR: Runs automatically when variable of type Grid is defined
    Grid() {
      for(int x=0; x<CELL_WIDTH; ++x) 
        for(int y=0; y<CELL_HEIGHT; ++y) 
          _grid[x][y] = (bool)(rand()%2);
    }

    // METHOD: Returns a string representation of the grid
    std::string to_string() {
        std::string result;
        for (int y=0; y < CELL_HEIGHT; ++y) {
            for(int x=0; x < CELL_WIDTH; ++x) {
                result += (_grid[x][y]) ? 'X' : '.';
            }
            result += '\n';
        }
        return result;
    }
};

// ///////////////////////////////////////////////////////////////////////////////////////
//  MAIN:  A bit simpler, no? In object-oriented programs, main is usually rather trivial
int main() {
  Grid grid;
  std::cout << grid.to_string() << std::endl;
}
