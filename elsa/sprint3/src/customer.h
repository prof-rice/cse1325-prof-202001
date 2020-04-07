#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <string>
#include <iostream>

class Customer {
  public:
    Customer(std::string name, std::string phone, std::string email);
    Customer(std::istream& ist);   // Open
    void save(std::ostream& ost);  // Save
    friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);
  private:
    std::string _name;
    std::string _phone;
    std::string _email;
};

#endif
