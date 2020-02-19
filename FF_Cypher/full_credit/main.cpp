#include "rot13.h"
#include "substitution.h"
#include <cctype>
#include <iostream>
#include <fstream>
#include <cctype>  // tolower
using namespace std;

int main() {
  string filename;
  string filename_out;
  char algorithm = ' ';
  bool do_encrypt = true;
  string aline;

  string key = "bfdhmojekixnwqrcltpsauzyvg";

  cout << "Enter filename: ";
  getline(cin, filename);

  if (filename.size() < 6) {
    do_encrypt = true;
  } else if (filename.substr(filename.size()-6) == ".rot13") {
    do_encrypt = false;
    algorithm = 'r';
  } else if (filename.substr(filename.size()-6) == ".subst") {
    do_encrypt = false;
    algorithm = 's';
  } else {
    do_encrypt = true;
    while (true) {
        cout << "Select an encryption algorithm: (R)ot13  (S)ubstitution ==> ";
        cin >> algorithm;
        cin.ignore();
        algorithm = tolower(algorithm);
        if (algorithm == 'r' or algorithm == 's') break;
        else cerr << "### Invalid key: Please press 'r' or 's'" << endl;
    }
  }

  if (do_encrypt) 
    filename_out = filename + ((algorithm == 'r') ? ".rot13" : ".subst");
  else
    filename_out = filename.substr(0, filename.size() - 6);

  ifstream ifs{filename};
  ofstream ofs{filename_out};

  if (algorithm == 'r') {
       Rot13 rot13;
       while(getline(ifs, aline)) 
           ofs << (do_encrypt ? rot13.encrypt(aline) : rot13.decrypt(aline)) << endl;
       cerr << (do_encrypt ? "Encrypted " : "Decrypted ") 
            << rot13.chars_encrypted() << " characters." << endl;

  } else if (algorithm == 's') {
       while (true) {
           cout << "Enter a 26-character key (Enter for default): ";
           string temp_key;
           getline(cin, temp_key);
           if (temp_key.size() == 26) {key = temp_key; break;}
           else if (temp_key.size() == 0) break;
           else cerr << "Invalid key" << endl;
       }

       Substitution substitution{key};
       while(getline(ifs, aline)) 
           ofs << (do_encrypt ? substitution.encrypt(aline) : substitution.decrypt(aline)) << endl;
       cerr << (do_encrypt ? "Encrypted " : "Decrypted ") 
            << Cypher::chars_encrypted() << " characters." << endl;
            //<< substitution.chars_encrypted() << " characters." << endl;
   }
}
