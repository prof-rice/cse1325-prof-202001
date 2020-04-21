#include "term.h"
#include <cmath>

Term::Term(double coefficient, double exponent) : _coeff{coefficient}, _exp{exponent} { }
Term::Term(std::istream& ist) {ist >> _coeff >> _exp;}
void Term::save(std::ostream& ost) {ost << _coeff << ' ' << _exp << '\n';}
double Term::eval(double x) {return _coeff * pow(x, _exp);}

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


