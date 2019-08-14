#include <iostream>

int main() {
    std::string s;
    std::cout << "What's your name? ";
    std::getline(std::cin, s);
    std::cout << "Hello, " << s << std::endl;
}
