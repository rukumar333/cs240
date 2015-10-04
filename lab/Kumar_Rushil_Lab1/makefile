#
# Specifiy the target
all:	Kumar_Rushil_Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Kumar_Rushil_Hello:	Kumar_Rushil_Hello.o
	g++  Kumar_Rushil_Hello.o Hello_Class.o -o Kumar_Rushil_Hello.exe

# Specify how the object files should be created from source files
Kumar_Rushil_Hello.o:	Hello_Class.o
	g++ -c Kumar_Rushil_Hello.cpp	

# Specify how the object files should be created from source files
Hello_Class.o: 
	g++ -c Hello_Class.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Kumar_Rushil_Hello.exe
