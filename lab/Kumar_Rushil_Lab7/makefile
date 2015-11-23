FLAGS = -g -std=c++11

all: Driver

Driver: Driver.o
	g++ $(FLAGS) Driver.o Time.o -o Driver.exe

Driver.o: Time.o Driver.cpp
	g++ $(FLAGS) -c Driver.cpp

Time.o: Time.cpp	
	g++ $(FLAGS) -c Time.cpp

clean: 
	rm *.exe *.o
