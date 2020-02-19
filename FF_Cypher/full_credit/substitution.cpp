#include "substitution.h"
#include <algorithm>
#include <cassert>

Substitution::Substitution(string key) : Cypher(), _key{key}, _dekey{key} { 
  // Data validation: length of key
  assert(_key.size() == 26);

  // Data validation: key has exactly one of each lowercase character
  string sorted_key = key;
  sort(sorted_key.begin(), sorted_key.end());
  assert(sorted_key == "abcdefghijklmnopqrstuvwxyz");

  // Create reverse key for decryption
  char k = 'a';
  for(char c : _key) _dekey[c-'a'] = k++;
}

string Substitution::substitute(string original, string key) {
    string encrypted;
    for(char c : original) {
        int capitalization = 0;
        if (c >= 'A' && c <= 'Z') {
          capitalization = 'A' - 'a';
          c -= capitalization;
        }
        if (c >= 'a' && c <= 'z')
          encrypted.append(1, key[c - 'a'] + capitalization);
        else 
          encrypted.append(1, c);
    }
    chars_encrypted(original.size());
    return encrypted;
}

string Substitution::encrypt(string unencrypted) {
    return substitute(unencrypted, _key);
}

string Substitution::decrypt(string encrypted) { 
    return substitute(encrypted, _dekey);
}
