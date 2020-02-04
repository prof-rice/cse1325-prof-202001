CXXFLAGS = --std=c++17

all: color

color: main.o color.o
	$(CXX) $(CXXFLAGS) main.o color.o -o color
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
color.o: color.cpp
	$(CXX) $(CXXFLAGS) -c color.cpp -o color.o
clean:
	rm -f *.o *.gch ~* a.out color
