#include "item.h"
#include <iomanip>

Item::Item(std::string name, double price) :
    _name{name}, _price{price} { }
double Item::cost() {return _price;}

std::ostream& operator<<(std::ostream& ost, const Item& item) {
    ost << std::fixed << std::setprecision(2) << "$" << std::setw(8) << item._price << "  " << item._name;
    return ost;
}
std::istream& operator>>(std::istream& ist, Item& item) {
    std::string& s = item._name;                      // Reference to the _name string
    item._price = 0;                                  // Signal if invalid
    std::getline(ist, s);                             // WARNING: Includes price as last token

    s.erase(s.find_last_not_of(" \n\r\t")+1);         // right-trim whitespace

    size_t dbl = s.find_last_of(" \n\r\t");           // find next whitespace from end
    if(dbl == std::string::npos) return ist;
        
    try {
        item._price = std::stod(s.substr(dbl+1));     // convert last word to price, if valid
    } catch(std::invalid_argument& e) {
        throw std::invalid_argument{                  //     "improve" the error message, if not
            "Invalid price: '" 
                + s.substr(0,dbl) + "' ==> '"
                + s.substr(dbl+1) + "'"};
    }

    s.erase(dbl+1);                                   // right-trim price
    s.erase(s.find_last_not_of(" \n\r\t")+1);         // right-trim trailing whitespace
    return ist;
}

