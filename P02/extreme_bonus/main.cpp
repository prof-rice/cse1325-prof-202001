#include "color.h"
#include <iostream>
#include <vector>
#include <algorithm>

bool less_than(const Color& lhs, const Color& rhs) {
    return lhs.compare(rhs) < 0;
}

int main() {
    std::vector<Color> colors;

    Color uta_blue{0,100,177};
    colors.push_back(uta_blue);

    Color uta_orange{245,128,38};
    colors.push_back(uta_orange);

    Color maroon{93,23,37};
    colors.push_back(maroon);

    std::sort(colors.begin(), colors.end(), less_than);

    for(auto& c : colors)
        std::cout << c.colorize(c.to_string()) << std::endl;
}
