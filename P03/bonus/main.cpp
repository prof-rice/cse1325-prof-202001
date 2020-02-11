#include "color.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

int main() {
    std::srand (std::time(NULL));

    std::vector<Color> colors;

    for(int i=0; i<64; ++i) 
        colors.push_back(Color{rand()%256, rand()%256, rand()%256});

    std::sort(colors.begin(), colors.end());

    for(auto& c : colors)
        std::cout << c << c.to_string() << std::endl;

    std::cout << Color::RESET;
}

