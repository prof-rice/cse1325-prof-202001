#include "coin.h"
#include "logger.h"

/*
void LOG(std::string s) {
    std::cerr << s << std::endl;
    std::cerr.flush();
}
*/

Coin::Coin(Coin_size size, Year year) : _size{size}, _year{year}, _notes{nullptr} {
    LOG("Coin::Coin");
}
Coin::Coin(const Coin& rhs) : _size{rhs._size}, _year{rhs._year}, _notes{nullptr} {
    LOG("Coin::Coin copy constructor");
    if(rhs._notes) _notes = new std::string{*rhs._notes};
}
Coin& Coin::operator=(Coin const& rhs) {
    LOG("Coin::operator=");
    if(this != &rhs) {
        _size = rhs._size;
        _year = rhs._year;
        _notes = nullptr;
        if(rhs._notes) _notes = new std::string{*rhs._notes};
    }
}
Coin::~Coin() {
    LOG("Coin::~Coin");
    delete _notes;
}

void Coin::add_note(std::string s) {
    if(_notes) *_notes+=s;
    else _notes = new std::string{s};
}

std::ostream& operator<<(std::ostream& ost, const Coin_size& size) {
    if(size == Coin_size::PENNY)   ost << "penny";
    else if(size == Coin_size::NICKEL)  ost << "nickel";
    else if(size == Coin_size::DIME)    ost << "dime";
    else if(size == Coin_size::QUARTER) ost << "quarter";
    else throw std::runtime_error{"Invalid coin size"};
    return ost;
}

std::ostream& operator<<(std::ostream& ost, const Coin& coin) {
    ost << coin._year << ' ' << coin._size;
    if (coin._notes) ost << '\n' << *coin._notes;
    return ost;
}
