#include <iostream>

enum Color {RED, GREEN, BLUE};
const std::string Color_to_string[3] = {
    "Red", "Green", "Blue"};

int main() {
  Color color = GREEN;
  std::cout << Color_to_string[color] << std::endl;
}
