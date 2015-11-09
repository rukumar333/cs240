FLAGS = -g -std=c++11

all: Driver

Driver: Driver.o 
	g++ $(FLAGS) Driver.o BST.o -o Driver.exe

Driver.o: BST.o Driver.cpp
	g++ $(FLAGS) -c Driver.cpp

BST.o: BST.cpp
	g++ $(FLAGS) -c BST.cpp

clean:
	rm *.o *.exe
