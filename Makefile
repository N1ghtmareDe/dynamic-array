CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

main: src/main.cpp src/DynamicArray.cpp include/DynamicArray.h
	$(CXX) $(CXXFLAGS) src/*.cpp -o main

clean:
	rm -f main
