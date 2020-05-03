#include <iostream>

int main() {
    // String to split, delimiting on , or ;
    std::string s = "I can't,decide;on a, delimiter!";

    // pos is the position in the string of the next delimiter
    std::string::size_type pos = std::string::npos;

    // Search until no more delimiters are found
    while ((pos = s.find_first_of(",;")) != std::string::npos) {

        // Print up to the delimiter
        std::cout << s.substr(0, pos) << std::endl;

        // Delete through the delimiter
        s.erase(0, pos + 1);
    }

    // No more delimiters - last word remains
    std::cout << s << std::endl;
}
