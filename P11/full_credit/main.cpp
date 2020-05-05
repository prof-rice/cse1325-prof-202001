#include "cart.h"
#include <iomanip>

int main() {
    Cart cart{"Prof Rice"}; 

    std::cout << "Enter product names and price (e.g., \"English peas 0.79\"):" << std::endl;
    while(std::cin) {
        try {
            Item item{"", 0};
            std::cin >> item;
            cart.add_item(item);
        } catch(std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "\nRegister Receipt\n\n";
    for(Item* i : cart) std::cout << *i << std::endl;
    std::cout << "--------------------\n";
    std::cout << "$" << std::setw(8) << cart.cost() << "  Total Cost" << std::endl;
}
