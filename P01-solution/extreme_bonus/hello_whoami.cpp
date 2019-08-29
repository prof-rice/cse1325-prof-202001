 #include <iostream>
 #include <fstream>
 #include <stdlib.h>

 using namespace std;

 int main() {
   system("whoami > whoami.txt");
   ifstream ifs{"whoami.txt"};
   string whoiam;
   ifs >> whoiam;
   cout << "Hello, " << whoiam << "!" << endl;
   system("rm -f whoami.txt");
 }
