#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <iostream>

class Options {
  public:
    Options(std::string name, double cost);
    virtual ~Options();
    double cost();
    virtual std::string to_string() const;
    Options(std::istream& ist);    // Open
    virtual void save(std::ostream& ost);  // Save
    virtual Options* clone(); // Return copy of *this on heap
    friend std::ostream& operator<<(std::ostream& ost, const Options& options);
  protected:
    std::string _name;
    double _cost;
};

#endif
