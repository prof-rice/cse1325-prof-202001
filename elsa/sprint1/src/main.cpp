#include "store.h"
#include <iostream>
#include <iomanip>

int main() {
    Store store;
    char cmd;
    std::cout << std::fixed << std::setprecision(2);
    while(true) {
        std::cout << R"(
                 ===============
                 Welcome to ELSA
                 ===============

   Exceptional Laptops and Supercomputers Always!

List (o)rders       (O)rder a new desktop computer
List (c)ustomers    (C)reate a new Customer (Woohoo!)
List (d)esktops     (D)efine a new desktop product
List (p)eripherals  (P)ut in new peripherals
(Q)uit

Command? )";

        std::cin >> cmd; std::cin.ignore(32767, '\n');

        // LIST ORDERS
        if(cmd == 'o') {
            for(int i=0; i<store.num_orders(); ++i) 
                std::cout << i << ") " << store.order(i) << "\n";

        // ORDER A NEW COMPUTER
        } else if(cmd == 'O') {
            int customer = -1;
            int order    = -1;
            int desktop  = -1;
            try {
                for(int i=0; i<store.num_customers(); ++i) 
                    std::cout << i << ") " << store.customer(i) << '\n';
                std::cout << "Customer? ";
                std::cin >> customer; std::cin.ignore(32767, '\n');
                std::cout << store.customer(customer) << '\n';

                order = store.new_order(customer);
                std::cout << "Order " << order 
                          << " created for Customer " << customer << std::endl;
                desktop = 0;
            } catch(std::exception& e) {
                std::cerr << "#### UNABLE TO CREATE ORDER FOR CUSTOMER " 
                          << customer << " ####\n\n"; 
            }

            while(desktop >= 0) {
                for(int i=0; i<store.num_desktops(); ++i) 
                    std::cout << i << ") " << store.desktop(i) << '\n';
                std::cout << "Desktop (-1 when done)? ";
                std::cin >> desktop; std::cin.ignore(32767, '\n');
                if(desktop == -1) break;
                try {
                    store.add_desktop(desktop, order);
                } catch (std::exception& e) {
                    std::cerr << "#### UNABLE TO ADD DESKTOP " << desktop
                              << " TO ORDER " << order << std::endl;
                    desktop = 0;
                }
            }

            if(order >= 0)
                std::cout << "\n++++ Order " << order << " Placed ++++\n" 
                          << store.order(order);

        // LIST CUSTOMERS
        } else if (cmd == 'c') {
            for(int i=0; i<store.num_customers(); ++i) 
                std::cout << i << ") " << store.customer(i) << "\n";

        // ADD A NEW CUSTOMER
        } else if (cmd == 'C') {
            std::cout << "Customer name? ";
            std::string name;
            std::getline(std::cin, name);
            if(name.size()) {
                std::cout << "Customer phone (xxx-xxx-xxxx)? ";
                std::string phone;
                std::getline(std::cin, phone);
                std::cout << "Customer email (xxx@domain.com)? ";
                std::string email;
                std::getline(std::cin, email);
                Customer customer{name, phone, email};
                store.add_customer(customer);
            }

        // LIST ALL PRODUCTS
        } else if (cmd == 'd') {
                for(int i=0; i<store.num_desktops(); ++i) 
                    std::cout << i << ") " << store.desktop(i) << "\n";

        // CREATE A NEW PRODUCT FROM OPTIONS
        } else if (cmd == 'D') {
            int desktop = store.new_desktop();
            while(true) {
                std::cout << store.desktop(desktop) << "\n\n";
                for(int i=0; i<store.num_options(); ++i) 
                   std::cout << i << ") " << store.option(i) << '\n';
                std::cout << "\nAdd which peripheral (-1 when done)? ";
                int option;
                std::cin >> option; std::cin.ignore(32767, '\n');
                if(option == -1) break;
                try {
                    store.add_option(option, desktop);
                } catch(std::exception& e) {
                    std::cerr << "#### INVALID OPTION ####\n\n";
                }
            }

        // LIST ALL OPTIONS
        } else if (cmd == 'p') {
            for(int i=0; i<store.num_options(); ++i) 
               std::cout << i << ") " << store.option(i) << "\n";

        // CREATE A NEW OPTION
        } else if (cmd == 'P') {
            std::cout << "Name of new peripheral? ";
            std::string s;
            std::getline(std::cin, s);
            std::cout << "Cost? ";
            double cost;
            if (std::cin >> cost) {
                Options option{s, cost};
                store.add_option(option);
            } else {
                std::cin.clear();
                std::cerr << "#### INVALID PRICE ####\n\n";
                std::cin.ignore(32767, '\n');
            }

        // QUIT
        } else if (toupper(cmd) == 'Q') {
            break;

        // INVALID COMMAND
        } else {
            std::cerr << "#### INVALID COMMAND ####\n";
        }
    }
}

