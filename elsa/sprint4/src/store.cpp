#include "store.h"
#include "ram.h"

// File I/O

Store::Store() {}
Store::Store(std::istream& ist) {
    // Input buffers
    std::string s;
    int vsize;

    // Verify file header (to ensure it's an Elsa file)
    std::getline(ist, s);
    if(s != ELSA_COOKIE) throw std::runtime_error{"Not an ELSA file"};
    std::getline(ist, s);
    if(ELSA_FILE_COMPATIBLE.count(s) == 0) 
        throw std::runtime_error{"Unsupported ELSA file version "+s};

    // Load Customers
    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) customers.push_back(Customer{ist});
    if(!ist) throw std::runtime_error{"Bad Customer Data"};

    // Load Options
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
    if(!ist) throw std::runtime_error{"Bad Options Data"};

    // Load desktops
    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) desktops.push_back(Desktop{ist});
    if(!ist) throw std::runtime_error{"Bad Product Data"};

    // Load Orders
    ist >> vsize; ist.ignore(32767, '\n');
    while(vsize--) orders.push_back(Order{ist});
    if(!ist) throw std::runtime_error{"Bad Order Data"};
}

void Store::save(std::ostream& ost) {
    // File header (to ensure it's an Elsa file)
    ost << ELSA_COOKIE << "\n";
    ost << ELSA_FILE_VERSION << "\n";

    // Save Customers
    ost << customers.size() << '\n';  // Number in vector
    for(auto c : customers) c.save(ost);

    // Save Options
    ost << options.size() << '\n';
    for(auto o : options) o->save(ost);

    // Save desktops
    ost << desktops.size() << '\n';
    for(auto d : desktops) d.save(ost);

    // Save Orders
    ost << orders.size() << '\n';
    for(auto o : orders) o.save(ost);
}

//
// Customers
//
void Store::add_customer(Customer& customer) {customers.push_back(customer);}
int Store::num_customers() {return customers.size();}
Customer& Store::customer(int index) {return customers.at(index);}

//
// Options
//
void Store::add_option(Options& option) {options.push_back(option.clone());}
int Store::num_options() {return options.size();}
Options& Store::option(int index) {return *options.at(index);}

//
// desktops
//
int Store::new_desktop() {
    desktops.push_back(Desktop{});
    return desktops.size()-1;
}
void Store::add_option(int option, int desktop) { // to desktop
    desktops[desktop].add_option(*options[option]);
}
int Store::num_desktops() {return desktops.size();}
Desktop& Store::desktop(int index) {return desktops[index];}

//
// Orders
//
int Store::new_order(int customer) {
    orders.push_back(Order{customers[customer]});
    return orders.size()-1;
}
    
void Store::add_desktop(int desktop, int order) { // to order
    orders[order].add_product(desktops[desktop]);
}
int Store::num_orders() {return orders.size();}
Order& Store::order(int index) {return orders[index];}
