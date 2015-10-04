all:	make_exe

make_exe:	word_obj
	g++ Word.o Driver.o -o Driver.exe
word_obj: 	driver_obj
	g++ -c Word.cpp
driver_obj:
	g++ -c Driver.cpp

