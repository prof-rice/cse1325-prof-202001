CXXFLAGS += --std=c++17

all: cart

debug: CXXFLAGS += -g
debug: alls

cart: main.o cart.o item.o *.h
	-$(CXX) $(CXXFLAGS) main.o cart.o item.o -o cart
item.o: item.cpp *.h
	-$(CXX) $(CXXFLAGS) -c item.cpp -o item.o
main.o: main.cpp *.h
	-$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
cart.o: cart.cpp *.h
	-$(CXX) $(CXXFLAGS) -c cart.cpp -o cart.o

clean:
	rm -f *.o *.gch a.out  cart 

