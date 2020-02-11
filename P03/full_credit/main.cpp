#include "color.h"
#include <iostream>

int main() {
    Color uta_blue{0,100,177};
    Color uta_orange{245,128,38};
    Color maroon{93,23,37};
    Color reset;
    std::cout << uta_blue << "UTA Blue" << ' '
              << uta_orange << "UTA Orange" << ' '
              << maroon << "Maroon" << reset << "\n\n";

    int red, green, blue;
    std::cout << "Enter color as (red, green, blue):   "; 
    Color color;
    std::cin >> color;
    std::cout << color << color.to_string() << reset << std::endl;
}
