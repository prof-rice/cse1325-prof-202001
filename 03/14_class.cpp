#include <iostream>

class Color {
  public:
    enum {RED, GREEN, BLUE} color;
    std::string to_string() {
        switch (color) {
            case RED   : return "Red";
            case GREEN : return "Green";
            case BLUE  : return "Blue";
            default    : return "Unknown";
        }
    }
};

int main() {
  Color color = Color{Color::GREEN};
  std::cout << color.to_string() << std::endl;
}
