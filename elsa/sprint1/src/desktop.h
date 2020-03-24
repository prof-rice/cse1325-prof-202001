#ifndef __DESKTOP_H
#define __DESKTOP_H

#include "options.h"
#include <vector>

class Desktop {
  public:
    void add_option(Options& option);
    double price();
    friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
  private:
    std::vector<Options*> options;
};

#endif
