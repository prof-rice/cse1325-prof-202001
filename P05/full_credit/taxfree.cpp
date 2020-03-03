#include "taxfree.h"

Taxfree::Taxfree(std::string name, double cost)
     : Product(name, cost) { }
Taxfree::~Taxfree() { }

double Taxfree::price() const {return _num * _cost;}

