CXXFLAGS += --std=c++17

all: alls

debug: CXXFLAGS += -g
debug: alls

redir: redir.cpp
	-$(CXX) $(CXXFLAGS) redir.cpp -o redir

alls:  redir

clean:
	rm -f *.o *.gch a.out  redir hello-world.log

