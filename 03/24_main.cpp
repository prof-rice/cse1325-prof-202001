#include <iostream>
#include "24_grid.h"

int main() {
  // Create the initial grid. This invokes the constructor 
  //    Grid::Grid() from grid.cpp

  Grid grid;

  // Define a string to receive input from the user

  std::string s;

  // Until the user presses Control-d (or Control-z on Windows),
  //   advance to the next generation of Life on each Enter
  while(std::getline(std::cin, s)) {

      // Generate and show the next  generation of Life
      // This invokes the constructor Grid::Grid(Grid& grid) 
      //    and the method Grid::to_string() from grid.cpp

      grid = Grid{grid};
      std::cout << grid.to_string() << std::endl;
  }
}

// Compile using:
//    g++ --std=c++17 24*cpp
// or:
//    make 24_main

