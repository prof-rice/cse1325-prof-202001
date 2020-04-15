#include "mainwin.h"

void Mainwin::on_button_click() {
  // Heap - if stack: Gtk::Dialog dialog{"Lime Iron", *this};
  Gtk::Dialog* dialog = nullptr;
  try {
    dialog = new Gtk::Dialog{"Lime Iron", *this}; // Heap only

    // ============ Entry, Scale, or SpinButton ====================
    // Gtk::Entry
    Gtk::Entry* entry = Gtk::manage(new Gtk::Entry);

    #ifdef NOT_ENTRY
    // Gtk::Scale (range may vary)
    Gtk::Scale* scale = Gtk::manage(new Gtk::Scale);
    scale->set_range(13.0, 83.0);
    scale->set_increments(1.0, 5.0);

    // Gtk::SpinButton (range may vary)
    Gtk::SpinButton* spinbutton = Gtk::manage(new Gtk::SpinButton);
    spinbutton->set_range(13.0, 83.0);
    spinbutton->set_increments(1.0, 5.0);
    #endif
    // =============================================================

    Gtk::Label* label = Gtk::manage(new Gtk::Label);
    label->set_markup("Select <b>Size</b>");
    Gtk::HBox* hbox = Gtk::manage(new Gtk::HBox);

    hbox->pack_start(*label, Gtk::PACK_SHRINK, 0);
    hbox->pack_start(*entry); // or scale or spinbutton
    dialog->get_content_area()->pack_start(*hbox);

    dialog->add_button("Close", 1);
    dialog->show_all();
    dialog->run();

    // ============ Entry, Scale, or SpinButton ====================
    // Gtk::Entry (range may vary)
    int i = std::stoi(entry->get_text());
    if (i < 13 || i > 83) throw std::out_of_range{"Bad value"};
    display->set_text(entry->get_text());

    #ifdef NOT_ENTRY
    // Gtk::Scale
    display->set_text(std::to_string(scale->get_value()));

    // Gtk::SpinButton
    display->set_text(std::to_string(spinbutton->get_value()));
    #endif
    // =============================================================

  } catch(std::exception& e) {
    display->set_text("-1");
  }
  delete dialog; // Heap only
}
