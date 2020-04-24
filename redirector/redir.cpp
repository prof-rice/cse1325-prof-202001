#include <fstream>
#include <iostream>

class redirecter {
  public:
    redirecter(std::ostream & dst, std::ostream & src)
        : src(src), sbuf(src.rdbuf(dst.rdbuf())) {}
    ~redirecter() { src.rdbuf(sbuf); }
  private:
    std::ostream & src;
    std::streambuf * const sbuf;
};

void hello_world() {
    std::cout << "Hello, world!\n";
}

int main() {
    std::ofstream log("hello-world.log");
    redirecter redirect(log, std::cout);
    hello_world();
    return 0;
}
