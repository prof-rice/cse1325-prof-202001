#ifndef __COLOR_H
#define __COLOR_H

#include <iostream>

class Color {
  public:
    Color();
    Color(int red, int green, int blue);

    // Constant to reset colors on the terminal (NOT required nor on the UML)
    static const Color RESET; // Resets the terminal

    // Compares corresponding reds, greens, and blues
    // Inline methods generate code where called rather than in the class
    inline bool operator==(const Color& rhs) {return compare(rhs) == 0;}
    inline bool operator!=(const Color& rhs) {return compare(rhs) != 0;}
    inline bool operator< (const Color& rhs) {return compare(rhs) < 0;}
    inline bool operator> (const Color& rhs) {return compare(rhs) > 0;}
    inline bool operator<=(const Color& rhs) {return compare(rhs) <= 0;}
    inline bool operator>=(const Color& rhs) {return compare(rhs) >= 0;}

    // Human output (to_string) and input (>>), and terminal control (<<)
    std::string to_string();
    friend std::ostream& operator<<(std::ostream& ost, const Color& color);
    friend std::istream& operator>>(std::istream& ist, Color& color);

    int magnitude() const;               // The "subjective brightness"
    int compare(const Color& rhs) const; // 1 if > rhs, 0 if ==, -1 if <
  private:
    void validate();  // Data validation - NOT required or shown on class diagram
    int _red;
    int _green;
    int _blue;
    bool _reset;
};

#endif
