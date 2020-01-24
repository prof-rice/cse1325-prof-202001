#include <iostream>
#include <vector>
#include "19_color.h"

// We can now use our Color type just as well as we can use int or double!
//   Well, almost (to_string()?). Give us a few more lectures...
int main() {
  std::vector<Color> colors{Color::RED, Color::GREEN, Color::BLUE, Color{128,128,128}};
  for(auto c : colors) std::cout << c.to_string() << std::endl;
}
