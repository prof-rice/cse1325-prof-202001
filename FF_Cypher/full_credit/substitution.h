#ifndef _SUBSTITUTION_H
#define _SUBSTITUTION_H

#include "cypher.h"

class Substitution : public Cypher {
  public:
    Substitution(string key);
    string encrypt(string unencrypted);
    string decrypt(string encrypted);
  private:
    string substitute(string original, string key);
    string _key;
    string _dekey;  // inverse of _key
};
#endif
