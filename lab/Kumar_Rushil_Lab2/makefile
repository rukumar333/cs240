all: 	make_exe
make_exe: 	second_object
	g++ -std=c++11 Lab2.o KumarRushilAccountFunctions.o -o Bank.exe

second_object: 	
	g++ -std=c++11 -c Lab2.cpp KumarRushilAccountFunctions.cpp	

clean: 
	rm *.o Bank.exe
