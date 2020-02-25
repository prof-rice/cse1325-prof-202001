#include "taxed.h"

double Taxed::_tax = 0;
void Taxed::set_tax_rate(double sales_tax) {_tax = sales_tax;}

Taxed::Taxed(std::string name, double cost)
     : Product(name, cost) { }
Taxed::~Taxed() { }
double Taxed::price() const {return _num * _cost * (1+_tax);}


