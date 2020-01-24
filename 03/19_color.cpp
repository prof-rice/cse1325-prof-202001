#include "19_color.h"

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

