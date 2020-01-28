// This main program can be used to test your class.
// **You must COMPLETE both color.h and color.cpp before compiling this!**
// Then, the provided Makefile will build it for you if you type 'make test'.

#include "color.h"
#include <iostream>

int main() {
    Color red{255,0,0};
    std::cout << red.colorize("Red") << std::endl;
}
