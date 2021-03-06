#include "term.h"
#include <cmath>

#include <map>
#include <sstream>

Term::Term(double coefficient, double exponent) : _coeff{coefficient}, _exp{exponent} { }
Term::Term(std::istream& ist) {ist >> _coeff >> _exp;}
void Term::save(std::ostream& ost) {ost << _coeff << ' ' << _exp << '\n';}
double Term::eval(double x) {return _coeff * pow(x, _exp);}

const std::map<char, char16_t> subs = {
   {'0', u'⁰'}, {'1', u'¹'}, {'2', u'²'},
   {'3', u'³'}, {'4', u'⁴'}, {'5', u'⁵'},
   {'6', u'⁶'}, {'7', u'⁷'}, {'8', u'⁸'},
   {'9', u'⁹'}, {'.', u'ᐧ'},
   {'+', u'⁺'}, {'-', u'⁻'}, {'e', u'ᵉ'},
};

std::ostream& operator<<(std::ostream& ost, const Term& term) {
    if     (term._coeff ==  0) return ost;
    else if(term._coeff == -1) ost << '-';
    else if(term._coeff ==  1) ost << '+';
    else if(term._coeff  >  0) ost << '+' << term._coeff;
    else                       ost << term._coeff;

    if(term._exp == 0) return ost;

    ost << 'x';
    if(term._exp == 1) return ost;

    // EXTREME BONUS: Print the exponent as Unicode exponent characters
    //   found at https://en.wikipedia.org/wiki/Unicode_subscripts_and_superscripts

    ost << '^' << term._exp;
    return ost;
}


