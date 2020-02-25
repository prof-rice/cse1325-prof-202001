CXXFLAGS += --std=c++17

all: store

store: main.o product.o taxed.o taxfree.o *.h
	$(CXX) $(CXXFLAGS) main.o product.o taxed.o taxfree.o  -o store

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

product.o: product.cpp *.h
	$(CXX) $(CXXFLAGS) product.cpp -c -o product.o

taxed.o: taxed.cpp *.h
	$(CXX) $(CXXFLAGS) taxed.cpp -c -o taxed.o

taxfree.o: taxfree.cpp *.h
	$(CXX) $(CXXFLAGS) taxfree.cpp -c -o taxfree.o

clean:
	rm -f *.o *.gch a.out store

