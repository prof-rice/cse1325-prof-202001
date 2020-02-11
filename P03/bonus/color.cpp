#include "color.h"

Color::Color() : _reset{true} { }
Color::Color(int red, int green, int blue)
    : _red{red}, _green{green}, _blue{blue}, _reset{false} {validate();}

// Static members MUST be define outside the class declaration
//   (NOT required nor on the UML)
const Color Color::RESET{};

void Color::validate() {
    if (_reset) return;
    if (255 < _red   || _red   < 0) throw std::out_of_range{"Invalid RGB red: "   + std::to_string(_red)};
    if (255 < _green || _green < 0) throw std::out_of_range{"Invalid RGB green: " + std::to_string(_green)};
    if (255 < _blue  || _blue  < 0) throw std::out_of_range{"Invalid RGB blue: "  + std::to_string(_blue)};
}

std::string Color::to_string() {
    if (_reset) return "(-1,0,0)";
    return "(" + std::to_string(_red)   + ","
               + std::to_string(_green) + ","
               + std::to_string(_blue)  + ")";
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

std::ostream& operator<<(std::ostream& ost, const Color& color) {
    if (color._reset) {
        //  ESC[ 0 m Reset to defaults
        ost << "\033[0m";
    } else {
        //  ESC[ 38;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB foreground color
        //  ESC[ 48;2;⟨r⟩;⟨g⟩;⟨b⟩ m Select RGB background color
        ost << "\033[38;2;" 
            << color._red << ';' 
            << color._green << ';'
            << color._blue << 'm';
    }
    return ost;
}

std::istream& operator>>(std::istream& ist, Color& color) {
    // Of the form "(64, 96, 128)" - remember, >> skips whitespace!
    // Some data validation would be GREAT to add here!  :-D
    char b, c, d;  // b is '(', c is ',', and d is ')'
    ist >> b >> color._red >> c >> color._green >> c >> color._blue >> d;
    color._reset = (color._red == -1);
    color.validate();
    return ist;
}


