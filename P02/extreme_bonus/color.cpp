#include "color.h"

Color::Color(int red, int green, int blue) : _red{red}, _green{green}, _blue{blue} { }
std::string Color::to_string() {
    return "(" + std::to_string(_red)        + ","
               + std::to_string(_green)      + ","
               + std::to_string(_blue)       + ":"
               + std::to_string(magnitude()) + ")";
}

int Color::magnitude() const {            // The "subjective brightness"
    return static_cast<int>(
               0.21 * (double)_red
             + 0.72 * (double)_green
             + 0.07 * (double)_blue
    );
}

int Color::compare(const Color& rhs) const { // 1 if > rhs, 0 if ==, -1 if <
    if(magnitude() > rhs.magnitude()) return  1;
    if(magnitude() < rhs.magnitude()) return -1;
    return 0;
}

std::string Color::colorize(std::string text) {
    return "\033[38;2;" 
         + std::to_string(_red)   + ';' 
         + std::to_string(_green) + ';'
         + std::to_string(_blue)  + 'm'
         + text
         + "\033[0m";
}
