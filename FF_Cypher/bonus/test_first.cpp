#include "rot13.h"
#include "xor.h"
#include "substitution.h"
#include <iostream>
using namespace std;

int main() {
  const string s = "Hello, world";

  // Test Rot13
  cout << "Rot13\n-----\n";
  Rot13 rot13;
  cout << rot13.encrypt(s) << endl;
  cout << rot13.decrypt(rot13.encrypt(s)) << endl;
  cout << "Chars encrypted: " << rot13.chars_encrypted() << endl << endl;

  // Test Substitution
  cout << "Substitution (reverse)\n------------\n";
  string key = "zyxwvutsrqponmlkjihgfedcba";
  Substitution substitution{key};
  cout << substitution.encrypt(s) << endl;
  cout << substitution.decrypt(substitution.encrypt(s)) << endl;
  cout << "Chars encrypted: " << substitution.chars_encrypted() << endl << endl;

  // Test Substitution
  cout << "Substitution (random)\n------------\n";
  key = "bfdhmojekixnwqrcltpsauzyvg";
  Substitution subrandom{key};
  cout << subrandom.encrypt(s) << endl;
  cout << subrandom.decrypt(subrandom.encrypt(s)) << endl;
  cout << "Chars encrypted: " << subrandom.chars_encrypted() << endl << endl;

  // Test Substitution as Rot13
  cout << "Substitution (Rot13)\n------------\n";
  key = "nopqrstuvwxyzabcdefghijklm";
  Substitution subrot13{key};
  cout << subrot13.encrypt(s) << endl;
  cout << subrot13.decrypt(subrot13.encrypt(s)) << endl;
  cout << "Chars encrypted: " << subrot13.chars_encrypted() << endl << endl;

  // Test Exclusive OR (xor)
  cout << "Substitution (Xor)\n------------\n";
  key = "main.cpp";
  Xor xor_encrypt{key};
  string s_encrypted = xor_encrypt.encrypt(s);
  cout << s_encrypted << endl;
  Xor xor_decrypt{key};
  cout << xor_decrypt.decrypt(s_encrypted) << endl;
  cout << "Chars encrypted: " << xor_encrypt.chars_encrypted() +
                                 xor_decrypt.chars_encrypted() << endl << endl;
}
