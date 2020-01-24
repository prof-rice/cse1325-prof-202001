CXXFLAGS = --std=c++17

# Don't try to link class files with no main function
CLASSES = 18_color 19_color 22_grid 23_grid 24_grid 25_grid 

all: $(filter-out $(CLASSES), $(patsubst %.cpp, %, $(wildcard *.cpp)))

# Special cases: These have classes in separate files
#   Make correctly infers how to generate the .o files

18_main: 18_main.o 18_color.o
	$(CXX) $(CXXFLAGS) 18_main.o 18_color.o -o 18_main

19_main: 19_main.o 19_color.o
	$(CXX) $(CXXFLAGS) 19_main.o 19_color.o -o 19_main

22_main: 22_main.o 22_grid.o
	$(CXX) $(CXXFLAGS) 22_main.o 22_grid.o -o 22_main

23_main: 23_main.o 23_grid.o
	$(CXX) $(CXXFLAGS) 23_main.o 23_grid.o -o 23_main

24_main: 24_main.o 24_grid.o
	$(CXX) $(CXXFLAGS) 24_main.o 24_grid.o -o 24_main

25_main: 25_main.o 25_grid.o
	$(CXX) $(CXXFLAGS) 25_main.o 25_grid.o -o 25_main

# Otherwise, compile and link every .cpp file
%: %.cpp
	-$(CXX) $(CXXFLAGS) $< -o $@ 

clean:
	for f in *.cpp a.out; do \
	  rm -f $${f%.cpp} ; \
	done
	rm -f *.o *.gch ~* a.out

