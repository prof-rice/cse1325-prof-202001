// NOTE: The Makefile is NOT required! 

#include <iostream>
#include <fstream> // Stream to/from files, too!
#include <cstdlib> // Equivalent to stdlib.h

// For P01 only, the student may include the next line,
//   and / or use std::cout and std::endl below
// P02 and later, no more "using namespace"!
using namespace std;

int main() {
    // Run "finger" on "whoami" output on a command line,
    //   cutting everthing before the 2nd :, and
    //   storing the result in text file "finger.txt"
    system("finger $(whoami) | head -1 | cut -d ':' -f 3 > finger.txt");

    // Read the output of the above command into a string
    ifstream ifs{"finger.txt"};
    string finger;
    getline(ifs, finger);

    // Greet the current user by username
    cout << "Hello, " << finger << "!" << endl;

    // Remove the temporary file
    // (std::tmpfile is a better approach, of course)
    system("rm -f finger.txt");
 }
