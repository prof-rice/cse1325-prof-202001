#include "canvas.h"

bool Canvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    // Line width and color may vary
    cr->set_line_width(3.0);
    cr->set_source_rgb((double)255/256, (double)13/256, (double)11/256); 

    // Draw triangle (or + or X)
    cr->move_to(  0,   0);
    cr->line_to(  0, 100);
    cr->line_to(100,  50);
    cr->line_to(  0,   0);

    // Apply the colors to the window
    cr->stroke();

    // Drawing was successful
    return true;
}

