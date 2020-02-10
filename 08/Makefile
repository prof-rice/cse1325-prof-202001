CXXFLAGS = --std=c++17

all:  00_main 01_main 03_main 10_main 11_main
	@printf "\n02_main.cpp includes an intention error, and has been skipped\nType 'make 02_main' to see the error\n\n"

00_main: 00_main.cpp
	-$(CXX) $(CXXFLAGS) -o 00_main 00*.cpp

01_main: 01_main.cpp
	-$(CXX) $(CXXFLAGS) -o 01_main 01*.cpp

02_main: 02_main.cpp
	-$(CXX) $(CXXFLAGS) -o 02_main 02*.cpp

03_main: 03_main.cpp
	-$(CXX) $(CXXFLAGS) -o 03_main 03*.cpp

10_main: 10_main.cpp
	-$(CXX) $(CXXFLAGS) -o 10_main 10*.cpp

11_main: 11_main.cpp
	-$(CXX) $(CXXFLAGS) -o 11_main 11*.cpp

clean:
	rm -f *.o *.gch a.out  ??_main

