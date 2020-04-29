#include "polynomial.h"
#include "logger.h"
#include "ls.h" // Read list of files
#include <fstream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <thread>

int main() {
    // BONUS: Modify main() to load and solve multiple polynomials
    //    simultaneously using a set of threads for each polynomial.
    //    Note that this will break "make poly", so if you want to
    //    preserve the threadless build, handle that situation, too.

    // Working variables
    double c, e, x;
    int nthreads = 1; // number of threads
    std::vector<Polynomial> fv;
    int choice;
    int index;

    // Load a default polynomial if available
    std::string filename = "untitled.poly";
    try {
        std::ifstream ifs{filename};
        if(!ifs) throw std::runtime_error{"file not found"};
        fv.push_back(Polynomial(ifs));
        std::cout << "Loaded ";
    } catch(std::exception& e) {
        std::cout << "Failed to load";
    }
    std::cout << filename << ": " << fv.back() << std::endl;

    // Main menu
    std::string menu = R"(

   Polynomial Paradise
   ========== ========

1) New Polynomial
2) Add Terms to a Polynomial
3) Load a Polynomial
4) Save a Polynomial
5) Evaluate a Polynomial
6) Solve All Polynomials
7) Delete a Polynomial
0) Exit

Polynomials
-----------
)";

    // =============================================================
    // Main loop
    do {
        
        std::cout << menu;
        for(int i=0; i<fv.size(); ++i) std::cout << i << ") " << fv[i] << '\n';
        // for(Polynomial& f : fv) std::cout << f << '\n';
        std::cout << "\n==> ";
        std::cin >> choice; std::cin.ignore(32767, '\n');

        // Data validation
        if(0 > choice || choice > 7 || !std::cin) {
            std::cerr << "### INVALID CHOICE ###\n";
            std::cin.clear();
            choice = -1;
        }
        if(choice == 2 || choice >= 4) {
            if(fv.size() < 1) {
                std::cerr << "No polynomials are loaded\n";
                choice = -1;
            }
        }

        // Select a polynomial for choices needing one specified
        if(choice == 2 || choice == 4 || choice == 5 || choice == 7) {
            if(fv.size() == 1) {
                index = 0;
            } else {
                std::cout << "Which polynomial? ";
                std::cin >> index;
                if(0 > index || index >= fv.size()) choice = -1;
            }
        }

        // Select a filename for choices requiring one
        if(choice == 3 || choice == 4) {
            for(auto& s : ls("*.poly")) std::cout << s << '\n';
            std::cout << "\nFilename ? ";
            std::getline(std::cin, filename);
            if(filename.empty()) choice = -1;
        }

        if(choice == 1) {                   // New Polynomial
            fv.push_back(Polynomial{});
            index = fv.size() - 1;
        }
        if(choice == 1 || choice == 2) {    // Add Terms to Polynomial
            do {
                std::cout << "Enter coefficient then exponent (0 0 when done): ";
                std::cin >> c >> e;
                if(c != 0) fv[index].add_term(c, e);
            } while(e != 0.0);
        }
        if(choice == 3) {                   // Load Polynomial
            try {
                std::ifstream ifs{filename};
                if(!ifs) throw std::runtime_error{"Open failed"};
                fv.push_back(Polynomial(ifs));
                std::cout << "Loaded " << filename << ": " << fv.back() << std::endl;
            } catch(std::exception& e) {
                std::cerr << "Could not load " << filename << ": " 
                  << e.what() << std::endl;
            }
        } 
        if(choice == 4) {                   // Save a Polynomial
            try {
                std::ofstream ofs{filename};
                fv[index].save(ofs);
                std::cout << "Saved " << filename << ": " << fv[index] << std::endl;
            } catch(std::exception& e) {
                std::cerr << "Could not save " << filename << ": " 
                  << e.what() << std::endl;
            }
        } 
        if(choice == 5) {                   // Evaluate a Polynomial
            std::cout << "f(x) = " << fv[index] << std::endl;
            do {
                std::cout << "Enter x (0 exits): ";
                std::cin >> x;
                std::cout << "f(" << x << ") = " << fv[index](x) << std::endl;
            } while (x != 0.0);
       }
       if(choice == 6) {                    // Solve all Polynomials
            std::cout << "Solving " << fv.size() << " polynomials\n";
            std::cout << "Solve each between min max (== exits): ";
            std::cin >> c >> e; if(c >= e) break;
            std::cout << "Number of threads per polynomial: ";
            std::cin >> nthreads;

            // Solve each polynomial in a separate thread
            auto start = std::chrono::high_resolution_clock::now();  // Start the timer!
            std::vector<std::thread*> threads;
            for(Polynomial& fr : fv) {
                Polynomial* f = &fr; // Copy pointer to each polynomial to solve in the lambda
                threads.push_back(new std::thread{[=] {f->solve(c, e, nthreads);}});
            }
            for(std::thread* t : threads) t->join();
            auto stop = std::chrono::high_resolution_clock::now();

            // Print elapsed time for all threads
            std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count() << " seconds\n";

            // Print the roots
            for(Polynomial& f : fv) {
                std::cout << "=============================================\n";
                std::cout << "For polynomial: " << f << "\n\n";
                std::vector<double> roots = f.roots();
                if(roots.empty()) {
                    std::cout << "No roots found!\n";
                } else {
                    std::ios cout_state(nullptr);
                    cout_state.copyfmt(std::cout);
                    std::cout << std::fixed << std::setprecision(16);

                    std::cout << "\nx = \n";
                    for(double r : roots) {
                        std::cout << "    " << std::setw(21) << r << " f(x) = " << std::setw(21) << f(r) << std::endl;
                    }
                    std::cout.copyfmt(cout_state);
                }
            }
        }
        if(choice == 7) {
            fv.erase(fv.begin()+index);
        }
    } while(choice != 0);
}
        
