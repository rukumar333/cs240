all:	make_exe	

make_exe:	create_object
	g++ -std=c++11 Customer.o Bank.o main.o -o Bank.exe
create_object:
	g++ -std=c++11 -c Customer.cpp Bank.cpp main.cpp
clean:
	rm *.o Bank.exe


