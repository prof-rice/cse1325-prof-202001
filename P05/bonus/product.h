#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <string>
#include <ostream>

class Product {
  public:
    Product(std::string name, double cost);
    virtual ~Product();
    void set_quantity(int num);
    virtual double price() const = 0;
    friend std::ostream& operator<<(std::ostream& ost, const Product& product);
  protected:
    std::string _name;
    double _cost;
    int _num;
};

#endif
