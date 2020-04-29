#include "polynomial.h"
#include "logger.h" // use -DLOGGER to enable log messages
#include <thread>
#include <mutex>
#include <cmath>

std::mutex m;

Polynomial::Polynomial() { }
Polynomial::Polynomial(std::istream& ist) {
    int tsize; ist >> tsize;
    while(tsize--) _terms.push_back(Term{ist});
}
void Polynomial::save(std::ostream& ost) {
    ost << _terms.size() << '\n';
    for(auto t : _terms) t.save(ost);
}

void Polynomial::add_term(double coefficient, double exponent) {
    _terms.push_back(Term{coefficient, exponent});
}
double Polynomial::operator()(double x) {
    double y = 0.0;
    for(auto t : _terms) y += t.eval(x);
    return y;
}

void Polynomial::solve(double min, double max, int nthreads, double slices, double precision) {
    _roots = {};

    std::vector<std::thread*> threads;
    double delta = (max-min)/nthreads;
    double start = min;
    LOG("   SOLVE: Ready to create threads");
    for(int d=0; d<nthreads; ++d) {
        double end = start + delta;
        threads.push_back(new std::thread([=] {this->solve_recursive(start, end, d, slices/nthreads, precision);}));
        LOGT("   Creating thread " + std::to_string(d) + "[" 
            + std::to_string(start) + " , " 
            + std::to_string(end) + "]");
        start = end;
    }
    LOGT("   SOLVE: " + std::to_string(threads.size()) + " threads created!");
    for(auto* t : threads) t->join();
    LOGT("   SOLVE: Threads joined!");
}
void Polynomial::solve_recursive(double min, double max, int tid, double slices, double precision, int recursions) {
    Polynomial& f = *this;
    std::string id = std::to_string(tid);

    LOGT("   Thread " + id + " [" + std::to_string(min) + " , " + std::to_string(max) + "]");
    double delta = (max - min) / slices;
    double x1 = min;
    double y1 = f(min);
    double x2 = x1 + delta;
    double y2;

    while(x1 < max) {
        y2 = f(x2);
        if(std::signbit(y1) != std::signbit(y2)) {
            if((abs(f(x1+x2)/2) > precision) && (abs(x2 - x1) > precision) && (recursions < 20)) {
                LOGT("   " + id + " searching [" + std::to_string(x1) + " , " + std::to_string(x2) + "]");
                solve_recursive(x1, x2, tid, std::min(slices, (x2-x1)/precision), precision, recursions+1); // recurse for more precision
            } else {
                LOGT(">  " + id + " found " + std::to_string((x1+x2)/2));
                m.lock(); _roots.push_back((x1+x2)/2); m.unlock();
            }
        }
        x1 = x2; 
        x2 = x1 + delta;
        y1 = y2;
    }
}

std::vector<double> Polynomial::roots() {return _roots;}

std::ostream& operator<<(std::ostream& ost, const Polynomial& polynomial) {
    for(auto& t : polynomial._terms) ost << t;
    return ost;
}

