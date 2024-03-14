G++ = g++
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
LIBS = -larmadillo 

all: 003.exe

hartree-fock.o: hartree-fock.cpp
	$(G++) -c $< -o $@ $(LIBS)

003.o: 003.cpp
	$(G++) -c $< -o $@ $(LIBS)

003.exe: 003.o hartree-fock.o
	$(G++) $^ -o $@ $(LIBS)

clean:
	rm -rf *.exe *.o

