#include <string>

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

