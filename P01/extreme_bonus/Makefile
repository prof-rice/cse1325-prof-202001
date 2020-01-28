CXXFLAGS = --std=c++17

all: hello hello_getuid hello_whoami hello_finger

hello: hello.cpp
	$(CXX) $(CXXFLAGS) hello.cpp -o hello

hello_getuid: hello_getuid.cpp
	$(CXX) $(CXXFLAGS) hello_getuid.cpp -o hello_getuid

hello_whoami: hello_whoami.cpp
	$(CXX) $(CXXFLAGS) hello_whoami.cpp -o hello_whoami

hello_finger: hello_finger.cpp
	$(CXX) $(CXXFLAGS) hello_finger.cpp -o hello_finger

clean:
	-rm -f *.o *~ a.out hello hello_getuid hello_whoami hello_finger
