#include "async.h"
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>

Async::Async(int key, int dekey) : Cypher(), _key{key}, _dekey{dekey} { }

struct crypt : std::binary_function<int, int, int> {
    int operator()(int input, int key) const { 
        int n=391;
        int result = 1;
        for (int i=0; i<key; i++) {
            result *= input;
            result %= n;
        }
        return result;
    }
};

string Async::encrypt(string unencrypted) {
    std::vector<int> encrypted;
    string result;
    std::transform(unencrypted.begin(), 
        unencrypted.end(),  
        std::back_inserter(encrypted),
        std::bind2nd(crypt(), _key));
    for (int i : encrypted) result += " " + std::to_string(i);
    chars_encrypted(unencrypted.size());
    return result;
}

string Async::decrypt(string encrypted) { 
    std::vector<int> v_encrypted;
    int i;
    istringstream iss{encrypted};
    ostringstream result;
    while(iss >> i) v_encrypted.push_back(i);
    std::transform(v_encrypted.begin(), v_encrypted.end(), 
        std::ostream_iterator<char>(result, ""), 
        std::bind2nd(crypt(), _dekey));
    chars_encrypted(result.str().size());
    return result.str();
}
