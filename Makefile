CXX = g++
CXXFLAGS = -std=c++23

all:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) main.cpp -o main
run:
	$(all)
	./main

