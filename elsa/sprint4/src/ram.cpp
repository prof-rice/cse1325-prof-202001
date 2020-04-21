#include "ram.h"

Ram::Ram(std::string name, double cost, int gb)
    : Options(name, cost), _gb{gb} { }
Ram::~Ram() { }
std::string Ram::to_string() const {
    return _name + " (" + std::to_string(_gb) + " GB, $" 
                 + std::to_string(_cost) + ")";
}
Ram::Ram(std::istream& ist) : Options(ist) {
    ist >> _gb; ist.ignore(32767, '\n');
}
void Ram::save(std::ostream& ost) {
    ost << "Ram\n";
    Options::save(ost);
    ost << _gb << '\n';
}
Options* Ram::clone() {return new Ram{*this};}

