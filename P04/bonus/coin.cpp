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

std::istream& operator>>(std::istream& ist, Coin_size& size) {
    std::string s;
    ist >> s;
    for(char& c : s) c = toupper(c);
    if(s == "PENNY")   size = Coin_size::PENNY;
    else if(s == "NICKEL")  size = Coin_size::NICKEL;
    else if(s == "DIME")    size = Coin_size::DIME;
    else if(s == "QUARTER") size = Coin_size::QUARTER;
    else throw std::runtime_error{"Invalid coin size: " + s};
    return ist;
}

std::ostream& operator<<(std::ostream& ost, const Coin& coin) {
    ost << coin._year << ' ' << coin._size << '\n';
    if (coin._notes) ost << *coin._notes;
    ost << std::endl;
    return ost;
}

std::istream& operator>>(std::istream& ist, Coin& coin) {
    if(coin._notes) coin._notes->clear(); // Erase existing notes

    ist >> coin._year >> coin._size; ist.ignore(32767, '\n');
    if (coin._year < 1792) 
        throw std::out_of_range{"No US coins minted in "
                               + std::to_string(coin._year)};
    std::string s;
    std::getline(ist, s);
    if (s.size()) coin.add_note(s);
    return ist;
}
