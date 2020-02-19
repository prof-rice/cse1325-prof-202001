#include "xor.h"
#include <iostream>

Xor::Xor(string filename) : Cypher(), _filename{filename}, 
    _ifs{_filename, ios::binary} { }

string Xor::exclusive_or(string original) {
    string encrypted;
    char from_file;
    for(char c : original) {
        if (_ifs.eof()) {
           _ifs.clear(); // clear eof condition
           _ifs.seekg(0, ios::beg);
        }
        _ifs.get(from_file);
        encrypted.append(1, c^(from_file|0x80));
    }
    chars_encrypted(original.size());
    return encrypted;
}

string Xor::encrypt(string unencrypted) {
    return exclusive_or(unencrypted);
}

string Xor::decrypt(string encrypted) { 
    return exclusive_or(encrypted);
}
