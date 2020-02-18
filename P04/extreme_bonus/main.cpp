#include "coin.h"
#include <vector>
#include <fstream>

const std::string magic_cookie = "ℂ0iℿ";
const std::string file_version = "1.0";

int main() {
    std::vector<Coin> coins;
    const std::string menu = R"(
===============
 CSE1325 COINS
===============
A)dd a coin
L)ist all coins
D)elete a coin

S)ave all coins
O)pen coin file

Q)uit
)";
    char command;
    std::string filename;
    std::string current_file = "untitled.coins";

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
          case 'O' :
            try {
                // Get the filename to open - if not provided, abort the open
                std::cout << "Filename? ";
                std::getline(std::cin, filename);
                if(!filename.size()) break;

                // Open the input file stream
                std::ifstream ifs{filename};

                // Check the magic cookie to ensure this is a Coins file, and
                //   the version of the file format to ensure compatibility
                std::string mc, fv;
                std::getline(ifs, mc);
                std::getline(ifs, fv);
                if (mc != magic_cookie)
                    throw std::runtime_error{filename + " is not a Coins file"};
                if (fv != file_version)
                    throw std::runtime_error{filename + " is an unsupported file version"};

                // Go for open! Clear the vector and load data from the file
                // The ifs object will close the stream in its destructor
                coins.clear();
                while(ifs) {
                    ifs >> coin;
                    if(ifs) coins.push_back(coin);
                }
            } catch(std::exception& e) {
                std::cerr << "### Opening " << filename << " failed: " << e.what() << std::endl;
                break;
            }
            current_file = filename;
            break;
          case 'S' :
            try {
                // Get the filename to save - if not provided, use the most recently opened
                std::cout << "Filename (Enter for " << current_file << "): ";
                std::getline(std::cin, filename);
                if(!filename.size()) filename = current_file;

                // Open the output file stream
                std::ofstream ofs{filename};

                // Save the magic cookie and file version for verification when file is opened
                ofs << magic_cookie << '\n' << file_version << '\n';

                // Write the data to the file
                for(auto& c : coins) ofs << c;
            } catch(std::exception& e) {
                std::cerr << "### Write to " << filename << " failed: " << e.what() << std::endl;
                break;
            }
            current_file = filename;
            break;
          case 'Q' :
            break;
          default :
            std::cerr << "### Invalid command: " << command << std::endl;
        }
    } while(command != 'Q');
 }
