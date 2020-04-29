#include <iostream>
#include <sstream>
#include <map>

#include <codecvt>   // for codecvt_utf8
#include <locale>    // for wstring_convert
//#include <string>    // for string, u16string


//const std::string ordinals  = "0123456789.+-";
//const std::wstring exponents = u"⁰¹²³⁴⁵⁶⁷⁸⁹ᐧ⁺⁻";

const std::map<char, char16_t> subs = {
   {'0', u'⁰'}, {'1', u'¹'}, {'2', u'²'},
   {'3', u'³'}, {'4', u'⁴'}, {'5', u'⁵'},
   {'6', u'⁶'}, {'7', u'⁷'}, {'8', u'⁸'},
   {'9', u'⁹'}, {'.', u'ᐧ'},
   {'+', u'⁺'}, {'-', u'⁻'}, {'e', u'ᵉ'},
};

int main() {
    double e;
    do {
        std::cout << "Enter exponent: ";
        std::cin >> e;
        std::ostringstream oss;
        oss << e;
        std::u16string s;
        for(auto& c : oss.str()) s += subs.at(c);

        std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> cv;
        std::cout << 'X' << cv.to_bytes(s) << std::endl;
    } while(e != 0);
}

