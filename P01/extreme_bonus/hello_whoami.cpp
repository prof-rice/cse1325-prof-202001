// NOTE: The Makefile is NOT required! 

#include <iostream>
#include <fstream> // Stream to/from files, too!
#include <cstdlib> // Equivalent to stdlib.h

// For P01 only, the student may include the next line,
//   and / or use std::cout and std::endl below
// P02 and later, no more "using namespace"!
using namespace std;

int main() {
    // Run the "whoami" program on a command line,
    //   storing the result in text file "whoami.txt"
    system("whoami > whoami.txt");

    // Read the output of "whoami" into a string
    ifstream ifs{"whoami.txt"};
    string whoiam;
    ifs >> whoiam;

    // Greet the current user by username
    cout << "Hello, " << whoiam << "!" << endl;

    // Remove the temporary file
    // (std::tmpfile is a better approach, of course)
    system("rm -f whoami.txt");
 }
