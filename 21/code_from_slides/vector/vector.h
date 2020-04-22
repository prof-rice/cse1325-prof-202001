#ifndef __VECTOR_H
#define __VECTOR_H


// Here's a quick look a very simplified std::vector-like template.
// std::vector isn't magic - somebody wrote it! Somebody... like you?

#include <cassert>

template <class T>
class Vector {
  public:
    Vector(int s) : _size{0}, _max(s), _elem{new T[s]} { }
    ~Vector() {delete[ ] _elem; }
    int size() {return _size;}
    void push_back(T t) {_elem[_size] = t; assert(_size++ < _max);}
    void pop_back() {assert(_size-- > 0);}
    T& back() {return operator[](_size-1);}
    T& operator[](int n) {assert(0 <= n && n < _size); return _elem[n]; } 
  private:
    int _max;  // size of the array
    int _size; // next array element
    T*  _elem; // a pointer to the elements
};

#endif
