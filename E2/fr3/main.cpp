 #include "canvas.h"

 int main (int argc, char *argv[]) {
     auto app = Gtk::Application::create(argc, argv, "cse1325.exam.two");
     Canvas canvas;
     Gtk::Window win;
     win.add(canvas);
     win.show_all();
     return app->run(win);   
 }

