#include "taxed.h"
#include "taxfree.h"
#include <iostream>
#include <vector>

int main() {
    Taxed::set_tax_rate(0.0825);
    
    std::vector<Taxfree> tf = {
        Taxfree{"Milk", 2.85},
        Taxfree{"Bread", 1.99},
        Taxfree{"Cheese", 0.99},
    };

    std::vector<Taxed> t = {
        Taxed{"Ice Cream", 4.95},
        Taxed{"Poptarts", 3.49},
        Taxed{"Oreos", 5.99},
    };

    std::vector<Taxfree> tf_order;
    std::vector<Taxed> t_order;

    while(true) {
        std::cout << "========================\n"
                  << "  Welcome to the Store  \n"
                  << "========================\n";
        int index = 0;
        for(auto& p : tf) std::cout << index++ << ") " << p << '\n';
        for(auto& p : t)  std::cout << index++ << ") " << p << '\n';

        if ((tf_order.size() + t_order.size())>0) {
            std::cout << "\nCurrent Order" 
                      << "\n-------------\n";
            double price = 0.00;
            for(auto& p : tf_order) {std::cout << p << '\n'; price += p.price();}
            for(auto& p : t_order)  {std::cout << p << '\n'; price += p.price();}
            std::cout << "\nTotal price: $" << price << '\n';
        }

        int quantity;

        try {
            std::cout << "\nEnter quantity (0 to exit) and product index: ";
            std::cin >> quantity;
            if(quantity == 0) break;
            if(quantity < 0) throw std::out_of_range{"Invalid quantity"};
            
            std::cin >> index;
            if(index < 0 || index >= (tf.size() + t.size()))
                throw std::out_of_range{"Invalid product"};

            if(index < tf.size()) {
                tf_order.push_back(tf[index]);
                tf_order.back().set_quantity(quantity);
            } else {
                index -= tf.size();
                t_order.push_back(t[index]);
                t_order.back().set_quantity(quantity);
            }
        } catch(std::out_of_range& e) {
            std::cerr << "### Error: " << e.what() << std::endl;
        }        

        std::cin.ignore(32767, '\n');
        std::cout << std::endl;
    }
}

