#include "point.h"

namespace Graph_lib {   // our graphics interface is in Graph_lib
Point::Point(int x, int y) : _x(x), _y(y) { }

Point::Point(std::istream& ist) {ist >> _x >> _y;}
void Point::save(std::ostream& ost) {ost << _x << ' ' << _y << ' ';}


int Point::x() const {return _x;}
int Point::y() const {return _y;}

// Define equality of points
inline bool Point::operator==(Point rhs) {return _x==rhs._x && _y==rhs._y;} 
inline bool Point::operator!=(Point rhs) {return !(*this==rhs);}
}
