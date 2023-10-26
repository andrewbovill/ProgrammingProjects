G++ = g++
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: 001.exe

molecule.o: molecule.cpp
	$(G++) -g -c $< -o $@

001.o: 001.cpp
	$(G++) -g -c $< -o $@

001.exe: 001.o molecule.o
	$(G++) -g $^ -o $@

clean:
	rm -rf *.exe *.o
