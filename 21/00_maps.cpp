#include <map>
#include <iostream>
#include <iomanip>

int main() {
    std::map<std::string, double> grades = {
        {"Dopey", 66.3},
        {"Grumpy", 70.0},
        {"Bashful", 99.0},
        {"Sneezy", 83.1},
        {"Happy", 98.6},
        {"Sleepy", 71.2},
        {"Doc", 101.7},
    };        

    std::cout << std::setprecision(1) << std::fixed;
    for(const auto& [name, grade] : grades) 
        std::cout << name << " = " << grade << std::endl;

    // prior to C++ 17 adding "structured bindings", we would have written
    // for(const auto& record : grades) 
    //    std::cout << record.first << " = " << record.second << std::endl;

}
