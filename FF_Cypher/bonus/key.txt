#include "rot13.h"
#include "substitution.h"
#include <iostream>
#include <vector>
using namespace std;

class Test_vector {
  public:
    Test_vector(string unencrypted, string rot13, string substitution) 
        : _unencrypted{unencrypted}, _rot13{rot13}, _substitution{substitution} { }
    string unencrypted() {return _unencrypted;}
    string rot13() {return _rot13;}
    string substitution() {return _substitution;}
  private:
    string _unencrypted;
    string _rot13;
    string _substitution;
};
  
int main() {
    bool pass = true; // optimistic

    vector<Test_vector> test_vectors = { {"", "", ""},
        {"The quick brown fox jumps over the lazy dog",
         "Gur dhvpx oebja sbk whzcf bire gur ynml qbt",
         "Sem lakdx ftrzq ory iawcp rumt sem nbgv hrj",},
        {"Now is the time for all good students to come to the aid of their gpa",
         "Abj vf gur gvzr sbe nyy tbbq fghqragf gb pbzr gb gur nvq bs gurve tcn",
         "Qrz kp sem skwm ort bnn jrrh psahmqsp sr drwm sr sem bkh ro semkt jcb",},
        {"English punctuation includes , ; \" ' ! @ # $ % ^ & * ( ) - + = ` ! | \\ / ? . < and >",
         "Ratyvfu chapghngvba vapyhqrf , ; \" ' ! @ # $ % ^ & * ( ) - + = ` ! | \\ / ? . < naq >",
         "Mqjnkpe caqdsabskrq kqdnahmp , ; \" ' ! @ # $ % ^ & * ( ) - + = ` ! | \\ / ? . < bqh >",},
    };

    Rot13 rot13;
    for (auto tv : test_vectors) {
        string encrypted = rot13.encrypt(tv.unencrypted());
        string decrypted = rot13.decrypt(encrypted);
        if (tv.rot13() != encrypted) {
           cerr << "Rot13: Encryption error" << endl;
           cerr << "    " << tv.rot13() << endl;
           cerr << "    " << encrypted << endl << endl;
           pass = false;
        }
        if (tv.unencrypted() != decrypted) {
           cerr << "Rot13: Decryption error" << endl;
           cerr << "    " << tv.unencrypted() << endl;
           cerr << "    " << decrypted << endl << endl;
           pass = false;
        }
    }

    string key = "bfdhmojekixnwqrcltpsauzyvg";
    Substitution substitution{key};
    for (auto tv : test_vectors) {
        string encrypted = substitution.encrypt(tv.unencrypted());
        string decrypted = substitution.decrypt(encrypted);
        if (tv.substitution() != encrypted) {
           cerr << "Substitution: Encryption error" << endl;
           cerr << "    " << tv.substitution() << endl;
           cerr << "    " << encrypted << endl << endl;
           pass = false;
        }
        if (tv.unencrypted() != decrypted) {
           cerr << "Substitution: Decryption error" << endl;
           cerr << "    " << tv.unencrypted() << endl;
           cerr << "    " << decrypted << endl << endl;
           pass = false;
        }
    }

    if (!pass) {
        cerr << "fail" << endl;
        return -1;
    }
}
