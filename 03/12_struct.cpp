#include <iostream>
#include <vector>

struct Color {
  enum {RED, GREEN, BLUE} color;
};

std::string to_string(Color color) {
  const static std::vector<std::string> Color_to_string = {
    "Red", "Green", "Blue"};
  return Color_to_string[color.color];  // Index on the color member of Color
}

int main() {
  Color color = Color{Color::GREEN};
  std::cout << to_string(color) << std::endl;
}
