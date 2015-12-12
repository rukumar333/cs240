FLAGS = -g -std=c++11

all: Driver

Driver: Driver.o
	g++ $(FLAGS) LinkedList.o Graph.o Driver.o -o Driver.exe

Driver.o: LinkedList.o Graph.o Driver.cpp 
	g++ $(FLAGS) -c Driver.cpp

LinkedList.o: LinkedList.cpp
	g++ $(FLAGS) -c LinkedList.cpp

Graph.o: Graph.cpp
	g++ $(FLAGS) -c Graph.cpp

clean: 
	rm *.exe *.o
