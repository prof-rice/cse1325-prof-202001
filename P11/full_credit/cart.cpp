#include "cart.h"

// Rule of 3
Cart::Cart(std::string customer) : _customer{customer} { }
Cart::~Cart() {for(Item* i : _items) delete i;}
Cart::Cart(const Cart& cart) {
    _customer = cart._customer;
    for(Item* i : cart._items) _items.push_back(new Item{*i});
}
Cart& Cart::operator= (const Cart& cart) {
    if(this == &cart) return *this;
    _customer = cart._customer;
    for(Item* i : cart._items) _items.push_back(new Item{*i});
    return *this;
}

// Iteration
Cart::iterator Cart::begin() {return _items.begin();}
Cart::iterator Cart::end() {return _items.end();}

// Add Item
void Cart::add_item(Item& item) {
    if(item.cost() > 0) _items.push_back(new Item{item});
}
double Cart::cost() {
    double c;
    for(auto i : _items) c += i->cost();
    return c;
}

