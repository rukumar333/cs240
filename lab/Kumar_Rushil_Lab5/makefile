
# Here's the flag for C++11 support and a flag asking to be warned about
# everything. 
FLAGS = -Wall -std=c++11

all: LabT5

Lab5: Lab5.o Sorter.o
	g++ $(FLAGS) Lab5.o Sorter.o -o Lab5

Sorter.o: Sorter.cpp Sorter.h
	g++ $(FLAGS) -c Sorter.cpp -o Sorter.o

Lab5.o: Lab5.cpp Sorter.h
	g++ $(FLAGS) -c Lab5.cpp -o Lab5.o

LabT5: LabT5.o TSorter.o
	g++ $(FLAGS) LabT5.o TSorter.o -o LabT5.exe

TSorter.o: TSorter.cpp TSorter.h
	g++ $(FLAGS) -c TSorter.cpp -o TSorter.o

LabT5.o: LabT5.cpp TSorter.h
	g++ $(FLAGS) -c LabT5.cpp -o LabT5.o

clean:
	rm -f *.o Lab5

