#include "taxed.h"
#include "taxfree.h"
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    int errors = 0; // Using bit mask
    int errnum = 1;

    // Quantity is 0

    {
        std::ostringstream oss;
        const std::string expected{"Milk ($2.85) 0.00"};
        Taxfree t{"Milk", 2.85};
        oss << t << ' ' << t.price();
        if(oss.str() != expected) {
            errors |= errnum;
            std::cerr << "ERROR: Taxfree item incorrect\n  Expected: '"
                      << expected
                      << "'\n  Actual:   '"
                      << oss.str() << "'\n\n";
        }
        errnum <<=1;
    }

    
    {
        std::ostringstream oss;
        Taxed::set_tax_rate(0.0825);
        const std::string expected{"Ice Cream ($4.95) 0.00"};
        Taxed t{"Ice Cream", 4.95};
        oss << t << ' ' << t.price();
        if(oss.str() != expected) {
            errors |= errnum;
            std::cerr << "ERROR: Taxed item incorrect\n  Expected: '"
                      << expected
                      << "'\n  Actual:   '"
                      << oss.str() << "'\n\n";
        }
        errnum <<=1;
    }

    // Quantity non-zero

    {
        std::ostringstream oss;
        const std::string expected{"Milk (3 @ $2.85) 8.55"};
        Taxfree t{"Milk", 2.85};
        t.set_quantity(3);
        oss << t << ' ' << t.price();
        if(oss.str() != expected) {
            errors |= errnum;
            std::cerr << "ERROR: Taxfree item incorrect\n  Expected: '"
                      << expected
                      << "'\n  Actual:   '"
                      << oss.str() << "'\n\n";
        }
        errnum <<=1;
    }

    
    {
        std::ostringstream oss;
        Taxed::set_tax_rate(0.0825);
        const std::string expected{"Ice Cream (19 @ $4.95) 101.81"};
        Taxed t{"Ice Cream", 4.95};
        t.set_quantity(19);
        oss << t << ' ' << t.price();
        if(oss.str() != expected) {
            errors |= errnum;
            std::cerr << "ERROR: Taxed item incorrect\n  Expected: '"
                      << expected
                      << "'\n  Actual:   '"
                      << oss.str() << "'\n\n";
        }
        errnum <<=1;
    }

    if(errors) std::cerr << "\nFAIL" << std::endl;
}

