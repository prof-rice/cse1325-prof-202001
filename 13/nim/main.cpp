#include "mainwin.h"
#include <gtkmm.h>

int main (int argc, char *argv[]) {
    srand (time(NULL));
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.nim.v1_0");
    Mainwin win;
    return app->run(win);
}

