Test gtkmm
==========

To build the code in main.cpp, use the Makefile in lxterminal:

  ``make``

The Makefile creates an executable named simpley "hello", whcih may be executed in lxterminal using

  ``./hello``

The leading "./" just means "in the current directory". Unlike Windows, Linux will NOT run programs in the current directory without the "./". This is a security feature.

---

If you want to delete all of the build products and start over, first "clean" the directory, then run make again. Use these two commands:

  ``make clean``
  ``make``

Since commands can be separated on a single line using ;, you can also do this:

  ``make clean ; make``

---

The gtkmm library is rather complex, so no annotation of the source code is provided here. We'll discuss writing Graphical User Interfaces (GUI) in gtkmm in the middle third of CSE1325.
