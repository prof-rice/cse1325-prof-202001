#include <iostream>
#include <vector>

enum Color {RED, GREEN, BLUE};

std::string to_string(Color color) {
  // const static std::vector<std::string> Color_to_string = {
  //   "Red", "Green", "Blue"};
  // return Color_to_string[color];
    switch (color) {
        case RED   : return "Red";
        case GREEN : return "Green";
        case BLUE  : return "Blue";
        default    : return "Unknown";
    }

}

enum Size {SMALL, MEDIUM, LARGE};

std::string to_string(Size size) {
  const static std::vector<std::string> Size_to_string = {
    "Small", "Medium", "Large"};
  return Size_to_string[size];
}

int main() {
  Color color = GREEN;
  Size size = LARGE;
  std::cout << to_string(color) << std::endl;
  std::cout << to_string(size) << std::endl;
}
