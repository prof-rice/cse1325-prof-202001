#include <iostream>
#include <unistd.h>
#include <pwd.h>
using namespace std;

int main() {
  struct passwd *passwd;
  passwd = getpwuid(getuid());

  cout << "Hello, " << passwd->pw_gecos << endl;
}
