#include <iostream>
#include <ctime>
#include "25_grid.h"

int main() {
  srand (time(NULL));

  Grid grid;
  std::string s;
  int generation = 0;

  do {
      grid = Grid{grid};
      std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
          << "Generation " << ++generation
          << " Enter for next gen, ^d to exit\n\n"
          << grid.to_string() << std::endl;
  } while(std::getline(std::cin, s));
}

// CHALLENGE: Modify main to allow you to "back up" and see previous generations.
//   (HINT: Consider pushing each Grid object onto a std::vector<Grid> container.
//          You can "back up" using e.g., v[desired_generation].to_string().)


// Compile using:
//    g++ --std=c++17 25*cpp
// or:
//    make 25_main

