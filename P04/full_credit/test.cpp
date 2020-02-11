#include "coin.h"

int main() {
    Coin c1{Coin_size::PENNY,  2006};
    c1.add_note("This is a 2006 penny");

    Coin c2{Coin_size::NICKEL, 1996};
    c2.add_note("This is a 1996 nickel");

    Coin cc{c1};
    cc.add_note(" created via the copy constructor");

    c2 = c1;
    c2.add_note(" created by the copy assignment operator");

    std::cout << '\n';
    std::cout << "c1: " << c1 << "\n\n";
    std::cout << "c2: " << c2 << "\n\n";
    std::cout << "cc: " << cc << "\n\n";
}
