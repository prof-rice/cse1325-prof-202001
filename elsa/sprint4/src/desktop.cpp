#include "desktop.h"
#include "ram.h"

Desktop::Desktop() { }
void Desktop::add_option(Options& option) {options.push_back(&option);}
double Desktop::price() {
    double p = 0.0;
    for(auto o : options) p+= o->cost();
    return p;
}

Desktop::Desktop(std::istream& ist) {
    int vsize;
    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) {
        std::string s;
        std::getline(ist, s);  // Get type marker
        if(s == "Options") {
            options.push_back(new Options{ist});
        } else if (s == "Ram") {
            std::getline(ist, s);  // Remove "Options"
            options.push_back(new Ram{ist});
        } else {
            throw std::runtime_error{"Bad Options Data"};
        }
    }
}
void Desktop::save(std::ostream& ost) {
    ost << options.size() << '\n';
    for(auto c : options) c->save(ost);
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop) {
    ost << "Desktop includes";
    for(auto o : desktop.options) ost << "\n  " << *o;
    return ost;
}

