#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <string>
#include <ostream>

class Options {
  public:
    Options(std::string name, double cost);
    virtual ~Options();
    double cost();
    virtual std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& ost, const Options& options);
  protected:
    std::string _name;
    double _cost;
};

#endif
