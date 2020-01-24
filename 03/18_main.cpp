#include <iostream>
#include "18_color.h"

int main() {
  Color color = Color{Color::GREEN};
  std::string s = color.to_string();
  std::cout << s << ' ' << s.size() << std::endl;
}
