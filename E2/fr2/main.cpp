#include "mainwin.h"

int main (int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.nim.v1_2_1");
    Mainwin win;
    return app->run(win);
}

