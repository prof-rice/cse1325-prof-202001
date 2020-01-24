#include <string>

// We usually prefer to put the public interface first,
//   since that will be of primary interest to most readers,
//   and the private data structures at the end.

class Color {
  public:
    Color(int red, int green, int blue);
    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    std::string to_string();
  private:
    int _red;
    int _green;
    int _blue;
};

