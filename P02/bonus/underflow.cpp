#include <iostream>

int main() {
    int red=128;
    std::cout << red/100*21 << ' '  // Beware the underflow!
              << red*21/100 << ' '
              << (double)red*0.21 << std::endl;
}
