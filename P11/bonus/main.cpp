#include <map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>

std::ostream& operator<<(std::ostream& ost, const std::pair<std::string, int> p) {
    ost << std::left << p.first << std::right << std::setw(6) << p.second;
    return ost;
}

int main(int args, char* argv[]) {
    std::map<std::string, int> words;
    std::string s;
    std::string::size_type swidth = 0;

    std::ifstream ifs {std::string{argv[1]}};
    if(!ifs) {std::cerr << "Provide filename as parameter\n"; return -1;}
    while(ifs >> s) {
        words[s]++;
        swidth = std::max(swidth, s.size());
    }
    for(auto& it : words) std::cout << std::setw(swidth) << it << '\n';

    int size;
    while(true) {
        std::cout << "====================================\n"
                  << "List words with which frequency? ";
        if(!(std::cin >> size) || (size <= 0)) break;
        auto it_next = words.begin();
        while(it_next != words.end()) {
            auto it = std::find_if(it_next, words.end(), 
                [size] (std::pair<std::string, int> p) {return p.second == size;});
            if(it == words.end()) break;
            std::cout << std::setw(swidth) << *it << '\n';
            it_next = ++it;
        }
    }
    std::cout << std::endl;    
}
