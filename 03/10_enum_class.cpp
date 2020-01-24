#include <iostream>
#include <vector>

enum class Color {RED, GREEN, BLUE};

std::string to_string(Color color) {
//  const static std::vector<std::string> Color_to_string = {
//    "Red", "Green", "Blue"};
//  return Color_to_string[color];
    switch (color) {
        case Color::RED   : return "Red";
        case Color::GREEN : return "Green";
        case Color::BLUE  : return "Blue";
        default           : return "Unknown";
    }
}

int main() {
  Color color = Color::GREEN;
  std::cout << to_string(color) << std::endl;
}
