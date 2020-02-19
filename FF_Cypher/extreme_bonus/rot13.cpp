#include "rot13.h"

Rot13::Rot13() : Cypher() { }

string Rot13::encrypt(string unencrypted) {
    string encrypted;
    for(char c : unencrypted) {
        if ((c >= 'a' && c <= 'm') ||
            (c >= 'A' && c <= 'M')) encrypted.append(1, c += 13);
        else if ((c >= 'n' && c <= 'z') ||
                 (c >= 'N' && c <= 'Z')) encrypted.append(1, c -= 13);
        else encrypted.append(1, c);
    }
    chars_encrypted(unencrypted.size());
    return encrypted;
}

string Rot13::decrypt(string encrypted) { 
    return encrypt(encrypted);
}

