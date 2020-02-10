#ifndef __PATRON_H
#define __PATRON_H

#include <vector>
#include "library.h"

class Patron {
  public:
    void add_library(Library& library);
  private:
    std::vector<Library*> _libraries;
};
#endif
