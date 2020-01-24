#include <iostream>
#include "22_grid.h"

int main() {
  Grid grid;
  std::cout << grid.to_string() << std::endl;
}

// Compile just the main function using the bash / gcc command:
//    g++ --std=c++17 -c 22_main.cpp
// This will produce a new file, 22_main.o. YOU CAN'T RUN MAIN.O!

// Finally, you must link (stitch together) main with its classes.
// Use the bash / gcc command:
//    g++ --std=c++17 22_main.o 22_grid.o

// This produces the desired a.out executable, which can be run with:
//    ./a.out

// Alternately, you can compile AND link it all with one command:
//    g++ --std=c++17 22*cpp




// OR just type "make 22_main" :-)
