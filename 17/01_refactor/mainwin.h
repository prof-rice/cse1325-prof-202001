#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>

const std::string TITLE = "CSE1325 Paint";
const std::string VERSION = "2.0.0";
const std::string EXT = "ctp";

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_painting_click();      // Create a new painting
        void on_save_as_click();           // Save the painting to a file
        void on_open_click();              // Load the painting from a file
        void on_about_click();             // Display About dialog
        void on_quit_click();              // Exit the game
    private:
        Gtk::DrawingArea* canvas;          // The painting
        Gtk::Label *msg;                   // Status message display
};
#endif 

