#include <iostream>
#include "23_grid.h"

int main() {
  Grid grid;
  std::cout << grid.to_string() << std::endl;
}

// Compile using:
//    g++ --std=c++17 23*cpp
// or:
//    make 23_main

// This doesn't actually change the program's behavior.
// How do we TEST num_adjacent?
