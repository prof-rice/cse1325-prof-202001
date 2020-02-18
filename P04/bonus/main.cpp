#include "coin.h"
#include <vector>

int main() {
    std::vector<Coin> coins;
    const std::string menu = R"(
===============
 CSE1325 COINS
===============
A)dd a coin
L)ist all coins
D)elete a coin

Q)uit
)";
    char command;

    Coin coin{Coin_size::PENNY,  2006};
    do {
        std::cout << menu << '\n'
                  << coins.size() << " coins >> ";

        std::cin >> command; std::cin.ignore(32767, '\n');
        command = toupper(command);
        switch(command) {
          case 'A' :
            try {
                std::cout << "Coin (year size \\n notes): ";
                std::cin >> coin;
                coins.push_back(coin);
            } catch(std::exception& e) {
                std::cerr << "### Invalid coin: " << e.what() << std::endl;
            }
            break;
          case 'L' :
            std::cout << "\nooooooooooooooo\n   C O I N S\nooooooooooooooo\n\n";
            for(int i=0; i<coins.size(); ++i)
                std::cout << i << ") " << coins[i] << std::endl;   
            break;
          case 'D' :
            int index;
            try {
                std::cout << "Coin index: ";
                std::cin >> index; std::cin.ignore(32767, '\n');
                if(index > coins.size()-1) throw std::out_of_range{"Invalid index"};
                coins.erase(coins.begin() + index);
            } catch(std::exception& e) {
                std::cerr << "### Unable to delete " << index
                          << ": " << e.what() << std::endl;
            }
            break;
          case 'Q' :
            break;
          default :
            std::cerr << "### Invalid command: " << command << std::endl;
        }
    } while(command != 'Q');
 }
