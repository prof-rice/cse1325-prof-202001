#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_store_click();         // Create a new store
        void on_save_click();              // Save the game to default file
        void on_save_as_click();           // Save the game to selected file
        void on_open_click();              // Load the game from selected file
        void on_quit_click();              // Exit the program
                                           // List in data area:
        void on_view_peripheral_click();   //   Peripherals (options)
        void on_view_desktop_click();      //   Desktops (products)
        void on_view_order_click();        //   Orders
        void on_view_customer_click();     //   Customers
                                           // Create a new:
        void on_insert_peripheral_click(); //   Peripheral (option)
        void on_insert_desktop_click();    //   Desktop (product)
        void on_insert_order_click();      //   Order
        void on_insert_customer_click();   //   Customer
        void on_easter_egg_click();        // Preload test data
        void on_about_click();             // Display About dialog

        // These utility methods act as std::cin >> with a dialog
        std::string get_string(std::string prompt);
        double      get_double(std::string prompt);
        int         get_int(std::string prompt);

        // These utility methods write text to screen regions
        void set_data(std::string s);      // Main data area
        void set_msg(std::string s);       // Msg or status bar
    private:
        Store *store;                      // Current store

        Gtk::Label *data;                  // Main data display
        Gtk::Label *msg;                   // Status bar display

        std::string filename;              // Save file for current store
};
#endif 

