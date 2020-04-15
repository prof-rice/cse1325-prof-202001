#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_button_click(); 
        void on_file_new_activate();
        void on_file_open_activate();
        void on_file_save_activate();
        void on_edit_copy_activate();
        void on_edit_cut_activate();
        void on_edit_paste_activate();
        void on_quit_click(); 
};
#endif 

