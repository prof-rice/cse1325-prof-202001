#include "rot13.h"
#include "xor.h"
#include "substitution.h"
#include "async.h"
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
  char achar;

  string key = "bfdhmojekixnwqrcltpsauzyvg"; // for substitution
  string filename_key = "main.cpp";  // for Xor
  int async_key = 47;
  int async_dekey = 15;

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
  } else if (filename.substr(filename.size()-4) == ".xor") {
    do_encrypt = false;
    algorithm = 'x';
  } else if (filename.substr(filename.size()-6) == ".async") {
    do_encrypt = false;
    algorithm = 'a';
  } else {
    do_encrypt = true;
    while (true) {
        cout << "Select an encryption algorithm" << endl
             << "  (R)ot13" << endl
             << "  (S)ubstitution" << endl
             << "  (X)or" << endl
             << "  (A)sync" << endl
             << "> ";
        cin >> algorithm;
        cin.ignore();
        algorithm = tolower(algorithm);
        if (algorithm == 'r' || algorithm == 's' || algorithm == 'x' || algorithm == 'a') break;
        else cerr << "### Invalid key: Please press 'r', 's', 'x', or 'a'" << endl;
    }
  }

  if (do_encrypt) 
    filename_out = filename + ((algorithm == 'r') ? ".rot13" : 
                              ((algorithm == 's') ? ".subst" : 
                              ((algorithm == 'x') ? ".xor" : ".async")));
  else
    filename_out = filename.substr(0, filename.size() - ((algorithm == 'x') ? 4 : 6));

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
            << substitution.chars_encrypted() << " characters." << endl;

  } else if (algorithm == 'x') {
       cout << "Enter a filename to use as the key (Enter for default): ";
       string filename_temp;
       getline(cin, filename_temp);
       if (filename_temp.size() > 0) filename_key = filename_temp;

       Xor exor{filename_key};
       while(getline(ifs, aline)) 
           ofs << (do_encrypt ? exor.encrypt(aline) : exor.decrypt(aline)) << endl;
       cerr << (do_encrypt ? "Encrypted " : "Decrypted ") 
            << exor.chars_encrypted() << " characters." << endl;
  } else if (algorithm == 'a') {
       Async async;
       while(getline(ifs, aline)) 
           ofs << (do_encrypt ? async.encrypt(aline) : async.decrypt(aline)) << endl;
       cerr << (do_encrypt ? "Encrypted " : "Decrypted ") 
            << async.chars_encrypted() << " characters." << endl;
  }
}
