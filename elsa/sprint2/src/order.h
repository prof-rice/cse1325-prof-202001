#ifndef __ORDER_H
#define __ORDER_H

#include "customer.h"
#include "desktop.h"

class Order {
  public:
    Order(Customer& customer);
    virtual ~Order();
    int add_product(Desktop& desktop);
    double price() const;
    friend std::ostream& operator<<(std::ostream& ost, const Order& order);
  private:
    Customer& _customer;
    std::vector<Desktop*> _products;
};

#endif
