#include "product.h"
#include <iomanip>

Product::Product(std::string name, double cost)
       : _name{name}, _cost{cost}, _num{0} {
    if(_cost < 0) throw std::runtime_error{"Negative cost for " + _name};
}
Product::~Product() { }

void Product::set_quantity(int num) {_num = num;}

std::ostream& operator<<(std::ostream& ost, const Product& product) {
    ost << product._name << " (";
    if(product._num > 0) ost << product._num << " @ ";
    ost << "$" << std::fixed << std::setprecision(2) << product._cost << ")";
    return ost;
}

