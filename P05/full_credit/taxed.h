#ifndef __TAXED_H
#define __TAXED_H

#include "product.h"

class Taxed : public Product {
  public:
    Taxed(std::string name, double cost);
    virtual ~Taxed();
    double price() const override;
    static void set_tax_rate(double sales_tax);
  private:
    static double _tax;
};

#endif

