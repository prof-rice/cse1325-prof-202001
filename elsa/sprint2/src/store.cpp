#include "store.h"

//
// Store
//
void Store::add_customer(Customer& customer) {customers.push_back(customer);}
int Store::num_customers() {return customers.size();}
Customer& Store::customer(int index) {return customers.at(index);}

//
// Options
//
void Store::add_option(Options& option) {options.push_back(new Options{option});}
int Store::num_options() {return options.size();}
Options& Store::option(int index) {return *options.at(index);}

//
// Products
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
