#ifndef _XOR_H
#define _XOR_H

#include "cypher.h"
#include <fstream>

class Xor : public Cypher {
  public:
    Xor(string filename);
    string encrypt(string unencrypted);
    string decrypt(string encrypted);
  private:
    string exclusive_or(string original);
    string _filename;
    ifstream _ifs;
};
#endif
