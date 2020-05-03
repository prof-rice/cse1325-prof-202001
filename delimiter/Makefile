CXXFLAGS += --std=c++17

all: alls

debug: CXXFLAGS += -g
debug: alls

delim: delim.cpp
	-$(CXX) $(CXXFLAGS) delim.cpp -o delim
delims: delims.cpp
	-$(CXX) $(CXXFLAGS) delims.cpp -o delims

alls:  delim delims

clean:
	rm -f *.o *.gch a.out  delim delims

