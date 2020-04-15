#include "mainwin.h"

Mainwin::Mainwin()  {

    set_default_size(400, 200);
    // Title may vary  ;-)
    set_title("Viking Mars Lander");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    //     F I L E (or E D I T)
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         S A V E (or Save As, Open, Copy, Cut, Paste)
    // Append Save to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_file_save_activate();});
    filemenu->append(*menuitem_save);

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*toolbar);

    //      B U T T O N
    // Add an icon for a button
    Gtk::Image* button1_image = Gtk::manage(new Gtk::Image{"toolbutton.png"});
    Gtk::ToolButton* button1 = Gtk::manage(new Gtk::ToolButton(*button1_image));
    //button1->set_tooltip_markup("Select one stick");
    button1->signal_clicked().connect([this] {this->on_button_click();});
    toolbar->append(*button1);

    // /////////////////////////// ////////////////////////////////////////////
    // D I S P L A Y
    // Provide a text entry box 
    Gtk::Label* display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);
    
    // Make the box and everything in it visible
    vbox->show_all();

}
