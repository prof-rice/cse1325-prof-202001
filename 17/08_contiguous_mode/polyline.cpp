#include "polyline.h"
#include <iostream>

namespace Graph_lib {

Polyline::Polyline(Gdk::RGBA color, double width) : Shape(color, width) { }

Polyline* Polyline::clone() {
    return new Polyline{*this}; 
}
}
