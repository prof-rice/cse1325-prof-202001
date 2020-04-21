#include "polynomial.h"
#include "logger.h"
#include <fstream>
#include <iomanip>

int main(int argc, char* argv[]) {
    int nthreads = 1;
    if(argc > 1) nthreads = std::stoi(argv[1]);
    std::cout << "Requested " << nthreads << " threads ";

    // Working variables
    Polynomial f;

    // Load default polynomial if available
    std::string filename = "untitled.poly";
    try {
        std::ifstream ifs{filename};
        if(!ifs) throw std::runtime_error{"unable to load " + filename};
        f = Polynomial(ifs);
        std::cout << "to solve " << f << " -- "; std::cout.flush();
    } catch(std::exception& e) {
        std::cout << " but failed: " << filename << ": " << e.what() << std::endl;
    }
    LOG("   MAIN: Ready to solve");
    f.solve(-500, 500, nthreads);
    LOG("   MAIN: Solved!");
    std::vector<double> roots = f.roots();
    std::cerr << std::to_string(roots.size()) << " roots found\n";
}
        
