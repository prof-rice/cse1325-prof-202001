#pragma once
#include <vector>
#include <iostream>
#include "term.h"

class Polynomial {
  public:
    Polynomial();
    Polynomial(std::istream& ist);
    void save(std::ostream& ost);

    void add_term(double coefficient, double exponent);
    double operator()(double x);   // Evaluate the polynomial for x
    void solve(double min, double max, int nthreads = 1, 
               double slices = 100000000, double precision = 0.00001);
    std::vector<double> roots();
    friend std::ostream& operator<<(std::ostream& ost, const Polynomial& polynomial);
  private:
    void solve_recursive(double min, double max, int tid, double slices, double precision, int recursions=1);
    std::vector<double> _roots;
    std::vector<Term> _terms;
};
