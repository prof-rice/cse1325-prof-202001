#include "mainwin.h"
#include <iostream> // for std::cerr logging

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_button_click(){std::cout << "on_button_click"<< std::endl;}
void Mainwin::on_file_new_activate()   {std::cout << "on_file_new_activate"   << std::endl;}
void Mainwin::on_file_open_activate()  {std::cout << "on_file_open_activate"  << std::endl;}
void Mainwin::on_file_save_activate()  {std::cout << "on_file_save_activate"  << std::endl;}
void Mainwin::on_edit_copy_activate()  {std::cout << "on_edit_copy_activate"  << std::endl;}
void Mainwin::on_edit_cut_activate()   {std::cout << "on_edit_cut_activate"   << std::endl;}
void Mainwin::on_edit_paste_activate() {std::cout << "on_edit_paste_activate" << std::endl;}

