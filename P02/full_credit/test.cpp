// This main program can be used to test your class.
// The provide Makefile will build it for you if you type 'make test'.

#include "color.h"
#include <iostream>

int main() {
    Color red{255,0,0};
    std::cout << red.colorize("Red") << std::endl;
}
