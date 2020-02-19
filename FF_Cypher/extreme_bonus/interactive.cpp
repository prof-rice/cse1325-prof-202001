#include "rot13.h"
#include "substitution.h"
#include <cctype>
#include <iostream>
#include <cctype>  // tolower
using namespace std;

int main() {
  string original;
  char algorithm;
  char encrypt_or_decrypt = ' ';

  string key = "bfdhmojekixnwqrcltpsauzyvg";

  while (true) {
    cout << "(E)ncrypt or (D)ecrypt? ";
    cin >> encrypt_or_decrypt;
    cin.ignore();
    encrypt_or_decrypt = tolower(encrypt_or_decrypt);
    if (encrypt_or_decrypt == 'e' || encrypt_or_decrypt == 'd') break;
    else cerr << "### Invalid key: Please press 'e' or 'd'" << endl;
  }

  cout << "Enter text to " << ((encrypt_or_decrypt == 'e') ? "encrypt: " : "decrypt: ");
  getline(cin, original);

  while (true) {
      cout << "Select an encryption algorithm" << endl
           << "  (R)ot13" << endl
           << "  (S)ubstitution" << endl
           << "> ";
      cin >> algorithm;
      cin.ignore();
      algorithm = tolower(algorithm);
      if (algorithm == 'r' or algorithm == 's') break;
      else cerr << "### Invalid key: Please press 'r' or 's'" << endl;
  }

  if (algorithm == 'r') {
       Rot13 rot13;
       if (encrypt_or_decrypt == 'e') {
           cout << rot13.encrypt(original) << endl;
           cout << "Encrypted " << rot13.chars_encrypted() << " characters." << endl;
       } else {
           cout<< rot13.decrypt(original) << endl
                << "Decrypted " << rot13.chars_encrypted() << " characters." << endl;
       }
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
       if (encrypt_or_decrypt == 'e') {
           cout << substitution.encrypt(original) << endl;
           cout << "Encrypted " << substitution.chars_encrypted() << " characters." << endl;
       } else {
           cout << substitution.decrypt(original) << endl;
           cout << "Decrypted " << substitution.chars_encrypted() << " characters." << endl;
       }
   }
}
