// This is an example of how colorful text is printed to the console.
// You can compile using "make example", and run with "./example".

#include <iostream>

int main() {
    std::cout << "\033[38;2;0;100;177m" // Sets color to 0 red, 100 green, 177 blue
              << "UTA Blue"             // Text to print in the above color
              << "\033[0m"              // Resets terminal to default state
              << std::endl;             // Newline and flushes the output buffer
}
