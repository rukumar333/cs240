FLAGS = -g -std=c++11

all: Driver

Driver: Driver.o
	g++ $(FLAGS) Driver.o Time.o Song.o Radio.o MaxHeap.o LinkedList.o Hash.o -o Driver.exe

Driver.o: Song.o Time.o Radio.o MaxHeap.o LinkedList.o Hash.o Driver.cpp 
	g++ $(FLAGS) -c Driver.cpp

Hash.o: Hash.cpp
	g++ $(FLAGS) -c Hash.cpp

LinkedList.o: LinkedList.cpp
	g++ $(FLAGS) -c LinkedList.cpp

MaxHeap.o: MaxHeap.cpp
	g++ $(FLAGS) -c MaxHeap.cpp

Time.o: Time.cpp	
	g++ $(FLAGS) -c Time.cpp

Song.o: Song.cpp
	g++ $(FLAGS) -c Song.cpp

Radio.o: Radio.cpp
	g++ $(FLAGS) -c Radio.cpp

clean: 
	rm *.exe *.o
