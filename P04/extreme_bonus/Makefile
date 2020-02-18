CXXFLAGS += --std=c++17

all: coin

logger: CXXFLAGS += -DLOGGER
logger: coin

coin: main.o coin.o *.h
	$(CXX) $(CXXFLAGS) main.o coin.o -o coin

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

coin.o: coin.cpp *.h
	$(CXX) $(CXXFLAGS) coin.cpp -c -o coin.o

clean:
	rm -f *.o *.gch a.out coin

