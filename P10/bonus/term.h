#pragma once
#include <iostream>

class Term {
  public:
    Term(double coefficient, double exponent);
    Term(std::istream& ist);
    void save(std::ostream& ost);

    double eval(double x);
    friend std::ostream& operator<<(std::ostream& ost, const Term& term);
  private:
    double _coeff;
    double _exp;
};


