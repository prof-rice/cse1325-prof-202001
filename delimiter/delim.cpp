#include <iostream>

int main() {
    std::string s;
    std::cout << "Enter words separate by colons, Ctrl-d to exit:" << std::endl;
    while(std::getline(std::cin, s, ':')) {
        std::cout << s << std::endl;
        std::cout.flush();  // print output buffer before continuing
    }
}
