// NOTE: The Makefile is NOT required! 

#include <iostream>
#include <unistd.h> // No C++ equivalent
#include <pwd.h>    // No C++ equivalent

// For P01 only, the student may include the next line,
//   and / or use std::cout and std::endl below
// P02 and later, no more "using namespace"!
using namespace std;

int main() {

    // A little C magic
    // http://man7.org/linux/man-pages/man3/getpwnam.3.html
    struct passwd *passwd;
    passwd = getpwuid(getuid());

    cout << "Hello, " << passwd->pw_gecos << endl;
}
