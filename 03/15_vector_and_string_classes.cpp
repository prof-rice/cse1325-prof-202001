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
  std::string s = color.to_string();
  std::cout << s << ' '
            << s.size() << ' '
            << color.to_string().size() // see below
            << std::endl;

  // Note that we call color's to_string() method, which returns a string,
  // and then call string's size() method, which returns (more or less) an int
}
