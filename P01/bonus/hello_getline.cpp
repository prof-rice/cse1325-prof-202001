// NOTE: The Makefile is NOT required! 

#include <iostream>

// For P01 only, the student may include the next line,
//   and / or use std::cout and std::endl below
// P02 and later, no more "using namespace"!
using namespace std;

int main() {
    string name;
    cout << "What's your name? ";

    getline(cin, name);  // Get a \n-terminated line from cin

    cout << "Hello, " << name << "!" << endl;
    return 0;
}
