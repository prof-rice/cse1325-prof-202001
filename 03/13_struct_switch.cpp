#include <iostream>
#include <vector>

struct Color {
  enum {RED, GREEN, BLUE} color;
};

std::string to_string(Color color) {
    switch (color.color) {
        case Color::RED   : return "Red";
        case Color::GREEN : return "Green";
        case Color::BLUE  : return "Blue";
        default    : return "Unknown";
    }
}

int main() {
  Color color = Color{Color::GREEN};
  std::cout << to_string(color) << std::endl;
}
