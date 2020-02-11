#ifndef __COLOR_H
#define __COLOR_H

#include <iostream>

class Color {
  public:
    Color();
    Color(int red, int green, int blue);

    // Human output (to_string) and input (>>), and terminal control (<<)
    std::string to_string();
    friend std::ostream& operator<<(std::ostream& ost, const Color& color);
    friend std::istream& operator>>(std::istream& ist, Color& color);

  private:
    void validate();  // Data validation - NOT required or shown on class diagram
    int _red;
    int _green;
    int _blue;
    bool _reset;
};

#endif
