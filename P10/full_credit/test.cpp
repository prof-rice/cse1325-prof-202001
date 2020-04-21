#include "polynomial.h"
#include <iostream>
#include <sstream>
#include <algorithm>

int main() {
    double c, e, x;

    {   // Quadratic evaluation test
        Polynomial f;
        f.add_term( 1, 2);
        f.add_term(-2, 1);
        f.add_term(-8, 0);

        if(f( 4) !=  0) std::cerr << "FAIL: f( 4) = x²-2x-8 =  0, not " << f( 4) << std::endl; // ROOT
        if(f(-2) !=  0) std::cerr << "FAIL: f(-2) = x²-2x-8 =  0, not " << f(-2) << std::endl; // ROOT
        if(f( 5) !=  7) std::cerr << "FAIL: f( 4) = x²-2x-8 =  7, not " << f( 5) << std::endl;
        if(f( 0) != -8) std::cerr << "FAIL: f(-8) = x²-2x-8 = -8, not " << f( 0) << std::endl;
    }

    {   // Trinomial evaluation test
        Polynomial f;
        f.add_term( 1, 3);
        f.add_term(-5, 2);
        f.add_term(-1, 1);
        f.add_term( 5, 0);

        if(f(-1) !=  0) std::cerr << "FAIL: f(-1) = x³-5x²-x+5 =  0, not " << f(-1) << std::endl; // ROOT
        if(f( 1) !=  0) std::cerr << "FAIL: f( 1) = x³-5x²-x+5 =  0, not " << f( 1) << std::endl; // ROOT
        if(f( 5) !=  0) std::cerr << "FAIL: f( 5) = x³-5x²-x+5 =  0, not " << f( 5) << std::endl; // ROOT
        if(f( 2) != -9) std::cerr << "FAIL: f( 2) = x³-5x²-x+5 = -9, not " << f( 2) << std::endl;
        if(f( 0) !=  5) std::cerr << "FAIL: f( 4) = x³-5x²-x+5 =  5, not " << f( 0) << std::endl;

        // Solver tests
        try {
            f.solve(-2000, 2000, 1, 1000000);
            std::vector<double> roots = f.roots();
            std::sort(roots.begin(), roots.end());
            if(abs(roots.at(0) + 1.0) > 0.001)
                std::cerr << "FAIL: " << roots[0] << " found solving f(-1) = x³-5x²-x+5 =  0, not " << f(-1) << std::endl;
            if(abs(roots.at(1) - 1.0) > 0.001)
                std::cerr << "FAIL: " << roots[1] << " found solving f( 1) = x³-5x²-x+5 =  0, not " << f( 1) << std::endl;
            if(abs(roots.at(2) - 5.0) > 0.001)
                std::cerr << "FAIL: " << roots[2] << " found solving f( 5) = x³-5x²-x+5 =  0, not " << f( 5) << std::endl;
        } catch(std::exception& e) {
            std::cerr << "FAIL: found fewer than 3 roots for x³-5x²-x+5" << std::endl;
        }

        // Save and Load tests
        std::stringstream ss;
        f.save(ss);
        if(ss.str() != "4\n1 3\n-5 2\n-1 1\n5 0\n") std::cerr << "FAIL: wrote f(x) = x³-5x²-x+5 as \n" << ss.str() << std::endl;
        Polynomial g{ss};
        if(g(-1) !=  0) std::cerr << "FAIL: g(-1) = x³-5x²-x+5 =  0, not " << g(-1) << std::endl; // ROOT
    }
 }
