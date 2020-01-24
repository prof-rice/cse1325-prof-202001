#include <iostream>

// At last, class Color is just the *interface*
class Color {
    int _red;
    int _green;
    int _blue;
  public:
    Color(int red, int green, int blue);
    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    std::string to_string();
};

// Define the bodies separately
Color::Color(int red, int green, int blue)
      : _red{red}, _green{green}, _blue{blue} { }

std::string Color::to_string() {
        return "(" + std::to_string(_red)   + ","
                   + std::to_string(_green) + ","
                   + std::to_string(_blue)  + ")";
}

// Static members MUST be define outside the class declaration
const Color Color::RED  {255,0,0};
const Color Color::GREEN{0,255,0};
const Color Color::BLUE {0,0,255};

int main() {
  Color color = Color{Color::GREEN};
  std::string s = color.to_string();
  std::cout << s << ' ' << s.size() << std::endl;
}
