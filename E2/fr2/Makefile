CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: fr2

debug: CXXFLAGS += -g
debug: mainwin

fr2: main.o mainwin.o fr2.o 
	$(CXX) $(CXXFLAGS) main.o mainwin.o fr2.o $(GTKFLAGS) -o fr2

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

fr2.o: fr2.cpp *.h
	$(CXX) $(CXXFLAGS) -c fr2.cpp $(GTKFLAGS) -o fr2.o

clean:
	rm -f *.o *.gch fr2
