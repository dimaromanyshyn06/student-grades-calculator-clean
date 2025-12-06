CXX = g++
CXXFLAGS = -std=c++17 -O2

SRC = person.cpp file_utils.cpp
HDR = person.h file_utils.h split_strategies.h timer.h

all: vector_v1 list_v1 deque_v1

vector_v1: main.cpp $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) main.cpp $(SRC) -o vector_v1.exe

list_v1: list_version.cpp $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) list_version.cpp $(SRC) -o list_v1.exe

deque_v1: deque_version.cpp $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) deque_version.cpp $(SRC) -o deque_v1.exe

clean:
	rm -f *.exe
