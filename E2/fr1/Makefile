CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: fr1

debug: CXXFLAGS += -g
debug: mainwin

fr1: main.o mainwin.o fr1.o 
	$(CXX) $(CXXFLAGS) main.o mainwin.o fr1.o $(GTKFLAGS) -o fr1

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

fr1.o: fr1.cpp *.h
	$(CXX) $(CXXFLAGS) -c fr1.cpp $(GTKFLAGS) -o fr1.o

clean:
	rm -f *.o *.gch fr1
