#include <gtkmm.h>
#include "mainwin.h"

int main (int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.elsa.v0_2_0");
    Mainwin win;
    return app->run(win);
}

