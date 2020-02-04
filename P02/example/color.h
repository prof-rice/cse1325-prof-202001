#ifndef __COLOR_H
#define __COLOR_H

#include <string>

class Color {
  public:
    Color(int red, int green, int blue);
    std::string to_string();
    std::string colorize(std::string text);

    int magnitude() const;               // The "subjective brightness"
    int compare(const Color& rhs) const; // 1 if > rhs, 0 if ==, -1 if <
  private:
    int _red;
    int _green;
    int _blue;
};

#endif
