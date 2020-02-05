CXXFLAGS = --std=c++17

info:
	@echo
	@printf 'Type e.g., "make auto"  to create program "auto"\n'
	@printf 'Type       "make all"   to create every program\n'
	@printf 'Type       "make clean" to delete every program\n\n'

00_foo: 00_foo.cpp
	-$(CXX) $(CXXFLAGS) -o 00_foo 00_foo.cpp
	@printf "Now type ./00_foo to execute the result\n\n"

01_foo: 01_foo.cpp
	-$(CXX) $(CXXFLAGS) -o 01_foo 01_foo.cpp
	@printf "Now type ./01_foo to execute the result\n\n"

02_foo: 02_foo.cpp
	-$(CXX) $(CXXFLAGS) -o 02_foo 02_foo.cpp
	@printf "Now type ./02_foo to execute the result\n\n"

03_foo: 03_foo.cpp
	-$(CXX) $(CXXFLAGS) -o 03_foo 03_foo.cpp
	@printf "Now type ./03_foo to execute the result\n\n"

04_foo: 04_foo.cpp
	-$(CXX) $(CXXFLAGS) -o 04_foo 04_foo.cpp
	@printf "Now type ./04_foo to execute the result\n\n"

all:  00_foo 01_foo 02_foo 03_foo 04_foo 

clean:
	rm -f *.o *.gch a.out  00_foo 01_foo 02_foo 03_foo 04_foo 

