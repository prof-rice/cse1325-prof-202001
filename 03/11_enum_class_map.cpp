#include <iostream>
// #include <vector>
#include <map>

enum class Color {RED, GREEN, BLUE};

std::string to_string(Color color) {
//  const static std::vector<std::string> Color_to_string = {
//    "Red", "Green", "Blue"};
  static std::map<Color, std::string> Color_to_string = {
      {Color::RED, "Red"}, {Color::GREEN, "Green"}, {Color::BLUE, "Blue"}};
  return Color_to_string[color];
}

int main() {
  Color color = Color::GREEN;
  std::cout << to_string(color) << std::endl;
}
