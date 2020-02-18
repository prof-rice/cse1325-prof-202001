#ifndef __COIN_H
#define __COIN_H

#include <iostream>

enum class Coin_size {PENNY, NICKEL, DIME, QUARTER};
std::ostream& operator<<(std::ostream& ost, const Coin_size& size);

typedef int Year;

class Coin {
  public:
    Coin(Coin_size size, Year year);
    Coin(const Coin& rhs);
    Coin& operator=(const Coin& rhs);
    ~Coin();
    void add_note(std::string s);
    friend std::ostream& operator<<(std::ostream& ost, const Coin& coin);
  private:
    Coin_size _size;
    Year _year;
    std::string* _notes;
};
#endif
