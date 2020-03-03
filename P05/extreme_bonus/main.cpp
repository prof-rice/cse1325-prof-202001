#include "taxed.h"
#include "taxfree.h"
#include <iostream>
#include <vector>

int main() {
    Taxed::set_tax_rate(0.0825);
    
    std::vector<Product*> products = {
        new Taxfree{"Milk", 2.85},
        new Taxfree{"Bread", 1.99},
        new Taxfree{"Cheese", 0.99},
        new Taxed{"Ice Cream", 4.95},
        new Taxed{"Poptarts", 3.49},
        new Taxed{"Oreos", 5.99},
    };

    std::vector<Product*> orders;

    while(true) {
        std::cout << "========================\n"
                  << "  Welcome to the Store  \n"
                  << "========================\n";
        int index = 0;
        for(auto p : products) std::cout << index++ << ") " << *p << '\n';

        if (orders.size() > 0) {
            std::cout << "\nCurrent Order" 
                      << "\n-------------\n";
            double price = 0.00;
            for(auto& p : orders) {std::cout << *p << '\n'; price += p->price();}
            std::cout << "\nTotal price: $" << price << '\n';
        }

        int quantity;

        try {
            std::cout << "\nEnter quantity (0 to exit) and product index: ";
            std::cin >> quantity;
            if(quantity == 0) break;
            if(quantity < 0) throw std::out_of_range{"Invalid quantity"};
            
            std::cin >> index;
            if(index < 0 || index >= products.size())
                throw std::out_of_range{"Invalid product"};

            orders.push_back(products[index]);
            orders.back()->set_quantity(quantity);
        } catch(std::out_of_range& e) {
            std::cerr << "### Error: " << e.what() << std::endl;
        }        

        std::cin.ignore(32767, '\n');
        std::cout << std::endl;
    }
}

