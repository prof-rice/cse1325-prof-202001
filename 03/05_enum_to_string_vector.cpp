#include <iostream>
#include <vector>

enum Color {RED, GREEN, BLUE};
const static std::vector<std::string> Color_to_string = {
    "Red", "Green", "Blue"};

int main() {
  Color color = GREEN;
  std::cout << Color_to_string[color] << std::endl;
}
