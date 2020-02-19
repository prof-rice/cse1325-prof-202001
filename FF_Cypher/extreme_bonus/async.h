#ifndef _ASYNC_H
#define _ASYNC_H

// Algorithm adapted from 
// https://stackoverflow.com/questions/10005124/public-private-key-encryption-tutorials

#include "cypher.h"
#include <functional>

class Async : public Cypher {
  public:
    Async(int key = 47, int dekey = 15);
    string encrypt(string unencrypted);
    string decrypt(string encrypted);
  private:
    int _key;
    int _dekey;
};
#endif
