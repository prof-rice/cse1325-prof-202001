CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: fr3

debug: CXXFLAGS += -g
debug: mainwin

fr3: main.o canvas.o 
	$(CXX) $(CXXFLAGS) main.o canvas.o $(GTKFLAGS) -o fr3

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

canvas.o: canvas.cpp *.h
	$(CXX) $(CXXFLAGS) -c canvas.cpp $(GTKFLAGS) -o canvas.o

clean:
	rm -f *.o *.gch fr3
