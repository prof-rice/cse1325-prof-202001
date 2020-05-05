CXXFLAGS += --std=c++17

all: words

debug: CXXFLAGS += -g
debug: all

words: main.o
	-$(CXX) $(CXXFLAGS) main.o -o words
main.o: main.cpp
	-$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o *.gch a.out  words 

