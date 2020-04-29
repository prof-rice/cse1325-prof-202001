CXXFLAGS += --std=c++17

all: poly polyb polyt test

logger: CXXFLAGS += -DLOGGER
logger: all

debug: CXXFLAGS += -g
debug: all

poly: main.o polynomial.o term.o *.h
	$(CXX) $(CXXFLAGS) main.o polynomial.o term.o -o poly
polyt: maint.o polynomial_threaded.o term.o ls.o *.h
	$(CXX) $(CXXFLAGS) -pthread maint.o polynomial_threaded.o term.o ls.o -o polyt
polyb: batch.o polynomial_threaded.o term.o *.h
	$(CXX) $(CXXFLAGS) -pthread batch.o polynomial_threaded.o term.o -o polyb
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
maint.o: maint.cpp *.h
	$(CXX) $(CXXFLAGS) -c maint.cpp -o maint.o
batch.o: batch.cpp *.h
	$(CXX) $(CXXFLAGS) -c batch.cpp -o batch.o
polynomial.o: polynomial.cpp *.h
	$(CXX) $(CXXFLAGS) -c polynomial.cpp -o polynomial.o
polynomial_threaded.o: polynomial_threaded.cpp *.h
	$(CXX) $(CXXFLAGS) -c -pthread polynomial_threaded.cpp -o polynomial_threaded.o
term.o: term.cpp *.h
	$(CXX) $(CXXFLAGS) -c term.cpp -o term.o
ls.o: ls.cpp *.h
	$(CXX) $(CXXFLAGS) -c ls.cpp -o ls.o

test: test.o polynomial.o term.o *.h
	$(CXX) $(CXXFLAGS) test.o polynomial.o term.o -o test
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

clean:
	rm -f *.o *.gch ~* a.out poly polyt polyb test
