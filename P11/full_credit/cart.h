#ifndef __CART_H
#define __CART_H

#include "item.h"
#include <vector>

class Cart {
  public:
    Cart(std::string customer);
    virtual ~Cart();
    Cart(const Cart& cart);
    Cart& operator= (const Cart& cart);
    void add_item(Item& item);
    double cost();

    typedef std::vector<Item*>::iterator iterator;
    typedef std::vector<Item*>::const_iterator const_iterator;
    iterator begin();
    iterator end();
  private:
    std::string _customer;
    std::vector<Item*> _items;
};

#endif
