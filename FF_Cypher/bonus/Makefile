# Makefile for Cypher
CXXFLAGS += --std=c++14

all: main test interactive

debug: CXXFLAGS += -g
debug: all

rebuild: clean all

main: main.o cypher.o rot13.o xor.o substitution.o *.h
	$(CXX) $(CXXFLAGS) -o cypher main.o cypher.o rot13.o xor.o substitution.o
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
test: test.o cypher.o rot13.o substitution.o xor.o *.h
	$(CXX) $(CXXFLAGS) -o test test.o cypher.o rot13.o substitution.o xor.o
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp
cypher.o: cypher.cpp *.h
	$(CXX) $(CXXFLAGS) -c cypher.cpp
rot13.o: rot13.cpp *.h
	$(CXX) $(CXXFLAGS) -c rot13.cpp
xor.o: xor.cpp *.h
	$(CXX) $(CXXFLAGS) -c xor.cpp
substitution.o: substitution.cpp *.h
	$(CXX) $(CXXFLAGS) -c substitution.cpp
interactive: interactive.o cypher.o rot13.o substitution.o xor.o *.h
	$(CXX) $(CXXFLAGS) -o interactive interactive.o cypher.o rot13.o substitution.o xor.o
interactive.o: interactive.cpp *.h
	$(CXX) $(CXXFLAGS) -c interactive.cpp
clean:
	-rm -f *.o *.gch *~ test interactive cypher
