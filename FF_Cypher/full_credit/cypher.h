#ifndef _CYPHER_H
#define _CYPHER_H

#include <string>
using namespace std;

class Cypher {
  public:
    Cypher();
    virtual string encrypt(string unencrypted) = 0;
    virtual string decrypt(string encrypted) = 0;
    static int chars_encrypted();
  protected:
    static void chars_encrypted(int num);
    static int chars;
};
#endif
