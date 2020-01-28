CXXFLAGS = --std=c++17

all: example test color

color: main.o color.o
	$(CXX) $(CXXFLAGS) main.o color.o -o color
test: test.o color.o
	$(CXX) $(CXXFLAGS) test.o color.o -o test
example: example.o
	$(CXX) $(CXXFLAGS) example.o -o example

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
color.o: color.cpp
	$(CXX) $(CXXFLAGS) -c color.cpp -o color.o
example.o: example.cpp
	$(CXX) $(CXXFLAGS) -c example.cpp -o example.o

color.gch: color.h
	$(CXX) $(CXXFLAGS) -c color.h -o color.gch

clean:
	rm -f *.o *.gch ~* a.out test color example
