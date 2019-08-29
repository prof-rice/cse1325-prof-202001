CXXFLAGS = --std=c++17

all: hello_getenv_user hello_getuid hello_whoami

hello_getenv_user: hello_getenv_user.cpp
	$(CXX) $(CXXFLAGS) hello_getenv_user.cpp -o hello_getenv_user

hello_getuid: hello_getuid.cpp
	$(CXX) $(CXXFLAGS) hello_getuid.cpp -o hello_getuid

hello_whoami: hello_whoami.cpp
	$(CXX) $(CXXFLAGS) hello_whoami.cpp -o hello_whoami

clean:
	-rm -f *.o *~ a.out hello_getenv_user hello_getuid hello_whoami
