CXXFLAGS = --std=c++17

bad_init: bad_init.cpp
	@printf "Do you know why bad_init.cpp won't compile?\n"
	@printf "Can you fix it?\n--\n"
	-$(CXX) $(CXXFLAGS) -o bad_init bad_init.cpp

clean:
	rm -f *.o *.gch a.out bad_init

