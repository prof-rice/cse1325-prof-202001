#include "color.h"
#include <iostream>

int main() {
    Color red{255,0,0};
    Color green{0,255,0};
    Color blue{0,128,255};
    Color tru{255,255,0};

    std::cout << red.colorize("Roses are red,\n")
              << blue.colorize("Violets are blue,\n")
              << green.colorize("Dahlias are green,\n")
              << tru.colorize("and good friends are true!\n");
}
