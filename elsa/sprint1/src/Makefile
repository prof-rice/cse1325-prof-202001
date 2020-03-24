CXXFLAGS += --std=c++17

elsa: main.o store.o customer.o options.o desktop.o order.o
	$(CXX) $(CXXFLAGS) main.o store.o customer.o options.o desktop.o order.o -o elsa
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp
store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp
customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp
options.o: options.cpp *.h
	$(CXX) $(CXXFLAGS) -c options.cpp
desktop.o: desktop.cpp *.h
	$(CXX) $(CXXFLAGS) -c desktop.cpp
order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c order.cpp
clean:
	rm -f *.o *.gch elsa
